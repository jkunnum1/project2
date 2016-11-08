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
	bool equal = false;
	if (head == NULL) {
		head = new Node<T>;
		head->value = element;
	} else {
		Node<T> *temp = head;
		Node<T> *prev;
		while (temp) {
			prev = temp;
			if (temp->value > element) {
				temp = temp->left;
			} else if (temp->value < element) {
				temp = temp->right;
			} else {
				equal = true;
				break;
			}
		}
		if (!equal) {
			temp = new Node<T>;
			temp->value = element;
			if (prev->value > temp->value) {
				prev->left = temp;
			}
			if (prev->value < temp->value) {
				prev->right = temp;
			}
		} else {
			cout << "value already exists" << endl;
			return false;
		}
	}
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