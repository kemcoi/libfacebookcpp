This document is meant to serve as a reference to the coding style guidelines to be used and enforced by LibFacebookCpp. Most of the style is adopted from various open-source projects and The [Google C++ Style Guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml).

We've explicitly tried to keep this document as small as possible. Hence, while this document is not complete, please try to follow the existing coding conventions and try to use common sense<sup>TM</sup> where applicable.

# Constructors #
  * Use the `explicit` keyword on constructors with just one parameter to prevent an object from being accidentally constructed
  * Provide an implementation of a copy constructor and an assignment operator when required. If the default implementation is to be disabled, use the `DISALLOW_COPY_AND_ASSIGN` macro. If the default implementation suffices, leave it as is.

# Operator Overloading #
  * Under no circumstances are "exotic" operators, such as `operator()` or `operator&` are to be overloaded.

# Functions #
  * Try to keep functions clean.
  * Group the functions in the order of in-param first and then out-param.
  * Refer to all in-params as `const&`. This, among other things, saves many cycles such as not copying a string.
  * Refer to all out-params as pointers to the memory location.
  * Do not return complex objects such as `std::list<>`. If possible, return them using an out param.
  * If returning a pointer to an allocated object, wrap the pointer in an `auto_ptr`.
  * Mark the parameters using `IN` or `OUT` macros.

# Control Flow #
  * Do not write code with multiple returns. Only one return at the end of the each function is allowed.
  * Do not use `goto`.
    * **Note**: Using some macro-magic, our codebase will fail to compile if any `goto` instances are found.

# Casts #
  * Do not use C-style cast and `reinterpret_cast`.
  * Use `static_cast`.
  * Use `dynamic_cast` sparingly.
  * Under no circumstances is `const_cast` to be used.
    * **Note**: Using some macro-magic, our codebase will fail to compile if any `const_cast` instances are found.

# Asserts #
  * Use `ASSERT()` if something is fully expected.
    * **Note**: Our codebase instructs the compiler to assume that the given condition is valid after the assert is hit. This means that the compiler is free to optimize out the code marked as such, reducing code paths.
  * Use `CASSERT()` if you wish to enforce any compile-time assertions.