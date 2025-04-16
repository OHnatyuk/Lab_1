#include <iostream>
#include <fstream>
#include "Price.h"

using namespace std;

int main() {
    ifstream inputFile("prices.txt");

    Price total = { 0, 0 };
    int hrn, kop, quantity;

    while (inputFile >> hrn >> kop >> quantity) {
        Price itemPrice = { hrn, static_cast<short int>(kop) };
        Price product;
        multiplyPrice(product, itemPrice, quantity);

        Price newTotal;
        addPrice(newTotal, total, product);
        total = newTotal;
    }

    inputFile.close();

    cout << "Total before rounding: ";
    printPrice(total);

    roundPrice(total);

    cout << "Total to pay (rounded): ";
    printPrice(total);

    return 0;
}
