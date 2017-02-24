#ifndef __BST_CPP
#define __BST_CPP
#include <iostream>
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
// #include "time.h"
using namespace std;
template <class T>
bst<T>::bst()
{
	root = NULL;
}

template <class T>
void insertNode (bst_node<T>* t, string val, T key1) {
	if (key1>t->key && t->right==NULL) {
		bst_node<T>* t1 = new bst_node<T> (val,key1);
		t->right = t1;
		t1->parent = t;
	}
	else if (key1<t->key && t->left==NULL) {
                bst_node<T>* t1 = new bst_node<T> (val,key1);
                t->left = t1;
		t1->parent = t;
        }
	else if (key1>t->key && t->right!=NULL) {
		insertNode(t->right, val, key1);
	} 
	else if (key1<t->key && t->left!=NULL) {
		insertNode(t->left, val, key1);
	}
}

template <class T>
void bst<T>::insert(string val,T key1) {
if (root == NULL) {
	bst_node<T>* t = new bst_node<T>(val, key1);
	t->parent = NULL;
	root = t;
} else {
	if (key1 > root->key) {
		if (root->right==NULL) {
			bst_node<T>* t = new bst_node<T>(val, key1);
        		root->right = t;
			t->parent = root;
		} else {
			insertNode(root->right, val , key1);
		}
	} else {
		if (root->left==NULL) {
                        bst_node<T>* t = new bst_node<T>(val, key1);
                        root->left = t;
			t->parent = root;
                } else {
			insertNode(root->left, val , key1);
		}
	}	
}
}

template <class T>
bst_node<T>* searchFor(bst_node<T>* t, T key1) {
	if (t->key == key1) {
		return t;
	}
	if (t->right != NULL && key1 > t->key) {
		return searchFor(t->right, key1);
	}
	else if (t->left != NULL && key1 < t->key) {
                return searchFor(t->left, key1);
        }
}

template <class T>
bst_node<T>* bst<T>::search(T key1)
{
if (root == NULL) {
	return NULL;
} else {
	if (key1 > root->key) {
		return searchFor(root->right, key1);
	} else {
		return searchFor(root->left, key1);
	}
}
}

template <class T>
void bst<T>::delete_node(T key1)
{
	bst_node<T>* t;
	t = search(key1);
	if (t!=NULL) {
	// 1st case leaf
	if (t->right==NULL && t->left==NULL) {
		bst_node<T>* p;
		p = t->parent;
		if (t==p->right) {
			p->right = NULL;
			t->parent = NULL;
		}
		else if(t==p->left) {
			p->left = NULL;
			t->parent = NULL;
		}
	}

	//2nd case one child
	else if (t->right == NULL || t->left == NULL) {
		bst_node<T>* p;
                p = t->parent;
		if (t->right != NULL) {
			if (t==p->right) {
				t->right->parent = p;
	                        p->right = t->right;
				t->right = NULL;
//				t->parent = NULL;
        	        } else {
				t->right->parent = p;
                	        p->left = t->right;
				t->right = NULL;
//				t->parent = NULL;
               		}
		} 
		else if (t->left!=NULL) {
			if (t==p->right) {
                                t->left->parent = p;
                                p->right = t->left;
				t->left = NULL;
//				t->parent = NULL;
                        } else {
                                t->left->parent = p;
                                p->left = t->left;
				t->left = NULL;
//				t->parent = NULL;
                        }
		}
	}
	else if (t->right != NULL && t->left!=NULL) {
	// 3rd case both left right are not null
		bst_node<T>* temp;
		if (t->right->left != NULL) {
			for (bst_node<T>* i = t->right; i!=NULL; i=i->left) {
				temp = i;
			}
		} else {
			temp = t->right;
		}
		if (temp->right==NULL) {
			t->key = temp->key;
			t->value = temp->value;
			bst_node<T>* p;
               		p = temp->parent;
			if (temp==p->right) {
                        	p->right = NULL;
				temp->parent = NULL;
      		        } else {
                	        p->left = NULL;
				temp->parent = NULL;
               		}
		} else {
			t->key = temp->key;
                        t->value = temp->value;
			bst_node<T>* p;
	                p = temp->parent;
			if (temp==p->right) {
                                temp->right->parent = p;
                                p->right = temp->right;
				temp->right=NULL;
                        } else {
                                temp->right->parent = p;
                                p->left = temp->right;
				temp->right==NULL;
                        }

                }
      	}
	}
}

template<class T>
int last(bst_node<T>* t) {
        int n=0;
	int n1=0;
        if (t->right!=NULL) {
                n = 1+n+last(t->right);
        }
        if (t->left!=NULL) {
                n1 = 1+n1+last(t->left);
        }
	if (n>n1) {
	        return n;
	} else {
		return n1;
	}
}


template <class T>
int bst<T>::height( bst_node<T> *temp) {
	if (root == NULL) {return -1;}
	 else {
        	int h1 = last(temp);
		return h1;
	}
}



template<class T>
void bst<T>::replace(T old_key,T new_key)
{
	bst_node<T>* t;
        t = search(old_key);
	insert(t->value, new_key);
	delete_node(old_key);
}

template <class T>
bst_node<T>* bst<T>::getroot()
{
	return root;
}
#endif
