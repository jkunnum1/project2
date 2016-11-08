#include "BST.cpp"

int main(int argc, char const *argv[])
{
	BST<int> first;
	int x = 5;
	first.insert(x);
	first.remove(4);
	first.display();
	first.find(x);
	return 0;
}