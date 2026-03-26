rstd_alloc_sources = [
  'mod.cppm',
  'alloc.cppm',
  'rc.cppm',
  'string.cppm',
  'str.cppm',
  'boxed.cppm',
  'sync.cppm',
  'ffi/mod.cppm',
  'ffi/c_str.cppm',
  'vec/mod.cppm',
]

rstd_alloc = static_library('rstd.alloc',
  rstd_alloc_sources,
  dependencies : rstd_core_dep,
)

rstd_alloc_dep = declare_dependency(
  link_with : rstd_alloc,
  include_directories : include_directories('.'),
)
