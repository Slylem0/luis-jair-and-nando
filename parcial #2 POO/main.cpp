#include "Inventory.h"
#include <iostream>
#include "FileManager.h"

using namespace std;

void showMenu() {
    cout << "\n=== Inventory Management System ===\n";
    cout << "1. Add a product to the inventory\n";
    cout << "2. Show all products\n";
    cout << "3. Search for a product by name or code\n";
    cout << "4. Process a sale\n";
    cout << "5. Load inventory from file\n";
    cout << "6. Display sales report\n";
    cout << "0. Exit\n";
    cout << "===================================\n";
    cout << "Choose an option: ";
}

int main() {
    Inventory inventory;
    string filename = "inventory.bin";
    int choice;

    // Load inventory from file at the start
    FileManager::loadFromFile(inventory, filename);

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1: {
                string name, code;
                double price;
                int quantity;

                cout << "Enter product name: ";
                getline(cin, name);
                cout << "Enter product code: ";
                getline(cin, code);
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;

                Product product(name, code, price, quantity);
                inventory.addProduct(product);
                cout << "Product added successfully!" << endl;

                // Save inventory to file after adding a product
                FileManager::saveToFile(inventory, filename);
                break;
            }
            case 2:
                inventory.displayProducts();
                break;

            case 3: {
                string query;
                cout << "Enter product name or code to search: ";
                getline(cin, query);

                Product* product = inventory.findProduct(query);
                if (product) {
                    cout << "Product found:\n";
                    product->display();
                } else {
                    cout << "No product matches the search query." << endl;
                }
                break;
            }
            case 4: {
                string code;
                int quantity;

                cout << "Enter product code for the sale: ";
                getline(cin, code);
                cout << "Enter quantity to sell: ";
                cin >> quantity;

                if (inventory.processSale(code, quantity)) {
                    // Save inventory to file after processing a sale
                    FileManager::saveToFile(inventory, filename);
                }
                break;
            }
            case 5:
                FileManager::loadFromFile(inventory, filename);
                break;

            case 6:
                inventory.displaySalesReport();
                break;

            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}