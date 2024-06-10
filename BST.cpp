#include <iostream>
#include <fstream>
#include <algorithm>
#include "BST.h"


using namespace std;


BST::BST() {
	root = NULL;
	count = 0;
}


bool BST::empty() {
	if (count == 0) return true;
	return false;
}


int BST::size() {
	return count;
}


void BST::preOrderPrint() {
	if (root == NULL) return;// handle special case
	else preOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::preOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	cur->item.print(cout);
	preOrderPrint2(cur->left);
	preOrderPrint2(cur->right);
}


void BST::inOrderPrint() {
	if (root == NULL) return;// handle special case
	else inOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::inOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	inOrderPrint2(cur->left);
	cur->item.print(cout);
	inOrderPrint2(cur->right);
}


void BST::postOrderPrint() {
	if (root == NULL) return;// handle special case
	else postOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::postOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	postOrderPrint2(cur->left);
	postOrderPrint2(cur->right);
	cur->item.print(cout);
}



int BST::countNode() {
	int	counter = 0;
	if (root == NULL) return 0;
	countNode2(root, counter);
	return counter;
}


void BST::countNode2(BTNode *cur, int &count) {
	if (cur == NULL) return;
	countNode2(cur->left, count);
	countNode2(cur->right, count);
	count++;
}


bool BST::findGrandsons(type grandFather) {
	if (root == NULL) return false;
	return (fGS2(grandFather, root));
}


bool BST::fGS2(type grandFather, BTNode *cur) {
	if (cur == NULL) return false;
	//if (cur->item == grandFather) {
	if (cur->item.compare2(grandFather)){

		fGS3(cur, 0);// do another TT to find grandsons
		return true;
	}
	if (fGS2(grandFather, cur->left)) return true;
	return fGS2(grandFather, cur->right);
}


void BST::fGS3(BTNode *cur, int level) {
	if (cur == NULL) return;
	if (level == 2) {
		cur->item.print(cout);
		return;  // No need to search downward
	}
	fGS3(cur->left, level + 1);
	fGS3(cur->right, level + 1);
}



void BST::topDownLevelTraversal() {
	BTNode			*cur;
	Queue		    q;


	if (empty()) return; 	// special case
	q.enqueue(root);	// Step 1: enqueue the first node
	while (!q.empty()) { 	// Step 2: do 2 operations inside
		q.dequeue(cur);
		if (cur != NULL) {
			cur->item.print(cout);

			if (cur->left != NULL)
				q.enqueue(cur->left);

			if (cur->right != NULL)
				q.enqueue(cur->right);
		}
	}
}

//insert for BST
bool BST::insert(type newItem) {
	BTNode	*cur = new BTNode(newItem);
	if (!cur) return false;		// special case 1
	if (root == NULL) {
		root = cur;
		count++;
		return true; 			// special case 2
	}
	insert2(root, cur);			// normal
	count++;
	return true;
}


void BST::insert2(BTNode *cur, BTNode *newNode) {
	//if (cur->item > newNode->item) {
	if (cur->item.compare1(newNode->item)){
		if (cur->left == NULL)
			cur->left = newNode;
		else
			insert2(cur->left, newNode);
	}
	else {
		if (cur->right == NULL)
			cur->right = newNode;
		else
			insert2(cur->right, newNode);
	}
}



bool BST::remove(type item) {
	if (root == NULL) return false; 		// special case 1: tree is empty
	return remove2(root, root, item); 		// normal case
}

bool BST::remove2(BTNode *pre, BTNode *cur, type item) {

	// Turn back when the search reaches the end of an external path
	if (cur == NULL) return false;

	// normal case: manage to find the item to be removed
	//if (cur->item == item) {
	if (cur->item.compare2(item)){
		if (cur->left == NULL || cur->right == NULL)
			case2(pre, cur);	// case 2 and case 1: cur has less than 2 sons
		else
			case3(cur);		// case 3, cur has 2 sons
		count--;				// update the counter
		return true;
	}

	// Current node does NOT store the current item -> ask left sub-tree to check
	//if (cur->item > item)
	if (cur->item.compare1(item))
		return remove2(cur, cur->left, item); 

	// Item is not in the left subtree, try the right sub-tree instead
	return remove2(cur, cur->right, item);
}


void BST::case2(BTNode *pre, BTNode *cur) {

	// special case: delete root node
	if (pre == cur) {
		if (cur->left != NULL)	// has left son?
			root = cur->left;
		else
			root = cur->right;

		free(cur);
		return;
	}

	if (pre->right == cur) {		// father is right son of grandfather? 
		if (cur->left == NULL)			// father has no left son?
			pre->right = cur->right;			// connect gfather/gson
		else
			pre->right = cur->left;
	}
	else {						// father is left son of grandfather?
		if (cur->left == NULL)			// father has no left son? 
			pre->left = cur->right;				// connect gfather/gson
		else
			pre->left = cur->left;
	}

	free(cur);					// remove item
}


