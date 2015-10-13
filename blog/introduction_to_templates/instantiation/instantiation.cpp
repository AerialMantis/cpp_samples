/*
  Introduction to Templates : Instantiation

	Simple example of a function template.
*/

#include <iostream>

/* Function template that defines a generic groups of functions that take two
 * reference parameters of the same type and swaps their values. */
template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

/* Simple program which calls the function template swap and triggers implicit
 * instantiation. */
int main() {
  int a = 2, b = 5;
  
	std::cout << "before" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << b << std::endl;

	swap(a, b);

	std::cout << "after" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << b << std::endl;
}