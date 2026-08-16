#include <iostream>
using namespace std;

class Student
{
    int rollNumber;
    string name;
    int numberOfSubjects;
    float *marks;

public:
    void accept()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Number of Subjects: ";
        cin >> numberOfSubjects;

        marks = new float[numberOfSubjects];

        cout << "Enter marks for " << numberOfSubjects << " subjects:" << endl;

        for (int i = 0; i < numberOfSubjects; i++)
        {
            cin >> marks[i];
        }
    }

    void calculate()
    {
        float total = 0;

        for (int i = 0; i < numberOfSubjects; i++)
        {
            total = total + marks[i];
        }

        float average = total / numberOfSubjects;

        cout << "\nTotal Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }

    void display()
    {
        cout << "\nStudent Details" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Number of Subjects: " << numberOfSubjects << endl;

        cout << "Marks: ";

        for (int i = 0; i < numberOfSubjects; i++)
        {
            cout << marks[i] << " ";
        }

        cout << endl;

        calculate();
    }

    ~Student()
    {
        delete[] marks;
    }
};

int main()
{
    Student s;

    s.accept();
    s.display();

    return 0;
}
