#include <iostream>
using namespace std;

class Exam{
    char* studentname;  
    char* examdate;     
    double score;

    int stringLength(const char* str){
        int l = 0;
        while (str[l] != '\0'){
            l++;
        }
        return l;
    }

    void stringCopy(char* d, const char* src){
        int i = 0;
        while (src[i] != '\0'){
            d[i] = src[i];
            i++;
        }
        d[i] = '\0';
    }

public:
    Exam(const char* n, const char* d, double S){
        int nameLen = stringLength(n);
        studentname = new char[nameLen + 1];
        stringCopy(studentname, n);
        
        int dateLen = stringLength(d);
        examdate = new char[dateLen + 1];
        stringCopy(examdate, d);
        
        score = S;
        cout << endl;
    }

    ~Exam(){        
        delete[] studentname;
        delete[] examdate;

        studentname = nullptr;
        examdate = studentname;
    }

    void setStudentName(const char* n){
        delete[] studentname;
        int nameLen = stringLength(n);
        studentname = new char[nameLen + 1];
        stringCopy(studentname, n);
    }

    void setExamDate(const char* d){
        delete[] examdate;
        int dateLen = stringLength(d);
        examdate = new char[dateLen + 1];
        stringCopy(examdate, d);
    }

    void setScore(double examScore){score = examScore;}
    void displayExamDetails(){
        cout << "Student: ";
        if (studentname != nullptr){cout << studentname;} 
        else{cout << "N/A";}
        
        cout << "Date: ";
        if (examdate != nullptr){cout << examdate;} 
        else{cout << "Not Available!";}
        
        cout << "Score: " << score << "/100 & Percentage: " << score << "%" << endl;
    }
};

int main(){
    Exam exam1("John Doe", "2024-03-15", 85.5);
    exam1.displayExamDetails();
    cout << endl << endl;
 
    Exam exam2 = exam1;
    exam1.displayExamDetails();
    exam2.displayExamDetails();
    cout << endl << endl;

    exam2.setStudentName("Jane Smith");
    exam2.setScore(92.0);
    cout << endl;

    cout << "After modifying exam2:" << endl;
    exam1.displayExamDetails(); // Unexpected behaviour (Could crash)
    exam2.displayExamDetails();
    cout << endl;

    cout << "Both objects point to the same memory locations!" << endl;
    cout << "Destructors try to delete the same memory twice." << endl << endl;
    return 0;
}