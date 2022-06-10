#include<iostream>
#include<vector>
using namespace std;
const int N = 1010;

int v[N], w[N], n, m, f[N];
vector<int> ans[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)  
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
        {
            if (f[j] < f[j - v[i]] + w[i])
            {
                ans[j] = ans[j - v[i]];     //复制方案
                ans[j].push_back(i);    //更新方案
                f[j] = f[j - v[i]] + w[i];
            }
            else if (f[j] == f[j - v[i]] + w[i])
            {
                vector<int> b = ans[j - v[i]]; 
                b.push_back(i);
                if (b < ans[j])//按字典序比较，更新方案
                    ans[j] = b; 
            }
        }
    for (int i = 0; i < ans[m].size(); i++)    //输出方案
        cout << ans[m][i] << ' ';
    return 0;
}
