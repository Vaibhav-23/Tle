#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        arr[i]=abs(arr[i]);
    }
    sort(arr.begin(),arr.end());
    long long res=0;
    for(long long i=0;i<n-1;i++){
        auto it = upper_bound(arr.begin(),arr.end(),2*arr[i])-arr.begin();
        res+=(it-i-1);
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