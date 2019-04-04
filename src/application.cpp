/* -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#include <config.h>

#include <glib/gi18n.h>
#include <gtkmm/builder.h>
#include <signal.h>
#include "application.hpp"

void GsmApplication::load_settings() {
}

GsmApplication::GsmApplication()
    : Gtk::Application("com.mktneutral.gtkmm_testing", Gio::APPLICATION_HANDLES_COMMAND_LINE)
{
    Glib::set_application_name(_("gtkmm_testing"));
}

void GsmApplication::on_hide_window(Glib::RefPtr<RootWindow> window) {
    window.reset();
}

Glib::RefPtr<GsmApplication> GsmApplication::get () {
    static Glib::RefPtr<GsmApplication> singleton;
    if (!singleton) {
        singleton = Glib::RefPtr<GsmApplication>(new GsmApplication());
    }
    return singleton;
}

void GsmApplication::on_activate() {
    Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();
    cssProvider->load_from_resource("/org/gnome/gtkmm-testing/data/interface.css");

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    builder->add_from_resource("/org/gnome/gtkmm-testing/data/interface.ui");

    Gtk::Window* pWindow = nullptr;
    builder->get_widget("window", pWindow);

    Glib::RefPtr<Gdk::Screen> screen = pWindow->get_screen();

    //Glib::RefPtr<Gtk::StyleContext> windowStyleContext = pWindow->get_style_context();
    //windowStyleContext->add_provider(cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);
    Gtk::StyleContext::add_provider_for_screen(screen, cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    add_window(*pWindow);

    pWindow->present();
}

int GsmApplication::on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& command_line) {
    int argc = 0;
    char** argv = command_line->get_arguments(argc);

    on_activate();

    return 0;
}

void GsmApplication::shutdown() {
    quit();
}

void GsmApplication::on_startup() {
    Gtk::Application::on_startup();

    load_resources();
}

void GsmApplication::load_resources() {
}
