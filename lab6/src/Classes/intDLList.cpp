#include <iostream>
#include "intDLList.h"
#include "../errors.h"
using namespace std;

intDLList::intDLList() { head=tail=nullptr; };

intDLList::~intDLList() {
	// Loop through all of the nodes & free them from memory
	for (intDLLNode *p; !isEmpty(); head = p) {
		p = head->next;
		delete head;
	}
}
bool intDLList::isEmpty() { return head == nullptr;};

// This method is very useful even though it isn't in the lab instructions.
bool intDLList::hasOneItem() { return head == tail;};

void intDLList::addToHead(int el) {
	if (isEmpty()) head = tail = new intDLLNode(el); // Just create a node with null next and prev, and this is the head and tail
	else {
		// Otherwise create a new head node & update existing head to have a correct prev ptr
		head = new intDLLNode(el, head, nullptr);
		head->next->prev = head;
	}
};

void intDLList::addToTail(int el) {
	// Create a new node with tail prev and null next pointers
	tail = new intDLLNode(el, nullptr, tail);

	if (isEmpty()) head=tail; // If the list is empty, the existing tail ptr is null, so the above will suffice in creating the node. Just need set head and tail.
	else {
		// Otherwise, update the existing tail's next pointer, since this node is now tail-1
		tail->prev->next = tail;
	}
};

int intDLList::deleteFromHead()  {
	if (isEmpty()) throw DELETE_FROM_HEAD_IS_EMPTY;
	int el = head->info;

	if (hasOneItem()) {
		// The one item is the head, now list is empty
		delete head;
		head = tail = nullptr;
	}
	else {
		// Reassign head to head+1
		head = head->next;
		delete head->prev; // Head is now head+1, so head->prev is the previous head we are deleting
		head->prev = nullptr; // Set the new head's prev to nullptr, since we expect the head node to have null prev ptr
	}
	return el;
};

int intDLList::deleteFromTail()  {
	if (isEmpty()) throw DELETE_FROM_TAIL_IS_EMPTY;
		int el = tail->info;
		if (head  == tail) {
			delete tail;
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;

		}
		return el;
};

void intDLList::deleteNode(int el)  {
	if (!isEmpty()) {
		if (hasOneItem() && head->info == el) {
			delete head;
			head = tail = nullptr;
			return;
		}
		else {
			intDLLNode* tmp = head;
			// Search through entire list looking for el
			while (tmp->info != el && tmp != tail) {
				tmp = tmp->next;
			}
			if (tmp->info == el) {
				if (tmp != tail) tmp->next->prev = tmp->prev;
				else tail = tmp->prev;

				if (tmp != head) tmp->prev->next = tmp->next;
				else head = tmp->next;

				delete tmp;

			}

			return;
		}
	}
};

bool intDLList::isInList(int el)  {
	if (isEmpty()) return false;
	else if (hasOneItem()) return head->info == el;

	intDLLNode* tmp = head;
	// Search for el in all nodes until tail is reached
	while (tmp->info != el && tmp != tail) {
			tmp = tmp->next;
	}
	if (tmp->info == el) return true;
	else return false;
};


void intDLList::addSorted(int el) {
	// If empty, just add the node; it will be sorted by definition
	if (isEmpty()) head=tail=new intDLLNode(el);
	// If it has only one item, simply check if el > that item or < that item, and insert left/right accordingly
	else if (hasOneItem()) {
		if (head->info < el) addToTail(el);
		else addToHead(el);
	}
	else {
		intDLLNode* tmp = head;
		// Move the temp pointer to a node with info >= el, or until we hit the tail.
		while (tmp->info < el && tmp != tail) {
			tmp = tmp->next;
		}
		// If we found a node with info >= el (We didn't just stop the loop because tmp == tail)
		// We will insert our new node in the position just before our tmp pointer
		if (tmp->info >= el) {
			intDLLNode* ptr = new intDLLNode(el, tmp, tmp->prev);
			if (tmp->prev == nullptr) {
				// If the tmp node we found is the current head, reassign head
				head = ptr;
			}
			// Otherwise, reassign the tmp's previous node's next point to temp
			else tmp->prev->next = ptr;
			tmp->prev = ptr; // In any case, reassign tmp's prev field
		}
		// We stopped looping because no elements were >= el, so add it to the tail
		else {
			addToTail(el);
		}
	}
};

// Prints every node in the list head-to-tail or tail-to-head.
void intDLList::printlist(PrintListOrder order) {
	if (isEmpty()) cout << "List is empty." << endl;
	else {
		if (order == headToTail) {
			intDLLNode* tmp = head;
			while (tmp != nullptr) {
				cout << tmp->info << " ";
				tmp = tmp->next;
			}
		}
		else if (order == tailToHead) {
			intDLLNode* tmp = tail;
			while (tmp != nullptr) {
				cout << tmp->info << " ";
				tmp = tmp->prev;
			}
		}

		cout << endl;

	}

};

