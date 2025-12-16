

///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Needed for setting precision

using namespace std;

// ==========================================
// PART 1: The Item Class
// ==========================================
class Item {
private:
    // TODO: Declare member variables: name (string), price (double), quantity (int)
    std::string name;
    double price;
    int quantity;

public:
    // TODO: Write the Constructor to initialize the variables
    Item(std::string n, double p, int q) : name(n), price(p), quantity(q) {}

    // TODO: Write get_total_price() returning (price * quantity)
    double get_total_price() const {
        return price * quantity;
    }

    // TODO: Write update_price(double multiplier) to update the price
    // (Needed for Part 3)
    void update_price(double multiplier) {
        price *= multiplier;
    }

    // TODO: Write print_info() to display "[Name] - Price: $[Price] - Qty: [Qty]"
    // Hint: Use std::cout
    void print_info() const {
        // Use std::fixed and std::setprecision(2) to display prices with 2 decimal places
        std::cout << name << " - Price: $" 
                  << std::fixed << std::setprecision(2) << price 
                  << " - Qty: " << quantity << std::endl;
    }
};

// ==========================================
// PART 2: Read-Only Function
// ==========================================

// TODO: Write 'calculate_inventory_value'
// Arguments: A vector of Items passed by CONST REFERENCE
// Return: a floating point number (the sum of all item total prices)
double calculate_inventory_value(const std::vector<Item>& inventory) {
    double total_value = 0.0;
    for (const Item& item : inventory) {
        total_value += item.get_total_price();
    }
    return total_value;
}

// ==========================================
// PART 3: Modifying Function
// ==========================================

// TODO: Write 'apply_inflation'
// Arguments: A vector of Items passed by REFERENCE (so we can change them), and a double multiplier.
// Return: void
// Logic: Loop through the vector and update the price of every item.
void apply_inflation(std::vector<Item>& inventory, double multiplier) {
    for (Item& item : inventory) {
        // Since 'item' is a non-const reference, we can call the modifying method
        item.update_price(multiplier);
    }
}


// ==========================================
// PART 4: Main Execution
// ==========================================
int main() {
    // 1. Create a vector of Items
    std::vector<Item> inventory;

    // 2. Instantiate Items and push_back into the vector
    // Example: laptop - price: 1000.0, quantity: 5
    // TODO: Add at least 3 items to the 'inventory' vector.
    inventory.push_back(Item("Laptop", 1000.0, 5));
    inventory.push_back(Item("Mouse", 25.50, 20));
    inventory.push_back(Item("Keyboard", 75.99, 10));

    // 3. Print the details of all items
    std::cout << "--- Current Inventory ---" << std::endl;
    for (Item& i : inventory) {
        i.print_info();
    }

    // 4. Calculate and print total value
    // TODO: Call calculate_inventory_value and print the result.
    double initial_value = calculate_inventory_value(inventory);
    std::cout << "\nTotal Inventory Value: $" 
              << std::fixed << std::setprecision(2) << initial_value 
              << std::endl;

    // 5. Apply Inflation
    std::cout << "\n--- Inflation hits! (Prices +10%) ---" << std::endl;
    // TODO: Call apply_inflation with a multiplier of 1.1
    apply_inflation(inventory, 1.1);
    
    // Print the updated details (optional, but helpful for debugging)
    for (Item& i : inventory) {
        i.print_info();
    }

    // 6. Print new Total Value
    // TODO: Call calculate_inventory_value again and print result.
    double new_value = calculate_inventory_value(inventory);
    std::cout << "New Inventory Value: $" 
              << std::fixed << std::setprecision(2) << new_value 
              << std::endl;

    return 0;
}



/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For setting precision in output

using namespace std;

// TODO: TASK 1 - Define the 'Product' struct/class here
struct Product {
    std::string name;
    double price;
    int stock_level;
};

// TODO: TASK 3 - Write 'calculateTotalValue' here
// Arguments: A constant reference to a vector of Products (const std::vector<Product>&)
// Return: The total calculated value (sum of price * stock_level for all products)
double calculateTotalValue(const std::vector<Product>& inventory) {
    double total_value = 0.0;
    
    // Use a range-based for loop to iterate over the items
    for (const Product& p : inventory) {
        total_value += p.price * p.stock_level;
    }
    
    return total_value;
}


// TODO: TASK 4 - Write 'findLowStock' here
// Arguments: A constant reference to a vector of Products, and an integer threshold
// Return: void (it should print the low stock item names)
void findLowStock(const std::vector<Product>& inventory, int threshold) {
    for (const Product& p : inventory) {
        if (p.stock_level < threshold) {
            std::cout << "- " << p.name 
                      << " (Stock: " << p.stock_level << ")" << std::endl;
        }
    }
}

int main() {
    // Set output formatting for currency
    std::cout << std::fixed << std::setprecision(2);
    
    // TODO: TASK 2 - Create the 'inventory' vector and add items
    std::vector<Product> inventory;
    
    // Add items (Name, Price, Stock)
    inventory.push_back({"Laptop", 1200.00, 5});
    inventory.push_back({"Monitor", 350.50, 25});
    inventory.push_back({"Webcam", 45.99, 8});
    inventory.push_back({"Headphones", 99.00, 15});
    inventory.push_back({"Flash Drive", 10.99, 2});
    
    std::cout << "--- Inventory Status ---" << std::endl;
    for (const auto& p : inventory) {
        std::cout << p.name << " | Price: $" << p.price << " | Stock: " << p.stock_level << std::endl;
    }
    
    // Testing Task 3
    double total = calculateTotalValue(inventory);
    std::cout << "\nTotal Inventory Value: $" << total << std::endl;

    // Testing Task 4
    int low_stock_threshold = 10;
    std::cout << "\nLow Stock Items (Threshold < " << low_stock_threshold << "):" << std::endl;
    findLowStock(inventory, low_stock_threshold);

    return 0;
}