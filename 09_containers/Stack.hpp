#pragma once

#include "vector.hpp"
#include <stack>

namespace ft
{
	template< class _Tp, class Container = ft::vector<_Tp> > 
	class stack
	{
		protected:
		Container c;

		public:
		typedef typename Container::value_type			value_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference	const_reference;
		typedef typename Container::size_type			size_type;
		typedef	       	Container						container_type;

		explicit stack (const container_type& ctnr = container_type()) {
			c = ctnr;
		}

		const_reference	top() const
		{
			return c.back();
		}

		bool	empty() const
		{
			return c.empty();
		}

		void	push(value_type instance)
		{
			c.push_back(instance);
		}

		void	pop()
		{
			c.pop_back();
		}

		size_type	size()
		{
			return c.size();
		}

		friend bool operator==( const ft::stack<_Tp,Container>& lhs, const ft::stack<_Tp,Container>& rhs ) {
			return (lhs.c == rhs.c);
		}
		
		friend bool operator!=( const ft::stack<_Tp,Container>& lhs, const ft::stack<_Tp,Container>& rhs ) {
			return (lhs.c != rhs.c);
		}

		friend bool operator<( const ft::stack<_Tp,Container>& lhs, const ft::stack<_Tp,Container>& rhs ) {
			return (lhs.c < rhs.c);
			}

		friend bool operator<=( const ft::stack<_Tp,Container>& lhs, const ft::stack<_Tp,Container>& rhs ) {
			return (lhs.c <= rhs.c);
		}
	
		friend bool operator>( const ft::stack<_Tp,Container>& lhs, const ft::stack<_Tp,Container>& rhs ) {
			return (lhs.c > rhs.c);
		}
	
		friend bool operator>=( const ft::stack<_Tp,Container>& lhs, const ft::stack<_Tp,Container>& rhs ) {
			return (lhs.c >= rhs.c);
		}
	};
}
