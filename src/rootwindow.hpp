#ifndef _ROOTWINDOW_H
#define _ROOTWINDOW_H

#include <gtkmm/window.h>
#include <iostream>

class RootWindow : public Gtk::Window {
public:
  RootWindow();
  ~RootWindow() override;

  static RootWindow* get_root_window();

protected:
  static RootWindow* m_pRootWindow;
};

#endif //_ROOTWINDOW_H
