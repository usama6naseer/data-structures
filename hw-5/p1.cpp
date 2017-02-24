#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;
int main() {
	set<pair<int,string> > s;
	pair<int,string> p1 = make_pair(1,"a");
	s.insert(p1);
	pair<int,string> p2 = make_pair(2,"ab");
        s.insert(p2);
	pair<int,string> p3 = make_pair(3,"abc");
        s.insert(p3);
	pair<int,string> p4 = make_pair(4,"abcd");
        s.insert(p4);
	pair<int,string> p5 = make_pair(5,"az");
        s.insert(p5); 
	set<pair<int,string> >::iterator it;
	it = s.begin();
	cout << (*it).first << ' ' << (*it).second << endl;
	s.erase(it);
	it = s.begin();
	pair<int,string> s11 = *it;
        cout << (*it).first << ' ' << (*it).second << endl;
        s.erase(it);


return 0;
}
