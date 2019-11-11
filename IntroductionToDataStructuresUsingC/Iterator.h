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
		inline IteratorBase& operator++() { node_ = node_->next; return *this; }
		inline IteratorBase operator++(int) { Node* cache = node_; node_ = node_->next; return IteratorBase(cache); }
		inline IteratorBase& operator--() { node_ = node_->prev; return *this; }
		inline IteratorBase operator--(int) { Node* cache = node_; node_ = node_->prev; return IteratorBase(cache); }

		inline int& operator*() { return node_->data; }
		inline const int& operator*() const { return node_->data; }

		inline bool operator==(const IteratorBase& other) const { return node_ == other.node_; }
		inline bool operator!=(const IteratorBase& other) const { return node_ != other.node_; }

	protected:
		IteratorBase(Node* node) :
			node_(node) {}

		Node* node_;
	};

	class ConstIteratorBase : public IteratorBase
	{
	public:
		inline ConstIteratorBase& operator++() { return static_cast<ConstIteratorBase&>(IteratorBase::operator++()); }
		inline ConstIteratorBase operator++(int) { IteratorBase::operator++(0); }
		inline ConstIteratorBase& operator--() { return static_cast<ConstIteratorBase&>(IteratorBase::operator--()); }
		inline ConstIteratorBase operator--(int) { IteratorBase::operator--(0); }

		inline const int& operator*() const { return IteratorBase::operator*(); }

	protected:
		ConstIteratorBase(Node* node) :
			IteratorBase(node) {}
	};
}
