# Binary Search Tree

***Credit to: Khoo Zi Yi(Me), Ng Yi Hong***

Use the given source codes in this assignment and add the following functions below:

1. **bool readFile(char \*filename, BST \*t1)**
   
Reads student records from a text file and stores them according to the student id in a binary search tree (BST). The function prints to screen the number of student records successfully read. The function return false if file not successfully open and true otherwise. Refer to sample input text file student.txt given. An example of a student record BST is shown in Figure 3.1. Its data in the text file format, student.txt is included in the sample textfile folder. In the tree, each node stores a student record. The key for the BST is the id of each student.
<br><br>

2. **bool BST::deepestNodes()**
   
Finds and prints all the nodes at the deepest level.  For example, the deepest nodes of tree1 in Figure 3.2 are 2, 7 and 12 while tree2 has only 21. (Hint: You can either use height of tree to look for deepest). Function will return false for empty tree and true otherwise. 
<br><br>

3. **bool BST::display(int order, int source)**
   
Traverses a BST tree recursively and print the content of every node. The order variable is to specify if user want to print in ascending or descending order according to id. Use order = 1 for ascending and order = 2 for descending. The source variable is used to specify where to print the output. Use source = 1 to print to screen and source = 2 to print to a file name “student-info.txt”. (Hint: To print in ascending visit left son and then right son. As to print in descending visit right son and then left son.) Function will return false for empty tree and true otherwise. 
<br><br>

4. **bool BST::CloneSubtree(BST t1, type item)**
   
Clone a subtree in t1 where the root of the subtree contain value item. For example, if t2.CloneSubtree(t1, 126); is called, then the subtree in t1 (t1 is tree in Figure 3.1 and t2 is cloned subtree in Figure 3.1 (a))  where the root contain node 126 will be cloned and store in t2 as shown in Figure 3.1 (a) below. t1 will not change after function call and t2 must be an empty tree before cloning. Display t1 and t2 using preOrderPrint() after function call.  Function will return false if t1 is empty and true otherwise.
<br><br>

5. **bool BST::printAncestor(type item)**

Print all the ancestors for item. Table below shows the ancestor for each node in tree2 in Figure 3.2 below. Function return false for empty tree or item cannot be found in the tree. Print message “There is no ancestor for this item.” if item is the root item.
<br><br>

6. **bool BST::printSpiral()**

Print all the nodes in a BST in spiral order. For example, the spiral order of nodes for the BST in Figure3 .1 below is 123   65   126   234   125   78. Function return false for empty tree and true otherwise. 
