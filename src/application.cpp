/* -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#include <config.h>

#include <glib/gi18n.h>
#include <signal.h>
#include <iostream>
#include "application.hpp"

void GsmApplication::load_settings() {
}

GsmApplication::GsmApplication()
    : Gtk::Application("com.mktneutral.gtkmm_testing", Gio::APPLICATION_HANDLES_COMMAND_LINE)
{
    Glib::set_application_name(_("gtkmm_testing"));
}

Glib::RefPtr<GsmApplication> GsmApplication::get () {
    static Glib::RefPtr<GsmApplication> singleton;

    if (!singleton) {
        singleton = Glib::RefPtr<GsmApplication>(new GsmApplication());
    }
    return singleton;
}

void GsmApplication::on_activate() {
}

int GsmApplication::on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& command_line) {
    int argc = 0;
    char** argv = command_line->get_arguments(argc);

    on_activate ();

    return 0;
}

void GsmApplication::shutdown() {
    quit();
}

void GsmApplication::on_startup() {
    Gtk::Application::on_startup();

    std::cout << "Hola mundo desde on_startup()..." << std::endl;

    load_resources();
}

void GsmApplication::load_resources() {
}
