#pragma once

#include <functional>
#include "pair.hpp"
#include "BidirectionalIterator.hpp"
#include "reverse_iterator.hpp"
#include "Node.hpp"

namespace ft {

	template < class Key,                                     		// map::key_type
           	class T,                                       			// map::mapped_type
           	class Compare = std::less<Key>,                     	// map::key_compare
           	class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
           	> 
	class treeAA {
	public:
		typedef	ft::pair<const Key, T>				value_type;
		typedef Key 								key_type;
		typedef	Alloc	 							allocator_type;
		typedef Node<Key, T>* 						Nodeptr;
		typedef Node<Key, T> const* 				const_Nodeptr;
		typedef	typename allocator_type::pointer	pointer;
		typedef	typename allocator_type::const_pointer	const_pointer;
		typedef typename allocator_type::template 	rebind<Node<Key, T> >::other NodeAlloc;

		Nodeptr 		root;
		Node<Key, T>	endNode;
		size_t			size;

		allocator_type	_Alloc;
		NodeAlloc		_NodeAlloc;
		Compare			_compare;

		bool			resultInsert;
		Nodeptr 		pointerResultInsert;

	private:
//	public:
		Nodeptr skew( Nodeptr t ) {
			if (t == NULL)
				return NULL;
			else if (t->left == NULL)
				return t;
			else if ( t->left->level == t->level )
				t = rotateWithLeftChild( t );
			return t;
		}

		Nodeptr split( Nodeptr t ) {
		    if (t == NULL)
				return NULL;
			else if ((t->right == NULL) || (t->right->right == NULL))
				return t;
			else  if( t->right->right->level == t->level ) {
				t = rotateWithRightChild( t );
				t->level++;
				}
			return t;
		}


		Nodeptr rotateWithLeftChild( Nodeptr k2 ) { 
			Nodeptr k1 = k2->left;
			k1->parent = k2->parent;
			k2->left = k1->right;
			if (k2->left)	
				k2->left->parent = k2;
			k1->right = k2;
			if (k1->right)
				k1->right->parent = k1;
			return k1;
		}

		// Rotate binary tree node with right child.
		Nodeptr rotateWithRightChild( Nodeptr k1 ) {
			Nodeptr k2 = k1->right;
			k2->parent = k1->parent;
			k1->right = k2->left;
			if (k1->right)
				k1->right->parent = k1;
			k2->left = k1;
			if (k2->left)
				k2->left->parent = k2;
			return k2;
		}

		Nodeptr successor(Nodeptr t) {
			t = t->right;
			while (t->left != NULL)
				t = t->left;
			return t;
		}

		const_Nodeptr successor(const_Nodeptr t) const {
			t = t->right;
			while (t->left != NULL)
				t = t->left;
			return t;
		}

		// Returns son with the first value that is less than the value of the give vertex, complexity O(log n)
		Nodeptr predecessor(Nodeptr t) {
			t = t->left;
			while (t->right != NULL)
				t = t->right;
			return t;
		}

		const_Nodeptr predecessor(const_Nodeptr t) const {
			t = t->left;
			while (t->right != NULL) {
				t = t->right;
			}
			return t;
		}

		Nodeptr decrease_level (Nodeptr t) 
		{
			if (t == NULL)
				return NULL;
			unsigned int should_be;
			if ((t->left == NULL) || (t->right == NULL))
				should_be = 1;
			else  
				should_be = std::min(t->left->level, t->right->level) + 1;
			if (should_be < t->level)
				t->level = should_be;
			if ((t->right != NULL) && (should_be < t->right->level))
				t->right->level = should_be;
			return t;
		}

	public:
		treeAA() {
			this->root = NULL;
			this->size = 0;
			}

		void _helperinsert(const value_type& x) {
			Nodeptr rootAfterInsert = this->insert(x, this->root);
			this->endNode.right = root;
			this->endNode.left = root;
			if (root != NULL)
				root->parent = &endNode;
		}

		void _helperdeleteTree() {
			this->deleteTree(root);
			root = NULL;
			this->endNode.right = root;
			this->endNode.left = root;
		}

		void _helpererase(const key_type& x) {
			root = this->eraseNode(x, this->root);
			this->endNode.right = root;
			this->endNode.left = root;
			if (root != NULL)
				root->parent = &endNode;
		}

