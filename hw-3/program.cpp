#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "HashC.cpp"
#include "time.h"
#include "openAddress.cpp"
using namespace std;

int main(){
//	cout << 1;
        vector<string> v1;
        vector<string> v2;
        ifstream f("dict.txt");
        string str;
        if (f.is_open()) {
                while (getline(f, str)) {
                        v1.push_back(str);
                }
        }
        ifstream f1("queries.txt");
        string str1;
        if (f1.is_open()) {
                while (getline(f1, str1)) {
                        v2.push_back(str1);
                }
        }

	 //____________________________________Chaining_____________________________________
	int t1 = 0;
        for (int i=1; i<=50; i++) {
                HashC c(i);
                c.Load("dict.txt");
	       	startTimer();

	    	for (int j=0; j<v2.size(); j++) {
                        c.lookup(v2[j]);
                }
		stopTimer();
		t1 = t1 + c.Collisions();
                std::cout << c.Collisions() << std::endl;
        }
	t1 = t1/50;
	//______________________________________OA_______________________________________
	int t2 = 0;
	for (int i=1; i<=50; i++) {
		OpenAddress Dictionary(i);
        	for(int i1 = 0 ; i1 < v1.size() ; i1++){
        	        Dictionary.insertItem(v1[i1]);
		}
		startTimer();
		for (int j=0; j<v2.size(); j++) {
	                string result = Dictionary.lookUp(v2[j]);
		}
		stopTimer();
		t2 = t2 + Dictionary.Collisions();
		cout << Dictionary.Collisions() << endl;
        }
	t2 = t2/50;
	return 0;
}
