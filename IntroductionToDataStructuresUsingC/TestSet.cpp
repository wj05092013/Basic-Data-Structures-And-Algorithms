#include "TestSet.h"
#include "Print.h"

namespace test_set
{
	void Test()
	{
		data_structure::Set set;

		//
		// Insert
		//

		set.Insert(3);
		std::cout << "Insert(3)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(10);
		std::cout << "Insert(10)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(-5);
		std::cout << "Insert(-5)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(2);
		std::cout << "Insert(2)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(8);
		std::cout << "Insert(8)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(6);
		std::cout << "Insert(6)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(13);
		std::cout << "Insert(13)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(43);
		std::cout << "Insert(43)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(50);
		std::cout << "Insert(50)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(-31);
		std::cout << "Insert(-31)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(39);
		std::cout << "Insert(39)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(28);
		std::cout << "Insert(28)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		//
		// Erase
		//

		set.Erase(43);
		std::cout << "Erase(43)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Erase(8);
		std::cout << "Erase(8)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Erase(13);
		std::cout << "Erase(13)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Erase(20);
		std::cout << "Erase(20)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		//
		// Find
		//

		print::PrintSet(set); std::cout << std::endl;
		data_structure::ConstSetIterator iter = set.Find(2);
		std::cout << "Find(2): " << *iter << std::endl;
		std::cout << "++iter: " << *(++iter) << std::endl;
		std::cout << "iter++: " << *(iter++) << std::endl;
		std::cout << "*iter: " << *iter << std::endl << std::endl;

		print::PrintSet(set); std::cout << std::endl;
		iter = set.Find(28);
		std::cout << "Find(28): " << *iter << std::endl;
		std::cout << "--iter: " << *(--iter) << std::endl;
		std::cout << "iter--: " << *(iter--) << std::endl;
		std::cout << "*iter: " << *iter << std::endl << std::endl;

		//
		// Clear
		//

		set.Clear();
		std::cout << "Clear()" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		//
		// Reinsert
		//

		set.Insert(-14);
		std::cout << "Insert(-14)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;

		set.Insert(7);
		std::cout << "Insert(7)" << std::endl;
		std::cout << "Size(): " << set.Size() << std::endl;
		print::PrintSet(set); std::cout << std::endl << std::endl;
	}
}
