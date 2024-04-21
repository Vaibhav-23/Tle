#include <bits/stdc++.h> 
using namespace std; 
#define int long long 
#define pii pair<int,int> 
#define pb push_back 
#define F first 
#define S second 
#define pyes cout<<"Yes\n" 
#define pno cout<<"No\n" 
typedef long double ld; 
const int mod = 998244353; 
int fc3(int n){ 
    return (n*(n-1)*(n-2))/6; 
} 
int fc2(int n){ 
    return (n*(n-1))/2; 
} 
void solve(){ 
    int n; 
    cin>>n; 
    vector<int>a(n+1,0); 
    for(int i=0;i<n;i++){ 
        int x; 
        cin>>x; 
        a[x]++; 
    } 
    int ans=0; 
    int prev=0; 
    for(int i=0;i<=n;i++){ 
        if(a[i]>=3){ 
            ans+=fc3(a[i]); 
        } 
        if(a[i]>=2){ 
            ans+=fc2(a[i])*prev; 
        } 
 
        prev+=a[i]; 
    } 
    cout<<ans<<endl; 
} 
 
signed main() { 
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cin.tie(0); 
    cout.tie(0); 
    int t; 
    cin>>t; 
    while(t--) { 
        solve(); 
    } 
 
}