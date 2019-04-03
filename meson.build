project('gtkmm-testing',
  'c', 'cpp',
  default_options : [
    'c_std=c11', 'cpp_std=c++17'
  ],
  version: '0.0.1',
  meson_version: '>=0.50.0',
)

gnome = import('gnome')
i18n  = import('i18n')

cc = meson.get_compiler('c')
cx = meson.get_compiler('cpp')

gettext_package = meson.project_name()

conf = configuration_data()
conf.set_quoted('VERSION', meson.project_version())
conf.set_quoted('GETTEXT_PACKAGE', gettext_package)
conf.set_quoted('GNOMELOCALEDIR',
  join_paths(get_option('prefix'), get_option('localedir'))
)
conf.set_quoted('GSM_LIBEXEC_DIR',
  join_paths(get_option('prefix'), get_option('libexecdir'), meson.project_name())
)

dataconf = configuration_data()
dataconf.set('VERSION', meson.project_version())
dataconf.set('GETTEXT_PACKAGE', gettext_package)
dataconf.set('pkglibexecdir',
  join_paths(get_option('prefix'),get_option('libexecdir'),meson.project_name())
)

prefix = get_option('prefix')
datadir = join_paths(prefix, get_option('datadir'))

################################################################################
# Dependencies

giomm   = dependency('giomm-2.4',   version: '>=2.46')
glib    = dependency('glib-2.0',    version: '>=2.56.0')
glibmm  = dependency('glibmm-2.4',  version: '>=2.46')
gmodule = dependency('gmodule-2.0')
gtk3    = dependency('gtk+-3.0',    version: '>=3.22.0')
gtkmm   = dependency('gtkmm-3.0',   version: '>=3.3.18')
librsvg = dependency('librsvg-2.0', version: '>=2.35')
libxml  = dependency('libxml-2.0',  version: '>=2.0')

################################################################################
# Compiler flags

extra_flags = [
  '-pedantic',
  '-Wall',
  '-Wcast-align',
  '-Wchar-subscripts',
  '-Wextra',
  '-Winline',
  '-Wmissing-declarations',
  '-Wpointer-arith',
  '-Wsign-compare',
]
extra_cflags = [
  '-Wmissing-prototypes',
  '-Wnested-externs',
]
extra_cxxflags = [
]

cflags   = extra_flags + extra_cflags
cxxflags = extra_flags + extra_cxxflags

add_project_arguments(cc.get_supported_arguments(cflags),
  language: 'c'
)
add_project_arguments(cx.get_supported_arguments(cxxflags),
  language: 'cpp'
)

conf.set('HAVE_LKSTRFTIME', cc.has_function('strftime'))

conf.set('CTIME_R_THREE_ARGS', cc.compiles('''
#include <time.h>
int main() {
  char *buf;
  time_t date;
  ctime_r (&date, buf, 100);
}
'''))


configure_file(
  output: 'config.h',
  configuration: conf,
)

################################################################################
# Generate files

################################################################################
# Subdirectories

rootInclude = include_directories('.')

subdir('data')
subdir('src')
