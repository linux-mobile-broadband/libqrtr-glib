# SPDX-License-Identifier: LGPL-2.1-or-later
# Copyright (C) 2021 Iñigo Martinez <inigomartinez@gmail.com>

scan_args = ['--rebuild-types']

toml_data = configuration_data()
toml_data.set('VERSION', meson.project_version())

qrtr_toml = configure_file(
  input: 'libqrtr-glib.toml.in',
  output: 'libqrtr-glib.toml',
  configuration: toml_data,
)

dependency(
  'gi-docgen',
  version: '>= 2021.1',
  native: true,
  required: get_option('gtk_doc'),
)

gidocgen = find_program('gi-docgen')

docs_dir = qrtr_datadir / 'doc'

custom_target(
  'libqrtr-glib',
  input: [qrtr_toml, libqrtr_glib_gir[0]],
  output: 'libqrtr-glib-@0@'.format(qrtr_gir_version),
  command: [
    gidocgen,
    'generate',
    '--quiet',
    '--config=@INPUT0@',
    '--output-dir=@OUTPUT@',
    '--no-namespace-dir',
    '--content-dir=@0@'.format(meson.current_source_dir()),
    '--fatal-warnings',
    '@INPUT1@',
  ],
  build_by_default: true,
  install: true,
  install_dir: docs_dir,
)
