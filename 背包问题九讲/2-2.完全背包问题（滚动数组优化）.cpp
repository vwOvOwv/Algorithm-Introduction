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
		for (int j = v[i]; j <=m; j++) {//和01背包反过来
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
		/*？？？
		证明：
		用数学归纳法：
		1.假设考虑前i-1个物品后，所有的f[j]都是背包体积为j时的最大价值
		2.证明：考虑完第j个物品后，f[j]仍然是最大价值
		假设对于某个j而言，最优解中选了k个第i件物品
		f[j]=f[j-k*v[i]]+k*w[i];
		f[j-k*v[i]]=max(f[j-k*v[i]],f[j-k*v[i]-v[i]]+w[i])
		f[j-k*v[i]-v[i]]的最优解一定不选第i件物品
		所以max(f[j-k*v[i]],f[j-k*v[i]-v[i]]+w[i])=f[j-k*v[i]]不会更新
		*/
	}
	int res = f[m];
	cout << res << endl;
	return 0;
}
