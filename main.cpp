// libraries for timing functions
#include <chrono>
#include <ctime>
#include <ratio>

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

	//Calculate time duration
	using namespace std::chrono;

	steady_clock::time_point start = steady_clock::now();
	// function we are timing
	// In this example, we are timing how long it takes to loop 1000 times
	for(int i=0; i<1000; i++)
	{
		cout << ". ";
	}
	steady_clock::time_point end = steady_clock::now();

	duration<double> totalTime = duration_cast< duration<double> >(end - start);

	cout << "Looping 1000 times took " << totalTime.count() << " seconds.";
	cout << endl;

	return 0;
}
