#ifndef __TREE_H
#define __TREE_H
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

struct TreeItem
{
	string value;
	TreeItem *Parent; // parent node
	TreeItem *FChild; // pointer to first child node
	TreeItem *NextS; // pointer to next sibling node
	
	/*You can add additional variables if necessary*/

	TreeItem(string Val)
	{
		this->value = Val;
		this->Parent = NULL;
		this->FChild = NULL;
		this->NextS = NULL;
	}
};

class Tree
{
	TreeItem *head;
public:
	int visit;
	// Constructor
	Tree();
	Tree(string file); // constructor to load directory paths from the given file name
	void ctor(TreeItem* &t, string &str);
	void findLoc(TreeItem* t, std::string s, TreeItem* &p);

	// Destructor
	~Tree();
	
	void insert(string item); // takes the complete path of the file as an input and inserts it into the tree

	vector<string> Locate(string qry); // takes the file name as input and returns its path in the vector, returns empty vector if file not found
	// Lowest Common Ancestor
	string LComAc(string qry1, string qry2); // takes two filenames as an input and returns the name of lowest common ancestor, returns empty string if none exists

	TreeItem *getHead(); // returns the root of the tree

	/*You can add additional functions if necessary*/
};
#endif
