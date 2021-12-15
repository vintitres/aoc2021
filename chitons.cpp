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

int rr(int x) {
  if (x < 10) return x;
  return (x - 10) % 9 + 1;
}

int riskk(vector<vector<int>> &risk, int i, int j, int n, int m) {
  return rr(risk[i % n][j % m] + i / n + j / m);
}

int main(){
  string s;
  vector<vector<int>> risk;
  vector<vector<bool>> visited;
  while(cin >> s) {
    vector<int> v;
    for (char r : s) {
      v.push_back(r - '0');
    }
    risk.push_back(v);
  }
  int n = risk.size(), m = risk[0].size();
  for (int i = 0; i < 5 * n; ++i) {
    vector<bool> v(m * 5, false);
    visited.push_back(v);
  }
  priority_queue<pair<int,pair<int,int>>> q;
  q.push(make_pair(0, make_pair(0,1)));
  q.push(make_pair(0, make_pair(1,0)));
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    int i = p.second.first, j = p.second.second;
    if (i < 0 || i >= n*5 || j < 0 || j >= m*5 || visited[i][j]) continue;
    int r = p.first - riskk(risk, i, j, n, m);
    visited[i][j] = true;
    //cout << r << " " << i << " " << j << endl;
    if (i == n*5 - 1 && j == m*5 - 1) {
      cout << -r << endl;
      break;
    }
    q.push(make_pair(r, make_pair(i - 1, j)));
    q.push(make_pair(r, make_pair(i + 1, j)));
    q.push(make_pair(r, make_pair(i, j - 1)));
    q.push(make_pair(r, make_pair(i, j + 1)));
  }
}

