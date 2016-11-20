#ifndef TST_H
#define TST_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
struct NodeT {
	NodeT() : right(NULL), left(NULL), middle(NULL), maxSet(false) {}
	
	T min;
	T max;
	bool maxSet;
	NodeT *left;
	NodeT *middle;
	NodeT *right;
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
};

template <class T>
class TST {
private:
	NodeT<T> *head;

public:
	TST();
	bool insert(const T&);
	bool remove(const T&);
	NodeT<T> *removeHelper(NodeT<T> *root, const T& element);
	void removeMin(NodeT<T> *root, NodeT<T> *prev, const T& data);
	void removeMax(NodeT<T> *root, NodeT<T> *prev, const T& data);
	bool find(const T&) const;
	void display() const; // inorder display
	void displayHelper(NodeT<T> *node) const;
	~TST();

};

#endif
