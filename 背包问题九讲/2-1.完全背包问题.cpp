#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, m;
int f[N];
int v[N], w[N];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >=v[i]; j--) {
				for (int k = 0; k * v[i] <= j; k++)//选k个
					f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
		}
	}
	int res = f[m];
	cout << res << endl;
	return 0;
}
