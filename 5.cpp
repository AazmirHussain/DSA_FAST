// Number of courses is not const and a 2D or 1D array will leak memory
// To make it the most effective way to code we need to use pointer arrays aka jagged array
#include <iostream>
using namespace std;

int main(){
    const int depts = 4;
    int courses[depts] = {3, 4, 2, 1};
    double* gpa[depts];

    for(int i = 0; i < depts; i++){
        gpa[i] = new double[courses[i]];
    }

    cout << "Enter GPA values for core courses (0.0 - 4.0):" << endl;
    for(int i = 0; i < depts; i++){
        cout << endl << "Department " << i + 1 << " (" << courses[i] << " courses):" << endl;
        for(int j = 0; j < courses[i]; j++){
            do {
                cout << "Course " << j + 1 << ": ";
                cin >> gpa[i][j];
                if (gpa[i][j] < 0.0 || gpa[i][j] > 4.0) {
                    cout << "Invalid GPA! Enter a value between 0.0 and 4.0.\n";
                }
            } while (gpa[i][j] < 0.0 || gpa[i][j] > 4.0);
        }
    }

    cout << endl << "--- GPA Report ---" << endl;
    string deptNames[depts] = {"Software Engineering", "Artificial Intelligence", 
        "Computer Science", "Data Science"};
    
    for (int i = 0; i < depts; i++){
        cout << deptNames[i] << " (" << courses[i] << " courses): ";
        for (int j = 0; j < courses[i]; j++){
            cout << gpa[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < depts; i++){
        delete[] gpa[i];
    }

    return 0;
}