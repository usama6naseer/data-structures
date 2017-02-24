#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "list.cpp"
#include <vector>
#include "math.h"
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
	//for (int i=0; i<size; i++) {
	//	arr[i] = nums[i];
	//}
	for(int i=1; i<size; i++) {
		arr[i] = nums[i];
		for (int j=i; j>0; j--) {
			if (arr[j] < arr[j-1]) {
				//swap1(arr[j], arr[j-1]);
				long a = arr[j];
			        arr[j] = arr[j-1];
			        arr[j-1] = a;

			}
		}
	}
	vector<long> v;
	for (int i=0; i<size; i++) {
                v.push_back(arr[i]);
        }
	return v;
}

//=====================================================================================
/*
ListItem<long>* divideMS(ListItem<long>* h, int size) {

        int h1 = floor(size/2);
	int h2 = size-h1;

	if (size <= 1) {
		return h;
	} else { 

		ListItem<long>* p1 = h;
		ListItem<long>* p2 = p1;
	        for (int i=0; i<h1; i++) {
	                p2 = p2->next;
	        }
		p2->prev->next = NULL;
		p2->prev = NULL;

		ListItem<long>* half1;
		ListItem<long>* half2;

		half1 = divideMS(p1, h1);
		half2 = divideMS(p2, h2);

		return joinMS(half1, half2);
	}
}
*/

ListItem<long>* joinMS(ListItem<long>* p1, ListItem<long>* p2) {
	if (p1->next == NULL && p2->next == NULL) {
		if (p1->value < p2->value) {
			p1->next = p2;
			return p1;
		} else {
			p2->next = p1;
			return p2;
		}
	} else {
		int s1=0;
		int s2=0;
		for (ListItem<long>* k = p1; k!=NULL; k=k->next) {
			s1++;
		}
		for (ListItem<long>* k = p2; k!=NULL; k=k->next) {
                        s2++;
                }
		int size = 0;
		int diff = 0;
		if (s1 > s2) {
			size=s1;
			diff = s1-s2;
		} else {
			size = s2;
			diff = s2-s1;	
		}
		ListItem<long>* i = p1;
		ListItem<long>* j = p2;
		ListItem<long>* head;
		ListItem<long>* head1;
		int c1 = s1;
		int c2 = s2;
		int count = 0;

		while (count < s1+s2) {

			if (c1>0 && c2>0) {
				if (j->value > i->value) {
					if (count == 0) {
						head = i;
						head1 = i;
						if (i->next!=NULL) {
	                                	        i = i->next;
						} else { i = NULL;}
						c1--;
					} else {
						head1->next = i;
						head1 = head1->next;
						if (i->next!=NULL) {
							i = i->next;
						} else { i = NULL;}
						c1--;
					}
				} else {
					if (count == 0) {
						head = j;
						head1 = j;
						if (j->next!=NULL) {
							j = j->next;
						} else { j = NULL;}	
						c2--;
        	                        } else {
						head1->next = j;
						head1 = head1->next;
						if (j->next!=NULL) {	
							j = j->next;
						} else { j = NULL;}
						c2--;
					}
				}
			} else {
				if (i == NULL) {
					head1->next = j;
                                        head1 = head1->next;
                                        if (j->next!=NULL) {
                                                j = j->next;
                                        } else { j = NULL;}
					c2--;
				} else {
					head1->next = i;
                                        head1 = head1->next;
					if (i->next!=NULL) {
                                                i = i->next;
                                        } else { i = NULL;}
					c1--;
				}
			}
			count++;
		}
		return head;
	}
}

ListItem<long>* divideMS(ListItem<long>* h, int size) {

        int h1 = floor(size/2);
        int h2 = size-h1;

        if (size <= 1) {
                return h;
        } else {

                ListItem<long>* p1 = h;
                ListItem<long>* p2 = p1;
                for (int i=0; i<h1; i++) {
                        p2 = p2->next;
                }
                p2->prev->next = NULL;
                p2->prev = NULL;

                ListItem<long>* half1;
                ListItem<long>* half2;
		
                half1 = divideMS(p1, h1);
		half2 = divideMS(p2, h2);

                return joinMS(half1, half2);
        }
}


