#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Inventory.h"
#include <string>

class FileManager {
public:
    // Save inventory to a binary file
    static void saveToFile(const Inventory& inventory, const std::string& filename);

    // Load inventory from a binary file
    static void loadFromFile(Inventory& inventory, const std::string& filename);
};

#endif // FILEMANAGER_H