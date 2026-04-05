# Rust-like std for C++

A C++ 20 module of Rust-like std.  

C++’s language features are exciting, but I’m tired of the std.  
Made this for coding with C++ easier.  

## Require
- clang 18+
- gcc 15+
- windows(clang 22+)

## Progress

### core
| Feature | Status |
|---------|--------|
| Option\<T\> | done |
| Result\<T, E\> | done |
| fmt (Display, Debug, format) | done |
| Trait system (Impl, dyn dispatch) | done |
| Clone, Copy, Send, Sync markers | done |
| From / Into / AsRef / AsMut | done |
| PartialEq, Ord | partial |
| ptr (NonNull, ref, mut_ref, dyn) | done |
| mem (ManuallyDrop, MaybeUninit, transmute) | done |
| Pin\<T\> | done |
| str, CStr | done |
| num (NonZero, integer) | done |
| Atomic\<T\> | done |
| Hash, Hasher | done |
| Duration | done |
| FnOnce / FnMut / Fn | done |
| panic (PanicInfo, Location) | done |
| slice | partial |

### alloc
| Feature | Status |
|---------|--------|
| Box\<T\> | done |
| Vec\<T\> | done |
| String | done |
| Rc\<T\> / Weak\<T\> | done |
| Arc\<T\> / Weak\<T\> | done |
| Layout, Global allocator | done |
| CString | done |

### std
| Feature | Status |
|---------|--------|
| Read / Write / Seek / BufRead traits | done |
| Stdin / Stdout / Stderr | done |
| BufReader / BufWriter | done |
| Cursor\<T\> | done |
| io::Error | done |
| print / println / eprint / eprintln | done |
| Thread (spawn, sleep, park, yield) | done |
| JoinHandle\<T\> | done |
| Mutex\<T\> / MutexGuard | done |
| mpsc (channel, sync_channel) | done |
| Instant / SystemTime | done |
| process::abort | done |

### runtime
| Feature | Status |
|---------|--------|
| Default allocator (operator new) | done |
| Panic handler (rstd_panic_impl) | done |

### Not yet implemented
- Iterator / IntoIterator
- HashMap / BTreeMap
- Error trait (defined, not widely used)
- Future / async
- RwLock / Condvar / Barrier
- Path / File / fs
- net (TcpStream, UdpSocket)
- env, process (spawn)

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
[Borrowing Trouble: The Difficulties Of A C++ Borrow-Checker](https://docs.google.com/document/d/e/2PACX-1vSt2VB1zQAJ6JDMaIA9PlmEgBxz2K5Tx6w2JqJNeYCy0gU4aoubdTxlENSKNSrQ2TXqPWcuwtXe6PlO/pub)  
[rusty-cpp](https://github.com/shuaimu/rusty-cpp): Bringing Rust's safety to C++  
[fragile](https://github.com/shuaimu/fragile): A polyglot compiler that supports Rust, C++, Go  
[cxx](https://github.com/dtolnay/cxx): Safe interop between Rust and C++  
