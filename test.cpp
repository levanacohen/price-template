//
// Created by levana on 11/8/20.
//

#include "test.h"

void test(){





    Price<int> p1(3, 25);
    Price<int> p2(3, 50);
    Price<int> p3 = p1 + p2;
    Price<int> p4 = p1 - p2;
    Price<int> p5 = p1 * 5;
    Price<int> p6 = p1 / p2;
    Price<int> p7 = p1 % p2;

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;

    std::cout << "p2: " << p2 << std::endl;
    std::cout << "p7: " << p7 << std::endl;
    p2 = -p2;
    std::cout << p2 << std::endl;
    std::cout << (p7<p2) << std::endl;
    std::cout << (p7==p2) << std::endl;
    std::cout << (p7!=p2) << std::endl;
    std::cout << (p7>=p2) << std::endl;
}

void test2(){

    Price<long> p1(4, 40);
    Price<long> p2(4, 5);
    Price<long> p3 = p1 * 6;
    double x = (double)p1;

    std::cout << x << std::endl;

}