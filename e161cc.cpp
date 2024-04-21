#include <bits/stdc++.h>
#define int long long
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

vector<int> function_to_sort(vector<int> &v)
{
    sort(v.begin(), v.end());
    return v;
}

void sol(int a, int b){
    int sum = a+b;
    vector<int>k(sum);

    for(auto &x: k)cin>>x;
}

int_fast32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        n -= 1;
        int no_of_subsequence = 1;
        int idx = 0;
        while (n >= no_of_subsequence)
        {
            n -= no_of_subsequence;
            no_of_subsequence = no_of_subsequence * 2;
            ans.push_back(idx);
            idx += 1;
        }
        idx = 10000;
        while (n != 0)
        {
            int pankaj = 0;
            if (idx >= 60)
            {
                pankaj = INT64_MAX;
            }
            else
            {
                pankaj = powl(2, idx);
            }
            if (n >= pankaj)
            {
                ans.push_back(idx);
                n -= (pankaj);
            }
            idx -= 1;
        }
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}