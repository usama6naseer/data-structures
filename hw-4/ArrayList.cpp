#ifndef __LIST_CPP
#define __LIST_CPP

#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& otherArrayList)
{
	capacity = otherArrayList.capacity;
	size = 0;
	array = new T[otherArrayList.capacity];
	for (int i = 0; i < otherArrayList.size; i++) {
		if (size == capacity) {
			capacity = capacity * 2;
		}
		array[i] = otherArrayList.array[i];
		size = size + 1;
	}


}

template <class T>
ArrayList<T>::~ArrayList()
{
	delete array;
	// size = 0;
}

template <class T>
void ArrayList<T>::insertAtHead(T item)
{
	// if (size == capacity) {
	//         capacity = capacity*2;
	// }
	resize();
	for (int i = size; i != 0; i = i - 1) {
		array[i] = array[i - 1];
	}
	array[0] = item;
	size = size + 1;


}

template <class T>
void ArrayList<T>::insertAtTail(T item)
{
	// if (size == capacity) {
	//         capacity = capacity*2;
	// }
	resize();
	array[size] = item;
	size = size + 1;
}



template <class T>
void ArrayList<T>::insertAfter(T toInsert, T afterWhat)
{
	// if (size == capacity) {
	//         capacity = capacity*2;
	// }
	resize();
	int index = 0;
	int check = 0;
	for (int i = 0; i<size; i++){
		if (array[i] == afterWhat) {
			index = i;
			check = 1;
			break;
		}
	}
	if (check == 1) {
		for (int i = size; i>index + 1; i = i - 1) {
			array[i] = array[i - 1];
		}
		array[index + 1] = toInsert;
		size = size + 1;
	}
}


template <class T>
void ArrayList<T>::insertSorted(T item)
{
	// if (size == capacity) {
	//         capacity = capacity*2;
	// }
	resize();
	int index = 0;
	if (array[0]>item){
		insertAtHead(item);
	}
	else {
		for (int i = 0; i + 1<size; i++) {
			if (getAt(i) <= item && getAt(i + 1) > item) {
				insertAfter(item, array[i]);
				break;
			}
		}
	}
	if (getAt(size - 1) <= item) {
		insertAtTail(item);
	}
}

template <class T>
T ArrayList<T>::getAt(int i)
{
	T val = array[i];
	return val;
}

template <class T>
int ArrayList<T>::searchFor(T item)
{
	for (int i = 0; i<size; i++) {
		if (array[i] == item){
			return i;
		}
	}
	return 0;
}

template <class T>
void ArrayList<T>::deleteElement(T item)
{
	int check = 0;
	int index = 0;
	for (int i = 0; i + 1 <= size; i++) {
		if (array[i] == item) {
			index = i;
			check = 1;
		}
	}
	if (check == 1) {
		for (int i = index; i + 2 <= size; i++) {
			array[i] = array[i + 1];
		}
		// array[size-1] = 0;
		size = size - 1;
	}
}

template <class T>
void ArrayList<T>::deleteHead()
{
	for (int i = 0; i + 1 < size; i++) {
		array[i] = array[i + 1];
	}
	// array[size-1] = 0;
	size = size - 1;
}

template <class T>
void ArrayList<T>::deleteTail()
{
	// array[size-1] = 0;
	size = size - 1;
}

template <class T>
int ArrayList<T>::length()
{
	return size;
}

template <class T>
void ArrayList<T>::resize()
{
	if (size == capacity) {
		capacity = capacity * 2;
		T *arr = new T[capacity];
		for (int i = 0; i<size; i++) {
			arr[i] = array[i];
		}
		array = arr;
	}
}

#endif
