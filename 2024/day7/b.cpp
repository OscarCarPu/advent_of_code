#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int target, const vector<int>& nums, int pos = 0, int current = 0) {
  if (pos == nums.size()) {
    return current == target;
  }
  if (pos == 0) {
    return check(target, nums, pos + 1, nums[0]);
  }
  if (check(target, nums, pos + 1, current + nums[pos])) {
    return true;
  }
  if (check(target, nums, pos + 1, current * nums[pos])) {
    return true;
  }
  string b = to_string(nums[pos]);
  string a = to_string(current);
  string c = a + b;
  int num = stoll(c);
  return check(target, nums, pos + 1, num);

}
  

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  freopen("input.txt","r",stdin);
  string s;
  int total = 0;
  while(getline(cin, s)) {
    if(s.empty()) break;
    size_t colon_pos = s.find(':');
    int oper = stoll(s.substr(0, colon_pos));
    istringstream iss(s.substr(colon_pos + 1));
    vector<int> v;
    int x;
    while(iss >> x){
      v.push_back(x);
    }
    if(check(oper,v)){
      cout<<oper<<endl;
      total += oper;
    }
  }
  cout<<total;
}