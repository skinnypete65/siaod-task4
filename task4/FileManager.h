#pragma once
#include <fstream>
#include "BinaryTree.h"
#include "Data.h"
#include <string>

using namespace std;
class FileManager
{
private:
	ifstream in;
	ofstream out;
public:
	void createFile(string name);
	BinaryTree* getBinaryTree(string name);
};

