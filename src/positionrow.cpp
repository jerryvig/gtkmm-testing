#include <positionrow.hpp>

PositionRow::PositionRow() {
}

PositionRow::PositionRow(std::string ticker, int share_count, double share_basis) : m_ticker(ticker),
    m_share_count(share_count),
    m_share_basis(share_basis)
{
    Glib::RefPtr<Gtk::Builder> rowBuilder = Gtk::Builder::create();
    rowBuilder->add_from_resource("/org/gnome/gtkmm-testing/data/position_row.ui");

    rowGrid = Glib::RefPtr<Gtk::Grid>::cast_static(rowBuilder->get_object("position_row"));

    Glib::RefPtr<Gtk::Label> tickerLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("ticker_label"));
    tickerLabel->set_text("Some ticker here");

    Glib::RefPtr<Gtk::Label> shareCountLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("share_count_label"));
    shareCountLabel->set_text("1200");

    Glib::RefPtr<Gtk::Label> shareBasisLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("share_basis_label"));
    shareBasisLabel->set_text("34.66");

    Glib::RefPtr<Gtk::Label> lastTradeLabel = Glib::RefPtr<Gtk::Label>::cast_static(rowBuilder->get_object("last_trade_label"));
    lastTradeLabel->set_text("99.99");
}

PositionRow::~PositionRow() {
}
