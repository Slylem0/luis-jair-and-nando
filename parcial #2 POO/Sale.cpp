#include "Sale.h"
#include <iostream>

Sale::Sale(const std::string& productCode, int quantity, double totalPrice)
    : productCode(productCode), quantity(quantity), totalPrice(totalPrice) {}

std::string Sale::getProductCode() const {
    return productCode;
}

int Sale::getQuantity() const {
    return quantity;
}

double Sale::getTotalPrice() const {
    return totalPrice;
}

void Sale::display() const {
    std::cout << "Product Code: " << productCode
              << "\nQuantity: " << quantity
              << "\nTotal Price: " << totalPrice << std::endl;
}