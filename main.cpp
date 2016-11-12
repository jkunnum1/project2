// libraries for timing functions
#include <chrono>
#include <ctime>
#include <ratio>

#include "BST.cpp"

template <typename T>
void helpermakeBBST(BST<T> &bst, T left, T right)
{
	//base case
	if(left > right)
	{
		return;
	}

	//get the middle value and make it the root
	T middle = (left + right)/2;
	// Node<T>* root = new Node<T>;
	bst.insert(middle);
	// root->value = middle;

	helpermakeBBST(bst, left, middle-1);
	helpermakeBBST(bst, middle+1, right);
	// root->left = helpermakeBBST(left, middle-1);
	// root->right = helpermakeBBST(middle+1, right);
	return;

}

// creates a balanced BST
template <typename T>
BST<T> makeBBST(T largest)
{
	cout << "making an balanced BST" << endl;
	BST<T> bst;

	// helpermakeBBST(BST<T>, start, end)
	helpermakeBBST(bst, 0, largest);

	return bst;
}

// creates an unbalanced BST
template <typename T>
BST<T> makeUBST(int size, T firstValue)
{
	cout << "making an unbalanced BST" << endl;
	BST<T> bst;
	T value = firstValue;

	// This generates a BST with ONLY right children because each node we are inserting
	// is always greater than the previous node inserted
	for(int i=0; i<size; i++)
	{
		Node<T> tempNode;
		tempNode.value = value;
		value++;

		bst.insert(value);
	}

	return bst;
}

int main(int argc, char const *argv[])
{

	// makeUBST(int size, T firstValue)
	// the purpose of inserting a first value is so that the function knows what
	// type of BST to return
	BST<int> test = makeBBST(1000);
	BST<int> test2 = makeUBST(1000, 1);
	//BBST.display();
	// BST<int> first;
	// int x = 5;
	// first.insert(x);
	// first.insert(3);
	// first.insert(3);
	// first.insert(8);
	// first.insert(8);
	// first.insert(10);
	// first.insert(1);
	// //first.remove(4);
	// first.display();
	// first.find(x);
	//
	// //Calculate time duration
	// using namespace std::chrono;
	//
	// steady_clock::time_point start = steady_clock::now();
	// // function we are timing
	// // In this example, we are timing how long it takes to loop 1000 times
	// for(int i=0; i<1000; i++)
	// {
	// 	cout << ". ";
	// }
	// steady_clock::time_point end = steady_clock::now();
	//
	// duration<double> totalTime = duration_cast< duration<double> >(end - start);
	//
	// cout << "Looping 1000 times took " << totalTime.count() << " seconds.";
	// cout << endl;
	//
	// return 0;
}