		void _helpererasePos(Nodeptr& position) {
			if (root == position) {
					this->_helpererase(position->pair.first);

			}
			else {
			//	std::cout << "this case " << std::endl;
				Nodeptr nodeParent = position->parent;
				if (nodeParent->left == position) {
				//	std::cout << "this left case " << std::endl;
					//position->parent->left = 
					nodeParent->left = this->eraseNode(position->pair.first, position);
			//		nodeParent->left = this->eraseSomeNode(position);
					if (nodeParent->left == nodeParent)
						nodeParent->left = NULL;
				}
				else {
				//	std::cout << "this right case " << std::endl;
					nodeParent->right = this->eraseNode(position->pair.first, position);
			//		nodeParent->right = this->eraseSomeNode(position);
					if (nodeParent->right == nodeParent)
						nodeParent->right = NULL;
				}
			}
		}

		Nodeptr find(const key_type& x, Nodeptr t) const {
		if (t == NULL)
			return t;
		else if (x < t->pair.first)
			t = find(x, t->left);
		else if (x > t->pair.first)
			t = find(x, t->right);
		else if (x == t->pair.first)
			return t;
		return t;
		}

		Nodeptr findBound(const key_type& x, Nodeptr t) const {
		if (t == NULL)
			return (NULL);
		else if ((_compare(x, t->pair.first) == true) && (t->left != NULL))
			t = findBound(x, t->left);
		else if ((_compare(t->pair.first, x) == true) && (t->right != NULL))
			t = findBound(x, t->right);
		else if (((_compare(t->pair.first, x) == true) && (t->right == NULL)) ||
				 ((_compare(x, t->pair.first) == true) && (t->left == NULL)) ||
				 (x == t->pair.first))
			return t;
		return t;
		}

		Nodeptr insert(const value_type& x, Nodeptr& t) {
		if (t == NULL) {
			t = _NodeAlloc.allocate(1);
			_NodeAlloc.construct(t, Node<Key, T>(x));
			size++;			
			resultInsert = true;
			pointerResultInsert = t;
		}
		else if (_compare(x.first, t->pair.first) != 0)
			t->left = insert(x, t->left);
		else if (_compare(t->pair.first, x.first) != 0)
			t->right = insert(x, t->right);
		else
			pointerResultInsert = t;
		if (t->right != NULL)
			t->right->parent = t;
		if (t->left != NULL)
			t->left->parent = t;			
		t = skew(t);
		t = split(t);
		return t;
		}


