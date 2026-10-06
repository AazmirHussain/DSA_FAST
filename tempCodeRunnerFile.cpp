#include <iostream>
#include <string>
using namespace std;

int main(){
    int r;
    cout << "Enter number of rows in the hall: ";
    cin >> r;

    int* seats = new int[r];
    string** chart = new string*[r];

    for (int i = 0; i < r; i++){
        cout << "Enter number of seats in row " << i + 1 << ": ";
        cin >> seats[i];
        chart[i] = new string[seats[i]];
    }

    cout << endl << "Enter attendee names for each seat: ";
    for(int i = 0; i < r; i++){
        cout << endl << "Row " << i + 1 << " (" << seats[i] << " seats):";
        for(int j = 0; j < seats[i]; j++){
            cout << "Seat " << j + 1 << ": ";
            cin >> chart[i][j];
        }
    }

    cout << endl << " Seating Chart " << endl;
    for(int i = 0; i < r; i++){
        cout << "Row " << i + 1 << ": ";
        for(int j = 0; j < seats[i]; j++){
            cout << chart[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < r; i++){
        delete[] chart[i];
    }
    delete[] chart;
    delete[] seats;

    return 0;
}