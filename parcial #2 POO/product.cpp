#include "Product.h"
#include <iostream>
#include <cstring>

Product::Product(const std::string& name, const std::string& code, double price, int quantity) {
    std::strncpy(this->name, name.c_str(), sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';
    std::strncpy(this->code, code.c_str(), sizeof(this->code) - 1);
    this->code[sizeof(this->code) - 1] = '\0';
    this->price = price;
    this->quantity = quantity;
}

std::string Product::getName() const {
    return std::string(name);
}

std::string Product::getCode() const {
    return std::string(code);
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setName(const std::string& name) {
    std::strncpy(this->name, name.c_str(), sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';
}

void Product::setCode(const std::string& code) {
    std::strncpy(this->code, code.c_str(), sizeof(this->code) - 1);
    this->code[sizeof(this->code) - 1] = '\0';
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Product::display() const {
    std::cout << "Name: " << name << "\nCode: " << code << "\nPrice: " << price << "\nQuantity: " << quantity << std::endl;
}

void Product::reduceQuantity(int quantity) {
    if (this->quantity >= quantity) {
        this->quantity -= quantity;
    } else {
        std::cerr << "Error: Insufficient quantity available." << std::endl;
    }
}