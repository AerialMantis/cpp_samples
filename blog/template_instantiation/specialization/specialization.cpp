/*
  Template Instantiation : Specialization

  Simple example of the different stages of specialization.
*/

#include <iostream>

/* Function template with a template parameter. */
template <typename T>
void function_a() {
  std::cout << "function_a(" << typeid(T).name() << ")" << std::endl;
}

/* Function template with a template parameter, that is the type of the function paramter. */
template <typename T>
void function_b(T t) {
  std::cout << "function_b(" << typeid(T).name() << ")" << std::endl;
}

/* Function template with a template parameter, that has a default argument. */
template <typename T = int>
void function_c() {
  std::cout << "function_c(" << typeid(T).name() << ")" << std::endl;
}


int main () {
  /* Typename 'T' is explicitly specified as
  'float'. */
  function_a<float>();

	/* Typename 'T' is deduced by the function
  parameter 'false' as 'bool'. */
  function_b(false);

	/* Typename 'T' is deduced by the default argument
  as 'int'. */
  function_c();
}