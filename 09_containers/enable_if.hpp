#pragma once

namespace ft
{
//	 warning: default template arguments for a function template are a C++11 extension 
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };
}


