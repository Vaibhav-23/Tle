#include<bits/stdc++.h>
using namespace std;
bool isPossible(double mid,vector<int>&arr,int k){
    int cnt=0;
    for(auto &it : arr){
        cnt+=floor(it/mid);
        if(cnt>=k) return true;
    }
    return false;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double low=0,high=1e7,error=1e-7;
    double res=INT_MIN;
    while(high-low>error){
        double mid=(low+high)/2;
        if(isPossible(mid,arr,k)){
            res=max(mid,res);
            low=mid+error;
        }
        else{
            high=mid-error;
        }
    }
    cout<<setprecision(6)<<fixed<<res<<endl;
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