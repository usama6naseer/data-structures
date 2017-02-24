#ifndef PQUEUE1__H
#define PQUEUE1__H
#include <iostream>
using namespace std;

class pqueue
{
        protected:
                int size;
        public:
                int numE;
                edge* heap;
                pqueue();
                pqueue(int s);
                edge ExtractMin();
                void insert(T key);
                void heapify();

};
pqueue<T>::pqueue(){
        size = 0;
        numE = 0;
        heap = NULL;
}
pqueue<T>::pqueue(int s){
        size = s;
        numE = 0;
        heap = new edge[size];
}
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
			int wt = heap[i].weight;
			node* n1 = heap[i].Origin;
			node* n2 = heap[i].Dest;
			heap[i].weight = heap[p].weight;
			heap[i].Origin = heap[p].Origin;
			heap[i].Dest = heap[p].Dest;
			heap[p].Dest = n2;
			heap[p].Origin = n1;
			heap[p].weight = wt;
                }
        }
}
void pqueue<T>::insert(edge key) {
        heap[numE] = key;
        numE++;
        if (numE > 1) {
                heapify();
        }

}
edge pqueue<T>::ExtractMin() {
        edge k = heap[0];
        for (int i = 0; i < numE-1; i++) {
		 heap[i].weight = heap[i+1].weight;
                 heap[i].Origin = heap[i+1].Origin;
                 heap[i].Dest = heap[i+1].Dest;

        }
//        heap[numE - 1] = 0;
        numE--;
        heapify();
        return k;
}



#endif

