#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<int> lis[200001];
int vis[200001];
int dfsVis[200001];
 
bool checkCycle(int node)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : lis[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it))
                return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}
 
signed main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i <= n; i++)
        {
            lis[i].clear();
            vis[i] = 0;
            dfsVis[i] = 0;
        }
        for (int i = 0; i < k; i++)
        {
            vector<int> v(n);
            for (int j = 0; j < n; j++)
            {
                cin >> v[j];
            }
            for (int j = 2; j < n; j++)
            {
                lis[v[j - 1]].push_back(v[j]);
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                if (checkCycle(i))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}