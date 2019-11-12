#include "Set.h"

namespace data_structure
{
	//
	// SetIterator Class
	//

	SetIterator& SetIterator::operator++()
	{
		if (node_->right_child != nullptr)
		{
			node_ = node_->right_child;
			while (node_->left_child != nullptr)
				node_ = node_->left_child;
		}
		else
		{
			while (node_->parent->right_child == node_)
				node_ = node_->parent;
			node_ = node_->parent;
		}

		return *this;
	}

	SetIterator SetIterator::operator++(int)
	{
		TreeNode* temp = node_;
		operator++();
		return SetIterator(temp);
	}

	SetIterator& SetIterator::operator--()
	{
		if (node_->left_child != nullptr)
		{
			node_ = node_->left_child;
			while (node_->right_child != nullptr)
				node_ = node_->right_child;
		}
		else
		{
			while (node_->parent->left_child == node_)
				node_ = node_->parent;
			node_ = node_->parent;
		}

		return *this;
	}

	SetIterator SetIterator::operator--(int)
	{
		TreeNode* temp = node_;
		operator--();
		return SetIterator(temp);
	}

	//
	// Set Class
	//

	Set::Set() :
		root_(nullptr),
		begin_(nullptr),
		size_(0)
	{
		// Create a dummy.
		root_ = new TreeNode();
		begin_ = root_;
	}

	Set::Set(const Set& set)
	{
		DeleteSubtree(root_->left_child);

		CopySubtree(root_, &root_->left_child, set.root_->left_child);

		size_ = set.size_;

		UpdateBegin();
	}

	void Set::Insert(int data)
	{
		// The real tree starts from the left-side child of the root node.
		TreeNode* parent = root_;
		TreeNode** insert_pos = &(root_->left_child);
		
		while (*insert_pos != nullptr)
		{
			parent = *insert_pos;
			if (data < (*insert_pos)->data)
				insert_pos = &((*insert_pos)->left_child);
			else if ((*insert_pos)->data < data)
				insert_pos = &((*insert_pos)->right_child);
			else
				return;		// It is not allowed to store the same data.
		}

		TreeNode* node = new TreeNode(data);
		node->parent = parent;
		*insert_pos = node;

		++size_;

		// Update the begin position.
		if (begin_->left_child)
			begin_ = begin_->left_child;
	}

	void Set::Erase(int data)
	{
		// Find the target.
		//
		TreeNode* target = root_->left_child;

		while (target != nullptr)
		{
			if (data < target->data)
				target = target->left_child;
			else if (target->data < data)
				target = target->right_child;
			else
				break;		// Target found.
		}

		// Target was not found.
		if (target == nullptr)
			return;
		//__
		
		// 'proxy' is a node which will be deleted instead of the 'target' node.
		//	Initialize 'proxy' and 'proxy_child' as if the target has only right child node.
		TreeNode* proxy = target;
		TreeNode* proxy_child = target->right_child;

		// If the target has left child node, find the biggest one from the left subtree
		//  of the target to use it as a deletion proxy.
		if (target->left_child != nullptr)
		{
			proxy = target->left_child;

			while (proxy->right_child != nullptr)
				proxy = proxy->right_child;

			proxy_child = proxy->left_child;
		}

		// Distinct which side the proxy node is on from the parent node.
		TreeNode** parent_to_proxy = &proxy->parent->left_child;
		if (proxy->parent->data < proxy->data)
			parent_to_proxy = &proxy->parent->right_child;

		// Link the parent and the child of the proxy node.
		*parent_to_proxy = proxy_child;
		proxy_child->parent = proxy->parent;

		// Update the begin position.
		if (proxy == begin_)
			begin_ = proxy->parent;

		// Delete the proxy node.
		delete proxy;
		--size_;
	}

	void Set::Clear()
	{
		DeleteSubtree(root_->left_child);

		root_->left_child = nullptr;
		begin_ = root_;
		size_ = 0;
	}

	int Set::Size() const
	{
		return size_;
	}

	SetIterator Set::Find(int data)
	{
		TreeNode* target = root_->left_child;
		while (target != nullptr)
		{
			if (data < target->data)
				target = target->left_child;
			else if (target->data < data)
				target = target->right_child;
			else
				return SetIterator(target);		// Target found.
		}

		// Target not found.
		return End();
	}

	SetIterator Set::Begin()
	{
		return SetIterator(begin_);
	}

	ConstSetIterator Set::Begin() const
	{
		return ConstSetIterator(begin_);
	}

	SetIterator Set::End()
	{
		return SetIterator(root_);
	}

	ConstSetIterator Set::End() const
	{
		return ConstSetIterator(root_);
	}

	void Set::UpdateBegin()
	{
		begin_ = root_;
		while (begin_->left_child)
			begin_ = begin_->left_child;
	}

	void Set::DeleteSubtree(TreeNode* root)
	{
		if (root == nullptr)
			return;

		DeleteSubtree(root->left_child);
		DeleteSubtree(root->right_child);
		delete root;
	}

	void Set::CopySubtree(TreeNode* dst_parent, TreeNode** dst_to_current, const TreeNode* src_node)
	{
		TreeNode* current = new TreeNode(src_node->data);
		*dst_to_current = current;
		(*dst_to_current)->parent = dst_parent;

		if (src_node->left_child)
			CopySubtree(current, &current->left_child, src_node->left_child);
		if (src_node->right_child)
			CopySubtree(current, &current->right_child, src_node->right_child);
	}
}
