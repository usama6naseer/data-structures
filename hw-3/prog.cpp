#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "openAddress.cpp"
#include "HashC.cpp"
#include "time.h"

int main(){
	std::cout << 1;
	std::vector<std::string> v1;
	std::vector<std::string> v2;
	ifstream f("dict.txt");
        std::string str;
        if (f.is_open()) {
                while (getline(f, str)) {
                        v1.push_back(str);
                }
        }
	ifstream f1("queries.txt");
        std::string str1;
        if (f1.is_open()) {
                while (getline(f1, str1)) {
                        v2.push_back(str1);
                }
        }
	//____________________________________Chaining_____________________________________
	int colC = 0;
	int timeC = 0;
	for (int i=1; i<=50; i++) {
		HashC c(i);
        	c.Load("dict.txt");
		//startTimer();

		for (int j=0; j<v2.size(); j++) {
			startTimer();
			c.lookup(v2[j]);
			stopTimer();
		}
		std::cout << c.Collisions() << std::endl;
		//colC = colC + c.collisions();
		//timeC = timeC + stopTimer();
	}
	//colC = colC/50;
	//timeC = timeC/50;		




	return 0;
}
