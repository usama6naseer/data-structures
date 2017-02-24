#include "sorts.h"
#include "list.cpp"
#include <vector>
#include "math.h"
using namespace std;

long emin(vector<long> v) {
        long a = v[0];
        for (int i=1; i<v.size(); i++) {
                if (a > v[i]) {
                        a = v[i];
                }
        }
        return a;
}
long emax(vector<long> v) {
        long a = v[0];
        for (int i=1; i<v.size(); i++) {
                if (a < v[i]) {
                        a = v[i];
                }
        }
        return a;
}

int main() {

vector<long> v;
v.push_back(6);
v.push_back(1);
v.push_back(3);
v.push_back(92);
v.push_back(634);
v.push_back(66);
v.push_back(63);
v.push_back(62);
v.push_back(226);
v.push_back(16);

cout << emax(v) << endl;
cout << emin(v);

return 0;
}
