#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int productID;
    string productName;
    float price;
    int quantity;

public:
    // 1. Accept product details
    void accept()
    {
        cout << "Enter Product ID: ";
        cin >> productID;

        cout << "Enter Product Name: ";
        cin >> productName;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // 2. Display product details
    void display()
    {
        cout << productID << "\t"
             << productName << "\t"
             << price << "\t"
             << quantity << "\t"
             << price * quantity << endl;
    }

    // 3. Calculate cost of one product
    float getCost()
    {
        return price * quantity;
    }
};

int main()
{
    int n;
    float total = 0;

    // Ask user for number of products
    cout << "Enter number of products: ";
    cin >> n;

    // Dynamically allocate array of Product objects
    Product *p = new Product[n];

    // Accept details of all products
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Product " << i + 1 << ":\n";
        p[i].accept();
    }

    // Display all products
    cout << "\n---------------------------------------------------\n";
    cout << "ID\tName\tPrice\tQty\tCost\n";
    cout << "---------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        p[i].display();
    }

    // Calculate total cost
    for (int i = 0; i < n; i++)
    {
        total = total + p[i].getCost();
    }

    // 4. Display total amount
    cout << "---------------------------------------------------\n";
    cout << "Total Amount = " << total << endl;

    // 5. Release dynamically allocated memory
    delete[] p;

    return 0;
}
