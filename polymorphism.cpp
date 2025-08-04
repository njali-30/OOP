#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id, sal;
    string name, add;
public:
    virtual void accept() = 0;  
    virtual void display() = 0;
};

class Doctor : public Person {
public:
    void accept() {
        cout << "\nEnter the ID, Name and Address: ";
        cin >> id >> name >> add;
    }
    
    void display() {
        cout << "Doctor ID: " << id << ", Name: " << name << ", Address: " << add << endl;
    }
};

class Nurse : public Person {
public:
    void accept() {
        cout << "\nEnter the ID, Name, Address and Salary: ";
        cin >> id >> name >> add >> sal;
    }
    
    void display() {
        cout << "Nurse ID: " << id << ", Name: " << name << ", Address: " << add << ", Salary: " << sal << endl;
    }
};

class Astaff : public Person {
public:
    void accept() {
        cout << "\nEnter the ID, Name, Address and Salary: ";
        cin >> id >> name >> add >> sal;
    }
    
    void display() {
        cout << "Staff ID: " << id << ", Name: " << name << ", Address: " << add << ", Salary: " << sal << endl;
    }
};

int main() {
    Doctor doctors[10];
    Nurse nurses[10];
    Astaff staff[10];
    int doctorCount = 0, nurseCount = 0, staffCount = 0;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Accept details of Doctor\n";
        cout << "2. Display details of Doctor\n";
        cout << "3. Accept details of Nurse\n";
        cout << "4. Display details of Nurse\n";
        cout << "5. Accept details of Staff\n";
        cout << "6. Display details of Staff\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (doctorCount < 10) {
                    doctors[doctorCount].accept();
                    doctorCount++;
                } else {
                    cout << "Doctor list is full.\n";
                }
                break;
            case 2:
                for (int i = 0; i < doctorCount; ++i) {
                    doctors[i].display();
                }
                break;
            case 3: {
                int numNurses;
                cout << "How many nurses do you want to enter? ";
                cin >> numNurses;
                for (int i = 0; i < numNurses && nurseCount < 10; ++i) {
                    nurses[nurseCount].accept();
                    nurseCount++;
                }
                break;
            }
            case 4:
                for (int i = 0; i < nurseCount; ++i) {
                    nurses[i].display();
                }
                break;
            case 5: {
                int numStaff;
                cout << "How many staff members do you want to enter? ";
                cin >> numStaff;
                for (int i = 0; i < numStaff && staffCount < 10; ++i) {
                    staff[staffCount].accept();
                    staffCount++;
                }
                break;
            }
            case 6:
                for (int i = 0; i < staffCount; ++i) {
                    staff[i].display();
                }
                break;
            case 7:
                return 0;  
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
