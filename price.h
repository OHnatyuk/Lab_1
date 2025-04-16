#include <iostream>

struct Price {
    int hrn;
    short int kop;
};

void addPrice(Price& result, const Price& a, const Price& b);
void multiplyPrice(Price& result, const Price& price, int quantity);
void roundPrice(Price& price);
void printPrice(const Price& price);
