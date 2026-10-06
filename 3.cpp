#include <iostream>
#include <string>
using namespace std;

class DNA{
    const int ALPHABET_SIZE = 4;    
    int charToIndex(char c){
        switch(c){
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return -1;
        }
    }
    
    void preprocessBadChar(const string& pattern, int badChar[][100]){
        int m = pattern.length();
        for (int i = 0; i < ALPHABET_SIZE; i++){
            for (int j = 0; j < m; j++){badChar[i][j] = -1;}
        }
        
        for (int i = 0; i < m; i++){
            int idx = charToIndex(pattern[i]);
            badChar[idx][i] = i;
        }
        
        for (int i = 0; i < ALPHABET_SIZE; i++){
            int last = -1;
            for (int j = 0; j < m; j++){
                if (badChar[i][j] != -1){last = badChar[i][j];} 
                else{badChar[i][j] = last;}
            }
        }
    }
    
    void preprocessGoodSuffix(const string& pattern, int goodSuffix[], int borderPos[]){
        int m = pattern.length();
        
        for (int i = 0; i < m; i++){borderPos[i] = 0;}

        int i = m, j = m + 1;
        borderPos[i] = j;        
        while (i > 0){
            while (j <= m && pattern[i - 1] != pattern[j - 1]){
                if (goodSuffix[j] == 0) {goodSuffix[j] = j - i;}
                j = borderPos[j];
            }
            i--; j--;
            borderPos[i] = j;
        }
        
        j = borderPos[0];
        for (i = 0; i <= m; i++){
            if (goodSuffix[i] == 0){goodSuffix[i] = j;}
            if (i == j){j = borderPos[j];}
        }
        
        for (int i = 0; i < m; i++){
            goodSuffix[i] = m;
            for (int j = i; j < m; j++){
                if (pattern[j] != pattern[j - i]){
                    bool match = true;
                    for (int k = 0; k < m - j - 1; k++){
                        if (pattern[k] != pattern[j + 1 + k]){
                            match = false;
                            break;
                        }
                    }
                    if (match){
                        goodSuffix[i] = m - j - 1;
                        break;
                    }
                }
            }
        }
    }

public:
    void boyerMoore(const string& dna, const string& pattern, int indices[], int& count){
        count = 0;
        int n = dna.length();
        int m = pattern.length();
        if (m == 0 || m > n){return;}
        
        int badChar[ALPHABET_SIZE][m];
        preprocessBadChar(pattern, badChar);
        
        int goodSuffix[m];
        int borderPos[m];
        preprocessGoodSuffix(pattern, goodSuffix, borderPos);
        
        int s = 0;
        while (s <= n - m){
            int j = m - 1;
            
            cout << "Checking position " << s << ": ";
            while (j >= 0 && pattern[j] == dna[s + j]) {j--;}
            
            if (j < 0){
                indices[count] = s;
                count++;
                cout << "PATTERN FOUND" << endl;
                
                if (s + m < n){s += goodSuffix[0];} 
                else{s += 1;}
            } 
            else {
                char badCharMismatch = dna[s + j];
                cout << "Mismatch at pattern[" << j << "] = '" << pattern[j] << endl;
                cout << "' vs dna[" << s+j << "] = '" << badCharMismatch << "'" << endl;
                
                int badCharShift = j - badChar[charToIndex(badCharMismatch)][j];
                int goodSuffixShift = goodSuffix[j];                
                cout << "  Bad character shift: " << badCharShift << endl;
                cout << "  Good suffix shift: " << goodSuffixShift << endl;
                
                s += max(1, max(badCharShift, goodSuffixShift));
            }
        }
    }
};

int main(){
    DNA analyzer;
    string dna = "ACGTACGTGACG";
    string pattern = "ACG";
    
    int indices[100];
    int indexCount;
    
    cout << "DNA Sequence: " << dna << endl;
    cout << "Searching for motif: " << pattern << endl << endl;
    
    analyzer.boyerMoore(dna, pattern, indices, indexCount);
    
    cout << "\n=== FINAL RESULTS ===" << endl;
    cout << "Motif found at positions: [";
    for (int i = 0; i < indexCount; i++) {
        cout << indices[i];
        
        if (i < indexCount - 1) {cout << ", ";}
    }
    cout << "]" << endl;
    
    return 0;
}