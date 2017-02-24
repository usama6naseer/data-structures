#include <iostream>
#include "Chaining.h"
#include "LinkedList.cpp" // Your Own Implementation
#include <cstring>
#include <fstream>
#include "math.h"

using namespace std;

HashC::HashC(int _a) {
	a = _a;
	collisions = 0;
	tableSize = 159;
	hashTable = new LinkedList<string>[159];
}
void HashC::Load(char* file){ // Load a file of Strings into your Hash table
        ifstream f(file);
        std::string str;
        if (f.is_open()) {
                while (getline(f, str)) {
                        //std::cout << str << std::endl;
			insert(str);
                }
        }
}
	

int HashC::hashcode(string str) {
	int size = str.length();
        int hashsum = 0;
        for (int i=0; i<size; i++) {
                int index = (size-1)-i;
                hashsum = hashsum + (str[i]*pow(a,index));
        }
        return hashsum;
}
int HashC::compress(int k) {
	int a1 = k % tableSize;
	return a1;	
}
int HashC::hash(string str){ // Given a String, return its hash
	int hc = hashcode(str);
	int hash1 = compress(hc);
	return abs(hash1);
}
void HashC::insert(string word){ // Takes a hash of 'word' and inserts it into hashTable accordingly
	int hash1 = hash(word);
	if (hashTable[hash1].getHead() != NULL) {
		collisions++;
	}
	hashTable[hash1].insertAtTail(word);
}
ListItem<string>* HashC::lookup(string s){
	int hash1 = hash(s);
	return hashTable[hash1].searchFor(s);	
}
int HashC::Collisions(){ // Return number of collisions in hashTable
	return collisions;
}

