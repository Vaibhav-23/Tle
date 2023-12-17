#include<bits/stdc++.h>
using namespace std;
bool isPossible(long long mid,vector<long long>&arr,long long k){
    long long cnt=0,n=arr.size();
    for(long long i=0;i<n;i++){
        cnt=cnt+(mid/arr[i]);
        if(cnt>=k) return true;
    }
    return (cnt>=k);
}
void solve(){
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    long long low=1,high=INT_MIN;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        high=max(arr[i],high);
        low=min(low,arr[i]);
    }
    high=high*k;
    long long res=0;
    while(low<=high){
        long long mid=(low+high)/2;
        if(isPossible(mid,arr,k)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t=1;
    //cin>>t;
    while(t){
        t--;
        solve();
    }
}