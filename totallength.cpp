#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void solve(){
    long long n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll i=0,j=0,sum=0,curr=0;
    while(j<n){
        curr+=a[j];
        while(i<=j && curr>k){
            curr=curr-a[i];
            i++;
        }
        sum+=((j-i+1)*(j-i+2))/2;
        j++;
    }
    cout<<sum<<endl;
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