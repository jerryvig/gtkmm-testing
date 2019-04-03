sources = [
  'application.cpp',
  'main.cpp',
  'rootwindow.cpp',
]

headers = [
  'application.hpp',
  'rootwindow.cpp',
]

gsm_resource_dir = join_paths(get_option('datadir'), meson.project_name())
gsm_resource = gnome.compile_resources(
  'gsm',
  'gsm.gresource.xml',
  gresource_bundle: false,
  source_dir: meson.source_root(),
  install_header: true,
  install_dir: gsm_resource_dir,
)

executable(meson.project_name(),
  sources,
  include_directories: rootInclude,
  dependencies: [
    gmodule,
    gtkmm,
  ],
  cpp_args: [
    '-DGSM_RESOURCE_FILE="@0@"'.format(join_paths(
    get_option('prefix'), gsm_resource_dir, 'gsm.gresource')),
  ],
  install: true,
)
