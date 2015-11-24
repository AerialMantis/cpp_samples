/*
  Template Instantiation : Name Lookup

	Simple example of a qualified and unqualified name lookup.
*/

#include <iostream>

namespace bar {

/* Function template defined in the bar namespace. */
template <typename T>
void foo() {
	std::cout << "bar::foo()" << std::endl;
}

}  // namespace bar

/* Function template defined in the global namespace. */
template <typename T>
void foo() {
	std::cout << "foo()" << std::endl;
}

/* Simple program which calls two functions, one triggering a qualified name
 * lookup, the other triggering an unqualified name lookup. */
int main() {

  /* This function call triggers a qualified name lookup as it as it has a
   * namespace qualifier. */
  bar::foo<int>();

  /* This function call triggers an unqualified name lookup as it does not have
   * any scope qualifier. */
  foo<int>();
}