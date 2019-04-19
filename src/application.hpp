/* -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#ifndef _GSM_APPLICATION_H_
#define _GSM_APPLICATION_H_

#include <vector>
#include <gtkmm.h>

class GsmApplication : public Gtk::Application {
private:
    void load_settings();
    void load_resources();
    void addColumnHeaderClickHandlers(Glib::RefPtr<Gtk::Builder>& builder);

protected:
    GsmApplication();
public:
    static Glib::RefPtr<GsmApplication> get();
    void shutdown();

protected:
    virtual void on_activate();
    virtual void addPositionRows(Glib::RefPtr<Gtk::Grid>& grid);
    virtual int on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& command_line);
    virtual void on_startup();
    virtual void onAddButtonClicked();
    virtual bool onTickerColumnHeaderClicked(GdkEventButton* button_event);
    virtual bool onShareCountColumnHeaderClicked(GdkEventButton* button_event);
    virtual bool onShareBasisColumnHeaderClicked(GdkEventButton* button_event);
    virtual bool onLastTradeColumnHeaderClicked(GdkEventButton* button_event);
    virtual bool onShareChangeColumnHeaderClicked(GdkEventButton* button_event);
    virtual bool onPositionBasisColumnHeaderClicked(GdkEventButton* button_event);
    virtual bool onPositionValueColumnHeaderClicked(GdkEventButton* button_event);
    virtual bool onPositionChangeColumnHeaderClicked(GdkEventButton* button_event);

    std::vector<Gtk::Label*> rowLabels;
};

#endif /* _GSM_APPLICATION_H_ */
