#include <iostream>
#include <cstring>
using namespace std;

class HashNode{
public:
    char key[50];
    char value[50];
    HashNode* next;

    HashNode(const char* k, const char* v){
        strcpy(key, k);
        strcpy(value, v);
        next = nullptr;
    }
};

class HashTable{
    HashNode* table[10];
    int numBuckets;

    int hashFunction(const char* key){
        int sum = 0;
        for (int i = 0; key[i] != '\0'; i++){
            sum += int(key[i]);
        }
        return (sum % numBuckets);
    }

public:
    HashTable(int buckets = 10){
        numBuckets = buckets;
        for (int i = 0; i < numBuckets; i++){
            table[i] = nullptr;
        }
    }

    void insert(const char* key, const char* value){
        int index = hashFunction(key);
        HashNode* newNode = new HashNode(key, value);

        if (table[index] == nullptr){
            table[index] = newNode;
        } 
        else{
            HashNode* temp = table[index];
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display(){
        for (int i = 0; i < numBuckets; i++){
            cout << "Bucket " << i << ": ";
            HashNode* temp = table[i];
            while (temp != nullptr){
                cout << "(" << temp->key << ", " << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    HashTable myhash(10);

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    myhash.display();

    return 0;
}