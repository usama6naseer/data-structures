#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>
#include <string>
using namespace std;

string strSplit(string& s);
string strSplit(string& s) {
        string s1;
        int count = 1;
        for (int i=0;i<s.size();i++) {
                char a = s[i];
                char b = '/';
                char c = '\\';
		if(a==b || a==c) {
                        break;
                } else {
                        count++;
                        s1.push_back(s[i]);
                }
        }
        s.erase(0,count);
        return s1;
}
void Tree::ctor(TreeItem* &t, string &str) {
if (str.size() != 0) {
	string str1;
	int check = 0;
	str1 = strSplit(str);
	if (head==NULL) {
		TreeItem* tp = new TreeItem(str1);
		//tp->value = str1;
		head = tp;
		ctor(head,str);
	}
	else if (str1 == t->value) {
		check = 1;
		ctor(t, str);
	} else {
		if (t->FChild!=NULL && t->FChild->value == str1) {
			check = 1;
			ctor(t->FChild, str);
		}
		else if (t->FChild!=NULL && t->FChild->NextS != NULL) {
			TreeItem* i;
			for (i=t->FChild;i!=NULL;i=i->NextS) {
				if (i->value == str1) {
					check = 1;
					break;			
				}
			}
			if (check == 1) {				
				ctor(i,str);
			}
		}
		if (check == 0) {
			TreeItem* t1 = new TreeItem(str1);
			t1->Parent = t;
			if (t->FChild == NULL) {
				t->FChild = t1;
				ctor(t1, str);
			} else {
				//cout << str1 << endl;
        	                for (TreeItem* i=t->FChild;i!=NULL;i=i->NextS) {
                	                if (i->NextS == NULL) {
						i->NextS = t1;
						ctor(t1,str);
						break;
                	                }
          	                }
			}
		}
	}
}
}
Tree::Tree()
{
	head = NULL;
	visit = 0;
}

Tree::Tree(string file1) {
	ifstream file(file1.c_str());
	string str1;
	int count = 0;
	if (file.is_open()) {
	while(getline(file, str1)) {
		//file >> str1;
//cout << str1 << endl;
		if (count==0) {
			string s;
			s = strSplit(str1);
			TreeItem* u = new TreeItem(s);
			head = u;
		}
		ctor(head, str1);
		count++;
	}		
	}
}
Tree::~Tree()
{
}

void Tree::insert(string item)
{
}

void Tree::findLoc(TreeItem* t, string qry, TreeItem* &p) {
if (t!=NULL) {
	if (t->value == qry) {
		p = t;
                return;
        }
	else if (t->FChild!=NULL || t->NextS!=NULL) {
		if (t->FChild!=NULL) {
			findLoc(t->FChild,qry,p);
		}
		if (t->NextS!=NULL) {
                        findLoc(t->NextS,qry,p);
                }
		return;
	}
}
}

vector<string> Tree::Locate(string qry) {
if (head!=NULL) {
//cout << qry<< endl;
	vector<string> vec;
	TreeItem* t = head;
	TreeItem* p = NULL;
	findLoc(t, qry, p);
	if (p == NULL){
//cout << 1 << endl;
		return vec;
	}
//cout << p->value << endl;
	for (TreeItem* i=p;i!=NULL;i=i->Parent) {
		vec.push_back(i->value);
	}
	return vec;
}
}

string Tree::LComAc(string a, string b)
{
	vector<string> vec1;
	vector<string> vec2;
	vec1 = Locate(a);
	vec2 = Locate(b);
	for (int i=0; i<vec1.size(); i++) {
		for (int j=0; j<vec2.size(); j++) {
			if (vec1[i] == vec2[j]) {
				return vec1[i];
			}
        	}
	}
}

TreeItem* Tree::getHead()
{
	return head;
}
#endif
