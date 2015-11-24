/*
  Template Instantiation : Instantiation

  Simple example of the instantiation of a template id.
*/

#include <iostream>

/* Function template with an explicit, a default and a function parameter
 * deduceable template parameter. When the function template 'create' is called
 * from 'main' with the determined template arguments 'foo', 'float' and '5',
 * the body is instantiated to allocate a new pointer of type foo and construct
 * it with the float parameter and the int value '5', and then return the
 * pointer. */
template <typename S, typename T, int D = 5> S *create(T param) {
  S *s = new S(param, D);
  return s;
}

/* Struct that is constructable from the 'create' function. */
struct foo {
  foo(float param, int value) {
    std::cout << "foo:foo(float, " << value << ")" << std::endl;
  }
};

int main() {
  /* The create function body is instantiated to
  create an instance of foo with a float parameter
  and return that instance by value. */
  auto f = create<foo>(10.0f);
}