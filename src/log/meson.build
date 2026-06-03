rstd_log_sources = [
  'mod.cppm',
  'level.cppm',
  'record.cppm',
  'logger.cppm',
  'macros.cppm',
  'env_logger.cppm',
]

rstd_log = static_library('rstd.log',
  rstd_log_sources,
  dependencies : [rstd_core_dep, rstd_dep],
)

rstd_log_dep = declare_dependency(
  link_with : rstd_log,
  dependencies : [rstd_core_dep, rstd_dep],
)