vector<long> MergeSort(vector<long> nums)
{
	int size = nums.size();
	List<long>* list = new List<long>();
	for (int i=0; i<size; i++) {
		list->insertAtTail(nums[i]);
	}
	ListItem<long>* p = list->getHead();
	p = divideMS(p, size);
	vector<long> v;
	for (ListItem<long>* i=p; i!=NULL; i=i->next) {
                v.push_back(i->value);
        }
	return v;
}

//=====================================================================================

long calculate_pivot(long* arr, int size) {
	long p1 = arr[0];
        long p2 = arr[size%8];
        long p3 = arr[size-1];
        long pivot = arr[0];
        
	if ((p1>=p2 && p1<=p3) || (p1 >= p3 && p1<=p2)) {
                pivot = p1;
        }
        else if ((p2>=p1 && p2<=p3)||(p2>=p3 && p2<=p1)) {
                pivot = p2;
        } else {
		pivot = p3;
	} 
	return pivot;
}


long* mergeQSArray(long* arr1, long* pivot_arr, long* arr2, int h1, int h2, int h3) {
	long* ans = new long[h1+h2+h3];
	int index = 0;
	for (int i=0; i<h1; i++) {
		ans[index] = arr1[i];
		index++;
	}
	for (int j=0; j<h2; j++) {
                ans[index] = pivot_arr[j];
		index++;
        }
	for (int k=0; k<h3; k++) {
                ans[index] = arr2[k];
		index++;
        }
	return ans;
}

long* divideQSArray(long* arr, int size) {
	if (size <= 1) {
		return arr;
	} else {
		int half1 = 0;
		int half2 = 0;
		int num_pivot = 0;
		long pivot = calculate_pivot(arr, size);
		for (int i=0; i<size; i++) {
   	                if (arr[i] < pivot) {
        	                half1++;
                	}
         	        else if(arr[i] > pivot) {
                	        half2++;
           	        } else {
                	        num_pivot++;
               		}
	        }


		long* arr1 = new long[half1];
		long* arr2 = new long[half2];
		long* pivot_arr = new long[num_pivot];
		int a = 0;
		int b = 0;
		int c = 0; 
		for (int i=0; i<size; i++) {
			if (arr[i] < pivot) {
                	        arr1[a] = arr[i];
				a++;
	                }
        	        else if(arr[i] > pivot) {
				arr2[b] = arr[i];
				b++;
	                } else {
				pivot_arr[c] = arr[i];
				c++;
	                }
        	}
		arr1 = divideQSArray(arr1,half1);
		arr2 = divideQSArray(arr2,half2);

		return mergeQSArray(arr1, pivot_arr, arr2, half1, num_pivot, half2);
	}
}

vector<long> QuickSortArray(vector<long> nums)
{
	int size = nums.size();
	long* arr = new long[size];
	for (int i=0; i<size; i++) {
                arr[i] = nums[i];
        }
	long* ans;
	ans = divideQSArray(arr,size);
	vector<long> v;
	for (int i=0; i<size; i++) {
		v.push_back(ans[i]);
	}
	return v;

}

//=====================================================================================
long calculate_pivotList(List<long>* arr, int size) {
        ListItem<long>* a = arr->getHead();
	count = 0;
	for (int i=0;i<size/2;i++) {
		if (a->next != NULL) {
			a = a->next;
		}
		if (count >= 150) {
			break;
		}
		count++;
	}
	return a->value;
}


