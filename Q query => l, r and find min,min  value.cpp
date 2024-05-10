/// Abdur Rahman Salman ///

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"

/// template for q query => l, r and find min,min  value
vector<int> a;
vector<int> seg_tree;

void build(int node, int b, int e)
{
    if(b == e)
    {
        seg_tree[node] = a[b];
        return;
    }

    int Left, Right, Mid;
    Left = node * 2;
    Right = (node * 2) + 1;
    Mid = b + ((e - b) / 2);
    build(Left, b, Mid);
    build(Right, Mid + 1, e);
    seg_tree[node] = min(seg_tree[Left], seg_tree[Right]); //max(seg_tree[Left], seg_tree[Right]);
}

int query(int node, int b, int e, int I, int J)
{
    if(e < I || J < b) return INT_MAX; // INT_MIN
    if(I <= b && e <= J) return seg_tree[node];

    int Left, Right, Mid, q1, q2;
    Left = node * 2;
    Right = (node * 2) + 1;
    Mid = b + ((e - b) / 2);
    q1 = query(Left, b, Mid, I, J);
    q2 = query(Right, Mid + 1, e, I, J);
    return min(q1, q2); //max(q1, q2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        int n, q;
        cin >> n >> q;
        a.assign(n + 2, 0);
        seg_tree.assign((4 * n) + 2, 0);

        for(int i = 1; i <= n; i++) cin >> a[i];

        build(1, 1, n);
        cout << "Case " << tc << ":" << endl;

        while(q--)
        {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
/// Abdur Rahman Salman ///