		Nodeptr eraseNode(const key_type& x, Nodeptr& t)
		{
			if (t == NULL)
				return t;
			else if (_compare(t->pair.first, x) == true)
				t->right = eraseNode(x, t->right);
			else if (_compare(x, t->pair.first) == true)
				t->left = eraseNode(x, t->left);
//        If we're a leaf, easy, otherwise reduce to leaf case. 
			else {
				if ((t->left == NULL) && (t->right == NULL)) {
					_NodeAlloc.destroy(t);
					_NodeAlloc.deallocate(t, 1);
					size--;
//					t = NULL;
					return NULL;
				}
				else if (t->left == NULL) {
					const_Nodeptr s = successor(t);
					_Alloc.construct(&(t->pair), s->pair);
                	t->right = eraseNode(s->pair.first, t->right);
				}
				else {
					const_Nodeptr s = predecessor(t);
					_Alloc.construct(&(t->pair), s->pair);
					t->left = eraseNode(s->pair.first, t->left);
				}
			}
    		t = decrease_level(t);
    		t = skew(t);
    		t->right = skew(t->right);
    		if (t->right != NULL)
        		t->right->right = skew(t->right->right);
			t = split(t);
			t->right = split(t->right);
			return t;
		}


// удали конкретный итер
		Nodeptr eraseSomeNode(Nodeptr& t)
		{
			if (t == NULL)
				return t;
			if ((t->left == NULL) && (t->right == NULL)) {
				_NodeAlloc.destroy(t);
				_NodeAlloc.deallocate(t, 1);
				size--;
				return NULL;
			}
			else if (t->left == NULL) {
				const_Nodeptr s = successor(t); // t->left = NULL
				_Alloc.construct(&(t->pair), s->pair);
				t->right = eraseSomeNode(t->right);
			}
			else {
				const_Nodeptr s = predecessor(t); // t->right = NULL
				_Alloc.construct(&(t->pair), s->pair);
				t->left = eraseSomeNode(t->left);
			}
    		t = decrease_level(t);
    		t = skew(t);
    		t->right = skew(t->right);
    		if (t->right != NULL)
        		t->right->right = skew(t->right->right);
			t = split(t);
			t->right = split(t->right);
			return t;
		}










/*		Nodeptr eraseNode(const key_type& x, Nodeptr& t)
		{
			if (t == NULL)
				return t;
			else if (_compare(t->pair.first, x) == true)
				t->right = eraseNode(x, t->right);
			else if (_compare(x, t->pair.first) == true)
				t->left = eraseNode(x, t->left);
//        If we're a leaf, easy, otherwise reduce to leaf case. 
			else {
				//std::cout << "this null case" << std::endl;
				Nodeptr s;
				if ((t->left == NULL) && (t->right == NULL)) {
				//	std::cout << "this null null case" << std::endl;
					
					_NodeAlloc.destroy(t);
					_NodeAlloc.deallocate(t, 1);
					size--;
					t = NULL;
				//	std::cout << " exit  null null case " << std::endl;
					return NULL;
				}
				else if (t->left == NULL)
					s = successor(t);
				else
					s = predecessor(t);
					std::cout << "in erase " << s->pair.first << " " << t->pair.first << std::endl;
					std::cout << "in erase parent " << s->parent->pair.first << std::endl;
					if (s->parent->left == s) {
						std::cout << "s->parent->left == s " << std::endl;
						if (s->left == NULL)
							s->parent->left = s->right;
						else 
							s->parent->left = s->left;
					}
					else if (s->parent->right == s) {
						std::cout << "s->parent->right == s " << std::endl;
						if (s->left == NULL)
							s->parent->right = s->right;
						else 
							s->parent->right = s->left;
					}
					s->parent = t->parent;
					s->left = t->left;
					if (s->left == s)
						s->left = NULL;
					s->right = t->right;
					if (s->right == s)
						s->right = NULL;
					_NodeAlloc.destroy(t);
					_NodeAlloc.deallocate(t, 1);
					size--;
					return s;
				}
    		t = decrease_level(t);
    		t = skew(t);
    		t->right = skew(t->right);
    		if (t->right != NULL)
        		t->right->right = skew(t->right->right);
			t = split(t);
			t->right = split(t->right);
			return t;
		}
*/   
		void swap (treeAA& x) {
			size_t bufferSize = this->size;
			Nodeptr bufferRoot = this->root;
			this->size = x.size;
			this->root = x.root;
			x.size = bufferSize;
			x.root = bufferRoot;
			this->endNode.right = this->root;
			this->endNode.left = this->root;
			if (this->root != NULL)
				this->root->parent = &(this->endNode);
			x.endNode.right = x.root;
			x.endNode.left = x.root;
			if (x.root != NULL)
				x.root->parent = &(x.endNode);
		}

		void deleteTree(Nodeptr node)
		{
			if (node == NULL) 
				return;	
			/* first delete both subtrees */
			deleteTree(node->left);
			deleteTree(node->right);
			/* then delete the node */
			_NodeAlloc.destroy(node);
			_NodeAlloc.deallocate(node, 1);
			this->size--;
		}
 
		void printAll(Nodeptr temp)
		{
			if (!temp)
				return;
			printAll(temp->left);
			std::cout << "key: " << temp->pair.first << " value: " << temp->pair.second;
			std::cout << "  Level: " <<temp->level << std::endl;
			printAll(temp->right);
		}
		 
		Nodeptr getEndNode() {
			return &(this->endNode);
		}

		const_Nodeptr getEndNode() const {
			return &(this->endNode);
		}
	};
}

// https://en.wikipedia.org/wiki/AA_tree
// https://neerc.ifmo.ru/wiki/index.php?title=AA-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE
// https://ycpcs.github.io/cs350-fall2017/lectures/AA-tree_lecture.pdf
