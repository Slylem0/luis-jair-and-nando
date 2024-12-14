#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product() = default;
    Product(const std::string& name, const std::string& code, double price, int quantity);

    // Getters and setters
    std::string getName() const;
    std::string getCode() const;
    double getPrice() const;
    int getQuantity() const;

    void setName(const std::string& name);
    void setCode(const std::string& code);
    void setPrice(double price);
    void setQuantity(int quantity);

    void display() const;

    // Method to reduce quantity
    void reduceQuantity(int quantity);

private:
    char name[50];
    char code[20];
    double price;
    int quantity;
};

#endif // PRODUCT_H