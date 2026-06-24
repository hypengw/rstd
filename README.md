# Rust-like std for C++

A C++ 20 module of Rust-like std.  

C++’s language features are exciting, but I’m tired of the std.  
Made this for coding with C++ easier.  

I believe a standalone static-library std can solve many C++ pain points.  
It doesn't have to mirror another language's stdlib — it could be designed to fit C++ idioms better.  
My time is limited, so I anchored the design on Rust's std.

## Require
- clang 18+
- gcc 15+
- windows(clang 22+ with msvc std header)

## limitation
### Linear Type
C++ has no linear type support, so types like NotNull and Unique cannot be fully enforced.  
This project keeps them as part of the API and provides memcpy-like checks for null state.  

### Choice(match)
No good design for a general Choice interface yet. Option/Result are implemented independently for now and may migrate once a Choice API is designed.  

### Auto Trait
Could perhaps be done with some C++20 reflection magic, but I plan to wait for C++26.

### Todo
- **collections**: HashMap, BTreeMap
- **fs**: Path, File, read / write / metadata
- **net**: TcpStream, TcpListener, UdpSocket
- **sync**: RwLock, Condvar, Barrier, Once
- **async**: Future, async / await
- **os**: OsString / OsStr
- **error**: Error trait (defined, not widely used)

## [Documents](https://hypengw.github.io/rstd/)
work in progress

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
[rusty-cpp](https://github.com/shuaimu/rusty-cpp): Bringing Rust's safety to C++  
[fragile](https://github.com/shuaimu/fragile): A polyglot compiler that supports Rust, C++, Go  
[cxx](https://github.com/dtolnay/cxx): Safe interop between Rust and C++  
[pollcoro](https://github.com/troymoder/pollcoro): Coroutine library using polling instead of the traditional resume-based approach
