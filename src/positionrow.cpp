#include <positionrow.hpp>

#include <iostream>

PositionRow::PositionRow(int rowIndex) {
    builder = Gtk::Builder::create();
    builder->add_from_resource("/org/gnome/gtkmm-testing/data/position_row.ui");

    rowGrid = Glib::RefPtr<Gtk::Grid>::cast_static(builder->get_object("position_row"));

    auto tickerLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("ticker_label"));
    tickerLabel->set_text("(click to enter ticker)");

    auto shareCountLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("share_count_label"));
    shareCountLabel->set_text("");

    auto shareBasisLabel = Glib::RefPtr<Gtk::Label>::cast_static(builder->get_object("share_basis_label"));
    shareBasisLabel->set_text("");

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

    //Setup the row delete handler.
    auto deleteEventBox = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("delete_event_box"));
    deleteEventBox->set_events(Gdk::BUTTON_PRESS_MASK);
    deleteEventBox->signal_button_press_event().connect( sigc::mem_fun(*this, &PositionRow::onDeleteBoxClicked) );

    //Setup the ticker eventbox click handler.
    tickerEventBox = Glib::RefPtr<Gtk::EventBox>::cast_static(builder->get_object("ticker_event_box"));
    tickerEventBox->set_events(Gdk::BUTTON_PRESS_MASK);
    tickerEventBox->signal_button_press_event().connect( sigc::mem_fun(*this, &PositionRow::onTickerBoxClicked) );

    // Make entry objects here.
    tickerEntry = std::make_shared<Gtk::Entry>();
    tickerEntry->set_max_width_chars(5);
    tickerEntry->set_text("aapl");
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
    Glib::RefPtr<Gtk::Builder> rowBuilder = Gtk::Builder::create();
    rowBuilder->add_from_resource("/org/gnome/gtkmm-testing/data/position_row.ui");

    rowGrid = Glib::RefPtr<Gtk::Grid>::cast_static(rowBuilder->get_object("position_row"));

    Glib::RefPtr<Gtk::Label> tickerLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("ticker_label"));
    tickerLabel->set_text(m_ticker);

    Glib::RefPtr<Gtk::Label> shareCountLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("share_count_label"));
    shareCountLabel->set_text(std::to_string(share_count));

    Glib::RefPtr<Gtk::Label> shareBasisLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("share_basis_label"));
    shareBasisLabel->set_text(std::to_string(share_basis));

    Glib::RefPtr<Gtk::Label> lastTradeLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("last_trade_label"));
    lastTradeLabel->set_text(std::to_string(last_trade));

    Glib::RefPtr<Gtk::Label> shareChangeLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("share_change_label"));
    shareChangeLabel->set_text(std::to_string(share_change));

    Glib::RefPtr<Gtk::Label> positionBasisLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("position_basis_label"));
    positionBasisLabel->set_text(std::to_string(position_basis));

    Glib::RefPtr<Gtk::Label> positionValueLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("position_value_label"));
    positionValueLabel->set_text(std::to_string(position_value));

    Glib::RefPtr<Gtk::Label> positionChangeLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("position_change_label"));
    positionChangeLabel->set_text(std::to_string(position_change));
}

PositionRow::~PositionRow() {
}

bool PositionRow::onDeleteBoxClicked(GdkEventButton* button_event) {
    std::cout << "you clicked the delete event box" << std::endl;
    return true;
}

bool PositionRow::onTickerBoxClicked(GdkEventButton* button_event) {
    std::cout << "you clicked the ticker event box. need to add an input inside of the event box" << std::endl;

    tickerEventBox->remove();
    tickerEntry->set_visibility(true);

    tickerEventBox->add(*tickerEntry);
    tickerEntry->show();

    return true;
}
