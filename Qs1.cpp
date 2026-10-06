#include <iostream>
#include <string>
using namespace std;

const int Task = 100;
class List{
    string tasks[Task];
    int top;

public:
    List(){top = -1;}

    void addTask(const string& task){
        if(top < Task - 1){
            top++;
            tasks[top] = task;
            cout << "Added: " << task << " to your to-do list\n";
        } 
        else{cout << "List is full!\n";}
    }

    bool isEmpty(){return top == -1;}

    void completeTopTask(){
        if(!isEmpty()){
            string completedTask = tasks[top];
            top--;
            cout << "Completed: " << completedTask << endl;
        } 
        else {cout << "Your list is empty.\n";}
    }

    void showTopTask(){
        if(!isEmpty()){cout << "Next task: " << tasks[top] << endl;} 
        else{cout << "! No tasks remaining!\n";}
    }

    void showTaskCount(){cout << "Tasks Pending are: " << (top + 1) << endl;}
};

int main() {
    List myList;
    cout << "-----------------\n";
    
    myList.addTask("Prepare quarterly report");
    myList.addTask("Email client updates");
    myList.addTask("Team meeting preparation");
    cout << endl;
    
    myList.showTaskCount();
    myList.showTopTask();
    cout << endl;

    for(int i = 0; i < 3; i++){
        myList.completeTopTask();
        myList.showTopTask();
        cout << endl;
    }
    myList.completeTopTask();

    if(myList.isEmpty()){cout << "All tasks completed.\n";}
    
    return 0;
}