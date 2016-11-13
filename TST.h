#ifndef TST_H
#define TST_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
struct NodeT {
	NodeT() : right(NULL), left(NULL), middle(NULL) {}
	T value;

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

};

#endif
