#pragma once

namespace data_structure
{
	class LinkedList
	{
	private:
		struct Node
		{
			Node* prev;
			Node* next;
			int data;

			Node() :
				prev(nullptr),
				next(nullptr),
				data(0) {}

			Node(int data) :
				prev(nullptr),
				next(nullptr),
				data(data) {}

			Node(const Node& node) :
				prev(nullptr),
				next(nullptr),
				data(node.data) {}
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

		int PeekFront() const;
		int PeekBack() const;

	private:
		Node* head_;
		Node* tail_;
		int size_;
	};
}
