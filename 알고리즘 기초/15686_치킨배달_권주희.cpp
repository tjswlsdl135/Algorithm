#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
vector<pair<int, int>> chicken, house;
long mins=9999999999;
void dfs(int x, vector<pair<int, int>> v){
    if(v.size()==m) {
        int nu=0;
        for(int i=0; i<house.size(); i++) {
            int distance = 101;
            for(int j=0; j<v.size(); j++) {
                if(abs(house[i].first-v[j].first)+abs(house[i].second-v[j].second)<distance)
                    distance=abs(house[i].first-v[j].first)+abs(house[i].second-v[j].second);
            }
            nu+=distance;
        }
        if(nu<mins)
            mins=nu;
    } else {
        for(int j=x+1; j<chicken.size(); j++) {
            v.push_back(chicken[j]);
            dfs(j, v);
            v.pop_back();
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int t;
            cin>>t;
            if(t==2) {
                chicken.push_back({i,j});
            }
            if(t==1) {
                house.push_back({i,j});
            }
        }
    }
    vector<pair<int, int>> ve;
    ve.push_back(chicken[0]);
    dfs(0,ve);
    ve.pop_back();
    dfs(0,ve);
    cout<<mins<<endl;
}

