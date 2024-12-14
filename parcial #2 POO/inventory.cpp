#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <regex>

// Default constructor
Inventory::Inventory() {}

// Add a product to the inventory
void Inventory::addProduct(const Product& product) {
    products.push_back(product);
}

// Display all products in the inventory
void Inventory::displayProducts() const {
    if (products.empty()) {
        std::cout << "No products available in the inventory." << std::endl;
        return;
    }
    for (const auto& product : products) {
        product.display();
        std::cout << "-------------------" << std::endl;
    }
}

// Find a product by name or code (using regex)
Product* Inventory::findProduct(const std::string& query) {
    std::regex pattern(query, std::regex::icase);
    for (auto& product : products) {
        if (std::regex_search(product.getName(), pattern) || std::regex_search(product.getCode(), pattern)) {
            return &product;
        }
    }
    return nullptr;
}

// Process a sale and update inventory
bool Inventory::processSale(const std::string& code, int quantity) {
    Product* product = findProduct(code);
    if (product == nullptr) {
        std::cerr << "Error: Product not found." << std::endl;
        return false;
    }

    if (product->getQuantity() < quantity) {
        std::cerr << "Error: Insufficient quantity available." << std::endl;
        return false;
    }

    double totalPrice = product->getPrice() * quantity;
    product->reduceQuantity(quantity);
    sales.emplace_back(code, quantity, totalPrice); // Record the sale
    std::cout << "Sale processed successfully." << std::endl;
    return true;
}

// Load inventory from a binary file
void Inventory::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for reading." << std::endl;
        return;
    }

    products.clear();
    Product temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Product))) {
        products.push_back(temp);
    }
    file.close();
    std::cout << "Inventory loaded successfully from " << filename << "." << std::endl;
}

// Save inventory to a binary file
void Inventory::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    for (const auto& product : products) {
        file.write(reinterpret_cast<const char*>(&product), sizeof(Product));
    }
    file.close();
    std::cout << "Inventory saved successfully to " << filename << "." << std::endl;
}

// Display sales report
void Inventory::displaySalesReport() const {
    if (sales.empty()) {
        std::cout << "No sales recorded." << std::endl;
        return;
    }
    for (const auto& sale : sales) {
        sale.display();
        std::cout << "-------------------" << std::endl;
    }
}

const std::vector<Product>& Inventory::getProducts() const {
    return products;
}

void Inventory::clear() {
    products.clear();
}