sources = [
  'application.cpp',
  'main.cpp',
]

headers = [
  'application.hpp',
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
