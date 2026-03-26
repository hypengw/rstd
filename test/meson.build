gtest_dep = dependency('gtest_main', required : false)
if not gtest_dep.found()
  gtest_proj = subproject('googletest')
  gtest_dep = gtest_proj.get_variable('gtest_main_dep')
endif

test_sources = [
  'trait.cpp',
  'result.cpp',
  'compile.cpp',
  'option.cpp',
  'clone.cpp',
  'convert.cpp',
  'alloc/rc.cpp',
  'alloc/str.cpp',
  'alloc/boxed.cpp',
  'alloc/vec.cpp',
  'alloc/sync.cpp',
  'alloc/string.cpp',
  'sys/sync/mutex/futex.cpp',
  'sys/sync/mutex/pthread.cpp',
  'thread/thread.cpp',
  'num/nonzero.cpp',
  'thread.cpp',
  'sync/mpsc.cpp',
  'time.cpp',
  'fmt.cpp',
]

rstd_test = executable('rstd_test',
  test_sources,
  dependencies : [rstd_dep, gtest_dep],
)

test('rstd_test', rstd_test)
