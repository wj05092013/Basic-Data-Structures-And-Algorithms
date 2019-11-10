#include "LinkedList.h"

namespace data_structure
{
	//
	// Iterator Class
	//

	LinkedList::Iterator::Iterator(Node* node) :
		IteratorBase(node)
	{
	}

	//
	// LinkedList Class
	//

	LinkedList::LinkedList() :
		size_(0)
	{
		// Create dummies.
		head_ = new Node();
		tail_ = new Node();

		head_->next = tail_;
		tail_->prev = head_;
	}

	LinkedList::LinkedList(const LinkedList& list) :
		size_(list.size_)
	{
		Clear();

		Node* node = list.head_->next;

		while (node != list.tail_)
		{
			PushBack(node->data);

			node = node->next;
		}
	}

	LinkedList::~LinkedList()
	{
		Clear();

		delete head_;
		delete tail_;
	}

	void LinkedList::PushFront(int data)
	{
		// Create a new node.
		Node* node = new Node(data);
		node->prev = head_;
		node->next = head_->next;

		// Link the created node on the head.
		node->prev->next = node;
		node->next->prev = node;

		++size_;
	}

	void LinkedList::PushFront(const LinkedList& list)
	{
		Node* node = list.tail_->prev;

		while (node != list.head_)
		{
			PushFront(node->data);

			node = node->prev;
		}

		size_ += list.size_;
	}

	void LinkedList::PushBack(int data)
	{
		// Create a new node.
		Node* node = new Node(data);
		node->prev = tail_->prev;
		node->next = tail_;

		// Link the created node on the tail.
		node->prev->next = node;
		node->next->prev = node;

		++size_;
	}

	void LinkedList::PushBack(const LinkedList& list)
	{
		Node* node = list.head_->next;

		while (node != list.tail_)
		{
			PushBack(node->data);

			node = node->next;
		}

		size_ += list.size_;
	}

	void LinkedList::PopFront()
	{
		Node* node = head_->next;

		head_->next = node->next;
		node->next->prev = head_;

		delete node;

		--size_;
	}

	void LinkedList::PopBack()
	{
		Node* node = tail_->prev;

		tail_->prev = node->prev;
		node->prev->next = tail_;

		delete node;

		--size_;
	}

	void LinkedList::Clear()
	{
		Node* node = head_->next;

		while (node != tail_)
		{
			node = node->next;
			delete node->prev;
		}

		head_->next = tail_;
		tail_->prev = head_;

		size_ = 0;
	}

	LinkedList::Iterator LinkedList::Begin()
	{
		return Iterator(head_->next);
	}

	LinkedList::Iterator LinkedList::End()
	{
		return Iterator(tail_);
	}
}
