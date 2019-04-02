#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <gtkmm/window.h>
#include <iostream>

class MainWindow : public Gtk::Window {
public:
  MainWindow();
  ~MainWindow() override;

  static MainWindow* get_main_window();

protected:
  static MainWindow* m_pMainWindow;
};

#endif //_MAINWINDOW_H
