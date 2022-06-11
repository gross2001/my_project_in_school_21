#pragma once

namespace ft
{
	//remove volatile
	template<typename _Tp>
	struct remove_volatile
	{ typedef _Tp     type; };

	template<typename _Tp>
	struct remove_volatile<_Tp volatile>
	{ typedef _Tp     type; };

	// remove const
	template<typename _Tp>
	struct remove_const
	{ typedef _Tp     type; };

	template<typename _Tp>
	struct remove_const<_Tp const>
	{ typedef _Tp     type; };

	//remove const and volatile
	template<typename _Tp>
	struct remove_cv
	{ typedef typename remove_const<typename remove_volatile<_Tp>::type>::type	type; };


	template<typename _Tp, _Tp __v>
	struct integral_constant
	{
	public:
		const static _Tp                  		value = __v;
		typedef integral_constant<bool, value>	type;
		typedef bool							value_type;		
		operator value_type() const 			{ return value; }
	};

	typedef integral_constant<bool, true>     true_type;
	typedef integral_constant<bool, false>    false_type;

	template<typename>
	struct is_integral_helper : public false_type { };

	template<>
	struct is_integral_helper<bool> : public true_type { };

	template<>
	struct is_integral_helper<char> : public true_type { };

	template<>
	struct is_integral_helper<wchar_t> : public true_type { };

	template<>
	struct is_integral_helper<signed char> : public true_type { };

	template<>
	struct is_integral_helper<short int> : public true_type { };

	template<>
	struct is_integral_helper<int> : public true_type { };

	template<>
	struct is_integral_helper<long int> : public true_type { };

	template<>
	struct is_integral_helper<unsigned char> : public true_type { };

	template<>
	struct is_integral_helper<unsigned short int> : public true_type { };

	template<>
	struct is_integral_helper<unsigned int> : public true_type { };

	template<>
	struct is_integral_helper<unsigned long int> : public true_type { };

/*	template<>
	struct is_integral_helper<char16_t> : public true_type { };

	template<>
	struct is_integral_helper<long long> : public true_type { };

	template<>
	struct is_integral_helper<unsigned long long> : public true_type { };
*/

	template<typename _Tp>
	struct is_integral: public is_integral_helper<typename remove_cv<_Tp>::type>::type { };
}
