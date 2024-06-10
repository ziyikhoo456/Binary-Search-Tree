#ifndef BT_type
#define BT_type

#include	"BTNode.h"
#include	"Queue.h"


struct BST {

		int		count;
		BTNode	*root;

		// print operation for BST (same as BT)					
		void preOrderPrint2(BTNode *);	// recursive function for preOrderPrint()
		void inOrderPrint2(BTNode *);	// recursive function for inOrderPrint()
		void postOrderPrint2(BTNode *);	// recursive function for postOrderPrint()

		// sample operation (extra functions) - same as BT
		void countNode2(BTNode *, int &);		// recursive function for countNode()
		bool fGS2(type, BTNode *);					// recursive function for findGrandsons(): to find the grandfather
		void fGS3(BTNode *, int);				// recursive function for findGrandsons(): to find the grandsons after the grandfather has been found
		
		// basic functions for BST
		void insert2(BTNode *, BTNode *);		// recursive function for insert() of BST
		void case3(BTNode *);					// recursive function for remove()
		void case2(BTNode *, BTNode *);		// recursive function for remove()
		bool remove2(BTNode *, BTNode *, type);	// recursive function for remove()

		// basic functions for BST
		BST();
		bool empty();
		int size();
		bool insert (type);		// insert an item into a BST
		bool remove(type);			// remove an item from a BST
		
		// print operation for BST (same as BT)
		void preOrderPrint();			// print BST node in pre-order manner
		void inOrderPrint();			// print BST node in in-order manner
		void postOrderPrint();			// print BST node in post-order manner
		void topDownLevelTraversal();	// print BST level-by-level

		// sample operation (extra functions) - same as BT
		int countNode();		// count number of tree nodes
		bool findGrandsons(type);	// find the grandsons of an input father item



		//Print Deepest Nodes
		int findHeight(); //Find the total height of the tree
		void findHeight2(BTNode*, int&, int); //Recursive function for findHeight()
		bool deepestNodes(); //Print deepest Nodes in tree
		void deepestNodes2(BTNode*, int, int);//Recursive function for deepestNode

		//Display student
		void inOrderPrintFile();//Print BST node in ascending order in file
		void inOrderPrintF2(BTNode*); //Recursive function for inOrderPrintFile()
		void DescOrderPrintFile();//Print BST node in descending order in file
		void DescOrderPrintF2(BTNode*);//Recursive function for DescOrderPrintFile()
		void DescOrderPrint();//Print BST node in descending order on screen
		void DescOrderPrint2(BTNode*); //Recursive function for DescOrderPrint()
		bool display(int, int); //Print the content of every node in BST

		//Clone subtree
		void AutoInsert(BTNode*); //Insert the content of node into subCloneTree
		bool CloneSubtree(BST, type); //Clone a subtree

		//Print ancestor
		bool BSTsearch(BTNode*, type); //To check if the item exists in BST nodes
		bool printAncestor(type); //Print the ancestor of the node
		bool printAncestor2(BTNode*, type);//Recursive function of printAncestor()

		//Print spiral
		bool printSpiral(); //Print nodes in spiral form
		void printSpiral2(); //Recursive function of printSpiral()
};




#endif