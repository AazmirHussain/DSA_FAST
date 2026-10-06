#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string url;
    Node* next;
    Node(string u): url(u), next(nullptr){}
};

class BrowserHistory{
    Node* head;
    string stack[100];
    int top;

public:
    BrowserHistory(){
        head = nullptr;
        top = -1;
    }

    void visitWebsite(const string& url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;

        if (top < 99){stack[++top] = url;}
        cout << "Visited: " << url << endl;
    }

    void goBack(int n){
        if (top < n - 1){
            cout << "Not possible to go back " << n << " times.\n";
            return;
        }
        cout << "\nGoing back " << n << " time(s)...\n";

        for (int i = 0; i < n; i++){
            if (top >= 0){
                string popped = stack[top--];
                cout << "\nPopped from stack: " << popped << endl;
            }

            if (head != nullptr){
                Node* temp = head;
                head = head->next;
                cout << "Removed from history: " << temp->url << endl;
                delete temp;
            }
        }

        if (head != nullptr){cout << "\nCurrent page is: " << head->url << endl;} 
        else{cout << "\nNo pages in history!" << endl;}
    }

    void displayHistory(){
        cout << "Browsing History:\n";
        Node* current = head;
        int count = 1;
        
        while (current != nullptr){
            cout << count << ". " << current->url << endl;
            current = current->next;
            count++;
        }
        
        if (count == 1){cout << "No browsing history\n";}
    }

    void displayStack(){
        cout << "\nStack contents (top to bottom):\n";
        for (int i = top; i >= 0; i--) {cout << stack[i] << endl;}
        if (top == -1) {cout << "Stack is empty\n";}
    }

    ~BrowserHistory(){
        Node* current = head;
        while (current != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main(){
    BrowserHistory browser;

    cout << "Visiting websites...\n";
    browser.visitWebsite("Google");
    browser.visitWebsite("Facebook");
    browser.visitWebsite("Twitter");
    browser.visitWebsite("LinkedIn");
    browser.visitWebsite("Instagram");
    
    browser.displayHistory();
    browser.displayStack();
    
    browser.goBack(2);
    browser.displayHistory();
    browser.displayStack();
    
    return 0;
}