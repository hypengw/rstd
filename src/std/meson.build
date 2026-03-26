rstd_std_sources = [
  'mod.cppm',
  'mod.cpp',
  'time.cppm',
  'alloc.cppm',
  'forward.cppm',
  'error.cppm',
  'panicking.cppm',
  'process.cppm',
  'ffi/mod.cppm',
]

# sys sources
rstd_std_sources += [
  'sys/mod.cppm',
  'sys/io/mod.cppm',
  'sys/libc/mod.cppm',
  'sys/libc/pthread.cppm',
  'sys/libc/unix.cppm',
  'sys/libc/libc.cppm',
  'sys/pal/mod.cppm',
  'sys/pal/unix/mod.cppm',
  'sys/pal/unix/futex.cppm',
  'sys/pal/unix/time.cppm',
  'sys/pal/unix/sync/mutex.cppm',
  'sys/pal/unix/sync/condvar.cppm',
  'sys/pal/unix/sync/mod.cppm',
  'sys/pal/windows/mod.cppm',
  'sys/pal/windows/futex.cppm',
  'sys/pal/windows/time.cppm',
  'sys/sync/once_box.cppm',
  'sys/sync/mutex/mod.cppm',
  'sys/sync/mutex/futex.cppm',
  'sys/sync/mutex/pthread.cppm',
  'sys/sync/once/mod.cppm',
  'sys/sync/once/futex.cppm',
  'sys/sync/thread_parking/mod.cppm',
  'sys/sync/thread_parking/futex.cppm',
  'sys/sync/thread_parking/pthread.cppm',
  'sys/thread/mod.cppm',
  'sys/thread/unix.cppm',
  'sys/thread/windows.cppm',
  'sys/pal/unix/futex.cpp',
  'sys/pal/windows/futex.cpp',
  'sys/sync/once/futex.cpp',
  'sys/sync/thread_parking/futex.cpp',
  'sys/sync/thread_parking/pthread.cpp',
]

# io sources
rstd_std_sources += [
  'io/mod.cppm',
  'io/error.cppm',
]

# thread sources
rstd_std_sources += [
  'thread/mod.cppm',
  'thread/id.cppm',
  'thread/thread.cppm',
  'thread/main_thread.cppm',
  'thread/builder.cppm',
  'thread/functions.cppm',
  'thread/join_handle.cppm',
  'thread/lifecycle.cppm',
  'thread/scoped.cppm',
  'thread/forward.cppm',
  'thread/current.cppm',
  'thread/thread.cpp',
]

# sync sources
rstd_std_sources += [
  'sync/mod.cppm',
  'sync/mutex.cppm',
  'sync/poison/mod.cppm',
  'sync/poison/once.cppm',
  'sync/mpsc/mod.cppm',
  'sync/mpsc/mpmc/mod.cppm',
  'sync/mpsc/mpmc/counter.cppm',
  'sync/mpsc/mpmc/array.cppm',
  'sync/mpsc/mpmc/list.cppm',
  'sync/mpsc/mpmc/utils.cppm',
  'sync/mpsc/mpmc/context.cppm',
  'sync/mpsc/mpmc/waker.cppm',
  'sync/mpsc/mpmc/select.cppm',
]

rstd_std = static_library('rstd.std',
  rstd_std_sources,
  dependencies : [rstd_core_dep, rstd_alloc_dep],
)

rstd_dep = declare_dependency(
  link_with : rstd_std,
  dependencies : [rstd_core_dep, rstd_alloc_dep],
  include_directories : include_directories('.'),
)

meson.override_dependency('rstd', rstd_dep)
