#include <bits/stdc++.h>
using namespace std;

vector<string> Map;
vector<char> guard = {'>','v','<','^'};
int n,m;

bool check_loop(int x, int y, int g, int ox, int oy) {
  vector<vector<vector<bool>>> v(n, vector<vector<bool>>(n, vector<bool>(4, false)));
  vector<pair<int,int>> direction = {{1,0},{0,1},{-1,0},{0,-1}};
  
  int cx = x, cy = y, cg = g;
  while (true) {
    if (v[cy][cx][cg]) return true; 
    v[cy][cx][cg] = true;
    
    bool moved = false;
    for(int i=0;i<4;i++){
      int dir = (cg+i)%4;
      int nx = cx+direction[dir].first;
      int ny = cy+direction[dir].second;
      if(nx<0 or nx>=n or ny<0 or ny>=n) break;
      if((nx == ox && ny == oy) || Map[ny][nx]=='#') continue;
      cx = nx;
      cy = ny;
      cg = dir;
      moved = true;
      break;
    }
    if (!moved) return false; 
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  freopen("input.txt","r",stdin);
  int x,y;
  string s;
  do {
    cin>>s;
    for(char c : guard){
      if (s.find(c) != string::npos){
        x = s.find(c);
        y = Map.size();
        break;
      }
    }
    if (s == "") break;
    Map.push_back(s);
  } while (getline(cin, s));
  n = Map.size();
  
  int g;
  for (int i=0;i<4;i++){
    if(Map[y][x] == guard[i]){
      g=i;
    }
  }

  int sol = 0;
  int total_to_check = n*n;
  int checked = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout<<(checked++)<<"/"<<total_to_check<<endl;
      if(Map[i][j] == '.') {
        sol+=check_loop(x, y, g, j, i);
      }
    }
  }

  cout<<sol;
}