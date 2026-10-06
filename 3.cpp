#include <iostream>
using namespace std;

class Box{
    int* data;
public:
    Box() : data(nullptr){}
    Box(int value) {data = new int(value);}
    ~Box(){delete data;} // Destructor

    Box(const Box& other){
        if(other.data != nullptr){
            data = new int(*(other.data));
        } 
        else {data = nullptr;}
    }

    Box& operator=(const Box& other){
        if(this != &other){
            delete data;
            data = nullptr;
        }
        return *this;
    }

    void setValue(int value){
        if(data != nullptr){
            *data = value;
        }
        else{data = new int(value);}
    }

    int getValue(){
        if(data != nullptr){return *data;}
        return -1;
    }

    void display(const char* n){
        cout << n << ": ";
        if(data != nullptr){
            cout << "Value is: " << *data << " & Memory address is: " << data << endl;
        } 
        else{
            cout << "No data allocated";
        }
        cout << endl;
    }
};

void Shallow(){
   Box original(100);
    original.display("original");
    
    cout << "Without proper copy constructor Both objects point to the same memory address" << endl;
}

void Deep(){    
    Box box1(42);
    box1.display("box1");
    
    Box box2 = box1;
    box1.display("box1");
    box2.display("box2");
    
    box1.setValue(99);
    box1.display("box1");
    box2.display("box2");
    
    Box box3;
    box3 = box2;
    box2.display("box2");
    box3.display("box3");

    box3.setValue(77);
    box2.display("box2");
    box3.display("box3");
}

void SelfAssignment(){
    Box box(50);
    box.display("Before self-assignment");
    box = box;
    box.display("After self-assignment");
}

void NullHandling(){
    Box empty;
    empty.display("empty");
    
    Box copied = empty;
    copied.display("copied");
    
    Box anotherEmpty;
    anotherEmpty = empty;
    anotherEmpty.display("anotherEmpty");
}

int main(){
    Shallow();
    Deep();
    SelfAssignment();
    NullHandling();
    
    return 0;
}