#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

const int N = 1010, mod = 1000000007;
int n, m;
int f[N], g[N];
//f[i]表示体积恰好为i时的最大价值
//g[i]表示体积恰好为i时的方案数
int main()
{
	cin >> n >> m;
	g[0] = 1;
	for (int i = 1; i <= m; i++)//初始化方式不同
		f[i] = INT_MIN;
	for (int i = 0; i < n; i++) {
		int v, w;
		cin >> v >> w;
		for (int j = m; j >= v; j--) {
			int t= max(f[j], f[j - v] + w);
			int s = 0;
			if (t == f[j])
				s += g[j];
			if (t == f[j - v] + w)
				s += g[j - v];
			s %= mod;//注意控制数据大小
			f[j] = t;
			g[j] = s;
		}
	}
	int max_w = 0;
	for (int i = 0; i <= m; i++)//遍历寻找最优解
		max_w = max(max_w, f[i]);
	int res = 0;
	for (int i = 0; i <= m; i++) {//统计所有达到最优解的方案数
		if (max_w == f[i]) {
			res += g[i];
			res %= mod;//注意控制数据大小
		}
	}
	cout << res;
	return 0;
}
