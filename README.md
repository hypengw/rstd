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

## Progress

| Module | Area | Types & APIs |
|--------|------|-------------|
| **core** | types | `Option<T>`, `Result<T,E>` |
| | traits | `Impl` / `dyn` dispatch, `Clone`, `Copy`, `From` / `Into` / `AsRef` / `AsMut`, `PartialEq` (partial) |
| | fmt | `Display`, `Debug`, `Formatter`, `format_string`, `Arguments` |
| | ptr | `NonNull<T>`(just api, no linear type support), `ref<T>`, `mut_ref<T>`, `dyn<Trait>` |
| | mem | `ManuallyDrop`, `MaybeUninit`|
| | str | `str`, `CStr` |
| | num | `NonZero`, integer traits |
| | sync | `Atomic<T>`, memory ordering |
| | ops | `FnOnce`, `FnMut`, `Fn` |
| | misc | `Hash` / `Hasher`, `Duration`, `panic` / `PanicInfo`, `slice` (partial) |
| **alloc** | containers | `Box<T>`, `Vec<T>`, `String`, `CString` |
| | shared ownership | `Rc<T>` / `Weak<T>`, `Arc<T>` / `Weak<T>` |
| | allocator | `Layout`, `Global`, `alloc` / `dealloc` |
| **std** | io | `Read`, `Write`, `Seek`, `BufRead` traits, `BufReader` / `BufWriter`, `Cursor<T>`, `Stdin` / `Stdout` / `Stderr`, `io::Error`, `print` / `println` / `eprint` / `eprintln` |
| | thread | `spawn`, `sleep`, `park`, `yield_now`, `JoinHandle<T>`, `Builder`, `ThreadId` |
| | sync | `Mutex<T>` / `MutexGuard`, `mpsc::channel` / `sync_channel` |
| | process | `Command`, `Child`, `ExitStatus`, `Stdio`, `Output`, `ChildStdin` / `ChildStdout` / `ChildStderr` (impl Read/Write), `abort`, `exit`, `id` |
| | env | `var`, `set_var`, `remove_var` |
| | time | `Instant`, `SystemTime`, `Duration` |
| **runtime** | defaults | default allocator (`operator new`), panic handler (`rstd_panic_impl`) |

### Not yet implemented
- **iter**: Iterator / IntoIterator
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
[Borrowing Trouble: The Difficulties Of A C++ Borrow-Checker](https://docs.google.com/document/d/e/2PACX-1vSt2VB1zQAJ6JDMaIA9PlmEgBxz2K5Tx6w2JqJNeYCy0gU4aoubdTxlENSKNSrQ2TXqPWcuwtXe6PlO/pub)  
[rusty-cpp](https://github.com/shuaimu/rusty-cpp): Bringing Rust's safety to C++  
[fragile](https://github.com/shuaimu/fragile): A polyglot compiler that supports Rust, C++, Go  
[cxx](https://github.com/dtolnay/cxx): Safe interop between Rust and C++  
