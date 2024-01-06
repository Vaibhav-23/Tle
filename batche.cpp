#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
bool isPossible(long long mid,vector<long long> &arr,long long k){
    long long cnt=0;
    
}
void solve(){
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    long long low=1,high=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        high+=arr[i];
    }
    long long res=0;
    while(low<=high){
        long long mid=(low+high)/2;
        if(isPossible(mid,arr,k)){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
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