**While lack of time has prevented me from doing lots of work on this project, I've started to work on a C-port of this library for better compatibility. Work will be done to provide a C++ wrapper around the C library to allow the classes to be invoked in a manner similar to the current.**

libfacebookcpp is a library allowing access to the Facebook platform using the Graph API in C++. The external libraries used are libcurl, jsoncpp and Boost.

libfacebookcpp tries to abstract away the complexity of interoperability with Facebook's Graph API, such as building URIs, POST data and parsing objects. It uses libcurl to instantiate HTTP Requests and uses jsoncpp to parse the responses sent by Facebook. It then allows the linking code to interact with regular, type-safe, C++ classes.

The abstraction provided by libfacebookcpp is good enough for the calling code to not worry about any underlying details, including but not limited to the HTTP requests made. At the same time, it allows the programmer using the library to use the existing Graph API documentation to understand the inner working of the library.

This project is not affiliated with Facebook in any way or form.