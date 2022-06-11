#pragma once

#include "RandomAccessIterator.hpp"
#include "iterators_traits.hpp"

namespace ft
{
	template< class Iterator >
	class reverse_iterator
	{
	public:
		typedef	Iterator	iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;
	private:
		Iterator itr;
	public:
		reverse_iterator() {}

		explicit reverse_iterator(iterator_type itr): itr(itr) { }

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it): itr(rev_it.itr) { }

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ) {
			this->itr = other.iter;
		}

		iterator_type base() const {
			return itr;
		}

		reference operator*()  {
			Iterator tmp = itr;
			return *(--tmp); // <== returns the content of prev 
		}

		reverse_iterator operator+ (difference_type n) {
			itr -= n;
			return (*this);
		}

		reverse_iterator& operator++() {
		//	std::cout << " itr before " << itr->first << " ";
			itr--;
		//	std::cout << " itr after " << itr->first << " ";

			return *this;
		}

		reverse_iterator  operator++(int) { //post
		//	std::cout << " ++ this" << this->itr->first << " " << this->itr->second  << std::endl;
			reverse_iterator temp = *this;
			++(*this);
		//	std::cout << " ++ this" << this->itr->first << " " << this->itr->second  << std::endl;
		//	std::cout << " ++ temp" << temp.itr->first << " " << temp.itr->second << std::endl;
			return temp;
		}

		reverse_iterator& operator+= (difference_type n) {
			itr -= n;
			return (*this);
		}

		reverse_iterator operator- (difference_type n) {
			itr += n;
			return (*this);
		}

		reverse_iterator& operator--() {
			++itr;
			return *this;
		}

		reverse_iterator  operator--(int) { //post
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

		reverse_iterator& operator-= (difference_type n) {
			itr += n;
			return (*this);			
		}

		pointer operator->() {
			return &(operator*());
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return itr.operator[](n);
		}
	};
	
	template <class Iterator> 
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();	   
				   }

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
					}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();	   
					}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();	   
					}

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();	   
					}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() <= rhs.base();	   						
					}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it) {
		reverse_iterator<Iterator> result = rev_it;
		result.base() -= n;
		return (result);
			}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
    		const reverse_iterator<Iterator>& lhs,
    		const reverse_iterator<Iterator>& rhs) {
		typename reverse_iterator<Iterator>::difference_type result;
		result = lhs.base() - rhs.base();
		return (result);
			}		
}
