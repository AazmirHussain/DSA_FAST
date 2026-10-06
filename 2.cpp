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

class Dictionary{
    static const int tableSize = 100;
    HashNode* table[tableSize];

    int hashFunction(const char* key) {
        int sum = 0;
        for (int i = 0; key[i] != '\0'; i++){
            sum += int(key[i]);
        }
        return sum % tableSize;
    }

public:
    Dictionary() {
        for (int i = 0; i < tableSize; i++){
            table[i] = nullptr;
        }
    }

    void Add_Record(const char* key, const char* value){
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
        cout << "Record (" << key << ", " << value << ") added at index " << index << endl;
    }

    void Word_Search(const char* key){
        int index = hashFunction(key);
        HashNode* temp = table[index];
        while (temp != nullptr){
            if (strcmp(temp->key, key) == 0){
                cout << "Search key " << key << ": " << temp->value << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Error: Key " << key << " not found!" << endl;
    }

    void Delete_Record(const char* key){
        int index = hashFunction(key);
        HashNode* temp = table[index];
        HashNode* prev = nullptr;

        while (temp != nullptr){
            if (strcmp(temp->key, key) == 0){
                if (prev == nullptr){
                    table[index] = temp->next;
                }
                else{
                    prev->next = temp->next;
                }

                delete temp;
                cout << "Key " << key << " deleted successfully!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Error: Key " << key << " not found!" << endl;
    }

    void Print_Dictionary(){
        for (int i = 0; i < tableSize; i++){
            if (table[i] != nullptr){
                cout << "Index " << i << ": ";
                HashNode* temp = table[i];

                while (temp != nullptr){
                    cout << "(" << temp->key << ", " << temp->value << ") ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

int main(){
    Dictionary dict;

    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "ENG");

    dict.Word_Search("AB");
    dict.Delete_Record("EF");
    dict.Print_Dictionary();

    return 0;
}
