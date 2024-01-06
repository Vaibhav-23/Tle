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
void query(int x){
    cout<<"?"<<x<<endl;
}
void solve(){
    
    
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