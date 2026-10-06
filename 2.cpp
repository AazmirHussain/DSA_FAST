#include <iostream>
#include <string>
using namespace std;

class PlagDetector{
    const int PRIME = 101;

    int calculate(const string& str, int length){
        int hash = 0;
        for (int i = 0; i < length; i++){
            hash = (hash + str[i]) % PRIME;
        }
        return hash;
    }
    
    int recalculateHash(const string& text, int oldIndex, int oldHash, int patternLength){
        int newHash = oldHash - text[oldIndex];
        newHash = (newHash + text[oldIndex + patternLength]) % PRIME;

        if (newHash < 0){newHash += PRIME;}
        return newHash;
    }
    
public:
    void rabinKarpSearch(const string& text, const string& pattern, int indices[], int& count){
        count = 0;
        int n = text.length();
        int m = pattern.length();
        
        if (m == 0 || m > n){return;}
        
        int patternHash = calculate(pattern, m);
        int Hash = calculate(text, m);
        
        cout << "Pattern hash: " << patternHash << endl;
        for (int i = 0; i <= n - m; i++){
            cout << "Position " << i << ": Hash = " << Hash;
            
            if (patternHash ==Hash){
                bool trueMatch = true;
                for (int j = 0; j < m; j++){
                    if (text[i + j] != pattern[j]){
                        trueMatch = false;
                        cout << " - HASH COLLISION! Discarding false positive";
                        break;
                    }
                }
                
                if (trueMatch){
                    indices[count] = i;
                    count++;
                    cout << " - TRUE MATCH!";
                }
            } 
            else{cout << " - Hash mismatch";}
            cout << endl;
            
            if (i < n - m){Hash = recalculateHash(text, i, Hash, m);}
        }
    }
};

int main(){
    PlagDetector detector;
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";
    
    int indices[100];
    int count;    
    cout << "Searching for pattern: \"" << pattern << "\" in text:\n" << "\"" << text << "\"\n\n";

    detector.rabinKarpSearch(text, pattern, indices, count);
    
    cout << "\nFinal Results:" << endl;
    cout << "Pattern found at positions: [";
    for (int i = 0; i < count; i++){
        cout << indices[i];
        if (i < count - 1){cout << ", ";}
    }
    cout << "]" << endl;
    
    return 0;
}