#ifndef _POSITION_ROW_H_
#define _POSITION_ROW_H_

#include <gtkmm.h>

class PositionRow {
private:
    int rowIndex;
    Glib::RefPtr<Gtk::EventBox> tickerEventBox;
    std::shared_ptr<Gtk::Entry> tickerEntry;
    Glib::RefPtr<Gtk::Grid> containerGrid;
    Glib::RefPtr<Gtk::Window> appRootWindow;

protected:
    virtual bool onDeleteBoxClicked(GdkEventButton* button_event);
    virtual bool onTickerEntryUnfocused(GdkEventFocus* gdk_event);

public:
    PositionRow(int rowIndex, Glib::RefPtr<Gtk::Grid>& containerGrid, Glib::RefPtr<Gtk::Window>& appRootWindow);
    PositionRow(std::string ticker, int share_count, double share_basis, double last_trade, double share_change,
                double position_basis, double position_value, double position_change);
    ~PositionRow();

    std::string m_ticker;
    int m_share_count;
    double m_share_basis;
    double m_last_trade;
    double m_share_change;
    double m_position_basis;
    double m_position_value;
    double m_position_change;

    Glib::RefPtr<Gtk::Grid> rowGrid;
    Glib::RefPtr<Gtk::Builder> builder;
};

#endif /* _POSITION_ROW_H_ */
