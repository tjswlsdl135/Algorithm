#include <iostream>
#include <string>
using namespace std;
string map[51];
int n,m;
bool visited[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dp[51][51]={};
int dfs(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m)
        return 0;
    if(map[x][y]=='H')
        return 0;
    if(visited[x][y]) {
        cout<<-1<<endl;
        exit(0);
    }
    if(dp[x][y])
        return dp[x][y];
    visited[x][y]=true;
    for(int i=0; i<4; i++) {
        int curi = x + dx[i]*(map[x][y]-'0');
        int curj = y + dy[i]*(map[x][y]-'0');
        dp[x][y] = max(dfs(curi, curj)+1, dp[x][y]);
    }
    visited[x][y]=false;
    return dp[x][y];
}
int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>map[i];
    }
    cout<<dfs(0, 0)<<endl;
}
