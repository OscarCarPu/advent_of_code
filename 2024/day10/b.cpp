#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int n,m;

int solve(int x,int y){
  map<pair<int,int>,int> next;
  map<pair<int,int>,int> now;
  now[make_pair(x,y)] = 1;
  for(char c='8';c>='0';c--){
    cout<<c<<" "<<now.size()<<endl;
    next = map<pair<int,int>,int>();
    for(auto p : now){
      int nx = p.first.first;
      int ny = p.first.second;
      if(nx-1>=0 && grid[nx-1][ny]==c)next[make_pair(nx-1,ny)]+=p.second;
      if(nx+1<n && grid[nx+1][ny]==c)next[make_pair(nx+1,ny)]+=p.second;
      if(ny-1>=0 && grid[nx][ny-1]==c)next[make_pair(nx,ny-1)]+=p.second;
      if(ny+1<m && grid[nx][ny+1]==c)next[make_pair(nx,ny+1)]+=p.second;
    }
    now = next;
  }
  int total = 0;
  for(auto p : now){
    total+=p.second;
  }
  return total;
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
        cout<<sol<<endl;
      }
    }
  }
  cout<<sol;
}