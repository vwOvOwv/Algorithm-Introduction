//转化为01背包问题
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2010;
int n, m;
int f[N];
int v[N], w[N], s[N];
struct Good
{
	int v, w;
};
int main()
{
	vector<Good>goods;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int v, w, s;
		cin >> v >> w >> s;
		for (int k = 1; k <= s; k *= 2) {//二进制分解整数
			s -= k;
			goods.push_back({ v * k, w * k });
		}
		if (s > 0)
			goods.push_back({ v * s,w * s });
		/*
		定理：
		以上的分解得到的整数组可以组合出0-s的任意一个数且每个数至多用一次
		*/
	}
	for (auto good : goods) {
		for (int j = m; j >= good.v; j--)
			f[j] = max(f[j], f[j - good.v] + good.w);
	}
	cout << f[m] << endl;
	return 0;
}
