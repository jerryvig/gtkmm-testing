#ifndef _ROOTWINDOW_H
#define _ROOTWINDOW_H

#include <gtkmm/window.h>
#include <iostream>

class RootWindow : public Gtk::Window {
public:
  static Glib::RefPtr<RootWindow> get();
  ~RootWindow() override;

protected:
    RootWindow();
};

#endif //_ROOTWINDOW_H
