// Write Linked List Class Code Below
#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
head = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
        ListItem<T>* temp = new ListItem<T>(otherLinkedList.head->value);
	std::vector<std::string> vec(otherLinkedList.wordList);
        head = temp;
        for (ListItem<T>* i=otherLinkedList.head->next; i!=NULL; i=i->next)
        {
                ListItem<T>* temp1 = new ListItem<T>(i->value);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
        }
        delete temp;
}

template <class T>
LinkedList<T>::~LinkedList()
{
        while(length()!=0) {
                deleteHead();
        }
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
        if (head != NULL){
                ListItem<T>* nodeptr = new ListItem<T>(item);
                nodeptr->next = head;
                head->prev = nodeptr;
                head = nodeptr;
        } else {
                ListItem<T>* nodeptr = new ListItem<T>(item);
                head = nodeptr;
        }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
        if (head!=NULL) {
                ListItem<T>* ptr = new ListItem<T>(item);
                ListItem<T>* temp;
                for (ListItem<T>* i=head; i!=NULL; i=i->next)
                {
                        temp = i;
                }
                temp->next = ptr;
                ptr->prev = temp;
//              delete ptr;
//              delete temp;
        } else {
                ListItem<T>* ptr = new ListItem<T>(item);
                head = ptr;
                head->next = NULL;
//              delete ptr;
        }
}
template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
if(head!=NULL) {
        ListItem<T>* node = new ListItem<T>(toInsert);
        ListItem<T>* temp;
        for (ListItem<T>* i = head; i!=NULL; i=i->next) {
                if (i->value == afterWhat) {
                temp = i;
                break;
                }
        }
        if(temp->next!=NULL) {
                node->next = temp->next;
                node->prev = temp;
                temp->next->prev = node;
                temp->next = node;
        } else {
                insertAtTail(toInsert);
        }
//      delete node;
//      delete temp;
}
}
template <class T>
void LinkedList<T>::insertSorted(T item)
{
if (head!=NULL) {
        if (head->value > item) {
                insertAtHead(item);
        } else {
                for (ListItem<T>* i=head; i!=NULL ; i=i->next){
                        if (i->next != NULL) {
                                if (i->value <= item && i->next->value > item){
                                        insertAfter(item, i->value);
                                        break;
                                }
                        }
                        else if(i->next == NULL) {
                                if (i->value <= item) {
                                        insertAtTail(item);
                                        break;
                                }
                        }
                }
        }
} else {
        insertAtHead(item);
}
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
        return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
        for (ListItem<T>* i=head; i!=NULL; i=i->next)
        {
                if (i->next == NULL)
                {
                        return i;
                }
        }
        return NULL;
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
if (head!=NULL) {
        for (ListItem<T>* i=head; i!=NULL; i=i->next)
        {
                if (i->value==item)
                {
                        return i;
                }
        }
        return NULL;
}
}
template <class T>
void LinkedList<T>::deleteElement(T item)
{
if (head!=NULL) {
        if (head->value == item)
        {
                deleteHead();
        } else {
                ListItem<T>* temp;
                temp = searchFor(item);
                if (temp->next == NULL) {
                        deleteTail();
                }
                else if (temp->next != NULL) {
                        temp->next->prev = NULL;
                        temp = temp->prev;
                        temp->next = temp->next->next;
                }
//              delete temp;
        }
}
}
template <class T>
void LinkedList<T>::deleteHead()
{
        if (head!=NULL) {
                if (head->next==NULL) {
                        head = NULL;
                } else {
                        head = head->next;
                        head->prev = NULL;
                }
        }
}

template <class T>
void LinkedList<T>::deleteTail()
{
if (head!=NULL) {
        if (head->next==NULL) {
                head = NULL;
        } else {
        ListItem<T>* temp = head;
        for (ListItem<T>* i=head; i->next!=NULL; i=i->next)
        {
                temp = i;
        }
        temp->next->prev = NULL;
        temp->next = NULL;
//      delete temp;
}
}
}
template <class T>
int LinkedList<T>::length()
{
if (head!=NULL) {
        int length = 0;
        for(ListItem<T>* i = head; i!=NULL; i=i->next)
        {
                length = length+1;
        }
        return length;
}
}

#endif
