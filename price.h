//
// Created by levana on 11/8/20.
//

#include <iostream>
#include <limits>
#include <cmath>

#ifndef PRICETEMPLATE_PRICE_H
#define PRICETEMPLATE_PRICE_H

template <typename T>
class Price{
public:
    Price(int dollar = 0, int cent = 0);
    //Price operator=(int n);
    Price operator+=(const Price&);
    Price operator-=(const Price&);
    Price operator*=(const int num);
    Price operator/=(const Price&);
    Price operator%=(const Price&);

    Price operator++();
    Price operator++(int n);
    operator double();


    template <typename U>
    friend Price<U> operator-(const Price<U>&);
    template <typename U>
    friend Price<U> operator+(const Price<U>&, const Price<U> &);
    template <typename U>
    friend Price<U> operator-(const Price<U>&, const Price<U> &);
    template <typename U>
    friend Price<U> operator*(const Price<U>&, const int);
    template <typename U>
    friend Price<U> operator/(const Price<U>&, const Price<U> &);
    template <typename U>
    friend Price<U> operator%(const Price<U>&, const Price<U> &);

    template <typename U>
    friend bool operator==(const Price<U>&, const Price<U> &);
    template <typename U>
    friend bool operator!=(const Price<U>&, const Price<U> &);
    template <typename U>
    friend bool operator<=(const Price<U>&, const Price<U> &);
    template <typename U>
    friend bool operator>=(const Price<U>&, const Price<U> &);
    template <typename U>
    friend bool operator<(const Price<U>&, const Price<U> &);
    template <typename U>
    friend bool operator>(const Price<U>&, const Price<U> &);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &ostream, Price<U> price);

private:
    T m_price;

};

template <typename T>
Price<T>::operator double(){
    return m_price/100.0;
}

template <typename T>
Price<T>::Price(int dollar, int cent){
    try{
        if (dollar && cent < 0)
            throw "invalid input";
    }
    catch (const char* ex) {
        std::cout << ex;
    }

    if (dollar < 0)
        cent *= -1;

    m_price = dollar*100 + cent;
}

template <typename T>
Price<T> Price<T>::operator++(){
    m_price += 100;
    return this;
}

template <typename T>
Price<T> Price<T>::operator++(int n){
    m_price += 100;
    return this;
}

template <typename T>
std::ostream &operator<<(std::ostream &ostream, Price<T> price){
    Price<T> p(0);
    if (price < p)
        ostream << '-';
    ostream << abs(price.m_price/100) << '.' << abs(price.m_price%100);
    return ostream;
}

template <typename T>
Price<T> operator-(const Price<T>& p){
    return Price<T>(0, -p.m_price);
}


/* assignments operators */
template <typename T>
Price<T> Price<T>::operator+=(const Price<T> & other) {
    try{
        if (m_price < std::numeric_limits<T>::max() - other.m_price)
            throw "overflow";
    }
    catch (const char* ex) {
        std::cout << ex;
    }
    m_price += other.m_price;
    return this;
}
template <typename T>
Price<T> Price<T>::operator-=(const Price<T> & other) {
    m_price -= other.m_price;
    return this;
}

template <typename T>
Price<T> Price<T>::operator/=(const Price<T> & other) {
    m_price /= other.m_price;
    return this;
}

template <typename T>
Price<T> Price<T>::operator%=(const Price<T> & other) {
    m_price %= other.m_price;
    return this;
}

template <typename T>
Price<T> Price<T>::operator*=(const int num) {
    try{
        if (m_price < std::numeric_limits<T>::max() / num)
            throw "overflow";
    }
    catch (const char* ex) {
        std::cout << ex;
    }

    m_price *= num;
    return this;
}


/* comparisons operators */
template <typename T>
bool operator==(const Price<T>& p1, const Price<T> & p2){
    return p1.m_price == p2.m_price;
}
template <typename T>
bool operator!=(const Price<T>& p1, const Price<T> & p2){
    return !(p1 == p2);
}
template <typename T>
bool operator<=(const Price<T>& p1, const Price<T> & p2){
    return p1.m_price <= p2.m_price;
}
template <typename T>
bool operator>=(const Price<T>& p1, const Price<T> & p2){
    return p1.m_price >= p2.m_price;
}
template <typename T>
bool operator<(const Price<T>& p1, const Price<T> & p2){
    return !(p1 >= p2);
}
template <typename T>
bool operator>(const Price<T>& p1, const Price<T> & p2){
    return !(p1 <= p2);
}


/* binary operators */
template <typename T>
Price<T> operator+(const Price<T>& p1, const Price<T> &p2){
    Price<T> res;
    T sum = p1.m_price + p2.m_price;
    Price<T> p(0, sum);
    return p;
}
template <typename T>
Price<T> operator-(const Price<T>& p1, const Price<T> &p2){
    return p1 + (-p2);
}
template <typename T>
Price<T> operator*(const Price<T>& p1, const int num){
    try{
        if (p1.m_price < std::numeric_limits<T>::max() / num)
            throw "overflow";
    }
    catch (const char* ex) {
        std::cout << ex;
    }

    T mult = p1.m_price * num;
    Price<T> p(0, mult/100);
    return p;
}
template <typename T>
Price<T> operator/(const Price<T>& p1, const Price<T> &p2){
    float division = (float)p1.m_price / (float)p2.m_price;
    Price<T> p(0, (int)(division*100));
    return p;
}
template <typename T>
Price<T> operator%(const Price<T>& p1, const Price<T> &p2){
    T mod = p1.m_price % p2.m_price;
    Price<T> p(0, mod);
    return p;
}

#endif //PRICETEMPLATE_PRICE_H
