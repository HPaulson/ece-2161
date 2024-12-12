#ifndef _intDLLNode
#define _intDLLNode

// Node class for the intDLList
class intDLLNode {
	friend class intDLList;
	public:
	intDLLNode(int el = 0, intDLLNode *n = nullptr, intDLLNode *p = nullptr) {
		info = el;
		next = n;
		prev = p;
	};
	protected:
		int info;
		intDLLNode *next, *prev;
};
#endif
