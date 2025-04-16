#include "Price.h"
#include <iostream>

using namespace std;

void addPrice(Price& result, const Price& a, const Price& b) {
    int totalcoin = (a.hrn + b.hrn) * 100 + a.kop + b.kop;
    result.hrn = totalcoin / 100; // a.hrn + b.hrn якщо копійок більше 100 це виправииться в roundPrise
    result.kop = static_cast<short int>(totalcoin % 100);
}

void multiplyPrice(Price& result, const Price& price, int quantity) {
    int totalcoin = (price.hrn * 100 + price.kop) * quantity;
    result.hrn = totalcoin / 100;
    result.kop = static_cast<short int>(totalcoin % 100);
}

void roundPrice(Price& price) {
    int remainder = price.kop % 10;
    if (remainder < 5)
        price.kop -= remainder;
    else
        price.kop += (10 - remainder);

    if (price.kop >= 100) {
        price.hrn += price.kop / 100;
        price.kop %= 100;
    }
}

void printPrice(const Price& price) {
    cout << price.hrn << " hryvn " << price.kop << " coin" << endl;
}
