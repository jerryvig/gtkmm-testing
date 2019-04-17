/* -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#include <config.h>

#include <glib/gi18n.h>
#include <gtkmm/builder.h>
#include <signal.h>
#include "application.hpp"

#include <iostream>

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
    Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();
    cssProvider->load_from_resource("/org/gnome/gtkmm-testing/data/interface.css");

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    builder->add_from_resource("/org/gnome/gtkmm-testing/data/interface.ui");

    Glib::RefPtr<Gtk::Window> rootWindow = Glib::RefPtr<Gtk::Window>::cast_static(builder->get_object("window"));
    Glib::RefPtr<Gdk::Screen> screen = rootWindow->get_screen();
    Gtk::StyleContext::add_provider_for_screen(screen, cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    Glib::RefPtr<Gtk::EventBox> tickerColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("ticker_column_header"));
    tickerColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    tickerColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onTickerColumnHeaderClicked) );

    Glib::RefPtr<Gtk::EventBox> shareCountColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("share_count_column_header"));
    shareCountColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    shareCountColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onShareCountColumnHeaderClicked) );

    Glib::RefPtr<Gtk::EventBox> shareBasisColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("share_basis_column_header"));
    shareBasisColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    shareBasisColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onShareBasisColumnHeaderClicked) );

    Glib::RefPtr<Gtk::EventBox> lastTradeColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("last_trade_column_header"));
    lastTradeColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    lastTradeColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onLastTradeColumnHeaderClicked) );

    Glib::RefPtr<Gtk::EventBox> shareChangeColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("share_change_column_header"));
    shareChangeColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    shareChangeColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onShareChangeColumnHeaderClicked) );

    Glib::RefPtr<Gtk::EventBox> positionBasisColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("position_basis_column_header"));
    positionBasisColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    positionBasisColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onPositionBasisColumnHeaderClicked) );

    Glib::RefPtr<Gtk::EventBox> positionValueColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("position_value_column_header"));
    positionValueColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    positionValueColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onPositionValueColumnHeaderClicked) );

    Glib::RefPtr<Gtk::EventBox> positionChangeColumnHeader = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("position_change_column_header"));
    positionChangeColumnHeader->set_events(Gdk::BUTTON_PRESS_MASK);
    positionChangeColumnHeader->signal_button_press_event().connect( sigc::mem_fun(*this, &GsmApplication::onPositionChangeColumnHeaderClicked) );

    add_window(*(rootWindow.get()));

    rootWindow->present();
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

bool GsmApplication::onTickerColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE TICKER COLUMN HEADER." << std::endl;
    return true;
}

bool GsmApplication::onShareCountColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE SHARE COUNT COLUMN HEADER." << std::endl;
    return true;
}

bool GsmApplication::onShareBasisColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE SHARE BASIS COLUMN HEADER." << std::endl;
    return true;
}

bool GsmApplication::onLastTradeColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE LAST TRADE COLUMN HEADER." << std::endl;
    return true;
}

bool GsmApplication::onShareChangeColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE SHARE CHANGE COLUMN HEADER." << std::endl;
    return true;
}

bool GsmApplication::onPositionBasisColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE POSITION BASIS COLUMN HEADER." << std::endl;
    return true;
}

bool GsmApplication::onPositionValueColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE POSITION VALUE COLUMN HEADER." << std::endl;
    return true;
}

bool GsmApplication::onPositionChangeColumnHeaderClicked(GdkEventButton* button_event) {
    std::cout << "YOU CLICKED THE POSITION CHANGE COLUMN HEADER." << std::endl;
    return true;
}
