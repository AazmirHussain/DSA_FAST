#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val): val(val), next(nullptr){}
};

class ll{
    Node* head;

    bool search(Node* node, int key){
        if(node == nullptr){return false;}
        bool found = search(node->next, key);

        if(node->val == key){return true;}
        return found;
    }

public:
    ll(){head = nullptr;}

    void insert(int value){
        Node* newnode = new Node(value);
        
        if(!head){head = newnode; return;}

        Node* temp = head;
        while(temp->next){temp = temp->next;}
        temp->next = newnode;
    }

    bool searching(int key){return search(head, key);}

    void display(){
        cout << "Linked List: ";
        Node* temp = head;
        while (temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    int key;
    ll list;
    list.insert(10);
    list.insert(15);
    list.insert(25);
    list.insert(30);

    list.display();
    cout << "Enter the value you wish to find: ";
    cin >> key;

    if (list.searching(key)){
        cout << key << " Found!" << endl;
    } 
    else {
        cout << key << " Not found!" << endl;
    }

    return 0;
}