#include "price.h"
#define EPSILON 0.001

price_t::price_t() {
    exponent = 0;
    mantissa = 0;
}

price_t::price_t(int m_mantissa, int m_exponent) {
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
    return mantissa * pow(10, exponent);
}

std::string price_t::getDecimalString() {
    return std::to_string(mantissa * pow(10, exponent));
}

void price_t::setDecimal(std::string v) {
    std::string::size_type dot_pos = v.find_first_of('.');
    std::string::size_type sign_pos = v.find_first_of('-');
    int lpff=0;
    int sign =1;
    if(sign_pos!=std::string::npos){
        lpff=sign_pos+1;
        sign=-1;
    }
    int vl = v.length();
    if(dot_pos==std::string::npos){
        this->exponent=0;
        while(v.data()[lpff++]=='0');
        char * n=const_cast<char *>(v.data());
        this->mantissa=sign*strtoll(n+lpff-1,NULL,0);
    }
    else{
        std::string &ev = const_cast<std::string&>(v).erase(dot_pos,1);
        while(ev.data()[lpff++]=='0');
        char * n=const_cast<char *>(ev.data());
        this->mantissa=sign*strtoll(n+lpff-1,NULL,0);
        this->exponent=1-(vl-dot_pos);
    }
}

price_t price_t::operator+(const price_t& price2) {
    if (price2.getExponent() == exponent) {
        return price_t(mantissa + price2.getMantissa(), exponent);
    } else {
        int de = price2.getExponent() - exponent;
        if (de < 0) {
            return price_t(mantissa * pow(10, -de) + price2.getMantissa(), price2.getExponent());
        } else {
            return price_t(mantissa + price2.getMantissa()* pow(10, de), exponent);
        }
    }
}

price_t price_t::operator-(const price_t& price2) {
    if (price2.getExponent() == exponent) {
        return price_t(mantissa - price2.getMantissa(), exponent);
    } else {
        int de = price2.getExponent() - exponent;
        if (de < 0) {
            return price_t(mantissa * pow(10, -de) - price2.getMantissa(), price2.getExponent());
        } else {
            return price_t(mantissa - price2.getMantissa()* pow(10, de), exponent);
        }
    }
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