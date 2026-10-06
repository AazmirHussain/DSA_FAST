#include <iostream>
#include <string>
using namespace std;

class TextSearcher{
public:
    void searchPattern(const string& text, const string& pattern, int indices[], int& index, int& cmpcount){
        index = 0;
        cmpcount = 0;
        int n = text.length();
        int m = pattern.length();
        
        if (m == 0 || m > n){return;}
        
        for (int i = 0; i <= n - m; i++){
            bool match = true;
            for (int j = 0; j < m; j++){
                cmpcount++;
                if (text[i + j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            
            if (match){
                indices[index] = i;
                index++;
            }
        }
    }
};

int main(){
    TextSearcher search;
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    
    int indices[100];
    int index, cmp;
    search.searchPattern(text, pattern, indices, index, cmp);
    
    cout << "Input: Text = \"" << text << "\"" << endl;
    cout << "Pattern = \"" << pattern << "\"" << endl << "Output: [";
    for (int i = 0; i < index; i++){
        cout << indices[i];
        
        if (i < index - 1) {cout << ", ";}
    }
    cout << "]" << endl;
    cout << "Total comparisons: " << cmp << endl;
    
    return 0;
}