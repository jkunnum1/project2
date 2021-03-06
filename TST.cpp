#include "TST.h"

using namespace std;

template <class T>
TST<T>::TST()
{
	//cout << "in the default constructor" << endl;
	head = NULL;
}

template <class T>
TST<T>::~TST() {
	delete head;
			// delete head->left;
			// delete head->middle;
			// delete head->right;
}


template <class T>
bool TST<T>::insert(const T& element)
{
	//cout << "in the insert function" << endl;
	bool equal = false;
	bool inserted = false;
	// head is null
	if (head == NULL) {
		head = new NodeT<T>;
		head->min = element;
	}
	// head exists but only one value in there
	else if (!head->maxSet) {
		//head->maxSet = true;
		if (element > head->min)
			head->max = element;
		else if (element < head->min){
			head->max = head->min;
			head->min = element;
		} else {
			//cout << "value already exists" << endl;
			return false;
		}
		head->maxSet = true;
	}
	// there are two values in the head
	else {
		NodeT<T> *temp = head;
		NodeT<T> *prev;
		while (temp) {
			if (temp->maxSet)
				prev = temp;
			// check if there is a right value
			if (!temp->maxSet) {
				//temp->maxSet = true;
				if (element > temp->min)
					temp->max = element;
				else if (element < (temp->min)) {
					temp->max = temp->min;
					temp->min = element;
				} else {
					//cout << "value already exists" << endl;
					return false;
				}
				temp->maxSet = true;
				inserted = true;
				break;
			}
			if (element < (temp->min)) {
				temp = temp->left;
			} else if (element > (temp->min) && element < (temp->max)) {
				temp = temp->middle;
			} else if (element > (temp->max)) {
				temp = temp->right;
			} else {
				equal = true;
				break;
			}
		}
		if (equal) {
			//cout << "value already exists" << endl;
			return false;
		} else  {
			if (!inserted) {
				temp = new NodeT<T>;
				temp->min = element;
				temp->left = temp->right = temp->middle = NULL;
				temp->maxSet = false;
				if ((prev->min) > (temp->min)) {
					prev->left = temp;
				} else if ((prev->min) < (temp->min) && (prev->max) > (temp->min)) {
					prev->middle = temp;
				} else if ((prev->max) < (temp->min))
					prev->right = temp;
			}
		}
	}
  	return true;
}

template <class T>
void TST<T>::removeMax(NodeT<T> *root, NodeT<T> *prev, const T& data) {
	NodeT<T> *temp = root;
	if (root->right) {
		prev = temp;
		temp = temp->right;
		while (temp->left) {
			prev = temp;
			temp = temp->left;
		}
		// you are at the right most node. Get the higher value
		if (temp->maxSet) {
			root->max = temp->min;
			if (temp->right || temp->middle)
				removeMin(temp, prev, temp->min);
			else{
				temp->min = temp->max;
				temp->maxSet = false;
			}
		} else {
			root->max = temp->min;
			if (prev->right == temp)
				prev->right = NULL;
			if (prev->left == temp)
				prev->left = NULL;
			delete temp;
		}
	} else if (root->middle) {
		prev = temp;
		temp = temp->middle;
		while (temp->right) {
			prev = temp;
			temp = temp->right;
		}
		// you are at the left most node. get the lower value
		if (temp->maxSet) {
			root->max = temp->max;
			if (temp->middle || temp->right)
				removeMin(temp, prev, temp->max);
			else {
				temp->max = temp->max;
				temp->maxSet = false;
			}
		} else {
			root->max = temp->min;
			if (prev->middle == temp)
				prev->middle = NULL;
			if (prev->left == temp)
				prev->left = NULL;
			delete temp;
		}
	} else if (root->left) {
		prev = temp;
		temp = temp->left;
		while (temp->right) {
			prev = temp;
			temp = temp->right;
		}
		// you are at the left most node. get the lower value
		if (temp->maxSet) {
			root->max = temp->max;
			if (temp->middle || temp->right)
				removeMin(temp, prev, temp->max);
			else {
				temp->max = temp->max;
				temp->maxSet = false;
			}
		} else {
			root->max = temp->min;
			if (prev->middle == temp)
				prev->middle = NULL;
			if (prev->left == temp)
				prev->left = NULL;
			//if(prev->right = temp)

			delete temp;
		}
	// this is the case where there are no subtrees
	} else {
		if (root->maxSet) {
			root->min = root->max;
			root->maxSet = false;
		} else {
			if (prev->left == root)
				prev->left = NULL;
			else if (prev->middle == root)
				prev->middle = NULL;
			else if (prev->right == root)
				prev->right = NULL;
			delete root;
		}
	}
}

