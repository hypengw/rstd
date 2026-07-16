rstd_argparse_sources = [
  'mod.cppm',
  'error.cppm',
    'value_parser.cppm',
    'arg.cppm',
    'schema.cppm',
    'matches.cppm',
    'parser.cppm',
    'command.cppm',
]

rstd_argparse = static_library('rstd.argparse',
  rstd_argparse_sources,
  dependencies : [rstd_dep],
  install : true,
)

install_data(
  rstd_argparse_sources,
  install_dir : join_paths(get_option('includedir'), 'rstd', 'modules', 'argparse'),
)

rstd_argparse_dep = declare_dependency(
  link_with : rstd_argparse,
  dependencies : [rstd_dep],
)
