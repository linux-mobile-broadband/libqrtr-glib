# SPDX-License-Identifier: LGPL-2.1+
# Copyright (C) 2021 Iñigo Martinez <inigomartinez@gmail.com>

doc_module = 'libqrtr-glib'

scan_args = [
  '--rebuild-types',
  '--deprecated-guards="QRTR_DISABLE_DEPRECATED"',
]

glib_prefix = glib_dep.get_variable(pkgconfig: 'prefix')

fixxref_args = [
  '--html-dir=' + (qrtr_prefix / gnome.gtkdoc_html_dir(doc_module)),
  '--extra-dir=' + (glib_prefix / gnome.gtkdoc_html_dir('gio')),
  '--extra-dir=' + (glib_prefix / gnome.gtkdoc_html_dir('glib')),
]

version_xml = configure_file(
  input: 'version.xml.in',
  output: '@BASENAME@',
  configuration: {'VERSION': qrtr_version},
)

gnome.gtkdoc(
  doc_module,
  main_xml: doc_module + '-docs.xml',
  src_dir: libqrtr_glib_inc,
  include_directories: top_inc,
  dependencies: libqrtr_glib_dep,
  namespace: 'qrtr',
  scan_args: scan_args,
  fixxref_args: fixxref_args,
  content_files: version_xml,
  install: true,
)
