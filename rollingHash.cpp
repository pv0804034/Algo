#include <bits/stdc++.h>
#define ll long long
#define mod  1000000007

using namespace std;

ll modInverse(ll a, ll m) { 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 

    if (x < 0) 
       x += m0; 

    return x; 
}

void solve(){
    string text,pattern;
    ll p = 101;
    cin>>text>>pattern;
    int n = text.size();
    int m = pattern.size();
    vector<ll> powerList(m);
    powerList[0] = p;
    for(int i = 1;i<m;i++){
       powerList[i] = (powerList[i-1] * p) % mod;
    }

    ll modinv = modInverse(p,mod);
    ll patternHash = powerList[0] * ((pattern[0] - 'a') + 1);
    for(int i = 1;i<m;i++){
        patternHash += (powerList[i] * ((pattern[i] - 'a') + 1));
        patternHash %= mod;
    }

    ll textHash = powerList[0] * ((text[0] - 'a') + 1);
    for(int i = 1;i<m;i++){
        textHash += (powerList[i] * ((text[i] - 'a') + 1));
        textHash %= mod;
    }
    if(textHash == patternHash){
        cout<<"YES"<<endl;
        return;
    }
    for(int i = 1;i<=text.size()-pattern.size();i++){
        textHash -= (powerList[0] * ((text[i-1] - 'a') + 1));
        textHash *= modinv;
        textHash %= mod;
        textHash += (powerList[m-1] * ((text[i+m-1] - 'a') + 1));
        textHash %= mod;
        if(textHash == patternHash){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() { 
    int t;
    cin>>t;
    while(t--)solve();
    return 0; 
} 

