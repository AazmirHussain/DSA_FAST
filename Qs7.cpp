#include <iostream>
#include <string>
using namespace std;

class LibQueue{
    string queue[100];
    int front, rear, capacity;

public:
    LibQueue(){
        front = -1;
        rear = -1;
        capacity = 100;
    }

    bool isEmpty(){return front == -1;}
    bool isFull(){return (rear + 1) % capacity == front;}

    void enqueue(string patron){
        if (isFull()){
            cout << "Can't add " << patron << endl;
            return;
        }
        
        if (isEmpty()){
            front = 0;
            rear = 0;
        } 
        else{rear = (rear + 1) % capacity;}
        queue[rear] = patron;
    }

    string dequeue(){
        if (isEmpty()){return;}
        
        string patron = queue[front];
        
        if (front == rear){
            front = -1;
            rear = -1;
        } 
        else{front = (front + 1) % capacity;}
        return patron;
    }

    void display(){
        if (isEmpty()){
            cout << "Empty Queue\n";
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
        if (isEmpty()){return;}
        return queue[front];
    }

    int getSize() {
        if (isEmpty()){return 0;}
        if (rear >= front){return rear - front + 1;}
        return capacity - front + rear + 1;
    }
};

class LibSystem{
public:
    void runSimulation(){
        LibQueue libraryQueue;        

        string patrons[] = {"John", "Sarah", "Mike", "Emma", "David", "Lisa"};
        int totalPatrons = 6;

        cout << "\nLibrary Patrons: ";
        for (int i = 0; i < totalPatrons; i++){cout << patrons[i] << " ";}
        cout << endl << endl;

        cout << "Joining Queue\n" << endl;
        for (int i = 0; i < totalPatrons; i++){
            cout << patrons[i] << " arrives -> ";
            libraryQueue.enqueue(patrons[i]);
            cout << "Queue: ";
            libraryQueue.display();
            cout << " (Size: " << libraryQueue.getSize() << ")" << endl;
        }

        cout << "\nBook Transactions:\n";        
        int servedCount = 0;
        while (!libraryQueue.isEmpty()){
            servedCount++;
            cout << "\n--- Transaction " << servedCount << " ---" << endl;
            cout << "Currently serving: " << libraryQueue.getFront() << endl;
            
            string servedPatron = libraryQueue.dequeue();
            cout << "Patron " << servedPatron << " completed book transaction" << endl;
            
            cout << "Remaining queue: ";
            libraryQueue.display();
            cout << " (Size: " << libraryQueue.getSize() << ")" << endl;
            
            if (!libraryQueue.isEmpty()){cout << "Next: " << libraryQueue.getFront() << endl;}
        }

        cout << "\nTotal served: " << servedCount << endl;
        cout << "Queue status: ";
        libraryQueue.display();
    }
};

int main(){
    LibSystem library;
    library.runSimulation();

    cout << "Transactions completed!\n";
    return 0;
}