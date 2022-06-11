#pragma once

#include <functional>
#include <algorithm>
#include "pair.hpp"
#include "make_pair.hpp"
#include "reverse_iterator.hpp"
#include "treeAA.hpp"
#include  <limits>

namespace ft {

	template < class Key,                                     		// map::key_type
           	class T,                                       			// map::mapped_type
           	class Compare = std::less<Key>,                     	// map::key_compare
           	class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
           	> 
	class map
	{
	private:
	public:
		treeAA<Key, T, Compare, Alloc>	treeInstance;
		typedef typename treeAA<Key, T>::Nodeptr Nodeptr;
		typedef typename treeAA<Key, T>::const_Nodeptr const_Nodeptr;
	public:
		typedef Key 								key_type;
		typedef	T									mapped_type;
		typedef	ft::pair<const Key, T>				value_type;
		typedef	Compare								key_compare;
		typedef	Alloc	 							allocator_type;
		typedef	value_type&							reference;
		typedef	const value_type&					const_reference;
		typedef	typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef	typename ft::iterator<Key, T, Nodeptr>				iterator;
		typedef	typename ft::const_iterator<Key, T, const_Nodeptr>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef	std::ptrdiff_t										difference_type;
		typedef	std::size_t											size_type;

	private:
		void _helperInsert(const value_type& x) {
		//	this->treeInstance.insert(x, treeInstance.root);
			this->treeInstance._helperinsert(x);
		}

		void _helperInsert(const key_type& keyOfPair, const mapped_type& valueOfPair) {
			value_type x = make_pair(keyOfPair, valueOfPair);
			//this->treeInstance.insert(x, treeInstance.root);
			this->treeInstance._helperinsert(x);
		}

		void _helperEraseNode(const key_type& x) {
			this->treeInstance._helpererase(x);
		}

		Nodeptr _helperFindNode(const key_type& x) const {
			Nodeptr result = this->treeInstance.find(x, treeInstance.root);
			return result;
		}

		Nodeptr _helperFindBound(const key_type& x) const {
			Nodeptr result = this->treeInstance.findBound(x, treeInstance.root);
			return result;
		}

		void printAll() {
			this->treeInstance.printAll(treeInstance.root);
		}

