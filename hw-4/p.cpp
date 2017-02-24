#include <iostream>
#include <vector>
using namespace std;

//=====================================================================================
template <typename T>
void swap1(T& t1, T& t2) {
        T a = t1;
        t1 = t2;
        t2 = a;
}
//_____________________________________________________________________________________
vector<long> InsertionSort(vector<long> nums)
{
        int size = nums.size();
        long arr[size];
        for (int i=0; i<size; i++) {
                arr[i] = nums[i];
        }
        for(int i=1; i<size; i++) {
                for (int j=i; j>0; j--) {
                        if (arr[j] < arr[j-1]) {
                                swap1(arr[j], arr[j-1]);
                        }
                }
        }
        vector<long> v;
        for (int i=0; i<size; i++) {
                v.push_back(arr[i]);
        }
        return v;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Heap {
public:
	vector<long> list;
	int sizeh;
	Heap() { sizeh = 0; }
	void insert(long key);
	long extractmin();
	void heapify();
};
void Heap::heapify() {
	int s = sizeh - 1;
	for (int i = s; i > 0; i--) {
		int p;
		if ((i - 1) % 2 == 0) {
			p = ((i - 1) / 2);
		}
		else {
			p = ((i - 2) / 2);
		}
		if (list[i] < list[p]) {
			long t1;
			t1 = list[i];
			list[i] = list[p];
			list[p] = t1;
		}
	}
}

void Heap::insert(long key) {
	list.push_back(key);
	sizeh++;
	if (list.size() > 1) {
		heapify();
	}
}

long Heap::extractmin() {
	long k = list[0];
	for (int i = 0; i < sizeh-1; i++) {
		list[i] = list[i + 1];
	}
	list[list.size() - 1] = 0;
	sizeh--;
	heapify();
	return k;
}
vector<long> HeapSort(vector<long> nums)
{
        Heap h;
        for (int i=0; i<nums.size(); i++) {
                h.insert(nums[i]);
        }
        vector<long> v;
        for (int i=0; i<nums.size(); i++) {
                v.push_back(h.extractmin());
        }
        return v;
}

int main() {
	vector<long> v;
	v.push_back(3);
v.push_back(30);
v.push_back(89);
v.push_back(1);
v.push_back(32);
v.push_back(344);
v.push_back(53);
v.push_back(13);
v.push_back(31);
v.push_back(35);

v = HeapSort(v); 
for (int i = 0; i < v.size(); i++) {
                cout << v[i] << endl;
}

	/*
	Heap h;
	h.insert(10);
	h.insert(1);
	h.insert(120);
	h.insert(12);
	h.insert(138);
	h.insert(88);
	h.insert(121);
	h.insert(6);
	//h.insert(10);

	for (int i = 0; i < h.list.size(); i++) {
		cout << h.list[i] << endl;
	}
	

	cout << endl;
	cout << h.extractmin() << endl;
	cout << h.extractmin() << endl;
	cout << h.extractmin() << endl;
	cout << h.extractmin() << endl;
	cout << h.extractmin() << endl;
	cout << h.extractmin() << endl;
	cout << h.extractmin() << endl;
	cout << h.extractmin() << endl;
	
	int a;
	cin >> a;
	*/

return 0;
}




