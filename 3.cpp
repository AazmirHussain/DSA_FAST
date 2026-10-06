#include <iostream>
using namespace std;

template<typename K, typename V>
class Node {
public:
    K key;
    V value;
    Node* next;
    Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
};

template<typename K, typename V>
class HashTable{
    static const int DEFAULT_CAPACITY = 10;
    Node<K, V>** table;
    int capacity;
    int size;

    int hashFunction(const K& key) const {return (key.length() % capacity);}
    int hashFunction(int key) const {return key % capacity;}

public:
    HashTable(int cap = DEFAULT_CAPACITY) : capacity(cap), size(0){
        table = new Node<K, V>*[capacity];
        for (int i = 0; i < capacity; i++){table[i] = nullptr;}
    }

    ~HashTable(){
        clear();
        delete[] table;
    }

    void insert(const K& key, const V& value){
        int index = hashFunction(key);
        
        Node<K, V>* current = table[index];
        while (current != nullptr){
            if (current->key == key){
                current->value = value;
                return;
            }
            current = current->next;
        }
        
        Node<K, V>* newNode = new Node<K, V>(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        size++;
    }

    bool deleteKey(const K& key){
        int index = hashFunction(key);
        
        Node<K, V>* current = table[index];
        Node<K, V>* prev = nullptr;
        
        while (current != nullptr){
            if (current->key == key){
                if (prev == nullptr){table[index] = current->next;} 
                else {prev->next = current->next;}
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        
        return false;
    }

    V* search(const K& key){
        int index = hashFunction(key);
        
        Node<K, V>* current = table[index];
        while (current != nullptr){
            if (current->key == key){return &(current->value);}
            current = current->next;
        }
        return nullptr;
    }

    void display() const{
        cout << "Hash Table Contents:" << endl;
        cout << "Size: " << size << ", Capacity: " << capacity << endl;
        cout << endl << endl;
        
        for (int i = 0; i < capacity; ++i){
            cout << "Bucket " << i << ": ";
            
            Node<K, V>* current = table[i];
            if (current == nullptr){cout << "Empty";} 
            else{
                while (current != nullptr){
                    cout << "[" << current->key << " -> " << current->value << "] ";
                    current = current->next;
                }
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    int getSize(){return size;}
    bool isEmpty(){return size == 0;}
    void clear(){
        for (int i = 0; i < capacity; i++){
            Node<K, V>* current = table[i];
            while (current != nullptr){
                Node<K, V>* temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = nullptr;
        }
        size = 0;
    }

    HashTable(const HashTable& other) : capacity(other.capacity), size(0){
        table = new Node<K, V>*[capacity];
        for (int i = 0; i < capacity; i++) {table[i] = nullptr;}
        
        for (int i = 0; i < capacity; i++){
            Node<K, V>* current = other.table[i];
            while (current != nullptr) {
                insert(current->key, current->value);
                current = current->next;
            }
        }
    }

    HashTable& operator=(const HashTable& other){
        if (this != &other){
            clear();
            delete[] table;
            
            capacity = other.capacity;
            size = 0;
            table = new Node<K, V>*[capacity];
            for (int i = 0; i < capacity; i++){table[i] = nullptr;}
            
            for (int i = 0; i < capacity; i++){
                Node<K, V>* current = other.table[i];
                while (current != nullptr){
                    insert(current->key, current->value);
                    current = current->next;
                }
            }
        }
        return *this;
    }
};

int main() {
    cout << "=== Hash Table Implementation Demo ===" << endl;
    
    HashTable<string, int> hashTable;

    cout << "\n1. Inserting key-value pairs:" << endl;
    hashTable.insert("apple", 10);
    hashTable.insert("banana", 20);
    hashTable.insert("orange", 30);
    hashTable.insert("grape", 40);
    hashTable.insert("apple", 15);
    
    hashTable.display();

    cout << "\n2. Search operations:" << endl;
    int* value = hashTable.search("banana");
    if (value){cout << "Found 'banana': " << *value << endl;} 
    else{cout << "'banana' not found" << endl;}

    value = hashTable.search("mango");
    if (value){cout << "Found 'mango': " << *value << endl;} 
    else {cout << "'mango' not found" << endl;}

    cout << "\n3. Delete operations:" << endl;
    if (hashTable.deleteKey("orange")){cout << "Successfully deleted 'orange'" << endl;} 
    else{cout << "'orange' not found for deletion" << endl;}

    if (hashTable.deleteKey("pineapple")){cout << "Successfully deleted 'pineapple'" << endl;} 
    else {cout << "'pineapple' not found for deletion" << endl;}
    
    hashTable.display();

    cout << "\n4. Testing with integer keys:" << endl;
    HashTable<int, string> intTable(5);
    
    intTable.insert(1, "One");
    intTable.insert(6, "Six");
    intTable.insert(11, "Eleven");
    intTable.insert(3, "Three");
    
    intTable.display();

    cout << "\n5. Additional operations:" << endl;
    cout << "Current size: " << hashTable.getSize() << endl;
    cout << "Is empty: " << (hashTable.isEmpty() ? "Yes" : "No") << endl;

    cout << "\n6. Testing copy constructor:" << endl;
    HashTable<string, int> copiedTable = hashTable;
    cout << "Copied table:" << endl;
    copiedTable.display();

    return 0;
}