void BST::case3(BTNode *cur) {
	BTNode		*is, *isFather;

	// get the IS and IS_parent of current node
	is = isFather = cur->right;
	while (is->left != NULL) {
		isFather = is;
		is = is->left;
	}

	// copy IS node into current node
	cur->item = is->item;

	// Point IS_Father (grandfather) to IS_Child (grandson)
	if (is == isFather)
		cur->right = is->right;		// case 1: There is no IS_Father    
	else
		isFather->left = is->right;	// case 2: There is IS_Father

	// remove IS Node
	free(is);
}

int BST::findHeight() {//To find the height of a tree
	BTNode* cur = root;
	if (root == NULL) //If it is an empty tree, return height = 0
		return 0;

	else {
		int level = 1;
		int height = 0;
		findHeight2(cur, height, level); //Traverse the tree and update the value of height
		return height;
	}
}

void BST::findHeight2(BTNode* cur, int& height, int level) {
	if (cur == NULL) //If current node is null, back to the last node
		return;

	if (level > height) //If the level now is bigger than value of height,
		height = level; //height is updated with value of level.

	level++; //Increase level when go to next node.
	findHeight2(cur->left, height, level); //recursive function to update the value of height
	findHeight2(cur->right, height, level);
}

bool BST::deepestNodes() {
	if (root == NULL) //Return false when tree is empty.
		return false;

	else {
		int height = findHeight(); //Use findHeight function to get the height
		int level = 1;
		type2 tmp = root;
		cout << "\nThe deepest node of this BST is: \n\n";
		deepestNodes2(root, height, level); //Traverse the tree
		return true;
	}
}

void BST::deepestNodes2(BTNode* cur, int height, int level) {
	if (cur == NULL) //If current node is NULL, back to last node.
		return;

	if (level == height && cur != NULL) //print the node when the level is same with the height
		cout << cur->item.id << "\t";

	level++;
	deepestNodes2(cur->left, height, level); //Recursive function to traverse the tree.
	deepestNodes2(cur->right, height, level);
}

void BST::inOrderPrintFile() {
	if (root == NULL) return;// handle special case

	else {
		
		ofstream outfile;
		outfile.open("student-info.txt");//To make sure the file is created
		outfile.close(); //Close the file to avoid runtime error
		inOrderPrintF2(root);// do normal process
	}
	cout << endl;

}


void BST::inOrderPrintF2(BTNode* cur) {//in order print but with outfile

	if (cur == NULL) return; //If nothing, back to last node.

	inOrderPrintF2(cur->left);//Traverse to left son
	
	ofstream outfile;
	outfile.open("student-info.txt", ios::app); //Open the file and append student info inside
	cur->item.print(outfile);
	outfile.close();

	inOrderPrintF2(cur->right);//Traverse to right son

}

void BST::DescOrderPrintFile() {
	if (root == NULL) return;// handle special case
	else {
		ofstream outfile;
		outfile.open("student-info.txt");//To make sure the file is created
		outfile.close(); //Close the file to avoid runtime error
		DescOrderPrintF2(root);// do normal process
	}
	cout << endl;
}

void BST::DescOrderPrintF2(BTNode* cur) {//reverse travesal with in order print while using outfile
	if (cur == NULL) return;

	DescOrderPrintF2(cur->right);//Traverse to right son

	ofstream outfile;
	outfile.open("student-info.txt", ios::app);//Open the file and append student info inside
	cur->item.print(outfile);
	outfile.close();

	DescOrderPrintF2(cur->left);//Traverse to left son
}


