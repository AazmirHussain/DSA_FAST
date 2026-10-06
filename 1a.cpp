#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int v): value(v), next(nullptr){}
};

class LinkedList{
    Node* head;

public:
    LinkedList(): head(nullptr){}

    void insert(int v){
        Node* newnode = new Node(v);
        if(head == nullptr){
            head = newnode;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void deletefront(){
        if(head == nullptr){
            cout << "List is empty, so nothing can be deleted" << endl;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted from front.\n";
        delete temp;
    }

    void deletelast(){
        if(head == nullptr){
            cout << "List is empty, so nothing can be deleted\n";
        }
        if(head->next == nullptr){
            cout << "Deleted node with value: " << head->value << endl; 
        }

        Node* temp = head;
        while(temp->next->next != nullptr){temp = temp->next;}
        cout << "Deleted the last node." << endl;

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteanypos(int pos){
        if(head == nullptr){
            cout << "List is empty, so nothing can be deleted\n";
        }
        if(pos < 1){
            cout << "Invalid psoition entered" << endl;
            return;
        }

        if(pos == 1){
            deletefront();
            return;
        }

        Node* temp = head;
        int count = 1;
        while(temp != nullptr && count < pos - 1){
            temp = temp->next;
            count++;
        }

        Node * del = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted node at position " << pos << " having the value of: " << del->value << endl;
        delete del;
    }

    void display(){
        int a = 0;
        if(head == nullptr){
            cout << "Empty List!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while(temp != nullptr){
            cout << temp->value;
            if(temp->next != nullptr){
                cout << " -> ";
            }
            temp = temp->next;
            a++;
        }
        cout << "\nLength of the list is: " << a << endl << endl;
    }
};

int main(){
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(25);
    list.insert(35);
    list.insert(50);
    list.insert(60);
    list.insert(80);
    list.insert(82);
    list.display();

    list.deletefront();
    list.display();
    list.deletelast();
    list.display();
    list.deleteanypos(2);
    list.display();

    return 0;
}