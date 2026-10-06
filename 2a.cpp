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

    void bubblesort(){
        if(!head || !head->next){
            cout << "Bubble sorting not possible.\n";
            return;
        }
        bool swap;
        do{
            swap = false;
            Node* temp = head;
            while(temp->next){
                if(temp->value > temp->next->value){
                    int sum = temp->value;
                    temp->value = temp->next->value;
                    temp->next->value = sum;
                    swap = true;
                }
                temp = temp->next;
            }
        }while (swap);
    }

};

int main(){
    Linkedlist ll;
    ll.insertion(1);
    ll.insertion(14);
    ll.insertion(5);
    ll.insertion(30);
    ll.insertion(40);
    ll.insertion(2);
    ll.print();
    cout << endl;

    ll.bubblesort();
    ll.print();

    return 0;
}