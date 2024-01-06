#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void solve(){
    ll n,r;
    cin>>n>>r;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll i=0,j=0,cnt=0;
    while(j<n){
        
        while(i<=j && (a[j]-a[i])>r){
            i++;
        }
        if(a[j]-a[i]>r) cnt+=(i+1);
        else cnt+=i;
        j++;
    }
    cout<<cnt<<"\n";
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