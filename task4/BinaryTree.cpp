#include "BinaryTree.h"


void BinaryTree::print2DUtil(Node* root, int space)
{
	// Base case
	if (root == nullptr)
	{
		return;
	}

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space count
	cout << endl;
	for (int i = COUNT; i < space; i++)
	{
		cout << " ";
	}
	cout << root->key << "\n";

	// Process left child
	print2DUtil(root->left, space);
}

void BinaryTree::add(int gradeBookNumber, Data* data)
{
	
	if (head == nullptr) {
		head = new Node(gradeBookNumber, data);
		splay(head, gradeBookNumber);
		return;
	}

	Node* current = head;
	bool inserted = false;

	while (!inserted) {
		if (gradeBookNumber < current->key) {
			if (current->left == nullptr) {
				current->left = new Node(gradeBookNumber, data);
				inserted = true;
			}
			else {
				current = current->left;
			}
		}
		else {
			if (current->right == nullptr) {
				current->right = new Node(gradeBookNumber, data);
				inserted = true;
			}
			else {
				current = current->right;
			}
		}
	}
}

Data* BinaryTree::getData(int key)
{
	turnsNumber = 0;
	head = splay(head, key);
	if (head->key == key) {
		return head->data;
	}
	else {
		return nullptr;
	}
}

int BinaryTree::getLastTurnNumbers()
{
	return turnsNumber;
}

void BinaryTree::print2D()
{
	// Pass initial space count as 0
	print2DUtil(head, 0);
}

void BinaryTree::inOrder()
{
	inOrderUtil(head);
}

void BinaryTree::inOrderUtil(Node* root)
{
	if (root == nullptr) {
		return;
	}
	cout << root->key << " " << root->data->groupNumber << " " << root->data->fullName << endl;
	
	inOrderUtil(root->left);
	inOrderUtil(root->right);
}

BinaryTree::Node* BinaryTree::minValueNode(Node* node)
{
	Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL) {
		current = current->left;
	}

	return current;
}

Data* BinaryTree::deleteNode(int key)
{
	return deleteNodeUtil(head, key)->data;
}


BinaryTree::Node* BinaryTree::deleteNodeUtil(Node* root, int key)
{
	if (root == nullptr) {
		return root;
	}
	if (key < root->key) {
		root->left = deleteNodeUtil(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNodeUtil(root->right, key);
	}
	else {
		// node has no child
		if (root->left == nullptr and root->right == nullptr) {
			return nullptr;
		}
		// node with only one child or no child
		else if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		Node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNodeUtil(root->right, temp->key);

	}

	return root;
}


// ��������� ������� ��� ��������� ��������� � ������ y ������.
BinaryTree::Node* BinaryTree::rightRotate(Node* x)
{
	Node* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

// ��������� ������� ��� ��������� ��������� � ������ x �����
BinaryTree::Node* BinaryTree::leftRotate(Node* x)
{
	Node* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

BinaryTree::Node* BinaryTree::splay(Node* root, int key)
{
	// ������� ������: root ����� NULL ���
	// ���� ��������� � ����� 
	if (root == nullptr || root->key == key)
		return root;

	// ���� ����� � ����� ���������
	if (root->key > key)
	{
		// ����� ��� � ������, �� ���������
		if (root->left == nullptr) return root;

		// Zig-Zig (�����-�����) 
		if (root->left->key > key)
		{
			// ������� ���������� �������� ���� ��� ������ left-left
			root->left->left = splay(root->left->left, key);

			// ������ �������� ��� root, ������ �������� ����������� ����� else
			turnsNumber++;
			root = rightRotate(root);
		}
		else if (root->left->key < key) // Zig-Zag (�����-������) 
		{
			// ������� ���������� ��������� ���� ��� ������ left-right
			root->left->right = splay(root->left->right, key);

			// ��������� ������ �������� ��� root->left
			if (root->left->right != nullptr) {
				turnsNumber++;
				root->left = leftRotate(root->left);
			}

		}

		// ��������� ������ �������� ��� �����
		turnsNumber++;
		return (root->left == nullptr) ? root : rightRotate(root);
	}
	else // ���� ��������� � ������ ���������
	{
		// ����� ��� � ������, �� ���������
		if (root->right == nullptr) return root;

		// Zag-Zig (������-�����) 
		if (root->right->key > key)
		{
			// ������� ���� ��� ������ right-left 
			root->right->left = splay(root->right->left, key);

			// ��������� ������ ������� ��� root->right
			if (root->right->left != nullptr) {
				turnsNumber++;
				root->right = rightRotate(root->right);
			}
		}
		else if (root->right->key < key)// Zag-Zag (������-������) 
		{
			// ��������� ���� ��� ������ right-right � ��������� ������ ��������
			root->right->right = splay(root->right->right, key);
			turnsNumber++;
			root = leftRotate(root);		}

		// ��������� ������ �������� ��� root
		turnsNumber++;
		return (root->right == nullptr) ? root : leftRotate(root);
	}
}
