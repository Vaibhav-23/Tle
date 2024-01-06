#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

bool isPossible(long long mid,vector<long long>&arr){
    int n=arr.size();
    for(long long i=0;i<mid;i++){
        if(arr[i]<arr[i+mid] && arr[i]<arr[i+mid+1]) continue;
        else return false;
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long long low = 0,high=(n&1)?n/2:(n/2)-1,res=0;
    vector<int> b(arr.size());
    while(low<=high){
        long long mid=(low+high)/2;
        if(isPossible(mid,arr)){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<res<<endl;
    vector<long long> final(n);
    for(long long k=0;k<n;k++){
        
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