# Rust-like std for C++

A C++ 20 module of Rust-like std.  

C++’s language features are exciting, but I’m tired of the std.  
Made this for coding with C++ easier.  

## Require
- clang 21+
- gcc 15+

## Documents
TODO

## Installation
```cmake
FetchContent_Declare(
  rstd
  GIT_REPOSITORY https://github.com/hypengw/rstd.git
  GIT_TAG master
  # GIT_TAG <commit>
  EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(rstd)
```

## Related
[Type Systems for Memory Safety](https://borretti.me/article/type-systems-memory-safety)  
[Borrowing Trouble: The Difficulties Of A C++ Borrow-Checker](https://docs.google.com/document/d/e/2PACX-1vSt2VB1zQAJ6JDMaIA9PlmEgBxz2K5Tx6w2JqJNeYCy0gU4aoubdTxlENSKNSrQ2TXqPWcuwtXe6PlO/pub)  
[rusty-cpp](https://github.com/shuaimu/rusty-cpp): Bringing Rust's safety to C++  
[fragile](https://github.com/shuaimu/fragile): A polyglot compiler that supports Rust, C++, Go  
[cxx](https://github.com/dtolnay/cxx): Safe interop between Rust and C++  
