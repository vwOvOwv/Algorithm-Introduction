/*
f[i][j] ��ʾֻ��ǰi����Ʒ���������j������£��ܼ�ֵ���ֵ
result=max{f[n][0-V]}

f[i][j]:
1.��ѡ��i����Ʒ��f[i][j]=f[i-1][j];
2.ѡ��i����Ʒ��f[i][j]=f[i-1][j-v[i]]+w[i];
f[i][j]=max(1,2);
f[0][0]=0;

*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, m;
int f[N][N];
int v[N], w[N];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j >= v[i])
				f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
			else
				f[i][j] = f[i - 1][j];
		}
	}
	int res = 0;
	for (int i = 0; i <= m; i++)
		res = max(res, f[n][i]);
	cout << res << endl;
	return 0;
}
