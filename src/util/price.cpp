#include "price.h"
#define EPSILON 0.001

price_t::price_t() {
    exponent = 0;
    mantissa = 0;
}

price_t::price_t(int m_mantissa,int m_exponent ) {
    exponent = m_exponent;
    mantissa = m_mantissa;

}

void price_t::setExponent(int exponent) {
    this->exponent = exponent;
}

void price_t::setMantissa(int mantissa) {
    this->mantissa = mantissa;
}

int price_t::getExponent() const {
    return exponent;
}

int price_t::getMantissa() const {
    return mantissa;
}

double price_t::getDecimal() {
    return mantissa*pow(10, exponent);
}

std::string price_t::getDecimalString() {
    return  std::to_string(mantissa*pow(10, exponent));
}

void price_t::setDecimal(std::string decimal) {
    //TODO
}

price_t price_t::operator+(const price_t& price2) {
    //TODO
}

price_t price_t::operator-(const price_t& price2) {
    //TODO
}

bool price_t::operator==(price_t& price2) {
    double priceDec1 = this->getDecimal();
    double priceDec2 = price2.getDecimal();

    return fabs(priceDec1 - priceDec2) < EPSILON;
}

bool price_t::operator>(price_t& price2) {
    double priceDec1 = this->getDecimal();
    double priceDec2 = price2.getDecimal();

    return priceDec1 > priceDec2;
}

bool price_t::operator<(price_t& price2) {
    double priceDec1 = this->getDecimal();
    double priceDec2 = price2.getDecimal();

    return priceDec1 < priceDec2;
}

bool price_t::operator>=(price_t& price2) {
    double priceDec1 = this->getDecimal();
    double priceDec2 = price2.getDecimal();

    return priceDec1 >= priceDec2;
}

bool price_t::operator<=(price_t& price2) {
    double priceDec1 = this->getDecimal();
    double priceDec2 = price2.getDecimal();

    return priceDec1 <= priceDec2;
}