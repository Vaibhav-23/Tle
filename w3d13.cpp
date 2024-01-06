#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void solve(){
    int n;
    cin>>n;
    string s;
    vector<int> a(n);
    set<int> f;
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        a[i]=ch-'A';
        f.insert(a[i]);
    }
    int k=f.size();
    int i=0,j=0,res=n;
    map<int,int> freq;
    while(j<n){
        freq[a[j]]++;
        while(i<=j && freq.size()==k){
            if(freq[a[i]]<=1) break;
            freq[a[i]]--;
            i++;
        }
        if(freq.size()==k) res=min(res,j-i+1);
        j++;
    }
    cout<<res<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t){
        t--;
        solve();
    }
}