List<long>* mergeQSList(List<long>* arr1, List<long>* pivot_arr, List<long>* arr2) {
        ListItem<long>* p = pivot_arr->getHead();
	for (int i=0; i<pivot_arr->length(); i++) {
                arr1->insertAtTail(p->value);
		if (p->next != NULL) {
                	p = p->next;
                }
        }
	p = arr2->getHead();
        for (int i=0; i<arr2->length(); i++) {
                arr1->insertAtTail(p->value);
		if (p->next != NULL) {
                	p = p->next;
                }
        }
        return arr1;
}



List<long>* divideQSList(List<long>* arr, int size) {

        if (size <= 1) {
                return arr;
        } else {
                int half1 = 0;
                int half2 = 0;
                int num_pivot = 0;
                long pivot = calculate_pivotList(arr, size);

                List<long>* arr1 = new List<long>();
                List<long>* arr2 = new List<long>();
                List<long>* pivot_arr = new List<long>();
		
		ListItem<long>* p = arr->getHead();
                for (int i=0; i<size; i++) {
                        if (p->value < pivot) {
                                arr1->insertAtTail(p->value);
                                half1++;
                        }
                        else if(p->value > pivot) {
                                arr2->insertAtTail(p->value);
                                half2++;
                        } else {
                                pivot_arr->insertAtTail(p->value);
                                num_pivot++;
                        }
			if (p->next != NULL) {
                        	p = p->next;
                	}
                }
                arr1 = divideQSList(arr1,half1);
                arr2 = divideQSList(arr2,half2);

                return mergeQSList(arr1, pivot_arr, arr2);
        }
}


vector<long> QuickSortList(vector<long> nums)
{
	int size = nums.size();
        List<long>* arr = new List<long>();
        for (int i=0; i<size; i++) {
                arr->insertAtTail(nums[i]);

        }
        List<long>* ans;
        ans = divideQSList(arr,size);

	ListItem<long>* p = ans->getHead();
        vector<long> v;
        for (int i=0; i<size; i++) {
                v.push_back(p->value);
		if (p->next != NULL) {
			p = p->next;
        	}
	}
        return v;

}

//=====================================================================================
class Heap {
public:
	long* list;
	int sizeh;
	int cap;
	Heap(int a) {
	cap = a;
	list = new long[cap];
	sizeh = 0;
	}
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
	//list.push_back(key);
	list[sizeh] = key;
	sizeh++;
	if (sizeh > 1) {
		heapify();
	}
}
long Heap::extractmin() {
	long k = list[0];
	for (int i = 0; i < sizeh-1; i++) {
		list[i] = list[i + 1];
	}
	list[sizeh - 1] = 0;
	sizeh--;
	heapify();
	return k;
}
//____________________________________________________________________________________
vector<long> HeapSort(vector<long> nums)
{
	Heap h(nums.size());
	for (int i=0; i<nums.size(); i++) {
		h.insert(nums[i]);
	}
	vector<long> v;
	for (int i=0; i<nums.size(); i++) {
		v.push_back(h.extractmin());
	}

	return v;
}

//=====================================================================================
class HashC {
        public:
        int size;
        int collisions;
	long min;
	long max;
        List<long>* table;
        vector<long> collect();
	HashC(int a, long m, long m1) {
		max = m1;
		min = m;
                size = a;
                collisions = 0;
                table = new List<long>[size];
        }
        int hash(long a);
        void insert(long a);
};
int HashC::hash(long a) {
/*
	if (a < size ) {
		int h = a;
		return h;
	} else {
		int h = size-1;
		return h;
	}
*/
	double s = size-1;
	int b = round((a*(s))/max);
//	cout << a << ' ' << b << endl;
	return b;
}

