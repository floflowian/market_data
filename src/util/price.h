/* 
 * File:   price.h
 * Author: Florian
 *
 * Created on 1 mars 2015, 22:05
 */

#ifndef PRICE_H
#define	PRICE_H

#include <cmath>
#include <string>

class price_t {
    int exponent;
    int mantissa;
public:
    price_t();
    price_t(int exponent, int mantissa);
    void setExponent(int exponent);

    void setMantissa(int mantissa);

    int getExponent() const;

    int getMantissa() const;

    double getDecimal();

    std::string getDecimalString();

    void setDecimal(std::string decimal);

    price_t operator+(const price_t& price2);

    price_t operator-(const price_t& price2);

    bool operator==(price_t& price2);
    bool operator>(price_t& price2);
    bool operator>=(price_t& price2);
    bool operator<(price_t& price2);
    bool operator<=(price_t& price2);


};



#endif	/* PRICE_H */

