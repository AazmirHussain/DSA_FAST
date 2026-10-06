#include <iostream>
using namespace std;

class Pair{
public:
    int first, second;
    Pair(): first(0), second(0){}
    Pair(int f, int s): first(f), second(s){}
};

class HashTable{
    static const int TABLE_SIZE = 100;
    Pair table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];
    
    int hashFunction(int key){return abs(key) % TABLE_SIZE;}

public:
    HashTable(){
        for (int i = 0; i < TABLE_SIZE; i++){occupied[i] = false;}
    }

    void insert(int key, Pair value){
        int index = hashFunction(key);
        int startIndex = index;
        
        while (occupied[index]){
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex){return;}
        }
        
        table[index] = value;
        occupied[index] = true;
    }

    bool find(int key, Pair& result){
        int index = hashFunction(key);
        int startIndex = index;
        
        while (occupied[index]){
            result = table[index];
            return true;
        }
        return false;
    }

    bool contains(int key){
        int index = hashFunction(key);
        int startIndex = index;
        
        while (occupied[index]){return true;}
        return false;
    }
};

bool areDistinct(int a, int b, int c, int d){
    return(a != c && a != d && b != c && b != d);
}

void findPairsWithEqualSum(int arr[], int n){
    HashTable sumMap;
    bool found = false;
    
    for (int i = 0; i < n - 1 && !found; i++){
        for (int j = i + 1; j < n && !found; j++){
            int sum = arr[i] + arr[j];
            Pair existingPair;
            
            if (sumMap.find(sum, existingPair)){
                if (areDistinct(existingPair.first, existingPair.second, arr[i], arr[j])) {
                    cout << "(" << existingPair.first << ", " << existingPair.second << ") and ("
                    << arr[i] << ", " << arr[j] << ")" << endl;
                    found = true;
                }
            } 
            else{sumMap.insert(sum, Pair(arr[i], arr[j]));}
        }
    }
    
    if (!found){cout << "No pairs found" << endl;}
}

int main(){
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    findPairsWithEqualSum(arr1, n1);
    
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    findPairsWithEqualSum(arr2, n2);
    
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    findPairsWithEqualSum(arr3, n3);
    
    return 0;
}