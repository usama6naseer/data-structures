#include <iostream>
#include "pqueue.h"
#include "Graph.cpp"
using namespace std;



int main() {
pqueue<edge> a(10);
edge z;
z.weight = 4;
edge d;
d.weight = 3;
edge b;
b.weight = 2;
edge c;
c.weight = 1;

a.insert(z);
a.insert(b);
a.insert(c);
a.insert(d);
cout << a.ExtractMin().weight;

pqueue<int> h(100);
for (int i=0;i<100;i++) {
	h.insert(i);
}

return 0;
}
