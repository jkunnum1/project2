// libraries for timing functions
#include <chrono>
#include <ctime>
#include <ratio>

#include "BST.cpp"
using namespace std::chrono;

#define LOOP 10000

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
	int x = 15;
	int y = 2;
	int z = x / y;
	cout << z << endl;
	double elapsed_sec;
	for (int i = 0; i < 5; i++) {
		BST<int> test = makeBBST(LOOP);
		clock_t begin = clock();
		test.remove(LOOP / 2);
		clock_t end = clock();
		elapsed_sec += (double(end-begin) / CLOCKS_PER_SEC);
	}
	double average = elapsed_sec / 5;
	cout << "Looping average " << LOOP << " times took " << average << " seconds.";
	cout << endl;

	// BST<int> test2 = makeUBST(1000, 1);
	


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
	//Calculate time duration
	
	
	
	// function we are timing
	// In this example, we are timing how long it takes to loop 1000 times
	// for(int i=0; i<1000; i++)
	// {
	// 	cout << ". ";
	// }
	
	
	
	
	
	
	return 0;
}
