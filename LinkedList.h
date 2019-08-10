#pragma once
#include <iostream>

using namespace std;

class NodeElement {
public:
	NodeElement() : next(nullptr), data(0) {}

	~NodeElement() {
		cout << "NodeElement Destroyed!\n";
	}

	int getData() {
		return data;
	}

	void setNext(NodeElement* next) {
		this->next = next;
	}

	void setData(int data) {
		this->data = data;
	}

	NodeElement* getNext() {
		return next;
	}

private:
	int data;
	NodeElement* next;
};

void traverseNodes(NodeElement* head) {
	NodeElement* curr = head;

	cout << "Head of list is: ";
	cout << head;
	cout << "\n";

	while (curr) {
		cout << "Node: ";
		cout << curr;
		cout << " Data: ";
		cout << (*curr).getData();
		cout << " Next element is: ";
		cout << (*curr).getNext();
		cout << "\n";

		curr = (*curr).getNext();
	}
}

int findValue(NodeElement* head, int value) {
	NodeElement* curr = head;
	int i = 0;

	while (curr) {
		if (curr->getData() == value) {
			return i;
		}
		curr = curr->getNext();
		i++;
	}
	return -1;
}

bool insertElement(NodeElement** head, NodeElement* elem, int index) {
	NodeElement* curr = *head;
	NodeElement* prev = nullptr;
	int i = 0;

	if (index == 0) {
		elem->setNext(*head);
		*head = elem;
		return true;
	}

	while (curr) {
		if (i == index) {
			prev->setNext(elem);
			elem->setNext(curr);
			return true;
		}
		prev = curr;
		curr = (*curr).getNext();
		i++;
	}
	return false;
}

bool deleteElement(NodeElement** head, int index) {
	NodeElement* curr = *head;
	NodeElement* prev = nullptr;
	int i = 0;

	if (index == 0) {
		prev = *head;
		*head = curr->getNext();
		delete(prev);
		return true;
	}

	while (curr) {
		if (i == index) {
			prev->setNext(curr->getNext());
			delete(curr);
			return true;
		}
		prev = curr;
		curr = (*curr).getNext();
		i++;
	}
	return false;
}

NodeElement* createList(int length) {
	NodeElement* head = nullptr;
	NodeElement* prev = nullptr;

	for (int i = 0; i <= length; i++) {
		NodeElement* elem = new NodeElement;

		if (i == 0) {
			head = elem;
			prev = elem;
			(*elem).setData(i);
		}
		else {
			(*elem).setData(i);
			(*prev).setNext(elem);
			prev = elem;
		}
	}
	return head;
}
