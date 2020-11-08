//
// Created by levana on 11/8/20.
//

#include "price.h"

/*
//
// Created by levana on 11/5/20.
//

#include <ostream>
#include <iostream>
#include "price.h"

Price::Price(int dollar) : m_price(dollar*100) {}

Price::Price(int dollar, int cent){
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

Price::operator double(){
    return m_price/100.0;
}

long Price::getPrice() const{
    return m_price;
}

Price operator+(const Price& p1, const Price &p2){
    Price res;
    long sum = p1.getPrice() + p2.getPrice();
    Price p(0, sum);
    return p;
}

Price operator-(const Price& p1, const Price &p2){
    return p1 + (-p2);
}

Price operator*(const Price& p1, const Price &p2){
    long mult = p1.getPrice() * p2.getPrice();
    Price p(0, mult/100);
    return p;
}

Price operator/(const Price& p1, const Price &p2){
    float division = (float)p1.getPrice() / (float)p2.getPrice();
    Price p(0, (int)(division*100));
    return p;
}

Price operator%(const Price& p1, const Price &p2){
    long mod = p1.getPrice() % p2.getPrice();
    Price p(0, mod);
    return p;
}
void Price::operator=(int n) {
    m_price = n;
}
void Price::operator++() {
    m_price+=100;
}
void Price::operator++(int n) {
    m_price+=100;
}

std::ostream &operator<<(std::ostream &ostream, Price price) {
    ostream << price.m_price/100 << '.' << price.m_price%100;
    return ostream;
}

void Price::operator+=(const Price & other) {
    m_price += other.m_price;
}
void Price::operator-=(const Price & other) {
    m_price -= other.m_price;
}
void Price::operator*=(const Price & other) {
    m_price *= other.m_price/100;
}
void Price::operator/=(const Price & other) {
    m_price = m_price * 100 / other.m_price;
}
void Price::operator%=(const Price & other) {
    m_price = m_price % other.m_price;
}

Price operator-(const Price& p){
    return Price(0, -p.getPrice());
}
bool operator==(const Price& p1, const Price & p2){
    return p1.getPrice() == p2.getPrice();
}
bool operator!=(const Price& p1, const Price & p2){
    return !(p1 == p2);
}
bool operator<=(const Price& p1, const Price & p2){
    return p1.getPrice() <= p2.getPrice();
}
bool operator>=(const Price& p1, const Price & p2){
    return p1.getPrice() >= p2.getPrice();
}
bool operator<(const Price& p1, const Price & p2){
    return !(p1 >= p2);
}
bool operator>(const Price& p1, const Price & p2){
    return !(p1 <= p2);
}
 */