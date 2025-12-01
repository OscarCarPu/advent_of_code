#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> board;

int check(int i,int j){
  int ans=0;
  if(i==0 or j==0 or i==n-1 or j==m-1 or board[i][j]!='A'){
    return 0;
  }
  if(board[i+1][j+1]=='M' and board[i+1][j-1]=='M' and board[i-1][j-1]=='S' and board[i-1][j+1]=='S'){
    ans++;
  }
  if(board[i+1][j+1]=='S' and board[i+1][j-1]=='M' and board[i-1][j-1]=='M' and board[i-1][j+1]=='S'){
    ans++;
  }
  if(board[i+1][j+1]=='S' and board[i+1][j-1]=='S' and board[i-1][j-1]=='M' and board[i-1][j+1]=='M'){
    ans++;
  }
  if(board[i+1][j+1]=='M' and board[i+1][j-1]=='S' and board[i-1][j-1]=='S' and board[i-1][j+1]=='M'){
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