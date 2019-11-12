#pragma once

#include "Iterator.h"

namespace data_structure
{
	struct TreeNode
	{
		int data;
		TreeNode* parent;
		TreeNode* left_child;
		TreeNode* right_child;

		TreeNode() :
			data(0),
			parent(nullptr),
			left_child(nullptr),
			right_child(nullptr) {}

		TreeNode(int data) :
			data(data),
			parent(nullptr),
			left_child(nullptr),
			right_child(nullptr) {}

		TreeNode(const TreeNode& node) :
			data(node.data),
			parent(nullptr),
			left_child(nullptr),
			right_child(nullptr) {}
	};

	class SetIterator : public IteratorBase
	{
	public:
		SetIterator(TreeNode* node) :
			node_(node) {}

		SetIterator& operator++();
		SetIterator operator++(int);
		SetIterator& operator--();
		SetIterator operator--(int);

		inline int& operator*()
		{
			return node_->data;
		}

		inline const int& operator*() const
		{
			return node_->data;
		}

		inline bool operator==(const SetIterator& other) const
		{
			return node_ == other.node_;
		}

		inline bool operator!=(const SetIterator& other) const
		{
			return node_ != other.node_;
		}

	private:
		TreeNode* node_;
	};

	class ConstSetIterator : public SetIterator
	{
	public:
		ConstSetIterator(TreeNode* node) :
			SetIterator(node) {}

		inline ConstSetIterator operator++()
		{
			SetIterator::operator++();
			return *this;
		}

		ConstSetIterator operator++(int)
		{
			ConstSetIterator temp(*this);
			SetIterator::operator++();
			return *this;
		}

		ConstSetIterator& operator--()
		{
			SetIterator::operator--();
			return *this;
		}

		ConstSetIterator operator--(int)
		{
			ConstSetIterator temp(*this);
			SetIterator::operator--();
			return temp;
		}

		const int& operator*() const
		{
			return SetIterator::operator*();
		}
	};

	class Set
	{
	public:
		Set();
		Set(const Set& set);

		void Insert(int data);
		void Erase(int data);

		void Clear();
		int Size() const;

		SetIterator Find(int data);

		SetIterator Begin();
		ConstSetIterator Begin() const;

		SetIterator End();
		ConstSetIterator End() const;

	private:
		void UpdateBegin();
		void DeleteSubtree(TreeNode* root);
		void CopySubtree(TreeNode* dst_parent, TreeNode** dst_to_current, const TreeNode* src_node);

		TreeNode* root_;	// This dummy node is end position.
		TreeNode* begin_;
		int size_;
	};
}
