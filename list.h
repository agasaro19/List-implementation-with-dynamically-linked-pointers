#ifndef LIST_H
#define LIST_H
#include<map>
#include"node.h"

class List {
	int capacity;
	int length;
	Node * front;			// first in list or NULL if empty
	Node * back;			// last in list or NULL if empty
			 
public:
	List();
	List(int size);		// optional
	~List();
	int Insert(int payload);
	int Remove(int payload);
	void Print();
	void ReversePrint();	// optional

};
#endif