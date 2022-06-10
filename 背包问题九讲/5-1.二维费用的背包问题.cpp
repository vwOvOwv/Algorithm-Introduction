/*
f[i][j]体积是i重量是j下的最大价值
仍是01背包
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 110;
int f[N][N];
int n, v, m;
int main()
{
	cin >> n >> v >> m;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = v; j >= a; j--) {
			for (int k = m; k >= b; k--) {
				f[j][k] = max(f[j][k], f[j - a][k - b] + c);
			}
		}
	}
	cout << f[v][m];
	return 0;
}
