#pragma once
#include "Node.hpp"

namespace ft
{		template <class Key, class T, class _Iterator>
		class iterator {
		private:
		_Iterator pointerToNode;

		public:
			typedef ft::pair<const Key, T>					value_type;
			typedef value_type* 							pointer;
			typedef value_type&								reference;
			typedef value_type								difference_type;
			typedef typename std::forward_iterator_tag		iterator_category;
			typedef _Iterator								iterator_type;

			iterator() {};
			iterator(_Iterator const& ptr) : pointerToNode(ptr) {};
			iterator(iterator const& iter) : pointerToNode(iter.base()) {};

			iterator& operator=(iterator const& rhs) {
				this->pointerToNode = rhs.base();
				return (*this);
			}
			
			_Iterator& base()  {
				return (pointerToNode); 
			}

			const _Iterator& base() const {
				return (pointerToNode);
			}

			bool operator==(iterator const& other) const {
				if (this->pointerToNode == other.pointerToNode)
					return true;
				return false;
			}

			bool operator!=(iterator const& other) const {
				return (!((*this) == other));
			}

			reference operator*() const {
				return (pointerToNode->pair);
			}

			pointer operator->() const {
				return &(pointerToNode->pair);
			}

			iterator operator++() { //prefix increment
				_Iterator t = pointerToNode;
				if (pointerToNode == NULL)
					return NULL;
				if ((pointerToNode->left == pointerToNode->right)
					&& (pointerToNode->right != NULL))
					return (*this);
				t = t->successor(t);
				if (!t) {
					t = pointerToNode;
					t = t->biggerParent(t);
				}
				if (t == NULL) {
					t = pointerToNode;
					while (t->parent != NULL)
						t = t->parent;
				}
				pointerToNode = t;
				return (*this);
			}

			iterator operator++(int) { //postfix increment
				iterator beforeIncr(*this);
				++(*this);
				return (beforeIncr);
			}

			iterator operator--(int) { //postfix increment
				iterator beforeIncr(*this);
				--(*this);
				return (beforeIncr);

			}

			iterator operator--() { //prefix increment
				_Iterator t = pointerToNode;
				if (pointerToNode == NULL)
					return NULL;
				if ((t->right != NULL) && (t->right == t->left)) {
					_Iterator temp = t->right; 
					if (!temp)
						return NULL;
					while (temp->right) {
						temp = temp->right;
					}
					pointerToNode = temp;
					return (*this);
				}
				t = t->predecessor(t);
				if (!t) {
					t = pointerToNode;
					t = t->lessParent(t);
				}
				pointerToNode = t;
				return (*this);
			}
		};
		
		template <class Key, class T, class _Iterator>
		class const_iterator {
		private:
			_Iterator pointerToNode;

		public:
			typedef const ft::pair<const Key, T>			value_type;
			typedef value_type* 							pointer;
			typedef value_type&								reference;
			typedef value_type								difference_type;
			typedef typename std::forward_iterator_tag		iterator_category;
			typedef _Iterator								iterator_type;

			const_iterator() {};
			const_iterator(_Iterator const& ptr) : pointerToNode(ptr) {};
			const_iterator(const_iterator const& iter) : pointerToNode(iter.base()) {};
			
			template<typename _Iteratorr>
			const_iterator(iterator<Key, T, _Iteratorr> const& iter) : pointerToNode(iter.base()) {};


			const_iterator& operator=(const_iterator const& rhs) {
				this->pointerToNode = rhs.base();
				return (*this);
			}
			
			_Iterator& base()  {
				return (pointerToNode); 
			}

			const _Iterator& base() const {
				return (pointerToNode);
			}

			bool operator==(const_iterator const& other) const {
				if (this->pointerToNode == other.pointerToNode)
					return true;
				return false;
			}

			bool operator!=(const_iterator const& other) const {
				return (!((*this) == other));
			}

			reference operator*() const {
				return (pointerToNode->pair);
			}

			pointer operator->() const {
				return &(pointerToNode->pair);
			}

			const_iterator operator++() { //prefix increment
				_Iterator t = pointerToNode;
				if (pointerToNode == NULL)
					return NULL;
				t = t->successor(t);
				if (!t) {
					t = pointerToNode;
					t = t->biggerParent(t);
				}
				if (t == NULL) {
					t = pointerToNode;
					while (t->parent != NULL)
						t = t->parent;
				}
				pointerToNode = t;
				return (*this);
			}

			const_iterator operator++(int) { //postfix increment
				const_iterator beforeIncr(*this);
				++(*this);
				return (beforeIncr);
			}

			const_iterator operator--(int) { //postfix increment
				const_iterator beforeIncr(*this);
				--(*this);
				return (beforeIncr);

			}

			const_iterator operator--() { //prefix increment
				_Iterator t = pointerToNode;
				if (pointerToNode == NULL)
					return NULL;
				if ((t->right != NULL) && (t->right == t->left)) {
					_Iterator temp = t->right; 
					if (!temp)
						return NULL;
					while (temp->right) {
						temp = temp->right;
					}
					pointerToNode = temp;
					return (*this);
				}
				t = t->predecessor(t);
				if (!t) {
					t = pointerToNode;
					t = t->lessParent(t);
				}
				pointerToNode = t;
				return (*this);
			}
		};
}
