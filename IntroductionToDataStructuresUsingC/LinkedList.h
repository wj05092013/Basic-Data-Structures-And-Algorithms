#pragma once

#include "Iterator.h"

namespace data_structure
{
	struct ListNode
	{
		int data;
		ListNode* prev;
		ListNode* next;

		ListNode() :
			data(0),
			prev(nullptr),
			next(nullptr) {}

		ListNode(int data) :
			data(data),
			prev(nullptr),
			next(nullptr) {}

		ListNode(const ListNode& node) :
			data(node.data),
			prev(nullptr),
			next(nullptr) {}
	};

	class ListIterator : public IteratorBase
	{
	public:
		ListIterator(ListNode* node) :
			node_(node) {}

		inline ListIterator& operator++()
		{
			node_ = node_->next;
			return *this;
		}

		inline ListIterator operator++(int)
		{
			ListNode* cache = node_; node_ = node_->next;
			return ListIterator(cache);
		}

		inline ListIterator& operator--()
		{
			node_ = node_->prev;
			return *this;
		}

		inline ListIterator operator--(int)
		{
			ListNode* cache = node_; node_ = node_->prev;
			return ListIterator(cache);
		}

		inline int& operator*()
		{
			return node_->data;
		}

		inline const int& operator*() const
		{
			return node_->data;
		}

		inline bool operator==(const ListIterator& other) const
		{
			return node_ == other.node_;
		}

		inline bool operator!=(const ListIterator& other) const
		{
			return node_ != other.node_;
		}

	private:
		ListNode* node_;
	};

	class ConstListIterator : public ListIterator
	{
	public:
		ConstListIterator(ListNode* node) :
			ListIterator(node) {}

		inline ConstListIterator& operator++()
		{
			ListIterator::operator++();
			return *this;
		}

		inline ConstListIterator operator++(int)
		{
			ConstListIterator temp(*this);
			ListIterator::operator++();
			return temp;
		}

		inline ConstListIterator& operator--()
		{
			ListIterator::operator--();
			return *this;
		}

		inline ConstListIterator operator--(int)
		{
			ConstListIterator temp(*this);
			ListIterator::operator--();
			return temp;
		}

		inline const int& operator*() const
		{
			return ListIterator::operator*();
		}
	};

	class List
	{
	public:
		List();
		List(const List& list);
		~List();

		void PushFront(int data);
		void PushFront(const List& list);
		void PushBack(int data);
		void PushBack(const List& list);

		void PopFront();
		void PopBack();

		void Clear();
		int Size() const;

		int Front() const;
		int Back() const;

		ListIterator Begin();
		ConstListIterator Begin() const;

		ListIterator End();
		ConstListIterator End() const;

	private:
		ListNode* head_;
		ListNode* tail_;
		int size_;
	};
}
