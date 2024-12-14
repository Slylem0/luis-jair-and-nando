#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveToFile(const Inventory& inventory, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    const auto& products = inventory.getProducts();
    for (const auto& product : products) {
        file.write(reinterpret_cast<const char*>(&product), sizeof(Product));
    }
    file.close();
    std::cout << "Inventory saved successfully to " << filename << "." << std::endl;
}

void FileManager::loadFromFile(Inventory& inventory, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for reading." << std::endl;
        return;
    }

    inventory.clear();
    Product temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Product))) {
        inventory.addProduct(temp);
    }
    file.close();
    std::cout << "Inventory loaded successfully from " << filename << "." << std::endl;
}