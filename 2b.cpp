#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int v): value(v), next(nullptr){}
};

class LinkedList{
public:
    Node* head;
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

    void display(){
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
        }
    }
};

void merge(Node*& head1, Node*&head2){
    if(!head1 || !head2){return;}
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 && temp2){
        Node* next1 = temp1->next;
        Node* next2 = temp2->next;

        temp1->next = temp2;
        temp2->next = next1;

        temp1 = next1;
        temp2 = next2;
    }
    head2 = temp2;
}

int main(){
    LinkedList list1, list2;

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.display(); cout << endl;

    list2.insert(4);
    list2.insert(5);
    list2.insert(6);
    list2.insert(7);
    list2.insert(8);
    list2.display(); cout << endl;

    merge(list1.head, list2.head);
    
    cout << "\nAftet merging: \n";
    list1.display();
    cout << endl;
    list2.display();

    return 0;
}