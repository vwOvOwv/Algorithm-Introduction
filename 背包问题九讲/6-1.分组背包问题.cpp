/*
第一层循环枚举物品"组"
第二层循环从大到小枚举体积
第三层循环找每一组里的最优解
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 110;
int n, m;
int f[N], v[N], w[N];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++)
			cin >> v[j] >> w[j];
		for (int j = m; j >= 0; j--) {
			for (int k = 0; k < s; k++) {
				if (j >= v[k])
					f[j] = max(f[j], f[j - v[k]] + w[k]);
			}
		}
	}
	cout << f[m];
	return 0;
}
