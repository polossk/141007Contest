// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   guide.cpp                                                *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MaxN = 8192;
vector<int> data[MaxN];
int dp[MaxN][2], f[MaxN];
int n, t, tt;

void dfs(int root)
{
	for (int i = 0, sz = data[root].size(); i < sz; i++)
	{
		int c = data[root][i];
		dfs(c);
		dp[root][0] += dp[c][1];
		dp[root][1] += min(dp[c][0], dp[c][1]);
	}
}

int getRoot()
{
	int a = 0;
	while (f[a] != -1) a = f[a];
	return a;
}

void solve()
{
	n = nextInt();
	for (int i = 0; i < n; i++)
	{
		data[i].clear();
		f[i] = -1;
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		int fa = nextInt();
		int m = nextInt();
		for (int j = 0; j < m; j++)
		{
			int ch = nextInt();
			data[fa].push_back(ch);
			f[ch] = fa;
		}
	}
	int root = getRoot(); dfs(root);
	printf("Case #%d: %d\n", ++tt, min(dp[root][0], dp[root][1]));
}

int main()
{
    freopen("guide.in", "r", stdin);
    freopen("guide.out", "w", stdout);
    t = nextInt();
    while (t--) solve();
    return 0;
}
