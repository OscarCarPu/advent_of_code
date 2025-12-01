#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> board;

int check(int i,int j){
int ans=0;
if(i>2 and board[i][j]=='X' and board[i-1][j]=='M' and board[i-2][j]=='A' and board[i-3][j]=='S'){
ans++;
}
if(j>2 and board[i][j]=='X' and board[i][j-1]=='M' and board[i][j-2]=='A' and board[i][j-3]=='S'){
ans++;
}
if(j<m-3 and board[i][j]=='X' and board[i][j+1]=='M' and board[i][j+2]=='A' and board[i][j+3]=='S'){
ans++;
}
if(i<n-3 and board[i][j]=='X' and board[i+1][j]=='M' and board[i+2][j]=='A' and board[i+3][j]=='S'){
ans++;
}
if(i<n-3 and j<m-3 and board[i][j]=='X' and board[i+1][j+1]=='M' and board[i+2][j+2]=='A' and board[i+3][j+3]=='S'){
ans++;
}
if(i<n-3 and j>2 and board[i][j]=='X' and board[i+1][j-1]=='M' and board[i+2][j-2]=='A' and board[i+3][j-3]=='S'){
ans++;
}
if(i>2 and j<m-3 and board[i][j]=='X' and board[i-1][j+1]=='M' and board[i-2][j+2]=='A' and board[i-3][j+3]=='S'){
ans++;
}
if(i>2 and j>2 and board[i][j]=='X' and board[i-1][j-1]=='M' and board[i-2][j-2]=='A' and board[i-3][j-3]=='S'){
ans++;
}
return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  int sol = 0;
  string l;
  while (getline(cin, l)) {
    board.push_back(l);
  }
  n = board.size();
  m = board[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sol+=check(i,j);
    }
  }
  cout<<sol;
}