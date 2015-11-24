/*
  Template Instantiation : Two Phase Lookup

  Simple example of the two phase lookup principle.
*/

#include <iostream>

/* Function template. */
template <typename T> void foo(T param) {
  std::cout << "foo(" << typeid(T).name() << ")" << std::endl;
}

/* Function template that calls two functions. The first time this function is
 * parsed, a call is made to the function template 'foo' with the integer
 * literal '10', as this function call is not dependant on a template parameter,
 * it is compiled in the first phase, however the call with the variable 'var'
 * is dependant on the type of 'var' the template parameter 'T', therefore the
 * lookup cannot be performed and the compilation is defered to the second
 * phase. When the function template 'bar' is called from 'main' this triggers
 * instantaition of the function template, and once instantiated the second call
 * the the variable 'var' can be compiled. */
template <typename T> void bar(T var) {
  /* The lookup for the first call is done in phase one as it does not contain
   * any template dependent types. */
  foo(10);

  /* The lookup for the second call is differed to phase two as it contains the
   * template dependant type 'T' in it's argument 'var'. */
  foo(var);
}

/* Simple program which calls two functions, which are compiled in different
 * phases. */
int main() { bar<float>(1.2f); }