#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "mainwindow.hpp"

//static
MainWindow* MainWindow::m_pMainWindow = nullptr;

MainWindow::MainWindow() {
  m_pMainWindow = this;

  set_default_size (800, 600);
}

//static
MainWindow* MainWindow::get_main_window() {
  return m_pMainWindow;
}

MainWindow::~MainWindow() {
}
