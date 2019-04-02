sources = [
  'application.cpp',
  'main.cpp',
  'mainwindow.cpp',
]

headers = [
  'application.hpp',
  'mainwindow.cpp',
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
