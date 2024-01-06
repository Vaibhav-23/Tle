#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void solve(){
    long long n,k,d;
    cin>>n>>k>>d;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll i=0,j=0,res=k;
    map<ll,ll> freq;
    while(j<n){
        freq[a[j]]++;
        while(i<=j && (j-i+1)>d){
            freq[a[i]]--;
            if(freq[a[i]]==0) freq.erase(a[i]);
            i++;
        }
        if(j-i+1>=d){
            ll size=freq.size();
            res=min(size,res);
        }
        j++;
    }
    cout<<res<<"\n";
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