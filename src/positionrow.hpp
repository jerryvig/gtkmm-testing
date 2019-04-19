#ifndef _POSITION_ROW_H_
#define _POSITION_ROW_H_

#include <gtkmm.h>

class PositionRow {
private:

protected:
    virtual bool onDeleteBoxClicked(GdkEventButton* button_event);

public:
    PositionRow();
    PositionRow(std::string ticker, int share_count, double share_basis);
    ~PositionRow();

    std::string m_ticker;
    int m_share_count;
    double m_share_basis;
    double m_last_trade;
    double share_change;
    double position_basis;
    double position_value;
    double position_change;

    Glib::RefPtr<Gtk::Grid> rowGrid;
};

#endif /* _POSITION_ROW_H_ */
