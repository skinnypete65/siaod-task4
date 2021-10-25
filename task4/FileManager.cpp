#include "FileManager.h"


void FileManager::createFile(string name)
{
	out.open(name+".txt");
	out.close();
}

BinaryTree* FileManager::getBinaryTree(string name)
{
	in.open(name+".txt");
	if (!in.is_open()) {
		return nullptr;
	}

	BinaryTree* tree = new BinaryTree();

	while (!in.eof()) {
		string line;
		getline(in, line);
		
		int dataStartsIndex = line.find(' ');
		int key = stoi(line.substr(0, dataStartsIndex));
		string groupNumber = line.substr(dataStartsIndex + 1, line.find(',') - dataStartsIndex-1);
		string fullName = line.substr(line.find(',') + 1);

		Data* data = new Data(groupNumber, fullName);

		tree->add(key, data);
		
	}

	return tree;
}