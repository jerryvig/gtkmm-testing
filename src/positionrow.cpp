#include <positionrow.hpp>

#include <iostream>

#define ENTRY_WIDTH_CHARS 12

PositionRow::PositionRow(int rowIndex, Glib::RefPtr<Gtk::Grid>& containerGrid, Glib::RefPtr<Gtk::Window>& appRootWindow) :
    rowIndex(rowIndex),
    containerGrid(containerGrid),
    appRootWindow(appRootWindow)
{
    builder = Gtk::Builder::create();
    builder->add_from_resource("/org/gnome/gtkmm-testing/data/position_row.ui");

    rowGrid = Glib::RefPtr<Gtk::Grid>::cast_static(builder->get_object("position_row"));

    Glib::RefPtr<Gtk::Label> deleteLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("delete_label"));
    deleteLabel->set_name("delete-label");

    auto tickerEntry = Glib::RefPtr<Gtk::Entry>::cast_static(builder->get_object("ticker_entry"));
    tickerEntry->set_width_chars(ENTRY_WIDTH_CHARS);
    tickerEntry->set_events(Gdk::FOCUS_CHANGE_MASK);
    tickerEntry->signal_focus_out_event().connect( sigc::mem_fun(*this, &PositionRow::onTickerEntryUnfocused) );

    auto shareCountEntry = Glib::RefPtr<Gtk::Entry>::cast_static(builder->get_object("share_count_entry"));
    shareCountEntry->set_width_chars(ENTRY_WIDTH_CHARS);

    auto shareBasisEntry = Glib::RefPtr<Gtk::Entry>::cast_static(builder->get_object("share_basis_entry"));
    shareBasisEntry->set_width_chars(ENTRY_WIDTH_CHARS);

    auto lastTradeLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("last_trade_label"));
    lastTradeLabel->set_text("");

    auto shareChangeLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("share_change_label"));
    shareChangeLabel->set_text("");

    auto positionBasisLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("position_basis_label"));
    positionBasisLabel->set_text("");

    auto positionValueLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("position_value_label"));
    positionValueLabel->set_text("");

    auto positionChangeLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("position_change_label"));
    positionChangeLabel->set_text("");

    // Setup the row delete handler.
    auto deleteEventBox = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("delete_event_box"));
    deleteEventBox->set_events(Gdk::BUTTON_PRESS_MASK);
    deleteEventBox->signal_button_press_event().connect( sigc::mem_fun(*this, &PositionRow::onDeleteBoxClicked) );
}

PositionRow::PositionRow(std::string ticker, int share_count, double share_basis, double last_trade, double share_change,
        double position_basis, double position_value, double position_change) :
    m_ticker(ticker),
    m_share_count(share_count),
    m_share_basis(share_basis),
    m_last_trade(last_trade),
    m_share_change(share_change),
    m_position_basis(position_basis),
    m_position_value(position_value),
    m_position_change(position_change)
{
    builder = Gtk::Builder::create();
    builder->add_from_resource("/org/gnome/gtkmm-testing/data/position_row.ui");

    rowGrid = Glib::RefPtr<Gtk::Grid>::cast_static(builder->get_object("position_row"));

    Glib::RefPtr<Gtk::Label> deleteLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("delete_label"));
    deleteLabel->set_name("delete-label");

    auto tickerEntry = Glib::RefPtr<Gtk::Entry>::cast_static(builder->get_object("ticker_entry"));
    tickerEntry->set_width_chars(ENTRY_WIDTH_CHARS);
    tickerEntry->set_text(m_ticker);
    tickerEntry->grab_focus();

    auto shareCountEntry = Glib::RefPtr<Gtk::Entry>::cast_static(builder->get_object("share_count_entry"));
    shareCountEntry->set_width_chars(ENTRY_WIDTH_CHARS);
    shareCountEntry->set_text(std::to_string(share_count));

    auto shareBasisEntry = Glib::RefPtr<Gtk::Entry>::cast_static(builder->get_object("share_basis_entry"));
    shareBasisEntry->set_width_chars(ENTRY_WIDTH_CHARS);
    shareBasisEntry->set_text(std::to_string(share_basis));

    auto lastTradeLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("last_trade_label"));
    lastTradeLabel->set_text(std::to_string(last_trade));

    auto shareChangeLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("share_change_label"));
    shareChangeLabel->set_text(std::to_string(share_change));

    auto positionBasisLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("position_basis_label"));
    positionBasisLabel->set_text(std::to_string(position_basis));

    auto positionValueLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("position_value_label"));
    positionValueLabel->set_text(std::to_string(position_value));

    auto positionChangeLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("position_change_label"));
    positionChangeLabel->set_text(std::to_string(position_change));
}

PositionRow::~PositionRow() {
}

bool PositionRow::onDeleteBoxClicked(GdkEventButton* button_event) {
    std::cout << "you clicked the delete event box" << std::endl;

    containerGrid->remove(*(rowGrid.get()));
    appRootWindow->resize(100, 50);

    return true;
}

bool PositionRow::onTickerEntryUnfocused(GdkEventFocus* gdk_event) {
    std::cout << "you unfocused the ticker entry" << std::endl;
    std::cout << "aqui esta usted" << std::endl;

    return true;
}
