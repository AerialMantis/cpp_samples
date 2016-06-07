/*
  Template Meta Programming : Compile-time Functions

  Simple example of compile-time functions.
*/

#include <iostream>

/* Simple runtime function taking two integer paramters and returning their sum.
 */
int runtime_add(int a, int b) { return a + b; }

/* Simple compile-time function taking two integer parameters and returning
 * their sum. */
template <int a, int b> struct compile_time_add {
  enum { value = (a + b) };
};

/* Simple compile-time function taking a type parameter and returning it as a
 * pointer type. */
template <typename t> struct as_ptr { using type = t *; };

int main() {

  /* Example of a runtime function. */
  {
    int a = 3, b = 5, c = 7;

    int r1 = runtime_add(a, b);
    int r2 = runtime_add(a, c);

    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
  }

  /* Example of a compile-time function for constant values. */
  {
    const int a = 3, b = 5, c = 7;

    const int r1 = compile_time_add<a, b>::value;
    const int r2 = compile_time_add<a, c>::value;

    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
  }

  /* Example of a compile-time function for types. */
  {
    using a = int;
    using b = float;

    using r1 = as_ptr<a>::type;
    using r2 = as_ptr<b>::type;

    std::cout << typeid(r1).name() << std::endl;
    std::cout << typeid(r2).name() << std::endl;
  }
}