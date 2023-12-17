#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,k;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        if(i>0) arr[i]+=arr[i-1];
    }
    cin>>k;
    long long res=0;
    for(long long i=0;i<k;i++){
        int temp;
        cin>>temp;
        auto it = lower_bound(arr.begin(),arr.end(),temp)-arr.begin();
        cout<<it+1<<endl;
    }
    return;
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