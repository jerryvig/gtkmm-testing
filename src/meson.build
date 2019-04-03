sources = [
  'application.cpp',
  'main.cpp',
  'rootwindow.cpp',
]

headers = [
  'application.hpp',
  'rootwindow.cpp',
]

executable(meson.project_name(),
  sources,
  include_directories: rootInclude,
  dependencies: [
    gmodule,
    gtkmm,
  ],
  cpp_args: [
  ],
  install: true,
)
