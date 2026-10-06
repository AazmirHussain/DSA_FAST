#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    Node* prev;
    int value;

    Node(int v): value(v), next(nullptr), prev(nullptr){}
};

class Linkedlist{
    Node* head;
    Node* tail;

public:
    Linkedlist(): head(nullptr), tail(nullptr){}

    void insertion(int v){
        Node* newnode = new Node(v);
        if(!head){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void reversal(){
        Node* curr = head;
        while(curr){
            Node* temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        Node* temp = head;
        head = tail;
        tail = temp;
    }

    void print(){
        Node* temp = head;
        while(temp){
            cout << temp->value;
            if(temp->next){
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Linkedlist ll;
    ll.insertion(10);
    ll.insertion(20);
    ll.insertion(25);
    ll.insertion(35);
    ll.insertion(40);
    ll.insertion(60);
    ll.print();
    cout << endl;

    ll.reversal();
    ll.print();
    
    return 0;
}