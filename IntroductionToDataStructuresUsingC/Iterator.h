#pragma once

namespace data_structure
{
	struct Node
	{
		int data;
		Node* prev;
		Node* next;

		Node() :
			data(0),
			prev(nullptr),
			next(nullptr) {}

		Node(int data) :
			data(data),
			prev(nullptr),
			next(nullptr) {}

		Node(const Node& node) :
			data(node.data),
			prev(nullptr),
			next(nullptr) {}
	};

	class IteratorBase
	{
	public:
		inline virtual IteratorBase& operator++() { node_ = node_->next; return *this; }
		inline virtual IteratorBase operator++(int) { Node* cache = node_; node_ = node_->next; return IteratorBase(cache); }
		inline virtual IteratorBase& operator--() { node_ = node_->prev; return *this; }
		inline virtual IteratorBase operator--(int) { Node* cache = node_; node_ = node_->prev; return IteratorBase(cache); }

		inline virtual int& operator*() { return node_->data; }
		inline virtual const int& operator*() const { return node_->data; }

		inline virtual bool operator==(const IteratorBase& other) const { return node_ == other.node_; }
		inline virtual bool operator!=(const IteratorBase& other) const { return node_ != other.node_; }

	protected:
		IteratorBase(Node* node) :
			node_(node) {}

		Node* node_;
	};
}
