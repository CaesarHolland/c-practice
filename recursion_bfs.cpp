#include <iostream>
#include <queue>
using namespace std;

typedef pair <int,int> P;

const int INF = 0x3f3f3f3f;
int n, m;
int sx, sy, nx, ny;

char maze[110][110];
int d[110][110];
int dx[4] = {1,0,-1,0} , dy[4] = {0,1,0,-1};

int bfs()
{
    memset(d, INF, sizeof d);
    queue<P> q;
    
    q.push(P(sx, sy));
    d[sx][sy] = 0;

    while(!q.empty())
    {
        P t = q.front();
        q.pop();

        int x = t.first, y = t.second;

        if(x == nx && y == ny) break;

        for(int i=0; i<4; i++)
        {
            int xx = x + dx[i] , yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && maze[xx][yy] != '#' && d[xx][yy] == INF)
            {
                q.push(P(xx,yy));
                d[xx][yy] = d[x][y] + 1;
            }
        }
    }

    return d[nx][ny];
}

int main()
{
    cin>>n>>m>>sx>>sy>>nx>>ny;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>maze[i][j];

    cout<<bfs()<<endl;

    return 0;
}
