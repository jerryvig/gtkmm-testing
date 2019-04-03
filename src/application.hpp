/* -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#ifndef _GSM_APPLICATION_H_
#define _GSM_APPLICATION_H_

#include <gtkmm.h>
#include "rootwindow.hpp"

class GsmApplication : public Gtk::Application {
private:
    void load_settings();
    void load_resources();

protected:
    GsmApplication();
public:
    static Glib::RefPtr<GsmApplication> get();

    Glib::RefPtr<RootWindow> create_rootwindow();
    void on_hide_window(Glib::RefPtr<RootWindow> window);

    void shutdown();

protected:
    virtual void on_activate();
    virtual int on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& command_line);
    virtual void on_startup();
};

#endif /* _GSM_APPLICATION_H_ */
