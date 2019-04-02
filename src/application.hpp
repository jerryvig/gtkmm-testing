/* -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#ifndef _GSM_APPLICATION_H_
#define _GSM_APPLICATION_H_

#include <gtkmm.h>
#include <algorithm>

class GsmApplication : public Gtk::Application {
private:
    void load_settings();
    void load_resources();

    void on_help_activate(const Glib::VariantBase&);
    void on_quit_activate(const Glib::VariantBase&);
protected:
    GsmApplication();
public:
    static Glib::RefPtr<GsmApplication> get ();

    void shutdown();
    // GtkApplicationWindow *main_window;

protected:
    virtual void on_activate();
    virtual int on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& command_line);
    virtual void on_startup();
};

#endif /* _GSM_APPLICATION_H_ */