void BST::DescOrderPrint() {
	if (root == NULL) return;// handle special case
	else DescOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::DescOrderPrint2(BTNode* cur) {//Print node in descending order
	if (cur == NULL) return;
	DescOrderPrint2(cur->right); //Traverse to right son
	cur->item.print(cout);
	DescOrderPrint2(cur->left); //Traverse to left son
}


bool BST::display(int order, int source) {

	if (root == NULL)//check for empty tree
		return false;

	if (order == 1) {//check requirements
		if (source == 1){
			cout << "\nThe ascending order of students: \n\n";
			inOrderPrint();//print on screen ascending
		}
		else {
			cout << "\nThe ascending order of students has been succesfully output to file student-info.txt.\n\n";
			inOrderPrintFile();//print in file ascending
		}
	}
	else
		if (source == 1){
			cout << "\nThe descending order of students: \n\n";
			DescOrderPrint();//print on screen descending
		}
		else{
			cout << "\nThe descending order of students has been succesfully output to file student-info.txt.\n\n";
			DescOrderPrintFile();//print in file descending
		}

	return true;
}


void BST::AutoInsert(BTNode* cur) {//Insert all nodes under the current nodes 
	if (cur == NULL) return;
	insert(cur->item);
	AutoInsert(cur->left);
	AutoInsert(cur->right);
}

bool BST::CloneSubtree(BST t1, type item) {
	BTNode* cur;

	if (t1.empty()) {//Print error message if the tree is empty
		cout << "\nError! The tree is empty.\n\n";
		return false;
	}

	cur = t1.root;

	while (!(cur->item.compare2(item))) {//While the node we want is not found
		
		if (cur->item.compare1(item)) {//traverse to left or right based on the value
			cur = cur->left;
		}
		else
			cur = cur->right;

		if (cur == NULL) {//If the node we want is not found in BST, print error message
			cout << "\nStudent id cannot be found.\n\n";
			return false;
		}
	}

	AutoInsert(cur); //Insert all nodes under the node we want

	cout << "Preorder for Student tree:\n"; 
	t1.preOrderPrint(); //Print original tree
	cout << "\n\n\n" << endl;

	cout << "Preorder for Clone tree of student ID " << item.id << ":\n";
	preOrderPrint(); //Print clone tree
	cout << "\n\n";
	return true;
}

bool BST::BSTsearch(BTNode* cur, type stud) {//To check if the value exist in BST

	if (cur == NULL) {//return false if the value does not exist in BST
		return false;
	}

	if (cur->item.compare3(stud.id)) {//return true if the id exist
		return true;
	}

	else {//traversal
		if (cur->item.id > stud.id)
			BSTsearch(cur->left, stud);
		else
			BSTsearch(cur->right, stud);
	}

}

bool BST::printAncestor(type item) {//Print ancestors of the node
	if (root == NULL) {//Print error message if it is an empty tree.
		cout << "\nError! The tree is empty.\n\n";
		return false;
	}

	if (root->item.id == item.id) {//If the root is the node we want, no ancestor for root can be printed.
		cout << "\nThere is no ancestor for this item!\n\n";
		return true;
	}

	if (!BSTsearch(root, item)) {//If the value does not exist in BST, print error message
		cout << "\nThe student ID " << item.id << " is not found!\n\n";
		return false;
	}

	system("cls");
	cout << "\nAncestors of student ID " << item.id << " are: \n\n";
	printAncestor2(root, item);//run recursive function
	return true;
}


bool BST::printAncestor2(BTNode* cur, type item) {

	if (cur->item.compare2(item)) {//return true if the node we want is found
		return true;
	}

	else {
		cout << cur->item.id << "\t";//continuously print the content of nodes until the value is found
		if (cur->item.compare1(item))//traversal
			printAncestor2(cur->left, item);

		else
			printAncestor2(cur->right, item);
	}
}


bool BST::printSpiral() {//Print nodes in spiral form
	if (root == NULL) return false;
	cout << "\nThe spiral order of nodes in BST: \n\n";
	printSpiral2(); //recursive function
	return true;
}

void BST::printSpiral2() {
	BTNode* cur;
	BTNode* curarray[20];
	Queue		    q;
	int count, count1 = 0, count2 = 1, level = 1;

	if (empty()) return; 	// special case

	q.enqueue(root);	//enqueue the first node
	level++;

	while (!q.empty()) { 	//repeat operations inside until the queue is empty
		q.dequeue(cur);
		cout << cur->item.id << "\t"; //print the information of dequeue node

		if (level%2 == 0) {//If level is even number, print node from left to right

			if (cur->right != NULL) {//insert right son into an array
				curarray[count1] = cur->right;
				count1++;
			}
			if (cur->left != NULL) {//insert left son into an array
				curarray[count1] = cur->left;
				count1++;
			}

			count2--;

			if (count2 == 0) {//check if all the node in the same level is completely dequeue
				level++;

				//Invert and insert the values in array into queue
				for (int i = 1; i <= count1; i++) {
					q.enqueue(curarray[count1 - i]);
				}
			}
		}


		else {//If level is odd number, print nodes from right to left
			if (cur->left != NULL) {//insert left son into an array
				curarray[count2] = cur->left;
				count2++;
			}

			if (cur->right != NULL) {//insert right son into an array
				curarray[count2] = cur->right;
				count2++;
			}

			count1--;

			if (count1 == 0) {//check if all the node in the same level is completely dequeue
				level++;

				//Invert and insert the value in array into queue
				for (int i = 1; i <= count2; i++) {
					q.enqueue(curarray[count2 - i]);
				}
			}
		}
	}
}




