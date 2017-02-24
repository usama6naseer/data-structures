#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.cpp"
#include <fstream>
			
int main() {
//std::vector<std::string> str;
//str.push_back("ab");
//str.push_back("cd");
//std::cout << str[0] <<"  "<<str[1] << std::endl;
//std::vector<std::string> str1(str);
//std::cout << str1[0] <<"  "<<str1[1] << std::endl;
//LinkedList<int>* li = new LinkedList<int>[5];
cout << 1;
        vector<string> v1;
        vector<string> v2;
        ifstream f("dict.txt");
cout << 1;
        std::string str;
        if (f.is_open()) {
                while (getline(f, str)) {
                        v1.push_back(str);
                }
        }
cout << 1;
        ifstream f1("queries.txt");
        std::string str1;
        if (f1.is_open()) {
                while (getline(f1, str1)) {
                        v2.push_back(str1);
                }
        }



return 0;
}
