#include "BST.h"

using namespace std;

template <class T>
BST<T>::BST() {
	head = NULL;
}

template <class T>
BST<T>::~BST() {
	cout << "destructor!" << endl;
	delete head;
}

template <class T>
bool BST<T>::insert(const T& element) {
	//cout << "in the insert function: " << element << endl;
	bool equal = false;
	if (head == NULL) {
		head = new Node<T>;
		head->value = element;
		head->right = head->left = NULL;
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
			temp->left = temp->right = NULL;
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
Node<T> *BST<T>::removeHelper(Node<T> *root, const T& data) {
	if(root == NULL)
		return root;
  	else if(data < root->value)
  		root->left = removeHelper(root->left,data);
  	else if(data > root->value)
  		root->right = removeHelper(root->right, data);
  	else {
    	// Case 1: No Child
    	if(root->left == NULL && root->right == NULL){
      		delete root;
      		root = NULL;
    	// Case 2: one child
    	} else if(root->left == NULL){
      		Node<T> *temp = root;
      		root = root->right;
      		temp->left = NULL;
      		temp->right = NULL;
      		delete temp;
    	} else if(root->right == NULL){
      		Node<T> *temp = root;
      		root = root->left;
      		temp->left = NULL;
      		temp->right = NULL;
      		delete temp;
      	// Case 3: two children
    	} else{
    		Node<T> *prev;
      		Node<T> * smallest = root->right;
			while (smallest->left != NULL) {
				prev = smallest;
				smallest = smallest->left;
			}
      		root->value = smallest->value;
      		prev->left = NULL;
      		smallest->left = NULL;
      		smallest->right = NULL;
      		delete smallest;
    }
  }
  return root;
}

template <class T>
bool BST<T>::remove(const T& element) {
	//cout << "in the remove function" << endl;
	head = removeHelper(head, element);
	return true;
}

template <class T>
bool BST<T>::find(const T& element) const {
	//cout << "in the find function" << endl;

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
	//cout << "in the display function" << endl;
	displayHelper(head);
	cout << endl;
}

template class BST<int>;
