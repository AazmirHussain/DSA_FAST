#include <iostream>
#include <string>
using namespace std;

class BookSearcher{
    void computeLPS(const string& pattern, int lps[]){
        int m = pattern.length();
        int len = 0;
        lps[0] = 0;
        
        int i = 1;
        while (i < m){
            if (pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            } 
            else {
                if (len != 0){len = lps[len - 1];} 
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    void KMPSearch(const string& text, const string& pattern, int indices[], int& indexCount){
        indexCount = 0;
        int n = text.length();
        int m = pattern.length();
        
        if (m == 0 || m > n){return;}
        
        int lps[m];
        computeLPS(pattern, lps);
        
        cout << "LPS Array for pattern \"" << pattern << "\": [";
        for (int i = 0; i < m; i++){
            cout << lps[i];
            if (i < m - 1){cout << ", ";}
        }
        cout << "]" << endl << endl;
        
        int i = 0, j = 0;
        
        while (i < n){
            cout << "Comparing text[" << i << "]='" << text[i] << "' with pattern[" << j << "]='" << pattern[j] << "'";
            
            if (pattern[j] == text[i]){
                cout << " - MATCH" << endl;
                i++;
                j++;
            }
            
            if (j == m){
                indices[indexCount] = i - j;
                indexCount++;
                cout << ">>> PATTERN FOUND at position " << (i - j) << " <<<" << endl;
                j = lps[j - 1];
            } 
            else if (i < n && pattern[j] != text[i]){
                cout << " - MISMATCH" << endl;
                if (j != 0){
                    cout << "  Backtracking j from " << j << " to " << lps[j - 1] << " using LPS" << endl;
                    j = lps[j - 1];
                } 
                else{i++;}
            }
        }
    }
};

int main(){
    BookSearcher searcher;
    string text = "ababababc";
    string pattern = "abab";
    
    int indices[100];
    int indexCount;
    
    cout << "Book Content: \"" << text << "\"" << endl;
    cout << "Searching for: \"" << pattern << "\"" << endl << endl;
    
    searcher.KMPSearch(text, pattern, indices, indexCount);
    
    cout << "\n=== SEARCH RESULTS === \n" << "Pattern found at positions: [";
    for (int i = 0; i < indexCount; i++){
        cout << indices[i];
        if (i < indexCount - 1){cout << ", ";}
    }
    cout << "]" << endl;
    
    return 0;
}