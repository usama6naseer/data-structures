#include <iostream>
#include "bst.h"
#include "bst.cpp"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include "time.h"

using namespace std;

string strSplit(string& s);
string strSplit(string& s) {
        string s1;
        int count = 1;
        for (int i=0;i<s.size();i++) {
                char a = s[i];
                char b = '~';
                if(a==b) {
                        break;
                } else {
                        count++;
                        s1.push_back(s[i]);
                }
        }
        s.erase(0,count);
        return s1;
}


int main() {
	cout << "Please enter a file name:" << endl;
	string s;
	cin >> s;
	
	ifstream file(s.c_str());
        string str;
	bst<int>* t = new bst<int>();
        int count = 0;
	startTimer();
        if (file.is_open()) {
	        while(getline(file, str)) {
			string str1; 
			str1 = strSplit(str);
			//cout << str1 << ' ' << endl;
			int a;
			a = atoi(str.c_str());
			//cout << a <<endl;
			t->insert(str1,a );
			count++;			
		}
	}
	cout << "File loaded successfully. " << count << " key/value pairs loaded from the file in ";
	stopTimer();
	cout << endl;

cout <<  "Press 1 to Insert another key/value Pair" << endl <<
"Press 2 to search for a value using its key" << endl <<
"Press 3 to delete a key/value pair" << endl <<
"Press 4 to update the key of an existing value" << endl <<
"Press 5 to see the current height of the Tree" << endl;
	int c;
	cin >> c;
	//startTimer();
	if (c==1){
		cout << "Please enter a string value to insert:" << endl;
                string s1;
		cin >> s1;
		cout << "Please enter a key to insert:" << endl;
		int d;
                cin >> d;
		startTimer();
		t->insert(s, d);
                cout << "Node inserted in: ";
                stopTimer();

	}	
	else if (c==2){
		cout << "Please enter a key to search:" <<endl;
        	int d;
                cin >> d;
		startTimer();
                bst_node<int>* tt = t->search(d);
                cout << "Node searched in: ";
                stopTimer();
		cout << "Value corresponding to key is:" << endl;
		cout << tt->value<<endl;;
	}
	else if (c==3){
		cout << "Please enter a key to delete:" << endl;
		int d;
		cin >> d;
		startTimer();
        	t->delete_node(d);
		cout << "Node deleted in: ";
		stopTimer();
	}
	else if (c==4){
		cout << "Please enter the new key:" << endl;
		int d;
                cin >> d;
		cout << "Please enter the old key to be replaced:" << endl;
		int d1;
                cin >> d1;
		startTimer();
		t->replace(d1, d);
		cout << "Key replaced in: ";
		stopTimer();
        }
	else if (c==5){	
		startTimer();
		int d = t->height(t->getroot());
                cout << "Height of tree is: " << d << endl;
                cout << "Height found in: ";
                stopTimer();
        }


}
