#include <iostream>
#include <string>
using namespace std;

class MessageQueue{
    string queue[100];
    int front, rear, capacity;

public:
    MessageQueue(){
        front = -1;
        rear = -1;
        capacity = 100;
    }

    bool isEmpty(){return front == -1;}
    bool isFull(){return (rear + 1) % capacity == front;}

    void enqueue(string message){
        if (isFull()){
            cout << "Can't add " << message << endl;
            return;
        }
        
        if (isEmpty()){
            front = 0;
            rear = 0;
        } 
        else{rear = (rear + 1) % capacity;}
        queue[rear] = message;
    }

    string dequeue(){
        if (isEmpty()){return "";}
        string message = queue[front];
        
        if (front == rear){
            front = -1;
            rear = -1;
        } 
        else{front = (front + 1) % capacity;}
        return message;
    }

    void display(){
        if (isEmpty()){
            cout << "[Empty Queue]" << endl;
            return;
        }
        
        cout << "[";
        int i = front;

        while (true){
            cout << queue[i];
            if (i == rear) break;
            i = (i + 1) % capacity;
            cout << " <- ";
        }
        cout << "]";
    }

    string getFront(){
        if (isEmpty()){return "";}
        return queue[front];
    }

    int getSize() {
        if (isEmpty()){return 0;}
        if (rear >= front){return rear - front + 1;}
        
        return capacity - front + rear + 1;
    }
};

class Message{
public:
    void runSimulation(){
        MessageQueue messageQueue;        

        string messages[] = {"Hello", "Meeting", "Urgent", "Report", "Update"};
        int totalMessages = 5;

        cout << "\nMessages: ";
        for (int i = 0; i < totalMessages; i++){cout << messages[i] << " ";}
        cout << endl;
        cout << "MESSAGES ARRIVING\n" << endl;

        for (int i = 0; i < totalMessages; i++){
            cout << "Message \"" << messages[i] << "\" arrives -> ";
            messageQueue.enqueue(messages[i]);
            cout << "Queue: ";
            messageQueue.display();
            cout << " (Size: " << messageQueue.getSize() << ")" << endl;
        }

        cout << "\nPROCESSING MESSAGES:\n";        
        int processedCount = 0;
        while (!messageQueue.isEmpty()){
            processedCount++;
            cout << "\n--- Processing " << processedCount << " ---" << endl;
            cout << "Currently processing: " << messageQueue.getFront() << endl;
            
            string processedMessage = messageQueue.dequeue();
            cout << "Message \"" << processedMessage << "\" completed" << endl;
            
            cout << "Remaining queue: ";
            messageQueue.display();
            cout << " (Size: " << messageQueue.getSize() << ")" << endl;
            
            if (!messageQueue.isEmpty()){cout << "Next message: " << messageQueue.getFront() << endl;}
        }

        cout << "\nTotal messages processed: " << processedCount << endl;
        cout << "Queue status: ";
        messageQueue.display();
        cout << "\nAll messages processed!" << endl;
    }
};

int main(){
    Message messaging;
    messaging.runSimulation();
    return 0;
}