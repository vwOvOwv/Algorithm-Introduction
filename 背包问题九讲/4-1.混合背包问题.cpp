#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1010;
int n, m;
int f[N];
struct Thing
{
	int kind;
	int v, w;
};
vector<Thing> things;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int v, w, s;
		cin >> v >> w >> s;
		if (s < 0)
			things.push_back({ -1,v,w });//01背包
		else if (s == 0)
			things.push_back({ 0,v,w });//完全背包
		else {
			for (int k = 1; k <= s; k *= 2) {//多重背包二进制分解为01背包
				s -= k;
				things.push_back({ -1,v * k,w * k });
			}
			if (s > 0)
				things.push_back({ -1,v * s,w * s });
		}
	}
	for (auto thing : things) {
		if (thing.kind < 0) {//01背包
			for (int j = m; j >= thing.v; j--)
				f[j] = max(f[j], f[j - thing.v] + thing.w);
		}
		else {//完全背包
			for (int j = thing.v; j <= m; j++)
				f[j] = max(f[j], f[j - thing.v] + thing.w);
		}
	}
	cout << f[m] << endl;
	return 0;
}