	public:

		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) {
			treeInstance._Alloc = alloc;
			treeInstance._compare = comp;
		}
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) {
			treeInstance._Alloc = alloc;
			treeInstance._compare = comp;
			for (InputIterator iter = first; iter != last; iter++)
				this->_helperInsert(iter->first, iter->second);
			}
		

		map (const map& x) {
			for (map::const_iterator iter = x.begin(); iter != x.end(); iter++)
				this->treeInstance._helperinsert(*iter);
		}

		~map() {
			this->clear();
		}

		 map& operator= (const map& x) {
			this->clear();
			for (map::const_iterator iter = x.begin(); iter != x.end(); iter++)
				this->treeInstance._helperinsert(*iter);
			return (*this);
		 }

		//Iterators:
		iterator begin() {
			if (this->size() == 0 || treeInstance.root == NULL)
				return (end());
			Nodeptr temp = treeInstance.root;
			while (temp->left)
				temp = temp->left;
			iterator result(temp);
			return (result);
		}

		const_iterator begin() const {
			if (this->size() == 0 || treeInstance.root == NULL)
				return (end());
			Nodeptr temp = treeInstance.root;
			while (temp->left)
				temp = temp->left;
			const_iterator result(temp);	
			return (result);
		}

      	iterator end() {
			iterator result(this->treeInstance.getEndNode());
			return result;
		}

		const_iterator end() const {
			const_iterator result(this->treeInstance.getEndNode()); 
			return (result);
		}

	      reverse_iterator rbegin() {
			  return (reverse_iterator(this->end()));
		  }

		  const_reverse_iterator rbegin() const {
			  return (reverse_iterator(this->end()));
		  }
		  
		  reverse_iterator rend() {
			return (reverse_iterator(this->begin()));
		  }
		  
		  const_reverse_iterator rend() const {
			return (reverse_iterator(this->begin()));
		  }
		
		//	Capacity:

		bool empty() const {
			return ((treeInstance.size == 0) ?	true : false);
		}

		size_type size() const {
			return (treeInstance.size);
		}

		size_type max_size() const {
			size_t diffTypeMax = std::numeric_limits<size_type>::max() / sizeof(T);
			return diffTypeMax;
		}
		
		//Element access:

		mapped_type& operator[] (const key_type& k) {
			return (*( (this->insert(make_pair(k,mapped_type()) ) ).first)).second;
		}

     	mapped_type& at (const key_type& k) {
			Nodeptr result = this->_helperFindNode(k);
			if (result == NULL)
				throw std::out_of_range(" out_of_range ");
			return (result->pair.second);
		}

		const mapped_type& at (const key_type& k) const {
			Nodeptr result = this->_helperFindNode(k);
			if (result == NULL)
				throw std::out_of_range(" out_of_range ");
			return (result->pair.second);			
		}

		// Modifiers

		pair<iterator,bool> insert (const value_type& val) {
			this->treeInstance.resultInsert = false;
			this->_helperInsert(val);
			iterator iter(this->treeInstance.pointerResultInsert);
			ft::pair<iterator, bool> result(iter, this->treeInstance.resultInsert);
			return (result);
		}

		iterator insert (iterator position, const value_type& val) {
			this->_helperInsert(val);
			iterator iter(this->treeInstance.pointerResultInsert);
			return (iter);
		}
		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			for (InputIterator iter = first; iter != last; iter++)
				this->_helperInsert(*iter);
		}


		void erase (iterator position) {
			this->treeInstance._helpererasePos(position.base());
//			this->treeInstance._helpererase(position->first);
//			this->_helperEraseNode(position->first);
		}

		size_type erase (const key_type& k) {
			size_type sizeBefore = this->size();
			this->_helperEraseNode(k);
			size_type sizeAfter = this->size();
			return (sizeBefore - sizeAfter);
		}

		void erase (iterator first, iterator last) {
			key_type key1;
			key_type key2 = last->first;
			iterator iter1;

			for (iterator iter = first; iter->first != key2; ) {
				iter1 = iter;
				iter1++;
				key1 = iter1->first;
				erase(iter);
				iter = find(key1);
			}
		}

		void swap (map& x) {
			this->treeInstance.swap(x.treeInstance);
		}

		void clear() {
			this->treeInstance._helperdeleteTree();
	//		while (this->treeInstance.size != 0)
	//			this->erase(this->begin());
		}


	// Observers:
		key_compare key_comp() const {
			return (this->treeInstance._compare);
		}

		friend class value_compare;

		class value_compare : std::binary_function<value_type,value_type, bool>
		{
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
					}
		};
		
		value_compare value_comp() const {
			return value_compare(this->treeInstance._compare);
	}

	//Operations:
		iterator find (const key_type& k) {
			Nodeptr result = this->_helperFindNode(k);
			iterator resultIter(result);
			return resultIter;
		}
			
		const_iterator find (const key_type& k) const {
			Nodeptr result = this->_helperFindNode(k);
			const_iterator resultIter(result);
			return resultIter;			
		}
			
		size_type count (const key_type& k) const {
			Nodeptr result = this->_helperFindNode(k);
			if (result == NULL)
				return 0;
			return 1;
		}
		
		iterator lower_bound (const key_type& k) {
			Nodeptr result = this->_helperFindBound(k);
			iterator	resultIter(result);
			if (resultIter == NULL)
				resultIter = this->end();
			else if (this->treeInstance._compare(resultIter->first, k) == true)
				resultIter++;
			return resultIter;
		}
		
		const_iterator lower_bound (const key_type& k) const {
			Nodeptr result = this->_helperFindBound(k);
			const_iterator	resultIter(result);
			if (resultIter == NULL)
				resultIter = this->end();
			else if (this->treeInstance._compare(resultIter->first, k) == true)
				resultIter++;
			return resultIter;
		}

		iterator upper_bound (const key_type& k) {
			Nodeptr result = this->_helperFindBound(k);
			iterator	resultIter(result);
			if (resultIter == NULL)
				resultIter = this->end();
			else if (this->treeInstance._compare(k, resultIter->first) == false)
				resultIter++;
			return resultIter;
		}

		const_iterator upper_bound (const key_type& k) const {
			Nodeptr result = this->_helperFindBound(k);
			const_iterator	resultIter(result);
			if (resultIter == NULL)
				resultIter = this->end();
			else if (this->treeInstance._compare(resultIter->first, k) == true)
				resultIter++;
			return resultIter;
		}

		pair<const_iterator, const_iterator> equal_range (const key_type& k) const {
			const_iterator firstIter = lower_bound(k);
			const_iterator secondIter = upper_bound(k);
			pair<const_iterator, const_iterator> result = ft::make_pair(firstIter, secondIter);
			return result;
		}

		pair<iterator,iterator> equal_range (const key_type& k) {
			iterator firstIter = lower_bound(k);
			iterator secondIter = upper_bound(k);
			pair<iterator,iterator> result = ft::make_pair(firstIter, secondIter);
			return result;
		}

		//Allocator:
		allocator_type get_allocator() const {
			return (this->treeInstance._Alloc);
		}
	};

		template< class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs ) {
			if (lhs.size() != rhs.size())
				return false;
			typename ft::map<Key,T>::const_iterator lhsIter = lhs.begin();
			typename ft::map<Key,T>::const_iterator rhsIter = rhs.begin();
			for (; (lhsIter != lhs.end()) && (rhsIter != rhs.end()); lhsIter++, rhsIter++) {
				if (*lhsIter != *rhsIter)
					return false;
			}
			return true;
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (!(lhs == rhs));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (!(std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())));	
						}

		template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
					}

		template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (!(std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));	
						}
}
