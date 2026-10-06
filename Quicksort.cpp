#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return(i+1);
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){
    int a = 8;
    int arr[a];
    int low = 0;
    int high = a-1;

    cout << "Enter the elements for array: ";
    for(int i = 0; i < a; i++){cin >> arr[i];}
    cout << endl << endl;
    for(int i = 0; i < a; i++){cout << arr[i] << " ";}
    cout << endl;

    quicksort(arr, low, high);
    for(int i = 0; i < a; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}