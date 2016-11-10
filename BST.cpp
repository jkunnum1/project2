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
	if (head == NULL) {
		cout << "no valid in the tree" << endl;
		return false;
	}
	else {
		Node<T> *temp = head;
		Node<T> *prev;
		while (temp) {
			
			if (temp->value > element) {
				prev = temp;
				temp = temp->left;
				
			} else if (temp->value < element) {
				prev = temp;
				temp = temp->right;

			} else {
				break;
			}
		}
		cout << "temp: " << temp->value << "   prev: " << prev->value << endl;
		// if the node has one or less children
		if (temp->left == NULL) {
			if (prev->value > temp->value) {
				prev->left = temp->right;
				delete temp;
			} else if (prev->value < temp->value) {
				prev->right = temp->right;
				delete temp;
			}
		} else if (temp->right == NULL) {
			if (prev->value > temp->value) {
				prev->left = temp->left;
				delete temp;
			} else if (prev->value < temp->value) {
				prev->right = temp->left;
				delete temp;
			}
		}
		// now the case that are 2 children
		// need to find the minimum value node and put that in place 
		else {
			Node<T> * smallest = temp;
			while (smallest->left != NULL) {
				smallest = smallest->left;
			}
			// now smallest has the smallest value of the tree after the node
			// that is being removed
			if (prev->value < temp->value) {
				if (temp->left != smallest)
					smallest->left = temp->left;
				else
					smallest->left = NULL;
				smallest->right = temp->right;
				prev->right = smallest;
				delete temp;
			} else if (prev->value > temp->value) {
				if (temp->left != smallest)
					smallest->left = temp->left;
				else
					smallest->left = NULL;
				smallest->right = temp->right;
				prev->left = smallest;
				delete temp;
			}

		}
	}
   	return true;
}

template <class T>
bool BST<T>::find(const T& element) const {
	cout << "in the find function" << endl;

	bool found = false;

	if (head == NULL) // empty tree
	{
		return false;
	}
	else
	{
		Node<T> *temp = head;

		while (temp)
		{
			if (temp->value > element)
			{
				temp = temp->left;
			}
			else if (temp->value < element)
			{
				temp = temp->right;
			}
			else
			{
				found = true;
				break;
			}
		}
	}

	return found;

}

template <class T>
void BST<T>::displayHelper(Node<T> *node) const{
	if (node == NULL)
		return;
	displayHelper(node->left);
	cout << node->value << " ";
	displayHelper(node->right);
}

template <class T>
void BST<T>::display() const {
	cout << "in the display function" << endl;
	displayHelper(head);
	cout << endl;
}

template class BST<int>;