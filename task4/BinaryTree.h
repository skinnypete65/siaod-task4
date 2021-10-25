#pragma once
#include "Data.h";
#include <iostream>

using namespace std;

class BinaryTree
{
private:
	const int COUNT = 5;

	class Node {
	public:
		int key;
		Data* data;

		Node* left;
		Node* right;

		Node(int key, Data* data) {
			this->key = key;
			this->data = data;
		}

	};

	Node* head;
	int turnsNumber; //Calculate turns in splay method

	void print2DUtil(Node* root, int space);
	void inOrderUtil(Node* root);

	Node* deleteNodeUtil(Node* root, int key);
	Node* minValueNode(Node* node);

	Node* rightRotate(Node* x);
	Node* leftRotate(Node* x);
	Node* splay(Node* root, int key);
public:
	void print2D();

	void add(int gradeBookNumber, Data* data);
	Data* getData(int key);
	void inOrder();
	Data* deleteNode(int key);
	int getLastTurnNumbers();
};

