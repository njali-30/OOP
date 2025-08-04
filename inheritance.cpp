#include <iostream>
#include <string>
using namespace std;

class student {
protected:
    int roll;
    string prn, name;

public:
    void accept() {
        cout << "Enter student roll number: ";
        cin >> roll;
        cout << "Enter PRN: ";
        cin >> prn;
        cin.ignore(); 
        cout << "Enter name of the student: ";
        getline(cin, name);  
    }

    void displayStudent() const {
        cout << roll << "\t" << prn << "\t" << name << "\t";
    }
};

class test : virtual public student {
protected:
    int c1[5], c2[5], e1[5];  
    string sub[5];            

public:
    void acceptTest() {
        for (int i = 0; i < 5; i++) {
            cin.ignore();  
            cout << "Enter name of subject " << (i + 1) << ": ";
            getline(cin, sub[i]);  

            cout << "Enter CIA1 marks for " << sub[i] << " (/20): ";
            cin >> c1[i];

            cout << "Enter CIA2 marks for " << sub[i] << " (/20): ";
            cin >> c2[i];

            cout << "Enter Endsem marks for " << sub[i] << " (/60): ";
            cin >> e1[i];
        }
    }

    void displayTest(int i) const {
        int total = c1[i] + c2[i] + e1[i];
        string result = (total < 30) ? "FAIL" : "PASS";
        cout << sub[i] << "\t" << c1[i] << "\t" << c2[i] << "\t" << e1[i] << "\t" << result << "\t";
    }
};

class sport : virtual public student {
protected:
    string grade;

public:
    void acceptSport() {
        cout << "Enter sport grade: ";
        cin >> grade;
    }

    void displaySport() const {
        cout << grade;
    }
};

class result : public test, public sport {
public:
    void acceptDetails() {
        accept();        
        acceptTest();    
        acceptSport();   
    }

    void displayResult() const {
        displayStudent();
        for (int i = 0; i < 5; i++) {
            if (i != 0) { 
                cout << "\t\t\t";  
            }
            displayTest(i);
            if (i == 0) {
                displaySport();  
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 0, ch;
    result r[10];  

    do {
        cout << "\nMenu:";
        cout << "\n1. Accept Student Details";
        cout << "\n2. Display Student Details";
        cout << "\n3. Display Test Results";
        cout << "\n4. Display Sport Grade";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter the number of students: ";
            cin >> n;
            if (n > 10) {
                cout << "Maximum 10 students allowed. Resetting to 10.\n";
                n = 10;
            }
            for (int i = 0; i < n; i++) {
                cout << "\nEnter details for student " << (i + 1) << endl;
                r[i].acceptDetails();  
            }
            break;

        case 2:
            cout << "\nRoll\tPRN\tName" << endl;
            for (int i = 0; i < n; i++) {
                r[i].displayStudent();  
                cout << endl;
            }
            break;

        case 3:
            cout << "\nRoll\tPRN\tName\tSubject\tCIA1\tCIA2\tEndsem\tResult\tSport Grade" << endl;
            for (int i = 0; i < n; i++) {
                r[i].displayResult();  
            }
            break;

        case 4:
            cout << "\nRoll\tPRN\tName\tSport Grade" << endl;
            for (int i = 0; i < n; i++) {
                r[i].displayStudent();        
                r[i].displaySport();   
                cout << endl;
            }
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (ch != 5);

    return 0;
}
