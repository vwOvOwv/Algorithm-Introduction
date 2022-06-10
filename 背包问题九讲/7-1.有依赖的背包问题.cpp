//树状动态规划，类似于分组背包问题
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 110;
int n, m;
int f[N][N], v[N], w[N];
//f[i][j]表示选了第i个物品且体积不大于j时的最大价值
int h[N], e[N], ne[N], idx;
/*
* h[N]:邻接表的头，下标是当前节点的编号，值是当前节点第一条边（即最后被存入的边）的编号
* e[N]:边的集合，下标是当前边的编号，数值是当前边的终点
* ne[N]:指向下一条边，下标是当前边的编号，数值当前节点是下一条边的编号，若为-1则表示没有下一条边
* idx:保存每条边上一条边的编号
*/
void add(int a, int b) {//物品b,父节点a
	e[idx] = b;
	ne[idx] = h[a];//父节点a的第一条边
	h[a] = idx++;
}
void dfs(int u) {
	for (int i = h[u]; i != -1; i = ne[i]) {//循环物品组
		int son = e[i];
		dfs(son);//先向下算出f
		for (int j = m - v[u]; j >= 0; j--) {//注意u是一定要选的，所以要留出位置
			for (int k = 0; k <= j; k++) {//循环决策
				f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
			}
		}
	}
	for (int i = m; i >= v[u]; i--)//把u放进去
		f[u][i] = f[u][i - v[u]] + w[u];
	for (int i = 0; i < v[u]; i++)//u都放不下
		f[u][i] = 0;
}
int main()
{
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	int root;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> v[i] >> w[i] >> p;
		if (p == -1)
			root = i;
		else
			add(p, i);
	}
	dfs(root);
	cout << f[root][m];
	return 0;
}
