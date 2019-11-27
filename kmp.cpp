#include <bits/stdc++.h>
  
using namespace std;

void computeLPSArray(string pat, int M, int* lps); 
  
vector<int> KMPSearch(string pat, string txt) { 
    int M = pat.size(); 
    int N = txt.size(); 
    vector<int> index;
    int lps[M]; 
    computeLPSArray(pat, M, lps); 
    int i = 0;
    int j = 0;
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
        if (j == M) { 
            index.push_back(i-j); 
            cout<<i-j<<endl;
            j = lps[j - 1]; 
        }else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return index;
} 
  
void computeLPSArray(string pat, int M, int* lps) {  
    int len = 0; 
    lps[0] = 0;
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } else{ 
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else{ 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int main() { 
    string text,pattern;
    cin>>text>>pattern;
    int n = text.size();
    int m = pattern.size();
    vector<int> index = KMPSearch(pattern, text); 
    for(int i = 0;i<index.size();i++){
        cout<<index[i]<<" ";
    }
    return 0; 
} 

