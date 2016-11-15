#ifndef TST_H
#define TST_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
struct NodeT {
	NodeT() : right(NULL), left(NULL), middle(NULL), maxSet(false) {}
	~NodeT() {
		if (right) {
			delete right;
		}
		if (middle) {
			delete middle;
		}
		if (left) {
			delete left;
		}
	}
	T min;
	T max;
	bool maxSet;
	NodeT *left;
	NodeT *middle;
	NodeT *right;

};

template <class T>
class TST {
private:
	NodeT<T> *head;

public:
	TST();
	bool insert(const T&);
	bool remove(const T&);
	bool find(const T&) const;
	void display() const; // inorder display
	void displayHelper(NodeT<T> *node) const;
	~TST();

};

#endif
