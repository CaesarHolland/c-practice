/*
Question:
    Judge that weather you can pick up some integer to make their summary equal to k;
*/
#include<iostream>
using namespace std;
int a[1000];
int n , k;

/*
递归的关键：
    1. 边界
    2. 回溯
    处理好这两个条件即可构成完整递归
    这里用递归实现DFS，该二叉树中每个分支代表选a[i]或不选a[i]
    
    这里的两个条件为：
    1. 边界：i = n
    2. 回溯：当遇到sum == k时return true
*/
bool dfs(int i, int sum){
    if(i==n) return sum == k;

    if(dfs(i+1,sum)) return 1;
    
    if(dfs(i+1,sum+a[i])) return 1;

    return false;
}

/*
这里的二叉树是虚拟的，并没有真实存在一个这样的结构，所谓递归实现DFS遍历二叉树只是一
种计算形式

这里需要将二叉树抽象为单个节点的构成要素与判断条件：
    要素：层数i | 节点值sum
    判断条件：i == n?  sum == k?
*/

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    bool f = dfs(0,0);
    cout<<(f?"yes":"no")<<endl;
    return 0;
}
