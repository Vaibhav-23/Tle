#include<bits/stdc++.h>
using namespace std;
bool isPossible(double t,vector<pair<double,double>> &arr){
    pair<double,double> temp={-1e18,1e18};
    for(auto &it: arr){
        double x=it.first;
        double v=it.second;

        pair<double,double> temp={max(x-v*t,temp.first),min(x+v*t,temp.second)};
        if(temp.first>temp.second) return false;
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<double,double>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    double error=1e-7;
    double low=error,high=1e9;
    double res=INT_MAX;
    for(int i=0;i<60;i++){
        double mid=(low+high)/2;
        if(isPossible(mid,arr)){
            res=min(mid,res);
            high=mid-error;
        }
        else{
            low=mid+error;
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