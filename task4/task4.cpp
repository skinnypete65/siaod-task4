#include <iostream>
#include <Windows.h>
#include "FileManager.h"
#include "Data.h"
#include "BinaryTree.h"

using namespace std;
void generateBinaryTree(BinaryTree* tree);

int main() {
	setlocale(LC_ALL, "rus");
	FileManager manager;

	BinaryTree* tree = manager.getBinaryTree("students");

	tree->print2D();
	cout << "\n\n";

	tree->inOrder();

	string decision = "0";
	int key;
	
	
	while (decision != "4")
	{
		cout << "choose:\n" << "1 - search\n" << "2 - delete\n" << "3 - print tree\n" << "4 - close\n";
		cin >> decision;
		if (decision == "1") {
			cout << "key to search: ";
			cin >> key;
			Data* d = tree->getData(key);
			if (d != nullptr) {
				cout << d->groupNumber << " " << d->fullName << endl;
				cout << "Число поворотов: " << tree->getLastTurnNumbers() << endl;
			}
			else {
				cout << "Нет такого ключа" << endl;
			}
		}
		else if (decision == "2") {
			cout << "key to delete: ";
			cin >> key;
			Data* d = tree->deleteNode(key);
			if (d != nullptr) {
				cout << "Удаленный ключ: " << key << " информационная часть: " << d->groupNumber << " " << d->fullName << endl;
			}
			else {
				cout << "Нет такого ключа" << endl;
			}
		}
		else if (decision == "3") {
			tree->print2D();
		}
		else if (decision == "4") {
			break;
		}
		else {
			cout << "Неправильная команда" << endl;

		}
	}


}

// если не удается считать данные с файлы, то можно сгенерировать дерево с помощью этой функции
void generateBinaryTree(BinaryTree *tree) {
	tree->add(4, new Data("inbo-04", "Nikita Leontev"));
	tree->add(1, new Data("inbo-01", "Svishev Andrey"));
	tree->add(6, new Data("inbo-05", "Namoev Atrem"));
	tree->add(2, new Data("inbo-04", "Kireeva Ksenia"));
	tree->add(10, new Data("inbo-02", "Komarov Sanya"));
	tree->add(7, new Data("inbo-04", "Khametov Aleskey"));
}
