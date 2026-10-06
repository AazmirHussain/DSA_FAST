#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string data;
    Node* next;
    Node(string d): data(d), next(nullptr){}
};

class LinkedStack{
    Node* top;

public:
    LinkedStack(){top = nullptr;}

    void push(string value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    string pop(){
        if (isEmpty()){return;}
        Node* temp = top;
        string value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    string peek(){
        if (isEmpty()){return;}
        return top->data;
    }
    bool isEmpty(){return top == nullptr;}

    void display(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        
        Node* current = top;
        cout << "Stack (top to bottom): ";
        while (current != nullptr){
            cout << current->data << "  ";
            current = current->next;
        }
        cout << endl;
    }
};

class ExpEval{
    LinkedStack mainStack;

public:
    void evaluateAndDisplay(){
        cout << "\nPushing original exp:" << endl;
        mainStack.push("x");
        mainStack.push("=");
        mainStack.push("12");
        mainStack.push("+");
        mainStack.push("13");
        mainStack.push("-");
        mainStack.push("5");
        mainStack.push("(");
        mainStack.push("0.5");
        mainStack.push("+");
        mainStack.push("0.5");
        mainStack.push(")");
        mainStack.push("+");
        mainStack.push("1");
        mainStack.display();

        cout << "\nCalculating the result" << endl;
        double calculation = 12 + 13 - 5 * (0.5 + 0.5) + 1;
        mainStack.push(to_string(calculation));
        mainStack.display();

        cout << "\nFinal verification:" << endl;
        cout << "Top element (result): " << mainStack.peek() << endl;
        
        cout << "\nAll elements in stack:" << endl;
        LinkedStack temp;
        int count = 0;
        
        while (!mainStack.isEmpty()){
            string element = mainStack.pop();
            cout << ++count << ": " << element << endl;
            temp.push(element);
        }
        
        while (!temp.isEmpty()){mainStack.push(temp.pop());}
    }
};

int main(){
    ExpEval evaluator;
    
    cout << "Expression: x = 12 + 13 - 5(0.5 + 0.5) + 1" << endl;
    cout << "Mathematical calculation:" << endl;
    cout << "12 + 13 = 25" << endl;
    cout << "0.5 + 0.5 = 1" << endl;
    cout << "5 * 1 = 5" << endl;
    cout << "25 - 5 = 20" << endl;
    cout << "20 + 1 = 21" << endl;
    cout << "Final Result: 21" << endl << endl;
    
    evaluator.evaluateAndDisplay();
    return 0;
}