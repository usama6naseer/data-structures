#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"
// #include "time.h"
#include <fstream>

template <class T>
AvL<T>::AvL()
{
	head = NULL;
}

template <class T>
AvL<T>::~AvL()
{
	delete(head);
}

template <class T>
AvLNode<T>* searchFor(AvLNode<T>* t, T key1) {
        if (t->key == key1) {
                return t;
        }
        if (t->right != NULL && key1 > t->key) {
                return searchFor(t->right, key1);
        }
        else if (t->left != NULL && key1 < t->key) {
                return searchFor(t->left, key1);
        } else {
		return NULL;
	}
}

template <class T>
AvLNode<T>* AvL<T>::search(T k)
{
	if (head == NULL) {
	        return NULL;
	}
	else if(k == head->key) {
		return head;
	} else {
	        if (k > head->key) {
	                return searchFor(head->right, k);
	        } else {
	                return searchFor(head->left, k);
	        }
	}
}

template <class T>
void AvL<T>::replace(T ok, T nk)
{
	AvLNode<T>* t;
        t = search(ok);
        insert(t->value, nk);
        delete_node(ok);
}

template <class T>
void AvL<T>::delete_node(T key1)
{
        AvLNode<T>* t;
	AvLNode<T>* t90;
        t = search(key1);
	t90 = t->parent;
        if (t!=NULL) {
        // 1st case leaf
        if (t->right==NULL && t->left==NULL) {
                AvLNode<T>* p;
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
                AvLNode<T>* p;
                p = t->parent;
                if (t->right != NULL) {
                        if (t==p->right) {
                                t->right->parent = p;
                                p->right = t->right;
                                t->right = NULL;
//                              t->parent = NULL;
                        } else {
                                t->right->parent = p;
                                p->left = t->right;
                                t->right = NULL;
//                              t->parent = NULL;
                        }
                }
                else if (t->left!=NULL) {
                        if (t==p->right) {
                                t->left->parent = p;
                                p->right = t->left;
                                t->left = NULL;
//                              t->parent = NULL;
                        } else {
                                t->left->parent = p;
				p->left = t->right;
                                t->right = NULL;
//                              t->parent = NULL;
                        }
                }
                else if (t->left!=NULL) {
                        if (t==p->right) {
                                t->left->parent = p;
                                p->right = t->left;
                                t->left = NULL;
//                              t->parent = NULL;
                        } else {
                                t->left->parent = p;
                                p->left = t->left;
                                t->left = NULL;
//                              t->parent = NULL;
                        }
                }
        }
        else if (t->right != NULL && t->left!=NULL) {
        // 3rd case both left right are not null
                AvLNode<T>* temp;
                if (t->right->left != NULL) {
                        for (AvLNode<T>* i = t->right; i!=NULL; i=i->left) {
                                temp = i;
                        }
                } else {
                        temp = t->right;
                }
                if (temp->right==NULL) {
                        t->key = temp->key;
                        t->value = temp->value;

                        AvLNode<T>* p;
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
                        AvLNode<T>* p;
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
//}
	if (t90 != NULL) {
		isAVL(t90);
	}
}


template <class T>
void insertNode (AvLNode<T>* t, string val, T key1) {
        if (key1>t->key && t->right==NULL) {
                AvLNode<T>* t1 = new AvLNode<T> (val,key1);
                t->right = t1;
                t1->parent = t;
        }
        else if (key1<t->key && t->left==NULL) {
                AvLNode<T>* t1 = new AvLNode<T> (val,key1);
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
void AvL<T>::insert(string val, T k)
{
	if (head==NULL) {
		AvLNode<T>* t = new AvLNode<T>(val, k);
		head = t;
	} else {
		if (k > head->key) {
			if (head->right==NULL) {
				AvLNode<T>* t = new AvLNode<T>(val, k);
				head->right = t;
				t->parent = head;
			} else {
				insertNode(head->right, val, k);
			}
		
		}
		else if (k < head->key) {
                        if (head->left==NULL) {
                                AvLNode<T>* t = new AvLNode<T>(val, k);
                                head->left = t;
                                t->parent = head;
                        } else {
                                insertNode(head->left, val, k);
                        }

                }
	}
	if (k != head->key) {
		AvLNode<T>* h = search(k);
		isAVL(h);
		//isAVL(head);
	}
}

template<class T>
int last(AvLNode<T>* t) {
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

template<class T>
int AvL<T>::nodeHeight( AvLNode<T> *temp)
{
	if (head == NULL) {return -1;}
        else {
                int h1 = last(temp);
                return h1;
        }
}

template<class T>
int AvL<T>::compare(AvLNode<T>* t) {
	int h1=0;
	int h2=0;
	if (t->right != NULL) {
		h1 = nodeHeight(t->right);
	} else {
		h1 = -1;
	}
	if (t->left != NULL) {
		h2 = nodeHeight(t->left);
	} else {
		h2 = -1;
	}
	return (h2-h1);
}

template<class T>
AvLNode<T>*  AvL<T>::rotRight(AvLNode<T>* k1) {
	AvLNode<T>* k2;
	if (k1->left!=NULL){
		k2 = k1->left;
	} else {
		k2 = NULL;
	}
	if (k2->right != NULL) {
		k1->left = k2->right;
		k2->right->parent = k1;
	} else {
		k1->left = NULL;
	}
	k2->right = k1;
	k1->parent = k2;
	k1 = k2;
	return k1;
}


template<class T>
AvLNode<T>*  AvL<T>::rotLeft(AvLNode<T>* k1) {
	AvLNode<T>* k2;
        if (k1->right!=NULL){
		k2 = k1->right;
	} else {
		k2 = NULL;
	}
	if (k2->left!=NULL){
        	k1->right = k2->left;
		k2->left->parent = k1;
	} else {
		k1->right = NULL;
	}
        k2->left = k1;
	k1->parent = k2;
	k1 = k2;
	return k1;
}
template<class T>
AvLNode<T>*  AvL<T>::rotRL(AvLNode<T>* k1) {
	AvLNode<T>* k2;
	k2 = k1->right;
	k2 = rotRight(k2);
	k2->parent = k1;
	k1->right = k2;
        k1 = rotLeft(k1);
	return k1;
}		


template<class T>
AvLNode<T>*  AvL<T>::rotLR(AvLNode<T>* k1) {
	AvLNode<T>* k2;
	k2 = k1->left;
	k2 = rotLeft(k2);
	k2->parent = k1;
	k1->left = k2;
	k1 = rotRight(k1);
	return k1;
}

template<class T>
void AvL<T>::isAVL(AvLNode<T>* k) {
	int h;
	h = compare(k);
	if (h==0 || h==1 || h== -1) {
		//do nothing
	} else {
		makeItAVL(k, h);
	}
	//if (k->right != NULL) {
	//	isAVL(k->right);
	//}
	//if (k->left != NULL) {
	//	isAVL(k->left);
	//}
	if (k->parent != NULL) {
		isAVL(k->parent);
	} 	
}

template<class T>
void AvL<T>::isAVLdel(AvLNode<T>* k) {
        int h;
        h = compare(k);
        if (h==0 || h==1 || h== -1) {
                //do nothing
        } else {
                makeItAVL(k, h);
        }
        if (k->right != NULL) {
              isAVL(k->right);
        }
        if (k->left != NULL) {
              isAVL(k->left);
        }
        //if (k->parent != NULL) {
        //        isAVL(k->parent);
        //}
}


template<class T>
void AvL<T>::makeItAVL(AvLNode<T>* k, int h) {
	if (h > 0) { //left sub tree needs adjustment
		int h1 = compare(k->left);
		if (h1 > 0) {
			if (k==head) {
				k=rotRight(k);
				head->parent = k;
				head = k;
head->parent = NULL;
			} else {
				AvLNode<T>* p;
        	                p = k->parent;
				//k = rotRight(k);
				if (k==p->right) {
					k = rotRight(k);
					k->parent = p;
					p->right = k;
				} else {
					k = rotRight(k);
					k->parent = p;
					p->left = k;
				}
			}
		} else {

			 if (k==head) {
                                k=rotLR(k);
				head->parent = k;
				head = k;
head->parent = NULL;
                        } else {

				AvLNode<T>* p;
				p = k->parent;
				//k = rotLR(k);
				//p->right = k;
				if (k==p->right) {
        	                        k = rotLR(k);
					k->parent = p;
                	                p->right = k;
                        	} else {
	                                k = rotLR(k);
					k->parent = p;
        	                        p->left = k;
                	        }
			}
		}
	}
	else if (h < 0) { //rightt sub tree needs adjustment
		int h1 = compare(k->right);

		if (h1 < 0 ) {
			if (k==head) {
                                k=rotLeft(k);
				head->parent = k;
				head = k;
head->parent = NULL;
                        } else {
				AvLNode<T>* p;
        	                p = k->parent;
                	        //k = rotLeft(k);
				//p->right = k;
				if (k==p->right) {
        	                        k = rotLeft(k);
					k->parent = p;
                	                p->right = k;
                        	} else {
 	                                k = rotLeft(k);
					k->parent = p;
        	                        p->left = k;
                	        }
			}
                } else {
			 if (k==head) {
                                k=rotRL(k);
				head->parent = k;
				head = k;
head->parent = NULL;
                        } else {
				AvLNode<T>* p;
        	                p = k->parent;
				//k = rotRL(k);
				if (k==p->right) {
                                	k = rotRL(k);
					k->parent = p;
	                                p->right = k;
        	                } else {
                	                k = rotRL(k);
					k->parent = p;
                        	        p->left = k;
    		                }
			}
                }
	}
}


template<class T>
AvLNode<T>* AvL<T>::getHead()
{
	return head;
}

#endif
