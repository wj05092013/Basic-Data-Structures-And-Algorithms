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

	class ConstSetIterator : public IteratorBase
	{
	public:
		ConstSetIterator(TreeNode* node) :
			node_(node) {}

		ConstSetIterator& operator++();
		ConstSetIterator operator++(int);
		ConstSetIterator& operator--();
		ConstSetIterator operator--(int);

		inline const int& operator*() const
		{
			return node_->data;
		}

		inline bool operator==(const ConstSetIterator& other) const
		{
			return node_ == other.node_;
		}

		inline bool operator!=(const ConstSetIterator& other) const
		{
			return node_ != other.node_;
		}

	private:
		TreeNode* node_;
	};

	class Set
	{
	public:
		Set();
		Set(const Set& set);
		~Set();

		void Insert(int data);
		void Erase(int data);

		void Clear();
		int Size() const;

		ConstSetIterator Find(int data);

		ConstSetIterator Begin() const;
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
