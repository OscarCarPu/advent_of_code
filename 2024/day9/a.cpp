#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  string s;
  cin>>s;
  int n = s.length();
  int sol = 0;
  int r = n-1-(n%2==0);
  int p=0;
  for(int i=0;i<n;i++){
    if(i%2==0){
      while(s[i]>'0'){
        cout<<(i/2)<<" "<<sol<<endl;
        s[i]--;
        sol+=(p++)*(i/2);
      }
    }
    else{
      if(r<=i)continue;
      while(s[i]>'0'){
        s[i]--;
        sol+=(p++)*(r/2);
        cout<<r/2<<" "<<sol<<endl;
        s[r]--;
        if(s[r]=='0'){
          r-=2;
          if(r<=i)break;
        }
      }
    }
  }
  cout<<sol;
}


















