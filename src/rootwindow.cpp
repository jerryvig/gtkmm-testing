#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "rootwindow.hpp"

//static
RootWindow* RootWindow::m_pRootWindow = nullptr;

RootWindow::RootWindow() {
  m_pRootWindow = this;

  set_default_size (800, 600);
}

//static
RootWindow* RootWindow::get_root_window() {
  return m_pRootWindow;
}

RootWindow::~RootWindow() {
}
