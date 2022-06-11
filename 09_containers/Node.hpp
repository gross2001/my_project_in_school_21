#pragma once

namespace ft
{
	template < class Key, class T> 
	struct Node {
		typedef	ft::pair<const Key, T>	value_type;
		value_type						pair;
		unsigned int 					level;
		Node* 							left;
		Node* 							right;
		Node* 							parent;
		Node() {};
		Node(const Node& rhs) :  right(rhs.right),  left (rhs.left), parent(rhs.parent), pair(rhs.pair), level(rhs.level) {};
		Node(const value_type& val) : right(NULL),  left (NULL), parent(NULL), pair(val), level(1) {} ;
		Node& operator=(Node const& rhs) {
			this->right = rhs.right;
			this->left = rhs.left;
			this->parent = rhs.parent;
			this->pair = rhs.pair;
			this->level = rhs.level;
			return (*this);
		}
		Node* lessParent( Node* t)  {
		while ((t->parent != NULL) && (t->parent->right != t))
			t = t->parent;
		return (t->parent);
		}
		
		Node* biggerParent( Node* t)  {
		if (t == NULL)
			return NULL;
		while ((t->parent != NULL) && (t->parent->left != t))
			t = t->parent;
		return (t->parent);
		}

	Node* successor( Node* t) {
		if ((t == NULL) || (t->right == NULL))
			return (NULL);
		t = t->right;
		while (t->left != NULL)
			t = t->left;
		return t;
		}

		Node* predecessor( Node* t) {
		if (t == NULL || t->left == NULL)
			return NULL;
		t = t->left;
		while (t->right != NULL)
			t = t->right;
		return t;
		}	
	
	Node const* lessParent( Node const* t)  const {
		while ((t->parent != NULL) && (t->parent->right != t))
			t = t->parent;
		return (t->parent);
		}
		
	Node const* biggerParent( Node const* t) const {
		if (t == NULL)
			return NULL;
		while ((t->parent != NULL) && (t->parent->left != t))
			t = t->parent;
		return (t->parent);
		}

	Node const* successor( Node const* t) const{
		if ((t == NULL) || (t->right == NULL))
			return (NULL);
		t = t->right;
		while (t->left != NULL)
			t = t->left;
		return t;
		}

		Node const* predecessor( Node const* t) const{
		if (t == NULL || t->left == NULL)
			return NULL;
		t = t->left;
		while (t->right != NULL)
			t = t->right;
		return t;
		}
	};
}
