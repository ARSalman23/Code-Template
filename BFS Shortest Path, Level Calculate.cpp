/// Abdur Rahman Salman ///

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mem(array, b) memset(array, b, sizeof(array))

const int N = 2e5 + 128;
vector<int> adj[N];
bool vis[N];
int level[N];

void BFS(int starting_node)
{
    queue<int> q;
    q.push(starting_node);
    vis[starting_node] = true;

    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();
        //cout << current_node << " ";
        for(auto child : adj[current_node])
        {
            if(!vis[child])
            {
                level[child] = level[current_node] + 1;
                q.push(child);
                vis[child] = true;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        mem(vis, 0);
        mem(adj, 0);
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        BFS(1);
        cout << level[n] << endl;

        //cout << endl;
        //for(int i = 1; i <= n; i++)
        //{
        //    cout << i << ": " << level[i] << endl;
        //}
    }

    return 0;
}
/*
/// Abdur Rahman Salman ///

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mem(array, b) memset(array, b, sizeof(array))

const int N = 2e5 + 128;
vector<int> adj[N];
bool vis[N];
int level[N];

void BFS(int starting_node)
{
    queue<int> q;
    q.push(starting_node);
    vis[starting_node] = true;

    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();
        for(auto child : adj[current_node])
        {
            if(!vis[child])
            {
                level[child] = level[current_node] + 1;
                vis[child] = true;
                q.push(child);
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(1);
    int q;
    cin >> q;
    int ans = INT_MAX, prev = INT_MAX;
    while(q--)
    {
        int x;
        cin >> x;
        //cout << level[x] << ' ';
        if(level[x] <= prev)
        {
            ans = min(x, ans);
            prev = level[x];
        }
        //cout << endl << ans << ' ';
    }
    cout << ans << endl;

    return 0;
}*/


