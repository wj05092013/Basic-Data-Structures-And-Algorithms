#include "TestPriorityQueue.h"
#include "Print.h"

namespace test_priority_queue
{
	void Test()
	{
		std::cout << "//////////////////////////////" << std::endl;
		std::cout << "// Min-Heap Priority Queue  //" << std::endl;
		std::cout << "//////////////////////////////" << std::endl << std::endl;

		//
		// Init
		//

		std::cout << "Create" << std::endl;
		data_structure::PriorityQueue<> prque;
		std::cout << "Capacity(): " << prque.Capacity() << std::endl << std::endl;

		//
		// Reserve
		//

		std::cout << "Reserve(2)" << std::endl;
		prque.Reserve(2);
		std::cout << "Capacity(): " << prque.Capacity() << std::endl;
		std::cout << "Size(): " << prque.Size() << std::endl << std::endl;

		//
		// Push
		//

		std::vector<int> arr{ 13,10,2,2,-5,-1,9,0,19,16,7,2,2,2,6,5,-11,-12,21,17 };

		std::cout << "Push(): ";
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
			prque.Push(arr[i]);
		}
		std::cout << std::endl;
		std::cout << "Size(): " << prque.Size() << std::endl << std::endl;

		//
		// Top & Pop
		//

		std::cout << "Top(): ";
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << prque.Top() << " ";
			arr[i] = prque.Pop();
		}
		std::cout << std::endl;
		std::cout << std::endl;

		//
		// After Pop
		//

		std::cout << "Pop(): ";
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Size(): " << prque.Size() << std::endl << std::endl;

		//
		// Push Again
		//

		std::cout << "Push(): ";
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
			prque.Push(arr[i]);
		}
		std::cout << std::endl;
		std::cout << "Size(): " << prque.Size() << std::endl << std::endl;

		//
		// Iterator
		//

		std::cout << "Begin() ~ End()" << std::endl;
		for (auto iter = prque.Begin(); iter != prque.End(); ++iter)
		{
			std::cout << *iter << " ";
		}
		std::cout << std::endl << std::endl;

		//
		// Clear
		//

		std::cout << "Clear()" << std::endl;
		prque.Clear();
		std::cout << "Size(): " << prque.Size() << std::endl << std::endl << std::endl;


		std::cout << "//////////////////////////////" << std::endl;
		std::cout << "// Max-Heap Priority Queue  //" << std::endl;
		std::cout << "//////////////////////////////" << std::endl << std::endl;

		//
		// Init
		//

		std::cout << "Create" << std::endl;
		data_structure::PriorityQueue<algorithm::compare::Greater<int>> prque_max;
		std::cout << "Capacity(): " << prque_max.Capacity() << std::endl << std::endl;

		//
		// Push
		//

		std::cout << "Push(): ";
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
			prque_max.Push(arr[i]);
		}
		std::cout << std::endl;
		std::cout << "Size(): " << prque_max.Size() << std::endl << std::endl;

		//
		// Top & Pop
		//

		std::cout << "Top(): ";
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << prque_max.Top() << " ";
			arr[i] = prque_max.Pop();
		}
		std::cout << std::endl;
		std::cout << std::endl;

		//
		// After Pop
		//

		std::cout << "Pop(): ";
		for (size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Size(): " << prque_max.Size() << std::endl << std::endl;

		//
		// Clear
		//

		std::cout << "Clear()" << std::endl;
		prque_max.Clear();
		std::cout << "Size(): " << prque_max.Size() << std::endl << std::endl << std::endl;
	}
}
