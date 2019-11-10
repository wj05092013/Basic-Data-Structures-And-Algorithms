#pragma once

#include "Iterator.h"

namespace data_structure
{
	class LinkedList
	{
	public:
		class Iterator : public IteratorBase
		{
		public:
			Iterator(Node* node);
		};

		class ConstIterator : public ConstIteratorBase
		{
		public:
			ConstIterator(Node* node);
		};

	public:
		LinkedList();
		LinkedList(const LinkedList& list);
		~LinkedList();

		void PushFront(int data);
		void PushFront(const LinkedList& list);
		void PushBack(int data);
		void PushBack(const LinkedList& list);

		void PopFront();
		void PopBack();

		void Clear();

		Iterator Begin();
		ConstIterator Begin() const;

		Iterator End();
		ConstIterator End() const;

	private:
		Node* head_;
		Node* tail_;
		int size_;
	};
}
