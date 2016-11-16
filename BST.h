#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
struct Node {
	T value;
	Node *right;
	Node *left;

	Node() : right(NULL), left(NULL) {}
	~Node() {
		if (right) {
			cout << "delete right wow! omg" << endl;
			delete right;
		}
		if (left) {
			cout << "delete left woohoehehj" << endl;
			delete left;
		}
	}
};

template <class T>
class BST {
private:
	Node<T> *head;
public:
	BST();
	bool insert(const T&);
	bool remove(const T&);
	Node<T> *removeHelper(Node<T> *root, const T&);
	bool find(const T&) const;
	void display() const; // inorder display
	void displayHelper(Node<T> *node) const;
	~BST();
};

#endif
