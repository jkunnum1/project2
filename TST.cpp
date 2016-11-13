#include "TST.h"

using namespace std;

template <class T>
TST<T>::TST()
{
	cout << "in the default constructor" << endl;
	head = NULL;
}

template <class T>
bool TST<T>::insert(const T& element)
{
	cout << "in the insert function" << endl;
	// bool equal = false;

	// if(head == NULL)
	// {
	// 		head = new NodeT<T>;
	// 		head->value = element;
	// 		cout << "Root: " << element << endl;
	// 		return true;
	// }
	// else
	// {
	// 		NodeT<T>* temp = head;
	// 		NodeT<T>* prev;
	//
	// 		while(temp)
	// 		{
	// 			prev = temp;
	//
	// 			if(temp->left !=NULL && temp->right !=NULL)
	// 			{
	// 				if(element > temp->left->value && element < temp->right->value)
	// 				{
	// 					cout << element << " goes to the middle" << endl;
	// 					temp = temp->middle;
	// 				}
	// 				else if(element < temp->value)
	// 				{
	// 					cout << element << " goes to the left" << endl;
	// 					temp = temp->left;
	// 				}
	// 				else if(element > temp->value)
	// 				{
	// 					cout << element << " goes to the right" << endl;
	// 					temp = temp->right;
	// 				}
	// 				else
	// 				{
	// 					equal = true;
	// 					break;
	// 				}
	// 			}
	// 			else if(element < temp->value)
	// 			{
	// 				cout << element << " goes to the left" << endl;
	// 				temp = temp->left;
	// 			}
	// 			else if(element > temp->value)
	// 			{
	// 				cout << element << " goes to the right" << endl;
	// 				temp = temp->right;
	// 			}
	// 			else
	// 			{
	// 				equal = true;
	// 				break;
	// 			}
	// 		}
	//
	// 		if(!equal)
	// 		{
	// 			temp = new NodeT<T>;
	// 			temp->value = element;
	//
	// 			if(temp->value < prev->value)
	// 			{
	// 					if(prev->left == NULL)
	// 					{
	// 						cout << "inserted " << element << " on the left" << endl;
	// 						prev->left = temp;
	// 					}
	// 					else
	// 					{
	// 						cout << "inserted " << element << " on the middle" << endl;
	// 						prev->middle = temp;
	// 					}
	// 			}
	// 			else if(temp->value > prev->value)
	// 			{
	// 				if(prev->right == NULL)
	// 				{
	// 					cout << "inserted " << element << " on the right" << endl;
	// 					prev->right = temp;
	// 				}
	// 				else
	// 				{
	// 						prev->middle = temp;
	// 						cout << "inserted " << element << " on the middle" << endl;
	// 				}
	// 			}
	// 		}
	// 		else
	// 		{
	// 			cout << "value already exists!" << endl;
	// 			return false;
	// 		}
	// }

  return true;
}

template <class T>
bool TST<T>::remove(const T& element)
{
	cout << "in the remove function" << endl;
  return true;
}

template <class T>
bool TST<T>::find(const T& element) const
{
	cout << "in the find function" << endl;
  return true;
}

template <class T>
void TST<T>::display() const
{
	cout << "in the display function" << endl;
}

template class TST<int>;
