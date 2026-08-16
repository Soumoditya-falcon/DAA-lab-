#include <iostream>
using namespace std;

int main()
{
    int *p;

    p = new int;

    cout << "Enter an integer: ";.........0000
    cin >> *p;

    cout << "The value is: " << *p << endl;

    delete p;

    return 0;
}
