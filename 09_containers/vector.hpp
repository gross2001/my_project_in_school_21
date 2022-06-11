#pragma once

#include <memory>
#include <cstddef>
#include "RandomAccessIterator.hpp"
#include "reverse_iterator.hpp"
#include <limits>
#include <stdexcept>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include <algorithm>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> > 
	class vector
	{
	public:
		typedef 		 T									value_type;
		typedef 		 Allocator							allocator_type;
		typedef			 size_t								size_type;
		typedef typename std::ptrdiff_t						difference_type;
		typedef typename Allocator::reference 				reference;
		typedef	typename Allocator::const_reference  		const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;

		typedef	typename ft::randomAccessIterator<pointer, vector>			iterator;
		typedef	typename ft::randomAccessIterator<const_pointer, vector>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		
	private:
		pointer				_beginOfAlloc;
		size_type			_size;
		size_type			_capacity;
		allocator_type	 	_Alloc;

		void reallocationWithoutCopy(size_type newCapacity) {
				_Alloc.deallocate(_beginOfAlloc, _capacity);
				_beginOfAlloc = _Alloc.allocate(newCapacity);
				_capacity = newCapacity;
		}

		
		void reallocationWithCopy(size_type newCapacity) {
			pointer		pointerToMove = _Alloc.allocate(newCapacity);
			iterator	iterToMove(pointerToMove);
			for (iterator iter = this->begin(); iter != this->end(); iter++, iterToMove++)
				*iterToMove = *iter;
			_Alloc.deallocate(_beginOfAlloc, _capacity);
			_beginOfAlloc = pointerToMove;
			_capacity = newCapacity;
			if (_size > _capacity)
				_size = _capacity;
		}
	
	public:
		explicit vector (const allocator_type& alloc = allocator_type())
		{
			_Alloc = alloc;
			_size = 0;
			_capacity = 0;
			_beginOfAlloc = NULL;
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_Alloc = alloc;
			_beginOfAlloc = _Alloc.allocate(n);
			_size = n;
			_capacity = n;
			for (iterator iter = this->begin(); iter != this->end(); iter++)
				*iter = val;
		}
						
		template <class InputIterator>
		vector (typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, 
				InputIterator last, const allocator_type& alloc = allocator_type())
		{
			_Alloc = alloc;
			size_type n = last - first;
			// but can n always have enough space?
			if (n > max_size())
				throw std::length_error(" cannot create std::vector larger than max_size() ");
			_beginOfAlloc = _Alloc.allocate(n);
			iterator vectIter(_beginOfAlloc);
			for (InputIterator iter = first; iter != last; iter++, vectIter++)
				*vectIter = *iter;
			_size = n;
			_capacity = n;	
		}
				
		vector (const vector& x) {
			_size = x.size();
			_capacity = x.capacity();
			_beginOfAlloc = _Alloc.allocate(_capacity);
			iterator vectIter = this->begin();
			for (const_iterator iter = x.begin(); iter != x.end(); iter++, vectIter++)
				*vectIter = *iter;				
		}

		~vector() {
			if (_beginOfAlloc)
				_Alloc.deallocate(_beginOfAlloc, _capacity);
		}

		vector& operator= (const vector& x) {
			if (this->_capacity < x.size())
			{
				if (_beginOfAlloc)
					_Alloc.deallocate(_beginOfAlloc, _capacity);
				_beginOfAlloc = _Alloc.allocate(x.size());
				_capacity = x.size();
				_size = x.size();
			}
			iterator iter = this->begin();
			for (const_iterator xIter = x.begin(); xIter != x.end(); iter++, xIter++)
				*iter = *xIter;
			for ( ; iter != this->end(); iter++)
				*iter = value_type();
			return (*this);
		}

	//Element access
		reference at( size_type pos ) {
			if (pos >= size())
				throw std::out_of_range(" out of range ");
			return (*(_beginOfAlloc + pos));
		}
	
		const_reference at( size_type pos ) const {
			if (pos >= size())
				throw std::out_of_range(" out of range ");
			return (*(_beginOfAlloc + pos));				
		}

		reference operator[]( size_type pos ) {
			return (*(_beginOfAlloc + pos));
		}

		const_reference operator[]( size_type pos ) const {
			return (*(_beginOfAlloc + pos));
		}

		reference front() {
			return (*(_beginOfAlloc));
		}

		const_reference front() const {
			return (*(_beginOfAlloc));
		}

		reference back(){
			return (*(_beginOfAlloc + (_size - 1)));
		}

		const_reference back() const {
			return (*(_beginOfAlloc + (_size - 1)));
		}

		T* data() {
			return (_beginOfAlloc);
		}

		const T* data() const {
			return (_beginOfAlloc);
		}

	// capacity
		size_type 	size() const { return (_size); }
		size_type	capacity() const { return (_capacity);}

		bool empty() const {
			if (_size == 0)
				return true;
			return false;
		}

		size_type max_size() const {
			size_t diffTypeMax = std::numeric_limits<difference_type>::max() / sizeof(T);
			//size_t allocMax = std::allocator_traits<allocator_type>::max_size();
			return diffTypeMax;
		}

		void reserve( size_type new_cap ) {
			if (new_cap <= _capacity)
				return ;
			if (new_cap > max_size())
				throw (std::length_error(" length_error ") );
			try
			{					
				allocator_type 	alloc;
				pointer			beginOfalloc = alloc.allocate(new_cap);
				pointer			toMove = beginOfalloc;

				_capacity = new_cap;
				for (iterator iter = this->begin(); iter != this->end(); iter++, toMove++)
					*toMove = *iter;
				_Alloc = alloc;
				_beginOfAlloc = beginOfalloc;

			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}				
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < _size)
				_size = n;
			if (n > _capacity) {
				pointer	pointerToMove = _Alloc.allocate(n);
				iterator iterToMove(pointerToMove);
				for (iterator iter = this->begin(); iter != this->end(); iter++, iterToMove++)
					*iterToMove = *iter;
				_Alloc.deallocate(_beginOfAlloc,_capacity);
				_beginOfAlloc = pointerToMove;
				_capacity = n;					
			}
			if (n > _size) {
				iterator iterToFill = this->end();
				_size = n;
				for (iterator iter = iterToFill; iter != this->end(); iter++)
					*iter = val;
			}
		}

	// iterators
		iterator begin() {
			return (iterator(_beginOfAlloc));
		}
		
		const_iterator begin() const {
			return ( iterator(_beginOfAlloc));
		}

		iterator end() {
			return (iterator(_beginOfAlloc + _size));
		}

		const_iterator end() const {
			return (iterator(_beginOfAlloc + _size));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(this->end()));
		}
		
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(this->end()));
		}
		
		reverse_iterator rend() {
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend() const{
			return (const_reverse_iterator(this->begin()));
		}

	//Modifiers:
		void push_back( const T& value )
		{
			if (_size < _capacity)
			{
				*(_beginOfAlloc + _size) = value;
				_size += 1;
			}
			else
				{
					size_type n = _capacity * 2;
					if (n == 0) n = 1;
					allocator_type	 	AllocToMove;
					pointer	_beginOfAllocToMove = AllocToMove.allocate(n);
					pointer toMove = 	_beginOfAllocToMove;
					for (iterator iter = this->begin(); iter != this->end(); iter++, toMove++)
						*toMove =  *iter;
					*toMove = value;
					_Alloc.deallocate(_beginOfAlloc, _capacity);
					_Alloc = AllocToMove;
					_beginOfAlloc = _beginOfAllocToMove;
					_size += 1;
					_capacity = n;
				}
		}

		template <class InputIterator>
		void assign (typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, 
			InputIterator last) {
			size_type n = last - first;
			if (n > _capacity) 
				reallocationWithoutCopy(n);
			else {
				for (pointer p = _beginOfAlloc; p != _beginOfAlloc + _size; p++)
					_Alloc.destroy(p);
			}
			_size = n;
			iterator iterVect = this->begin();
			for (InputIterator iter = first; iter != last; iter++, iterVect++)
				*iterVect = *iter;				
			}
		
		void assign (size_type n, const value_type& val) {				
			if (n > _capacity) 
				reallocationWithoutCopy(n);
			else {
				for (pointer p = _beginOfAlloc; p != _beginOfAlloc + _size; p++)
					_Alloc.destroy(p);
			}
			_size = n;
			for (pointer p = _beginOfAlloc; p != _beginOfAlloc + _size; p++)
				_Alloc.construct(p, val);
		}

		void pop_back() {
			if (this->empty())
				return ;
			_Alloc.destroy(_beginOfAlloc + _size - 1);
			_size--;
		}

		iterator insert (iterator position, const value_type& val) {
			size_t diff = position - this->begin();
			size_t n = 1;
			if ((_size + n) > _capacity) {
				while (_capacity < (_size + n))
					_capacity *= 2;
				pointer beginOfNewAlloc = _Alloc.allocate(_capacity);
				iterator iterToMove(beginOfNewAlloc);
				for (iterator iter = this->begin(); iter != this->end(); iter++, iterToMove++) {
					if (iter == position)
						for (size_type i = 0; i < n; i++, iterToMove++)
							*iterToMove = val; 
				*iterToMove = *iter;
				}
				_beginOfAlloc = beginOfNewAlloc;
				_size += n;
			}
			else {
				for (iterator iter = this->end() - 1; iter >= position; iter--)
					*(iter + n) = *(iter);
				for (iterator iter = position; iter != (position + n); iter++)
					*iter = val;
				_size += n;
			}
			return (this->begin() + diff);
		}
		
		void insert (iterator position, size_type n, const value_type& val) {
			if ((_size + n) > _capacity) {
				_capacity = _size + n;
				pointer beginOfNewAlloc = _Alloc.allocate(_capacity);
				iterator iterToMove(beginOfNewAlloc);
				for (iterator iter = this->begin(); iter != this->end(); iter++, iterToMove++) {
					if (iter == position)
						for (size_type i = 0; i < n; i++, iterToMove++)
							*iterToMove = val; 
				*iterToMove = *iter;
				}
				_beginOfAlloc = beginOfNewAlloc;
				_size += n;
			}
			else {
				for (iterator iter = this->end() - 1; iter >= position; iter--)
					*(iter + n) = *(iter);
				for (iterator iter = position; iter != (position + n); iter++)
					*iter = val;
				_size += n;
			}
		}

		template <class InputIterator>
		void insert (iterator position, 
			typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, 
			InputIterator last) {
				size_t capacityTemp = _capacity;
				size_type n = last - first;
				if (( _size + n ) > capacityTemp) {
					while (capacityTemp < (_size + n))
						{
							capacityTemp *= 2;
							if (capacityTemp == 0)
								capacityTemp = _size + n;
						}
					pointer beginOfNewAlloc = _Alloc.allocate(capacityTemp);
					iterator iterToMove(beginOfNewAlloc);
					for (iterator iter = this->begin(); iter != position; iter++, iterToMove++)
						*iterToMove = *iter;
					for (InputIterator iter = first; iter != last; iter++, iterToMove++)
						*iterToMove = *iter;
					for (iterator iter = position; iter != this->end(); iter++, iterToMove++)
						*iterToMove = *iter;
					_beginOfAlloc = beginOfNewAlloc;
					_size += n;
					_capacity = capacityTemp;
				}
				else {
					for (iterator iter = this->end() - 1; iter >= position; iter--)
							*(iter + n) = *iter;
					iterator iterToMove = position;
					for (InputIterator iter = first; iter != last; iter++, iterToMove++)
						*iterToMove = *iter;
					_size += n;
				}
		}

		void clear() {
//			pointer end = _beginOfAlloc + _size;
//			for (pointer p = _beginOfAlloc; p != end; p++)
//				_Alloc.destroy(p);
//			_Alloc.deallocate(_beginOfAlloc, _size);
			_size = 0;
		}

		iterator erase( iterator pos ) {
			_Alloc.destroy(pos.base());
			for (pointer pointerAsIter = pos.base(); pointerAsIter != _beginOfAlloc + _size; pointerAsIter++)
				*pointerAsIter = *(pointerAsIter + 1);
			_size--;
			return pos;
		}

		iterator erase( iterator first, iterator last ) {
			size_type n = last - first;
			for (pointer pointerAsIter = first.base(); (pointerAsIter + n) != _beginOfAlloc + _size; pointerAsIter++) {
				_Alloc.destroy(pointerAsIter);
				*pointerAsIter = *(pointerAsIter + n);
			}
			_size -= n;
			return last;
		}

		void swap (vector& x) {
			pointer pointerToSwap = x._beginOfAlloc;
			x._beginOfAlloc = this->_beginOfAlloc;
			_beginOfAlloc = pointerToSwap;

			size_type bufferToSwap = x._size;
			x._size = this->_size;
			_size = bufferToSwap;

			bufferToSwap = x._capacity;
			x._capacity = this->_capacity;
			_capacity = bufferToSwap;
		}

		allocator_type get_allocator() const {
			return _Alloc;
		}
	};

		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			for(unsigned int n = 0; n != lhs.size(); n++)
				if (lhs[n] != rhs[n])
					return false;
			return true;
		}

		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return true;
			for(unsigned int n = 0; n != lhs.size(); n++)
				if (lhs[n] != rhs[n])
					return true;
			return false;				
		}

		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (!(std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())));
		}

		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}
		
		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (!(std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
		}

}

namespace std
{
	template<class T, class Allocator> 
    void swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs)
    {
		lhs.swap(rhs);
    }
}
