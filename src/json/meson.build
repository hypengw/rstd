rstd_json_sources = [
  'mod.cppm',
  'number.cppm',
  'error.cppm',
  'value.cppm',
  'parser.cppm',
]

rstd_json = static_library('rstd.json',
  rstd_json_sources,
  dependencies : [rstd_core_dep, rstd_dep],
)

rstd_json_dep = declare_dependency(
  link_with : rstd_json,
  dependencies : [rstd_core_dep, rstd_dep],
)
