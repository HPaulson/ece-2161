#ifndef __intDLList
#define _intDLList
#include "intDLLNode.h"

enum PrintListOrder {
	headToTail,
	tailToHead
};

// Doubly Linked List for Integers
class intDLList {
public:
	intDLList();
	~intDLList();
	bool isEmpty();
	bool hasOneItem();
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int);
	void addSorted(int);
	void printlist(PrintListOrder);
private:
	intDLLNode *head, *tail;

};
#endif
