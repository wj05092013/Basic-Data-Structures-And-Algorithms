#include "LinkedList.h"

namespace data_structure
{
	//
	// List Class
	//

	List::List() :
		size_(0)
	{
		// Create dummies.
		head_ = new ListNode();
		tail_ = new ListNode();

		head_->next = tail_;
		tail_->prev = head_;
	}

	List::List(const List& list) :
		size_(list.size_)
	{
		Clear();

		ListNode* node = list.head_->next;

		while (node != list.tail_)
		{
			PushBack(node->data);

			node = node->next;
		}
	}

	List::~List()
	{
		Clear();

		delete head_;
		delete tail_;
	}

	void List::PushFront(int data)
	{
		// Create a new node.
		ListNode* node = new ListNode(data);
		node->prev = head_;
		node->next = head_->next;

		// Link the created node on the head.
		node->prev->next = node;
		node->next->prev = node;

		++size_;
	}

	void List::PushFront(const List& list)
	{
		ListNode* node = list.tail_->prev;

		while (node != list.head_)
		{
			PushFront(node->data);

			node = node->prev;
		}

		size_ += list.size_;
	}

	void List::PushBack(int data)
	{
		// Create a new node.
		ListNode* node = new ListNode(data);
		node->prev = tail_->prev;
		node->next = tail_;

		// Link the created node on the tail.
		node->prev->next = node;
		node->next->prev = node;

		++size_;
	}

	void List::PushBack(const List& list)
	{
		ListNode* node = list.head_->next;

		while (node != list.tail_)
		{
			PushBack(node->data);

			node = node->next;
		}

		size_ += list.size_;
	}

	void List::PopFront()
	{
		ListNode* node = head_->next;

		head_->next = node->next;
		node->next->prev = head_;

		delete node;

		--size_;
	}

	void List::PopBack()
	{
		ListNode* node = tail_->prev;

		tail_->prev = node->prev;
		node->prev->next = tail_;

		delete node;

		--size_;
	}

	void List::Clear()
	{
		ListNode* node = head_->next;

		while (node != tail_)
		{
			node = node->next;
			delete node->prev;
		}

		head_->next = tail_;
		tail_->prev = head_;

		size_ = 0;
	}

	int List::Size() const
	{
		return size_;
	}

	int List::Front() const
	{
		return *Begin();
	}

	int List::Back() const
	{
		return *(--End());
	}

	ListIterator List::Begin()
	{
		return ListIterator(head_->next);
	}

	ConstListIterator List::Begin() const
	{
		return ConstListIterator(head_->next);
	}

	ListIterator List::End()
	{
		return ListIterator(tail_);
	}

	ConstListIterator List::End() const
	{
		return ConstListIterator(tail_);
	}
}
