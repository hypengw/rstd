project('rstd', 'cpp',
  version : '0.1.0',
  default_options : ['cpp_std=c++20', 'warning_level=3', 'werror=true'])

cpp = meson.get_compiler('cpp')

if cpp.get_id() != 'clang'
  error('This project only supports Clang (found: ' + cpp.get_id() + ')')
endif

warn_opts = [
  '-Wall',
  '-Wpedantic',
  '-Wno-gnu-statement-expression',
  '-Wno-deprecated-declarations',
  '-fsized-deallocation',
]

add_project_arguments(warn_opts, language : 'cpp')

subdir('src')

if get_option('tests')
  subdir('test')
endif
