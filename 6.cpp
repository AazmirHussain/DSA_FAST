#include<iostream>
using namespace std;

int recursiveArraysum(int* arr[], int sizes[], int dim){
    int sum = 0;
    if(dim == 1){
        for(int i = 0; i < sizes[0]; i++){
            sum += arr[i];
        }
    }
    else{
        for(int i = 0; i < sizes[0]; i++){
            sum += recursiveArraysum((int**)arr[i], sizes + 1, dim - 1);
        }
    }

    return sum;
}

int main(){
    int cols, rows, total;
    cout << "Enter the size of rows and columns: ";
    cin >> rows >> cols;
    int sizes[2]= {rows, cols};
    int** array = new int* [rows];

    for(int i = 0; i < rows; i++){
        array[i] = new int[cols];
        for(int j = 0; j < cols; j++){
            cout << "(" << i << ", " << j << "(: ";
            cin >> array[i][j]; 
        }
    }


    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    total = recursiveArraysum((int**)array, sizes, 2);
    cout << "Sum is: " << total << endl;

    for(int i = 0; i < rows; i++){
        delete[] array[i];
    }
    delete[] array;

    return 0;
}