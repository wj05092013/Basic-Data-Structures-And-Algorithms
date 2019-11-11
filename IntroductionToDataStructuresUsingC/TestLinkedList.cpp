#include "TestLinkedList.h"
#include "Print.h"

namespace test_linked_list
{
	void Test()
	{
		data_structure::LinkedList list;

		list.PushBack(2);
		std::cout << "PushBack(2)" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PushBack(43);
		std::cout << "PushBack(43)" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PushBack(22);
		std::cout << "PushBack(22)" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PushBack(5);
		std::cout << "PushBack(5)" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PushFront(11);
		std::cout << "PushFront(11)" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PushFront(9);
		std::cout << "PushFront(9)" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PushFront(15);
		std::cout << "PushFront(15)" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PopBack();
		std::cout << "PopBack()" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PopFront();
		std::cout << "PopFront()" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.PopFront();
		std::cout << "PopFront()" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;

		list.Clear();
		std::cout << "Clear()" << std::endl;
		print::PrintLinkedList(list); std::cout << std::endl << std::endl;
	}
}
