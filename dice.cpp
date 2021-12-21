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
using namespace std;

class Roll {
  public:
  int val;
  long long int cnt;
  Roll(int _val, long long int _cnt) {
    val = _val;
    cnt = _cnt;
  }
};

class Score {
  public:
  int val;
  int pos;
  Score(int _pos) {
    val = 0;
    pos = _pos;
  }
  Score(int _val, int _pos) {
    val = _val;
    pos = _pos;
  }
  Score roll(Roll r) {
    int npos = pos + r.val;
    if (npos > 10) npos -= 10;
    return Score(val + npos, npos);
  }
};

vector<Roll> rolls {Roll(3, 1LL), Roll(4, 3LL), Roll(5, 6LL), Roll(6, 7LL), Roll(7, 6LL), Roll(8, 3LL), Roll(9, 1LL)};

tuple<long long int, long long int> play(Score s1, Score s2, long long int cnt = 1LL) {
  long long int wins1 = 0LL, wins2 = 0LL;
  for (auto roll : rolls) {
    auto rollcnt = cnt * roll.cnt;
    Score s1r = s1.roll(roll);
    if (s1r.val >= 21) wins1 += rollcnt;
    else {
      auto [w2, w1] = play(s2, s1r, rollcnt);
      wins1 += w1;
      wins2 += w2;
    }
  }
  return make_tuple(wins1, wins2);
}

int main() {
  // initial score positions should be read from input
  auto [w1, w2] = play(Score(8), Score(4));
  cout << (w1 > w2 ? w1 : w2) << endl;
}
