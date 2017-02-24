#include <string.h>
#include "LinkedList.cpp"

class OpenAddress
{
	private:
		long tableSize;
		string *hashTable;				// Include your linked list class for this!
		int a;							// input to the hash function
		int collisions;
		int val; // stores number of elements in array
	public:
		OpenAddress(int A);
		long getSize();
		void resize();
		void insertItem(string Word);	// Takes a hash of 'Word' and inserts it into hashTable accordingly
		string lookUp(string Word);		// Looks for 'Word' and if found, returns it
		int Collisions(); // Return number of collisions in hashTable.
		int hash(string s);	
		int hashcode(string word);

};
