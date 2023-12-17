#include<bits/stdc++.h>
using namespace std;
bool isPossible(long long mid,long long n){
    bool flag=false;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(mid%i==0){
            flag=true;
        }
        long long temp = ceil(double(mid/i));
        cnt+=min(n,temp);
    }
    if(!flag) return false;
    long long size=(n*n)/2+1;
    return (cnt>=size)?1:0;
}
void solve(){
    long long n;
    cin>>n;
    long long size = (n*n);
    long long low=1,high=size;
    long long res=0;
    while(low<=high){
        long long mid = (low+high)/2;
        if(isPossible(mid,n)){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t=1;
    while(t){
        t--;
        solve();
    }
}