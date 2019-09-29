// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include "BinaryTrees.h"
#include "STL_demo.h"

using namespace std;

void LinkedListDemo() {
	const int length = 5;
	NodeElement* head = createList(length);

	traverseNodes(head);

	cout << findValue(head, 5);
	cout << "\n";
	cout << findValue(head, 6);
	cout << "\n";

	NodeElement** headptr = &head;

	NodeElement* newElem = new NodeElement();
	newElem->setData(length + 1);
	cout << insertElement(headptr, newElem, 0);
	cout << "\n";

	NodeElement* newElem2 = new NodeElement();
	newElem2->setData(length + 2);
	cout << insertElement(headptr, newElem2, 3);
	cout << "\n";

	traverseNodes(head);

	cout << deleteElement(headptr, 0);
	cout << "\n";

	cout << deleteElement(headptr, 3);
	cout << "\n";

	traverseNodes(head);
}

int main()
{
	// Linked Lists
	//LinkedListDemo();

	// C++ STL 
	vectorDemo();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
