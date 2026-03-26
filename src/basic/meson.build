rstd_basic_sources = [
  'mod.cppm',
  'prelude.cppm',
  'basic.cppm',
  'mtp.cppm',
  'cppstd.cppm',
]

rstd_basic = static_library('rstd.basic',
  rstd_basic_sources,
  override_options : ['cpp_std=c++20'],
)

rstd_basic_dep = declare_dependency(
  link_with : rstd_basic,
  include_directories : include_directories('.'),
)
