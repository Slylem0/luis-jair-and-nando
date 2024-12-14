#ifndef SALE_H
#define SALE_H

#include <string>

class Sale {
public:
    Sale(const std::string& productCode, int quantity, double totalPrice);

    std::string getProductCode() const;
    int getQuantity() const;
    double getTotalPrice() const;

    void display() const;

private:
    std::string productCode;
    int quantity;
    double totalPrice;
};

#endif // SALE_H