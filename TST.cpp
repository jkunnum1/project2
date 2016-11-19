#include "TST.h"

using namespace std;

template <class T>
TST<T>::TST()
{
	cout << "in the default constructor" << endl;
	head = NULL;
}

template <class T>
TST<T>::~TST() {
	delete head;
}


template <class T>
bool TST<T>::insert(const T& element)
{
	cout << "in the insert function" << endl;
	bool equal = false;
	// head is null
	if (head == NULL) {
		head = new NodeT<T>;
		head->min = element;
	}
	// head exists but only one value in there
	else if (!head->maxSet) {
		head->maxSet = true;
		if (element > head->min)
			head->max = element;
		else if (element < head->min){
			head->max = head->min;
			head->min = element;
		} else {
			cout << "value already exists" << endl;
			return false;
		}
	}
	// there are two values in the head
	else {
		NodeT<T> *temp = head;
		NodeT<T> *prev;
		while (temp) {
			prev = temp;
			// check if there is a right value
			if (!temp->maxSet) {
				temp->maxSet = true;
				if (element > temp->min)
					temp->max = element;
				else if (element < temp->min) {
					temp->max = temp->min;
					temp->min = element;
				} else {
					cout << "value already exists" << endl;
					return false;
				}
				break;
			}
			if (temp->min > element) {
				temp = temp->left;
			} else if ((temp->min < element) && (temp->max > element)) {
				temp = temp->middle;
			} else if (temp->max < element) {
				temp = temp->right;
			} else {
				equal = true;
				break;
			}
		}
		if (equal) {
			cout << "value already exists" << endl;
			return false;
		} else {
			temp = new NodeT<T>;
			temp->min = element;
			temp->left = temp->right = temp->middle = NULL;
			if (prev->min > temp->min) {
				prev->left = temp;
			} else if (prev->min < temp->min && prev->max > temp->min) {
				prev->middle = temp;
			} else if (prev->max < temp->min)
				prev->right = temp;
		}
	}
  	return true;
}

template <class T>
NodeT<T> *TST<T>::removeHelper(NodeT<T> *root, const T& data)
{
	if(root == NULL) {
		cout << "root is null" << endl;
		return root;
	}
	NodeT<T> *prev;
	NodeT<T> *removeNode = root;
	while (removeNode->min != data && removeNode->max !=data) {
		prev = removeNode;
		if (removeNode->min > data)
			removeNode = removeNode->left;
		else if (removeNode->min < data && (removeNode->maxSet && removeNode->max > data))
			removeNode = removeNode->middle;
		else if (removeNode->maxSet && removeNode->max < data)
			removeNode = removeNode->right;
		else
			cout << "the number was not found it the tree" << endl;
	}
	cout << "removed node min: " << removeNode->min << " and max: " << removeNode->max << endl;
  	
  	// if the node has only one valid value and no children
  	if (removeNode->maxSet == false) {
  		if (prev->min > data)
			prev->left = NULL;
		else if (prev->min < data && (prev->maxSet && prev->max > data))
			prev->middle = NULL;
		else if (prev->maxSet && prev->max < data)
			prev->right = NULL;
		delete removeNode;
		return root;
	}
	// if the node has 2 valid values and no children
	else if (removeNode->maxSet && (!removeNode->left && !removeNode->middle && !removeNode->right)) {
		if (removeNode->min == data) {
			removeNode->min = removeNode->max;
			removeNode->maxSet = false;
		} else {
			removeNode->maxSet = false;
		}
	}

  	return root;
}


template <class T>
bool TST<T>::remove(const T& element)
{
	cout << "in the remove function" << endl;
	head = removeHelper(head, element);

  	return true;
}


template <class T>
bool TST<T>::find(const T& data) const {
	cout << "in the find function" << endl;
	if(head == NULL) {
		cout << "root is null" << endl;
		return false;
	}
	NodeT<T> *root = head;
	while (root->min != data && root->max !=data) {
		if (root->min > data)
			root = root->left;
		else if (root->min < data && (root->maxSet && root->max > data))
			root = root->middle;
		else if (root->maxSet && root->max < data)
			root = root->right;
		else {
			cout << "the value was not found" << endl;
			return true;
		}

	}
	cout << "the value was found" << endl;
	return true;
}


template <class T>
void TST<T>::display() const {
	cout << "in the display function" << endl;
	displayHelper(head);
	cout << endl;
}

template <class T>
void TST<T>::displayHelper(NodeT<T> *node) const{
	if (node == NULL)
		return;
	displayHelper(node->left);
	cout << node->min << " ";
	displayHelper(node->middle);
	if (node->maxSet)
		cout << node->max << " ";
	displayHelper(node->right);
}

template class TST<int>;
