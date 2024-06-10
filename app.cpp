#define _CRT_SECURE_NO_WARNINGS
#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"
#include	<string>

using namespace std;

bool readFile(char *, BST *);
int menu();

int main() {
	BST StudentTree;
	char* filePtr;
	int choice;

	while (true) {//Loop the main forever
		system("cls");
		choice = menu();//Display menu and input choice
		system("cls");

		//Read data to BST
		if (choice == 1) {
			char filename[12] = "student.txt";
			filePtr = filename;

			if (readFile(filePtr, &StudentTree)) //If the file can be read
				cout << "\n" << StudentTree.count << " student records in the file " << filePtr << " has been successfully read.\n\n";
			else
				cout << "\nThe file " << filePtr << " does not exist ToT.\n\n";

			system("pause");
		}

		//Print deepest node
		else if (choice == 2) {
			if (!StudentTree.deepestNodes()) //If the function return false, print error
				cout << "\nError! The tree is an empty tree :(\n\n";

			cout << "\n\n";
			system("pause");
		}

		//Display student
		else if (choice == 3) {
			int order, source, num;

			//Select display order
			cout << "Please select order\n1-Ascending\n2-Decending\n\n";
			cout << "Order: ";
			cin >> order;
			cout << "\n\n";

			//Select display source
			cout << "Please select source\n1-Screen\n2-File\n\n";
			cout << "Source: ";
			cin >> source;
			cout << "\n\n";

			system("cls");

			if(!StudentTree.display(order, source)) //If the function return false, print error message
				cout << "\nError! The tree is an empty tree :(\n\n";

			system("pause");
		}

		//Clone subtree
		else if (choice == 4) {
			type student;
			BST CloneTree;

			cout << "\nPlease enter a student id:"; //Ask for student id input
			cin >> student.id;
			cout << endl;
			system("cls");

			//Create a clonetree of that student id as root
			CloneTree.CloneSubtree(StudentTree, student);
				

			system("pause");
		}

		//Print ancestor
		else if (choice == 5) {
			type student;

			cout << "\nPlease enter a student id: "; //Ask for student id input
			cin >> student.id;

			//Print the ancestors of that student
			StudentTree.printAncestor(student);

			cout << "\n\n";
			system("pause");
		}

		//Print spiral
		else if (choice == 6) {

			if (!StudentTree.printSpiral()) { //Print error message if the function returns false
				cout << "\nError! The tree is empty.\n\n";
			}

			cout << "\n\n";
			system("pause");
		}

		//Exit
		else if (choice == 7) {
			return 0;
		}
	}

	system("pause");
	return 0;
}


bool readFile(char *filename, BST *t1) {
	ifstream infile;
	infile.open(filename); //Open the file

	if (infile.fail()) //Return false if unable to open the file
		return false;

	else {
		while (!infile.eof()) {//While it is not at last line of file
			char blank;
			Student student;

			//Ignore 10 characters then get id
			for (int i = 0; i < 10; i++)
				infile >> blank;
			infile >> student.id;

			//Ignore 5 characters then get name
			for (int i = 0; i < 5; i++)
				infile >> blank;
			infile.ignore();
			infile.get(student.name, 30);

			//Ignore 8 characters then get address
			for (int i = 0; i < 8; i++)
				infile >> blank;
			infile.ignore();
			infile.get(student.address, 100);

			//Ignore 4 character then get DOB
			for (int i = 0; i < 4; i++)
				infile >> blank;
			infile.ignore();
			infile.get(student.DOB, 20);

			//Ignore 12 characters then get phone_no
			for (int i = 0; i < 12; i++)
				infile >> blank;
			infile.ignore();
			infile.get(student.phone_no, 10);

			//Ignore 7 characters then get course
			for (int i = 0; i < 7; i++)
				infile >> blank;
			infile.ignore();
			infile.get(student.course, 5);

			//Ignore 5 characters then get cgpa
			for (int i = 0; i < 5; i++)
				infile >> blank;
			infile >> student.cgpa;
		
			//Insert the node into tree
			t1->insert(student);
		}
		return true;
	}
}


int menu() {
	int choice;

	cout << "Menu:\n\n" //Print the menu options
		<< "(1)Read data to BST\n"
		<< "(2)Print deepest nodes\n"
		<< "(3)Display student\n"
		<< "(4)Clone Subtree\n"
		<< "(5)Print Ancestor\n"
		<< "(6)Print Spiral\n"
		<< "(7)Exit\n\n";

	cout << "Enter your choice: ";
	cin >> choice; //Get choice and return it
	return choice;
}