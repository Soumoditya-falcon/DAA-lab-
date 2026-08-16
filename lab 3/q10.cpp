#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int employeeID;
    string employeeName;
    float basicSalary;
    float *earnings;
    int months;

public:

    // Constructor
    Employee(int n)
    {
        months = n;
        earnings = new float[months];
    }

    // Accept employee details and monthly earnings
    void accept()
    {
        cout << "Enter Employee ID: ";
        cin >> employeeID;

        cout << "Enter Employee Name: ";
        cin >> employeeName;

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        cout << "\nEnter monthly earnings:\n";

        for (int i = 0; i < months; i++)
        {
            cout << "Month " << i + 1 << ": ";
            cin >> earnings[i];
        }
    }

    // Calculate total earnings
    float calculateTotal()
    {
        float total = 0;

        for (int i = 0; i < months; i++)
        {
            total = total + earnings[i];
        }

        return total;
    }

    // Calculate average earning
    float calculateAverage()
    {
        return calculateTotal() / months;
    }

    // Find month with highest earning
    int highestMonth()
    {
        int highest = 0;

        for (int i = 1; i < months; i++)
        {
            if (earnings[i] > earnings[highest])
            {
                highest = i;
            }
        }

        return highest;
    }

    // Display complete analysis
    void display()
    {
        float total = calculateTotal();
        float average = calculateAverage();
        int highest = highestMonth();

        cout << "\n========== Employee Analysis ==========\n";
        cout << "Employee ID       : " << employeeID << endl;
        cout << "Employee Name     : " << employeeName << endl;
        cout << "Basic Salary      : " << basicSalary << endl;

        cout << "\nMonthly Earnings:\n";

        for (int i = 0; i < months; i++)
        {
            cout << "Month " << i + 1 << " : " << earnings[i] << endl;
        }

        cout << "\nTotal Earnings    : " << total << endl;
        cout << "Average Earnings  : " << average << endl;
        cout << "Highest Earning   : " << earnings[highest] << endl;
        cout << "Highest Earning Month : Month "
             << highest + 1 << endl;
    }

    // Destructor
    ~Employee()
    {
        delete[] earnings;
    }
};

int main()
{
    int n;

    cout << "Enter number of months: ";
    cin >> n;

    // Dynamically create Employee object
    Employee *emp = new Employee(n);

    // Accept details
    emp->accept();

    // Display analysis
    emp->display();

    // Delete dynamically created Employee object
    delete emp;

    return 0;
}
