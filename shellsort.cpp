#include<iostream>
using namespace std;

void shellsort(int arr[], int n){
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j-gap] > temp; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }

    cout << "Array after shell sort is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Enter the array length: ";
    int a;
    cin >> a;
    int arr[a];
    cout << "Enter the array elements \n";
    for(int i = 0; i < a; i++){
        cout << "Element " << i+1 << " is: ";
        cin >> arr[i];
    }
    cout << endl;
    
    for(int i = 0; i < a; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    shellsort(arr, a);

    return 0;
}