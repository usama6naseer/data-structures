#include <iostream>
//#include "LinkedList.cpp" // Your Own Implementation
#include <cstring>
#include <fstream>
#include "openAddress.h"
#include "math.h"
using namespace std;


int OpenAddress::hash(string str){ // Given a String, return its hash
        int size = str.length();
	int hashsum = 0;
        for (int i=0; i<size; i++) {
                int index = (size-1)-i;
                hashsum = hashsum + (str[i])*pow(a,index);
        }
        return abs(hashsum % tableSize);
}

OpenAddress::OpenAddress(int A) {
	val = 0;
	a = A;
	tableSize = 31;
	collisions = 0;
	hashTable = new string[tableSize];
}

long OpenAddress::getSize() {
	return tableSize;
}
  
void OpenAddress::resize() {
	collisions = 0;
	int v = tableSize;
	tableSize = tableSize*2;
	string* arr = new string[tableSize];
	int count = 0;
	for (int i=0; i<v; i++) {
		if (hashTable[i] != "") {
			count++;
			int hash1 = hash(hashTable[i]);
		        if (arr[hash1] == "") {
	      		        arr[hash1] = hashTable[i];
   	        	} else {
        	        	for (int ii=hash1; ii<hash1+tableSize; ii++) {
                        		int j = i%tableSize;
					//int j=ii;
        	             		//if (ii >= tableSize) {
	        	                //       	j=ii-tableSize;
	                	        //}
        	                	if (arr[j] == "") {
	                	              arr[j] = hashTable[i];
					      collisions++;
        		                      break;
                		        }
      	         		}
   		        }
		}
		if (count == val) {
			break;
		}
	}
	//hashTable = new string[tableSize];
	hashTable = arr;	
}

void OpenAddress::insertItem(string word) {   // Takes a hash of 'Word' and inserts it into hashTable accordingly
	if (val/tableSize >= 0.7) {
		resize();
	}
	int hash1 = hash(word);
	if (hashTable[hash1] == "") {
		hashTable[hash1] = word;
		val++;
	} else {
		for (int i=hash1; i<hash1+tableSize; i++) {
			int j = i%tableSize;
			//int j=i;
                        //if (i >= tableSize) {
                         //       j=i-tableSize;
                        //}
			if (hashTable[j] == "") {
                              hashTable[j] = word;
                              collisions++;
                              val++;
                              break;
                       }
		}
	}
}

string OpenAddress::lookUp(string word) {             // Looks for 'Word' and if found, returns it
	int hash1 = hash(word);
	if (hashTable[hash1] == word) {
		return word;
	} else {
		for (int i=hash1; i<hash1+tableSize; i++) {
			int j = i%tableSize;
			//int j=i;
			//if (i >= tableSize) {
			//	j=i-tableSize;
			//}				
			if (hashTable[j] == word) {
		                return word;
			}
		}
	}
	return "";
}

int OpenAddress::Collisions() { // Return number of collisions in hashTable.
	return collisions;
}
