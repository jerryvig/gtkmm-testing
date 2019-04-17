#include <positionrow.hpp>

PositionRow::PositionRow() {

}

PositionRow::PositionRow(std::string ticker, int share_count, double share_basis) : m_ticker(ticker),
    m_share_count(share_count),
    m_share_basis(share_basis)
{
}

PositionRow::~PositionRow() {

}

