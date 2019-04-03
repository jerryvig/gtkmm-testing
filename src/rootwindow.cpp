#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "rootwindow.hpp"

RootWindow::RootWindow() {
  set_title("Application Root Window");
  set_border_width(10);
  set_default_size (800, 600);
}

// static
Glib::RefPtr<RootWindow> RootWindow::get() {
    static Glib::RefPtr<RootWindow> singleton;
    if (!singleton) {
        singleton = Glib::RefPtr<RootWindow>(new RootWindow());
    }
    return singleton;
}

RootWindow::~RootWindow() {
}