void HashC::insert(long a) {
	int h1 = hash(a);
	if (table[h1].getHead() == NULL) {
		table[h1].insertAtHead(a);
	} else {
		collisions++;
		if (table[h1].getHead()->next == NULL) {
			if (a > table[h1].getHead()->value) {
				table[h1].insertAtTail(a);
			} else {
				table[h1].insertAtHead(a);
			}
		} else {
			int check = 0;		
			ListItem<long>* tail;
			if (a < table[h1].getHead()->value) {
                                table[h1].insertAtHead(a);
			} else {
				for (ListItem<long>* i=table[h1].getHead(); i->next!=NULL; i=i->next) {
					if (a > i->value && a < i->next->value) {
						check = 1;
						table[h1].insertAfter(a, i->value);
						break;
					} 
					else if (a == i->value) {
						check = 1;
						table[h1].insertAfter(a, i->value);
						break;
					}
					tail = i;
				}
				if (check == 0) {
					if (tail->next->value > a) {
						table[h1].insertAfter(a, tail->value);
					} else {
//cout << a << " val " << 9 <<' ' << h1 <<  endl;
						table[h1].insertAtTail(a);
					}
				}
			}
		}
	}
}
vector<long> HashC::collect() {
	vector<long> v;
	for (int i=0; i<size; i++) {
		if (table[i].getHead() != NULL) {
			for (ListItem<long>* k = table[i].getHead(); k!=NULL; k=k->next) {
				v.push_back(k->value);
			}
		}
	}
	return v;
}
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
	//total = 1;
        for (int i=1; i<v.size(); i++) {
	//	total++;
                if (a < v[i]) {
                        a = v[i];
                }
        }
        return a;
}

vector<long> BucketSort(vector<long> nums, int max)
{
	long min = emin(nums);
	long m = emax(nums);
	HashC h(max, min, m);
	for (int i=0; i<nums.size(); i++) {
                h.insert(nums[i]);
        }
	return h.collect();
}

/*
int main() {

vector<long> v;
v.push_back(11);
v.push_back(141);
v.push_back(777);
v.push_back(31);
v.push_back(522);
v.push_back(6);
v.push_back(982);
v.push_back(722);
v.push_back(82);
v.push_back(22);
v.push_back(722);
v.push_back(2422);
v.push_back(122);
v.push_back(722);
v.push_back(1522);
v.push_back(542);
v.push_back(52);
v.push_back(722);
v.push_back(5022);
v.push_back(5622);
v.push_back(3522);
v.push_back(11522);
v.push_back(11);
v.push_back(141);
v.push_back(777);
v.push_back(31);
v.push_back(522);
v.push_back(6);
v.push_back(982);
v.push_back(722);
v.push_back(82);
v.push_back(22);
v.push_back(722);
v.push_back(2422);
v.push_back(122);
v.push_back(722);
v.push_back(1522);
v.push_back(542);
v.push_back(52);
v.push_back(722);
v.push_back(5022);
v.push_back(5622);
v.push_back(3522);
v.push_back(11522);
v.push_back(11);
v.push_back(141);
v.push_back(777);
v.push_back(31);
v.push_back(522);
v.push_back(6);
v.push_back(982);
v.push_back(722);
v.push_back(82);
v.push_back(22);
v.push_back(722);
v.push_back(2422);
v.push_back(122);
v.push_back(722);
v.push_back(1522);
v.push_back(542);
v.push_back(52);
v.push_back(722);
v.push_back(5022);
v.push_back(5622);
v.push_back(3522);
v.push_back(11522);
v.push_back(11);
v.push_back(141);
v.push_back(777);
v.push_back(31);
v.push_back(522);
v.push_back(6);
v.push_back(982);
v.push_back(722);
v.push_back(82);
v.push_back(22);
v.push_back(722);
v.push_back(2422);
v.push_back(122);
v.push_back(722);
v.push_back(1522);
v.push_back(542);
v.push_back(52);
v.push_back(722);
v.push_back(5022);
v.push_back(5622);
v.push_back(3522);
v.push_back(11522);

v = BucketSort(v,14);

for (int i=0; i<v.size(); i++) {

	cout << v[i] << endl;

}
 

return 0;
}
*/
#endif
