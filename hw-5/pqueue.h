#ifndef PQUEUE__H
#define PQUEUE__H
#include <iostream>
//#include <malloc.h>

using namespace std;

template<class T>
class pqueue
{
        protected:
                int size;
        public:
                int numE;
                T* heap;
                pqueue();
		~pqueue();
                pqueue(int s);
                T ExtractMin();
                void insert(T key);
                void heapify();

};
template<class T>
pqueue<T>::pqueue(){
        size = 10;
        numE = 0;
        heap = new T[size];
}
template<class T>
pqueue<T>::~pqueue(){
	delete[] heap;
}

template<class T>
pqueue<T>::pqueue(int s){
        size = s;
        numE = 0;
        heap = new T[size];
}
template<class T>
void pqueue<T>::heapify() {
        int s = numE - 1;
        for (int i = s; i > 0; i--) {
                int p;
                if ((i - 1) % 2 == 0) {
                        p = ((i - 1) / 2);
                }
                else {
                        p = ((i - 2) / 2);
                }
                if (heap[i] < heap[p]) {
                        T t1;
                        t1 = heap[i];
                        heap[i] = heap[p];
                        heap[p] = t1;
                }
        }
}
template<class T>
void pqueue<T>::insert(T key) {
        heap[numE] = key;
        numE++;
        if (numE > 1) {
                heapify();
        }
}
template<class T>
T pqueue<T>::ExtractMin() {
        T k = heap[0];
        for (int i = 0; i < numE-1; i++) {
                heap[i] = heap[i + 1];
        }
//        heap[numE - 1] = 0;
        numE--;
        heapify();
        return k;
}


#endif
