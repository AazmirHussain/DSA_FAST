#include <iostream>
using namespace std;

class CircQueue{
    int queue[10], front, rear, capacity;

public:
    CircQueue(){
        front = -1;
        rear = -1;
        capacity = 10;
    }

    bool isEmpty(){return front == -1;}
    bool isFull(){return (rear + 1) % capacity == front;}

    void enqueue(int customerID){
        if (isFull()){
            cout << "Can't add " << customerID << endl;
            return;
        }
        
        if (isEmpty()){
            front = 0;
            rear = 0;
        } 
        else{rear = (rear + 1) % capacity;}
        queue[rear] = customerID;
    }

    int dequeue(){
        if (isEmpty()){return -1;}
        
        int customerID = queue[front];
        
        if (front == rear){
            front = -1;
            rear = -1;
        } 
        else{front = (front + 1) % capacity;}
        return customerID;
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

    int getFront(){
        if (isEmpty()){return -1;}
        return queue[front];
    }

    int getSize() {
        if (isEmpty()){return 0;}
        if (rear >= front){return rear - front + 1;}
        
        return capacity - front + rear + 1;
    }
};

class SupermarketSystem{
public:
    void runSimulation(){
        CircQueue checkoutLine;        

        int customerIDs[] = {13, 7, 4, 1, 6, 8, 10};
        int totalCustomers = 7;

        cout << "\nCustomer IDs: ";
        for (int i = 0; i < totalCustomers; i++){cout << customerIDs[i] << " ";}
        cout << endl << endl;

        cout << "CUSTOMERS JOINING QUEUE\n" << endl;
        for (int i = 0; i < totalCustomers; i++){
            cout << "Customer " << customerIDs[i] << " arrives -> ";
            checkoutLine.enqueue(customerIDs[i]);
            cout << "Queue: ";
            checkoutLine.display();
            cout << " (Size: " << checkoutLine.getSize() << ")" << endl;
        }

        cout << "\nSERVING CUSTOMERS:\n";        
        int servedCount = 0;
        while (!checkoutLine.isEmpty()){
            servedCount++;
            cout << "\n--- Transaction " << servedCount << " ---" << endl;
            cout << "Currently serving: Customer " << checkoutLine.getFront() << endl;
            
            int servedCustomer = checkoutLine.dequeue();
            cout << "Customer " << servedCustomer << " completed checkout" << endl;
            
            cout << "Remaining queue: ";
            checkoutLine.display();
            cout << " (Size: " << checkoutLine.getSize() << ")" << endl;
            
            if (!checkoutLine.isEmpty()){cout << "Next customer: " << checkoutLine.getFront() << endl;}
        }

        cout << "\n\nTotal customers served: " << servedCount << endl;
        cout << "Queue status: ";
        checkoutLine.display();
        cout << "\nSupermarket checkout is now closed!" << endl;
    }
};

int main(){
    SupermarketSystem market;
    market.runSimulation();
    
    return 0;
}