#include<bits/stdc++.h>
using namespace std;
bool isPossible(long long mid,vector<long long>&c,vector<long long>&t){
    long long i=0,j=0;
    while(i<c.size() && j<t.size()){
        if(abs(c[i]-t[j])<=mid){
            i++;
        }
        else j++;
    }
    return (i==c.size());
}
void solve(){
    long long n,m;
    cin>>n>>m;
    vector<long long> c(n),t(m);
    for(long long i=0;i<n;i++){
        cin>>c[i];
    }
    for(long long i=0;i<m;i++){
        cin>>t[i];
    }
    long long low=0,high=max(abs(c[n-1]-t[0]),abs(t[m-1]-c[0]));
    long long res=0;
    while(low<=high){
        long long mid = (low+high)/2;
        if(isPossible(mid,c,t)){
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