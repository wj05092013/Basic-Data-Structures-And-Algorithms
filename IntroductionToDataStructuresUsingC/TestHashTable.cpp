#include "Print.h"
#include "TestHashTable.h"

namespace test_hash_table
{
	void Test()
	{
		data_structure::HashTable<std::string> table(6);

		//
		// Initial size and slot count.
		//

		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		//
		// Insert
		//

		table.Insert(2, "apple");
		std::cout << "Insert(2, \"apple\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(9, "pineapple");
		std::cout << "Insert(9, \"pineapple\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(5, "grape");
		std::cout << "Insert(5, \"grape\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(1, "orange");
		std::cout << "Insert(1, \"orange\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(16, "banana");
		std::cout << "Insert(16, \"banana\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(3, "dragon fruit");
		std::cout << "Insert(3, \"dragon fruit\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(15, "melon");
		std::cout << "Insert(15, \"melon\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(21, "watermelon");
		std::cout << "Insert(21, \"watermelon\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(14, "cherry");
		std::cout << "Insert(14, \"cherry\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(8, "strawberry");
		std::cout << "Insert(8, \"strawberry\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(7, "raspberry");
		std::cout << "Insert(7, \"raspberry\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Insert(19, "kiwi");
		std::cout << "Insert(19, \"kiwi\")" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		//
		// Erase
		//

		table.Erase(8);
		std::cout << "Erase(8)" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		table.Erase(15);
		std::cout << "Erase(15)" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		//
		// Find
		//

		data_structure::HashTableIterator<std::string> iter;
		if ((iter = table.Find(14)) != table.End())
			std::cout << "Find(14): " << *iter << std::endl << std::endl;
		else
			std::cout << "Find(14): Failed" << std::endl << std::endl;

		if ((iter = table.Find(30)) != table.End())
			std::cout << "Find(30): " << *iter << std::endl << std::endl;
		else
			std::cout << "Find(30): Failed" << std::endl << std::endl;

		if ((iter = table.Find(9)) != table.End())
			std::cout << "Find(9): " << *iter << std::endl << std::endl;
		else
			std::cout << "Find(9): Failed" << std::endl << std::endl;

		if ((iter = table.Find(15)) != table.End())
			std::cout << "Find(15): " << *iter << std::endl << std::endl;
		else
			std::cout << "Find(15): Failed" << std::endl << std::endl;

		//
		// Rehash
		//

		table.Rehash(50);
		std::cout << "Rehash(50)" << std::endl;
		std::cout << "Size(): " << table.Size() << std::endl;
		std::cout << "SlotCount(): " << table.SlotCount() << std::endl;
		print::PrintHashTable(table); std::cout << std::endl << std::endl;

		//
		// operator[]
		//

		std::cout << "table[16]: " << table[16] << std::endl << std::endl;
		std::cout << "table[3]: " << table[16] << std::endl << std::endl;
		std::cout << "table[21]: " << table[16] << std::endl << std::endl;

		table[7] = "peach";
		std::cout << "table[7] = \"peach\" " << std::endl;
		std::cout << "table[7]: " << table[7] << std::endl << std::endl;

		table[5] = "grapefruit";
		std::cout << "table[5] = \"grapefruit\" " << std::endl;
		std::cout << "table[5]: " << table[5] << std::endl << std::endl;

		table[14] = "lemon";
		std::cout << "table[14] = \"lemon\" " << std::endl;
		std::cout << "table[14]: " << table[14] << std::endl << std::endl;
	}
}
