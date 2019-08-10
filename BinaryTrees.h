#pragma once
#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h>

using namespace std;

class BinaryTreeNode {
private:
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	int value;

public:
	BinaryTreeNode() : left(nullptr), right(nullptr), value(0) {}

	~BinaryTreeNode() {
		cout << "NodeElement Destroyed!\n";
	}

	void setLeft(BinaryTreeNode* l) {
		left = l;
	}

	void setRight(BinaryTreeNode* r) {
		right = r;
	}

	BinaryTreeNode* getLeft() {
		return left;
	}

	BinaryTreeNode* getRight() {
		return right;
	}

	void setValue(int v) {
		value = v;
	}

	int getValue() {
		return value;
	}
};

BinaryTreeNode* createBinarySearchTree(int length, int range) {
	// Creates a symmetrical BST
	srand(time(NULL));
	BinaryTreeNode* head = new BinaryTreeNode();
	BinaryTreeNode* prevLeft = nullptr;
	BinaryTreeNode* prevRight = nullptr;

	for (int i = 0; i <= length; i++) {
		if (i == 0) {
			prevLeft = head;
			prevRight = head;
			int val = rand() % (range + 1);
			(*head).setValue(val);
		}
		else {
			BinaryTreeNode* left = new BinaryTreeNode();
			prevLeft->setLeft(left);

			int leftVal = rand() % (range + 1) + prevLeft->getValue();

			do {
				leftVal = rand() % range + prevLeft->getValue();
			} while (leftVal >= prevLeft->getValue());

			BinaryTreeNode* right = new BinaryTreeNode();
			prevRight->setRight(right);

			int rightVal = rand() % (range + 1) + prevRight->getValue();

			do {
				rightVal = rand() % range + prevRight->getValue();
			} while (rightVal <= prevRight->getValue());
		}
	}
	return head;
}

BinaryTreeNode* lookupValue(BinaryTreeNode* head, int value) {
	BinaryTreeNode* curr = head;

	while (curr) {
		if (curr->getValue() == value) {
			return curr;
		} 
		else if (curr->getValue() > value) {
			curr = curr->getRight();
		}
		else if (curr->getValue() < value) {
			curr = curr->getLeft();
		}
		else {
			// something weird happened
			return nullptr;
		}
	}
	return curr;
}

BinaryTreeNode* lookupValueRecursively(BinaryTreeNode* node, int value) {
	if (!node) {
		return nullptr;
	}

	if (node->getValue() == value) {
		return node;
	}
	else if (node->getValue() > value) {
		return lookupValueRecursively(node->getRight(), value);
	}
	else if (node->getValue() < value) {
		return lookupValueRecursively(node->getLeft(), value);
	}
	else {
		return nullptr;
	}
}
