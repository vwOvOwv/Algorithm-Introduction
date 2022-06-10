#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, m;
int f[N];//背包体积为V时可获得的的最大价值
int v[N], w[N];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >=v[i]; j--) {//从后向前计算，从而使得f[j-v[i]]不被覆盖，从而达到降维的目的
			f[j] = max(f[j], f[j - v[i]] + w[i]);//这里的f[j-v[i]]一定是i-1时的
		}
	}
	int res = f[m];//若要求体积为m时的最大价值，则应在初始化时只将f[0]=0，其他的f[i]=-inf,res=max{f[i]}
	cout << res << endl;
	return 0;
}
