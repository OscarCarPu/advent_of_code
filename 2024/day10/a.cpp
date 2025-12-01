#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int n,m;

int solve(int x,int y){
  set<pair<int,int>> next;
  set<pair<int,int>> now;
  now.insert(make_pair(x,y));
  for(char c='8';c>='0';c--){
    cout<<c<<" "<<now.size()<<endl;
    next = set<pair<int,int>>();
    for(auto p : now){
      int nx = p.first;
      int ny = p.second;
      if(nx-1>=0){
        if(grid[nx-1][ny]==c){
          next.insert(make_pair(nx-1,ny));
        }
      }
      if(nx+1<n and grid[nx+1][ny]==c)next.insert(make_pair(nx+1,ny));
      if(ny-1>=0 and grid[nx][ny-1]==c)next.insert(make_pair(nx,ny-1));
      if(ny+1<m and grid[nx][ny+1]==c)next.insert(make_pair(nx,ny+1));
    }
    now = next;
  }
  return now.size();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  freopen("input.txt","r",stdin);
  string s;
  while(cin>>s){
    grid.push_back(s);
  }
  n =s.length();
  int sol = 0;
  m = grid.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]=='9'){
        sol+=solve(i,j);
      }
    }
  }
  cout<<sol;
}