template <class T>
void TST<T>::removeMin(NodeT<T> *root, NodeT<T> *prev, const T& data) {
	NodeT<T> *temp = root;
	if (root->left) {
		prev = temp;
		temp = temp->left;
		while (temp->right) {
			prev = temp;
			temp = temp->right;
		}
		// you are at the right most node. Get the higher value
		if (temp->maxSet) {
			root->min = temp->max;
			if (temp->left || temp->middle)
				removeMax(temp, prev, temp->max);
			else
				temp->maxSet = false;
		} else {
			root->min = temp->min;
			if (prev->right == temp)
				prev->right = NULL;
			if (prev->left == temp)
				prev->left = NULL;
			delete temp;
		}
	} else if (root->middle) {
		prev = temp;
		temp = temp->middle;
		while (temp->left) {
			prev = temp;
			temp = temp->left;
		}
		// you are at the left most node. get the lower value
		if (temp->maxSet) {
			root->min = temp->min;
			if (temp->middle || temp->right)
				removeMin(temp, prev, temp->min);
			else {
				temp->min = temp->max;
				temp->maxSet = false;
			}
		} else {
			//cout << "no max value " << endl;
			root->min = temp->min;
			if (prev->middle == temp) {
				//cout << "middle pointer" << endl;
				prev->middle = NULL;
			}
			if (prev->left == temp)
				prev->left = NULL;
			delete temp;
		}
	} else if (root->right) {
		prev = temp;
		temp = temp->right;
		while (temp->left) {
			prev = temp;
			temp = temp->left;
		}
		//you are at the left most node. get the lower value
		if (temp->maxSet) {
			root->min = temp->min;
			if(root->min > root->max) // out of order! must swap
			{
				T swap = root->min;
				root->min = root->max;
				root->max = swap;
			}
			if (temp->middle || temp->right)
				removeMin(temp, prev, temp->min);
			else {
				temp->min = temp->max;
				temp->maxSet = false;
			}
		} else {
			root->min = temp->min;
			if(root->min > root->max) // out of order! must swap
			{
				T swap = root->min;
				root->min = root->max;
				root->max = swap;
			}
			if (prev->middle == temp)
				prev->middle = NULL;
			if (prev->left == temp)
				prev->left = NULL;
			if(prev->right == temp)
				prev->right = NULL;
			delete temp;
		}
	// this is the case where there are no subtrees
	} else {
		if (root->maxSet) {
			root->min = root->max;
			root->maxSet = false;
		} else {
			if (prev->left == root)
				prev->left = NULL;
			else if (prev->middle == root)
				prev->middle = NULL;
			else if (prev->right == root)
				prev->right = NULL;
			delete root;
		}
	}
}

template <class T>
NodeT<T> *TST<T>::removeHelper(NodeT<T> *root, const T& data)
{
	if(root == NULL) {
		//cout << "root is null" << endl;
		return root;
	}
	NodeT<T> *prev;
	NodeT<T> *removeNode = root;

	// // removeNode will point to the node which holds the value we want to remove
	while (removeNode->min != data && removeNode->max !=data) {
		prev = removeNode;
		if (removeNode->min > data)
			removeNode = removeNode->left;
		else if (data > (removeNode->min) && (removeNode->maxSet) && data < (removeNode->max))
			removeNode = removeNode->middle;
		else if ((removeNode->maxSet) && data > (removeNode->max))
			removeNode = removeNode->right;
		else
			cout << "the number was not found it the tree" << endl;
	}

  	if (removeNode->min == data) {
  		removeMin(removeNode, prev, data);
  	}
  	else {
  		removeMax(removeNode, prev, data);
  	}

  	return root;
}


template <class T>
bool TST<T>::remove(const T& element)
{
	//cout << "in the remove function" << endl;

	if(!find(element)) {
		return false;
	} else {
			head = removeHelper(head, element);
	}

  return true;
}


template <class T>
bool TST<T>::find(const T& data) const {
	//cout << "in the find function" << endl;
	bool found = false;

	if(head == NULL) {
		//cout << "root is null" << endl;
		return false;
	} else {

		NodeT<T> *root = head;

		while(root){
			if (root->min > data)
				root = root->left;
			else if (data > (root->min) && (root->maxSet) && data < (root->max))
				root = root->middle;
			else if ((root->maxSet) && data > (root->max))
				root = root->right;
			else if(root->min == data || root->max == data) {
				found = true;
				break;
			} else {
				cout << "Node was not found." << endl;
				break;
			}
		}

	}

	return found;

	// while (root->min != data && root->max !=data) {
	// 	if (root->min > data)
	// 		root = root->left;
	// 	else if (data > (root->min) && (root->maxSet) && data < (root->max))
	// 		root = root->middle;
	// 	else if ((root->maxSet) && data > (root->max))
	// 		root = root->right;
	// 	else {
	// 		cout << "the value was not found" << endl;
	// 		return false;
	// 	}
	//
	// }
	//cout << "the value was found" << endl;
	//return found;
}


template <class T>
void TST<T>::display() const {
	//cout << "in the display function" << endl;
	displayHelper(head);
	cout << endl;
}

template <class T>
void TST<T>::displayHelper(NodeT<T> *node) const{
	if (node == NULL) {
		return;
	}
	//cout << "node min: " << node->min << " node max: " << node->max << endl;
	displayHelper(node->left);
	cout << node->min << " ";
	displayHelper(node->middle);
	if (node->maxSet)
		cout << node->max << " ";
	displayHelper(node->right);
}

template class TST<int>;
