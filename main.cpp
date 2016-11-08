#include "BST.cpp"

int main(int argc, char const *argv[])
{
	BST<int> first;
	int x = 5;
	first.insert(x);
	first.insert(3);
	first.insert(3);
	first.insert(8);
	first.insert(8);
	first.insert(10);
	first.insert(1);
	first.remove(4);
	first.display();
	first.find(x);
	return 0;
}