/*
Question:
    puddle number judging , acturally is to judging the number of continuous regions.

    In this question, we still use DFS to find out.
*/
#include<iostream>
using namespace std;
char water[110][110];
int n,m;
int sum = 0;

bool JW(char e){
    return e=='W' ? 1 : 0;
}

/*
Method:
    对遍历找到的一片连续区域进行DFS，将 “有水” 的地方 “变干” ；
    
    DFS函数在此处的用处就是：
        给定一片连续区域的开头位置，DFS这片区域，将其全部 “变干”；
        
    Complexity : O(n * m)

*/

void dfs(int x, int y){

    water[x][y] = '.';

    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            int xx = x+i;
            int yy = y+j;

            if(xx>=0 && yy>=0 && xx<n && yy<m){
                if(JW(water[xx][yy]))
                    dfs(xx,yy);
            }
        }
    }
    return;
}

int main()
{
    cout<<"n & m: ";
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>water[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(JW(water[i][j])){
                dfs(i,j);
                sum ++  ;
            }
        }
    }

    return 0;
}
