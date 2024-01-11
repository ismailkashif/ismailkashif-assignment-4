#include <iostream>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

class InventoryManager {
private:
    Product* inventory;
    int capacity;
    int numProducts;

public:
    InventoryManager() : inventory(nullptr), capacity(0), numProducts(0) {}

    ~InventoryManager() {
        delete[] inventory;
    }

    void addProduct(int id, const std::string& name, double price, int quantity) {
        if (numProducts == capacity) {

            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resizeInventory(newCapacity);
        }

        inventory[numProducts++] = { id, name, price, quantity };
        std::cout << "Product added to inventory." << endl;
    }

    void removeProduct(int id) {
        int index = findProductIndex(id);
        if (index != -1) {
            for (int i = index; i < numProducts - 1; ++i) {
                inventory[i] = inventory[i + 1];
            }
            --numProducts;
            std::cout << "Product removed from inventory." << endl;
        }
        else {
            cout << "Product with ID " << id << " not found in inventory." << endl;
        }
    }

    void displayInventory() {
        cout << "Inventory:" << endl;
        for (int i = 0; i < numProducts; ++i) {
            cout << "ID: " << inventory[i].id << ", Name: " << inventory[i].name
                << ", Price: $" << inventory[i].price << ", Quantity: " << inventory[i].quantity << endl;
        }
    }

private:
    void resizeInventory(int newCapacity) {
        Product* newInventory = new Product[newCapacity];
        for (int i = 0; i < numProducts; ++i) {
            newInventory[i] = inventory[i];
        }
        delete[] inventory;
        inventory = newInventory;
        capacity = newCapacity;
    }

    int findProductIndex(int id) {
        for (int i = 0; i < numProducts; ++i) {
            if (inventory[i].id == id) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    InventoryManager inventoryManager;


    inventoryManager.addProduct(1, "Laptop", 999.99, 5);
    inventoryManager.addProduct(2, "Smartphone", 299.99, 10);
    inventoryManager.addProduct(3, "Headphones", 49.99, 20);


    inventoryManager.displayInventory();


    inventoryManager.removeProduct(2);


    inventoryManager.displayInventory();

    
}