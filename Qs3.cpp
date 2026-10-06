#include <iostream>
#include <string>
using namespace std;

class Stack{
    char arr[100];
    int top;

public:
    Stack(){top = -1;}

    void push(char x){
        if (top < 99){arr[++top] = x;}
    }
    char pop(){
        if (top >= 0) {return arr[top--];}
        return '\0';
    }
    char peek(){
        if (top >= 0){return arr[top];}
        return '\0';
    }
    bool isEmpty(){return top == -1;}
};

class InfixToPostfix{
    Stack operatorStack;

    int getPrecedence(char op){
        if (op == '^'){return 3;}
        if (op == '*' || op == '/'){return 2;}
        if (op == '+' || op == '-'){return 1;}
        return 0;
    }

    bool isOperator(char c){return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');}
    bool isOperand(char c){return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));}

public:
    string convertToPostfix(string infix){
        string postfix = "";
        
        for (int i = 0; i < infix.length(); i++){
            char current = infix[i];
            
            if (isOperand(current)){postfix += current;}
            else if (current == '(') {operatorStack.push(current);}

            else if (current == ')'){
                while (!operatorStack.isEmpty() && operatorStack.peek() != '('){
                    postfix += operatorStack.pop();}
                operatorStack.pop();
            }
            else if (isOperator(current)){
                while (!operatorStack.isEmpty() && getPrecedence(operatorStack.peek()) >= getPrecedence(current)){
                    postfix += operatorStack.pop();}
                operatorStack.push(current);
            }
        }
        
        while (!operatorStack.isEmpty()){postfix += operatorStack.pop();}
        
        return postfix;
    }
};

int main(){
    InfixToPostfix converter;
    string infixExpression = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << infixExpression << endl;
    
    string postfixExpression = converter.convertToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;
    
    return 0;
}