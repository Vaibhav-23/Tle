#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void debug(vector<ll> &arr){
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";
}
void print(ll res){
    cout<<res<<"\n";
}
void prints(string &res){
    cout<<res<<"\n";
}
void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t){
        t--;
        solve();
    }
}