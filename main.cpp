// libraries for timing functions
//#include <chrono>
#include <ctime>
#include <ratio>

#include "BST.cpp"
#include "TST.cpp"
//using namespace std::chrono;

#define LOOP 60000

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
		bst.insert(value);
		value++;
	}

	return bst;
}

template <typename T>
void helpermakeBTST(TST<T> &tst, T left, T right)
{
	// if(left > right || left == right)// base case
	// {
	// 	return;
	// }
	if(right - left < 3) // this means you can't divide by 3 anymore
	{
		//cout << "BASECASE" << endl;

		tst.insert(left);
		//cout << "inserted: " << left << endl;
		tst.insert(right);
		//cout << "inserted: " << right << endl;

		if(right - left == 2) // there is a middle value?
		{
				tst.insert(left + 1);
				//cout << "inserted: " << left + 1 << endl;
		}
		return;
	}

	// get the range of the root node
	T mleft  = left + (right - left)/3;
	T mright = left + 2*((right - left)/3);

	// cout << "left: " << left << endl;
	// cout << "mleft: " << mleft << endl;
	// cout << "mright " << mright << endl;
	// cout << "right: " << right << endl;

	// inserted into root node
	tst.insert(mleft);
	//cout << "inserted: " << mleft << endl;
	tst.insert(mright);
	//cout << "inserted: " << mright << endl;

	// make left subtree
	helpermakeBTST(tst, left, mleft-1);
	// make middle subtree
	helpermakeBTST(tst, mleft+1, mright -1);
	// make right subtree
	helpermakeBTST(tst, mright+1, right);

	return;

}

// creates an unbalanced TST
template <typename T>
TST<T> makeUTST(int size, T firstValue)
{
		cout << "Making unbalanced TST" << endl;

		T value = firstValue;
		TST<T> tst;

		for(int i=0; i<=size; i++)
		{
			tst.insert(value);
			value++;
		}

		return tst;
}

// creates a balanced TST
template <typename T>
TST<T> makeBTST(T largest)
{
		cout << "Making a balanced TST" << endl;
		TST<T> tst;

		// helpermakeBTST(left, right, tst);
		helpermakeBTST(tst, 0, largest);

		return tst;
}

int main(int argc, char const *argv[])
{

	// Ternary Search Tree

	double elapsed_sec_remove = 0.0;
	double elapsed_sec_insert = 0.0;
	double elapsed_sec_find = 0.0;

	for (int i = 0; i < 1; i++) {
		clock_t begin_i = clock();
		TST<int> test = makeBTST(LOOP);
		clock_t end_i = clock();

		clock_t begin_f = clock();
		test.find(LOOP);
		clock_t end_f = clock();

		clock_t begin_r = clock();
		test.remove(LOOP / 2);
		clock_t end_r = clock();
		elapsed_sec_remove += (double(end_r-begin_r) / CLOCKS_PER_SEC);
		elapsed_sec_insert += (double(end_i-begin_i) / CLOCKS_PER_SEC);
		elapsed_sec_find += (double(end_f-begin_f) / CLOCKS_PER_SEC);
		cout << "AT THE END OF THE " << i << " LOOP" << endl;
	}

	double average = elapsed_sec_insert;
	cout << "Looping average insert " << LOOP << " times took " << average << " seconds." << endl;
	average = elapsed_sec_find;
	cout << "Looping average find " << LOOP << " times took " << average << " seconds." << endl;
	average = elapsed_sec_remove;
	cout << "Looping average remove " << LOOP << " times took " << average << " seconds." << endl;



	// TST<int> test = makeBTST(10000);
	// test.display();
	//
	// // makeUTST(size, firstValue)
	// TST<int> test2 = makeUTST(10000, 0);
	// test2.display();
	//
	// clock_t begin_i = clock();
	// test.insert(10002);
	// clock_t end_i = clock();
	// cout << "insert balanced: " << (double(end_i-begin_i) / CLOCKS_PER_SEC) << endl;
	//
	// begin_i = clock();
	// test2.insert(10002);
	// end_i = clock();
	// cout << "insert unbalanced: " << (double(end_i-begin_i) / CLOCKS_PER_SEC) << endl;


	// makeUBST(int size, T firstValue)
	// the purpose of inserting a first value is so that the function knows what
	// type of BST to return
	// double elapsed_sec_remove = 0.0;
	// double elapsed_sec_insert = 0.0;
	// double elapsed_sec_find = 0.0;
	// for (int i = 0; i < 1; i++) {
	// 	clock_t begin_i = clock();
	// 	BST<int> test = makeUBST(LOOP, 0);
	// 	clock_t end_i = clock();
	//
	// 	clock_t begin_f = clock();
	// 	test.find(LOOP);
	// 	clock_t end_f = clock();
	//
	// 	clock_t begin_r = clock();
	// 	test.remove(LOOP / 2);
	// 	clock_t end_r = clock();
	// 	elapsed_sec_remove += (double(end_r-begin_r) / CLOCKS_PER_SEC);
	// 	elapsed_sec_insert += (double(end_i-begin_i) / CLOCKS_PER_SEC);
	// 	elapsed_sec_find += (double(end_f-begin_f) / CLOCKS_PER_SEC);
	// 	cout << "AT THE END OF THE " << i << " LOOP" << endl;
	// }
	// //cout << "ssdlkjfslkfgj" << endl;
	// double average = elapsed_sec_insert;
	// cout << "Looping average insert " << LOOP << " times took " << average << " seconds." << endl;
	// average = elapsed_sec_find;
	// cout << "Looping average find " << LOOP << " times took " << average << " seconds." << endl;
	// average = elapsed_sec_remove;
	// cout << "Looping average remove " << LOOP << " times took " << average << " seconds." << endl;


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



	// TST<int> test;
	// test.insert(1);
	// test.insert(4);
	// test.insert(3);
	// test.insert(5);
	// test.insert(8);
	// test.display();


	return 0;
}
