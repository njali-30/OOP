#include <iostream>
#include <string.h>
using namespace std;

class bank {
public:
    string name;
    long ac;
    int i,wamt, bamt, damt, bal;

    void accept();
    void withdraw();
    void deposit();
    void display();
};

bank b[10];

void bank::accept() {
    cout << "Name : ";
    cin >> name;
    cout << "Account number : ";
    cin >> ac;
    cout << "Amount : ";
    cin >> bal;
}

void bank::display() {
    cout << "\n" << name << "\t" << ac << "\t" << bal;
}

void bank::deposit() {
    cout << "\nEnter the amount to deposit : ";
    cin >> damt;
    bal += damt;
    display();
}

void bank::withdraw() {
    cout<<"\nEnter the amount to withdraw : ";
    cin>> wamt;
    if(b[i].bal<wamt){
        bal-=wamt;
        display();
    }
    else{
        
        cout<<"Balance is low.";
    }
}


int main() {
    int x, ch;
    string n;
    bank b[10];
    cout << "Enter total number of customers : " << endl;
    cin >> x;

    do {
        cout << "\n1. Accept\n2. Display\n3. Deposit\n4. Withdraw";
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the customer details :" << endl;
                for (int i = 0; i < x; i++) {
                    b[i].accept();
                }
                break;

            case 2:
                cout << "\nName\tAccount Number\tBalance";
                for (int i = 0; i < x; i++) {
                    b[i].display();
                }
                break;

            case 3:
                cout << "Enter the customer's name: ";
                cin >> n;
                for (int i = 0; i < x; i++) {
                    if (b[i].name == n) {
                        b[i].deposit();
                        break; 
                    }
                }
                break;
                
            case 4:
                cout<<"Enter the customer's name : ";
                cin>>n;
                for(int i=0;i<x;i++){
                    if(b[i].name==n){
                        b[i].withdraw();
                    }
                }
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (ch != 0);

    return 0;
}
