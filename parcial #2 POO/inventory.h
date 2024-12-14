#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include "Sale.h"
#include <vector>
#include <string>

class Inventory {
public:
    Inventory();

    void addProduct(const Product& product);
    void displayProducts() const;
    Product* findProduct(const std::string& query);
    bool processSale(const std::string& code, int quantity);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    void displaySalesReport() const;
    const std::vector<Product>& getProducts() const;
    void clear();

private:
    std::vector<Product> products;
    std::vector<Sale> sales; // Add this line
};

#endif // INVENTORY_H