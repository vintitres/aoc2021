#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
#include<list>
#include<climits>
#include<set>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;

int main(){
  string s;
  vector<vector<int>> risk;
  while(cin >> s) {
    vector<int> v;
    for (char r : s) {
      v.push_back(r - '0');
    }
    risk.push_back(v);
  }
  int n = risk.size(), m = risk[0].size();
  priority_queue<pair<int,pair<int,int>>> q;
  q.push(make_pair(0, make_pair(0,1)));
  q.push(make_pair(0, make_pair(1,0)));
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    int i = p.second.first, j = p.second.second;
    if (i < 0 || i >= n || j < 0 || j >= m || risk[i][j] == -1) continue;
    int r = p.first - risk[i][j];
    risk[i][j] = -1;
    cout << r << " " << i << " " << j << endl;
    if (i == n - 1 && j == m - 1) {
      cout << -r << endl;
      break;
    }
    q.push(make_pair(r, make_pair(i - 1, j)));
    q.push(make_pair(r, make_pair(i + 1, j)));
    q.push(make_pair(r, make_pair(i, j - 1)));
    q.push(make_pair(r, make_pair(i, j + 1)));
  }
}

