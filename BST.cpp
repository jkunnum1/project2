#include "BST.h"

using namespace std;

template <class T>
BST<T>::BST() {
	cout << "in the default constructor" << endl;
	head = NULL;
}

template <class T>
bool BST<T>::insert(const T& element) {
	cout << "in the insert function" << endl;
   	return true;
}

template <class T>
bool BST<T>::remove(const T& element) {
	cout << "in the remove function" << endl;
   	return true;
}

template <class T>
bool BST<T>::find(const T& element) const {
	cout << "in the find function" << endl;
   	return true;
}

template <class T>
void BST<T>::display() const {
	cout << "in the display function" << endl;
}

template class BST<int>;