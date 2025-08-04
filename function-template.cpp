#include <iostream>
using namespace std;

template <class T>
void sort(T a[], int n) {
    T temp;
    cout << "\nEnter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int ch, n;
    int a[10];
    float b[10];
    char c[10];
    
    cout << "Enter total elements (up to 10): ";
    cin >> n;
    
    if (n > 10 || n <= 0) {
        cout << "Please enter a valid number of elements (1-10)." << endl;
        return 1;
    }
    
    do {
        cout << "\nMenu:\n1. Integer\n2. Float\n3. Char\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                sort(a, n);
                break;
                
            case 2:
                sort(b, n);
                break;
                
            case 3:
                sort(c, n);
                break;
                
            case 0:
                cout << "Exiting program." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 0);
    
    return 0;
}
