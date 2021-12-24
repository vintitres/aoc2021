#include<iostream>
#include<queue>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<map>
#include<list>
#include<climits>
#include<set>
#include<sstream>
#include<vector>
#include<stack>
#define MP make_pair
#define MT make_tuple
using namespace std;

int cc[] = {1, 10, 100, 1000};


void try_enter_room(const string &burrow, int i, int cost, priority_queue<pair<int,string>> &q) {
  if (burrow[i] == '.') return;
  int a = burrow[i] - 'A';
  int ii = 2 + 2 * a;
  //cout << a << en
  for (int k = i; k != ii; i < ii ? ++k : --k) {
    if (k == i) continue;
    if (burrow[k] != '.') return;
  }
//cout << a << "in" << endl;
  int j = 11 + a * 4;
  for (int k = j + 3; k >= j; --k) {
    //cout << a << "in" << k << endl;
    if (burrow[k] == '.') {
      //cout << "!" << endl;
      string b = burrow;
      b[i] = '.';
      b[k] = 'A' + a;
      q.push(make_pair(cost - cc[a] * (abs(ii - i) + k - j + 1), b));
      return;
    }
    if (burrow[k] - 'A' != a) return;
  }
}

void try_leave_room(const string &burrow, int i, int cost, priority_queue<pair<int,string>> &q) {
  int a = (i - 11) / 4;
  int j = 2 + a * 2;
  for (int k = j - 1; k >= 0; --k) {
    if (k != 0 && k != 10 && k % 2 == 0) continue;
    if (burrow[k] != '.') break;
    string b = burrow;
    b[i] = '.';
    b[k] = burrow[i];
    q.push(make_pair(cost - cc[burrow[i] - 'A'] * (j - k + (i - 11) % 4 + 1), b));
  }
  for (int k = j + 1; k < 11; ++k) {
    if (k != 0 && k != 10 && k % 2 == 0) continue;
    if (burrow[k] != '.') break;
    string b = burrow;
    b[i] = '.';
    b[k] = burrow[i];
    q.push(make_pair(cost - cc[burrow[i] - 'A'] * (k - j + (i - 11) % 4 + 1), b));
  }
}


int main() {
  set<string> seen;
  priority_queue<pair<int,string>> q;
  //q.push(make_pair(0, "...........BDDACCBDBBACDACA"));
  q.push(make_pair(0, "...........ADDCDCBCABADBACB"));
  //q.push(make_pair(0, "AA...C.B.BDBDDA.CBD...C..CA"));
  while (!q.empty()) {
    auto [cost, burrow] = q.top();
    q.pop();
    //if (true || burrow == "...........AAAABBBBCCCCDDDD" || burrow == "AA.....B.BDBDDA.CBD..CC..CA" || burrow == "AA.....B.BDBDDACCBD...C..CA") {
      //cout << burrow << endl;
    //}
    if (burrow == "...........AAAABBBBCCCCDDDD") { // || burrow == "AA.....B.BDBDDA.CBD..CC..CA") {
      cout << -cost << endl;
      return 0;
    }
    if (seen.find(burrow) != seen.end()) continue;
    seen.insert(burrow);
    for (int i = 0; i < 11; ++i) {
      try_enter_room(burrow, i, cost, q);
    }
    for (int a = 0; a < 4; ++a) {
      int j = 11 + 4 * a;
      bool noleave = true;
      for (int i = j; i < j + 4; ++i) {
        if (burrow[i] != '.' && burrow[i] - 'A' != a) {
          noleave = false;
          break;
        }
      }
      //cout << noleave << endl;
      if (noleave) continue;
      for (int i = j; i < j + 4; ++i) {
        if (burrow[i] != '.') {
          try_leave_room(burrow, i, cost, q);
          break;
        }
      }
    }
  }
}

