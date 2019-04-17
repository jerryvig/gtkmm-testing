sources = [
  'positionrow.cpp',
  'application.cpp',
  'main.cpp',
]

headers = [
  'application.hpp',
  'positionrow.hpp',
]

gsm_resource_dir = join_paths(get_option('datadir'), meson.project_name())
gsm_resource = gnome.compile_resources(
  'gsm-resources',
  'gsm.gresource.xml',
  gresource_bundle: false,
  source_dir: meson.source_root(),
  install_header: false,
  export: true,
)

executable(meson.project_name(),
  sources,
  gsm_resource,
  include_directories: rootInclude,
  dependencies: [
    gmodule,
    gtkmm,
  ],
  cpp_args: [
  ],
  install: true,
)
