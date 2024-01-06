#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void solve(){
    string n;
    cin>>n;
    string s[2];
    for(auto &it: n){
        s[int(it-'0')&1]+=it;
    }
    string res="";
    while(!s[0].empty() || !s[1].empty()){
        if(s[0].empty()){
            res+=s[1].front();
            s[1].erase(s[1].begin());
            continue;
        }
        if(s[1].empty()){
            res+=s[0].front();
            s[0].erase(s[0].begin());
            continue;
        }
        if(s[0].front()>s[1].front()){
            res+=s[1].front();
            s[1].erase(s[1].begin());
        }
        else{
            res+=s[0].front();
            s[0].erase(s[0].begin());
        }
    }
    prints(res);
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