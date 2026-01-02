# Rust-like std for C++

A C++ 20 module of Rust-like std.  

## Compiler
- clang 21+

## Planned
- [x] trait
- [x] option
- [x] result
- [x] convert
- [ ] iter
- [ ] slice
- [ ] mem
- [ ] thread
- alloc
  - [x] box
  - [x] rc
  - [x] arc
- sync
  - [ ] mpmc
  - [ ] mpsc
  - [ ] once
- [ ] match/enum

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
