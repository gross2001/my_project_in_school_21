#pragma once
#include "is_same.hpp"
#include "enable_if.hpp"
#include "iterators_traits.hpp"

namespace ft
{
	template<typename _Iterator, typename _Container>
	class randomAccessIterator
	{
	private:
		_Iterator	current;
	public:
		typedef typename iterator_traits<_Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<_Iterator>::value_type 		value_type;
		typedef typename iterator_traits<_Iterator>::pointer 		pointer;
		typedef typename iterator_traits<_Iterator>::reference 		reference;
		typedef typename std::random_access_iterator_tag			iterator_category;
		typedef _Iterator											iterator_type;
	public:
		randomAccessIterator() {};
		randomAccessIterator(randomAccessIterator const& iter) : current(iter.base()) {};
		randomAccessIterator(pointer ptr) : current(ptr) {};
		
		// Allow iterator to const_iterator conversion
		template<typename _Iter>
        randomAccessIterator(const randomAccessIterator<_Iter,
			  typename ft::enable_if<ft::is_same<_Iter, typename _Container::pointer>::value,
		      _Container>::type >& iter) 
        : current(iter.base())  { };

		randomAccessIterator& operator=(randomAccessIterator const& rhs) {
			this->current = rhs.current;
			return (*this);
		}
		
		const _Iterator& base() const {
			return (current); 
		}

		bool operator==(randomAccessIterator const& other) const {
			return (this->current == other.current);
		}

		bool operator!=(randomAccessIterator const& other) const {
			return !(this->current == other.current);
		}

		reference operator*() const {
			return *current;
		}
		
		pointer operator->() const {
			return current;
		}

		randomAccessIterator operator++() { //prefix increment
			(this->current)++;
			return (*this);
		}
	
		randomAccessIterator operator++(int) { //postfix increment
			randomAccessIterator beforeIncr(*this);
			(this->current)++;
			return (beforeIncr);
		}
		
		randomAccessIterator operator--() {
			(this->current)--;
			return (*this);
		}
		
		randomAccessIterator operator--(int) {
			randomAccessIterator beforeIncr(*this);
			(this->current)--;
			return (beforeIncr);
		};

		randomAccessIterator& operator+=(difference_type n) {
			this->current += n;
			return (*this);
		}

		friend randomAccessIterator<_Iterator, _Container> operator+(randomAccessIterator<_Iterator, _Container> const& a, 
				difference_type n) {
			randomAccessIterator<_Iterator, _Container> result = a;
			result.current += n;
			return (result);
		}

		friend randomAccessIterator<_Iterator, _Container> operator+(difference_type n ,
				const randomAccessIterator<_Iterator, _Container>& a) {
			randomAccessIterator<_Iterator, _Container> result = a;
			result.current += n;
			return (result);
			}

		randomAccessIterator& operator-=(difference_type n) {
			this->current -= n;
			return (*this);
		}

		friend randomAccessIterator<_Iterator, _Container> operator-(const randomAccessIterator<_Iterator, _Container>& a,
				difference_type n) {
			randomAccessIterator<_Iterator, _Container> result = a;
			result.current -= n;
			return (result);
		}

		friend difference_type operator-(const randomAccessIterator<_Iterator, _Container>& a, 
				const randomAccessIterator<_Iterator, _Container>& b) {
			return (a.current - b.current);
		}

		friend bool operator<(const randomAccessIterator<_Iterator, _Container>& a, const randomAccessIterator<_Iterator, _Container>& b) {
			if (a.current < b.current)
				return true;
			return false;
		}

		friend bool operator>(const randomAccessIterator<_Iterator, _Container>& a, const randomAccessIterator<_Iterator, _Container>& b) {
			if (a.current > b.current)
				return true;
			return false;
		}

		friend bool operator<=(const randomAccessIterator<_Iterator, _Container>& a, const randomAccessIterator<_Iterator, _Container>& b) {
			if (a.current <= b.current)
				return true;
			return false;
		}

		friend bool operator>=(const randomAccessIterator<_Iterator, _Container>& a, const randomAccessIterator<_Iterator, _Container>& b) {
			if (a.current >= b.current)
				return true;
			return false;
		}				

    	reference operator[](difference_type n) const {
			return *(*this + n);
		}
	};
}
