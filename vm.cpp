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

class State {
  public:
    long long int w, x, y, z;
    State () {
      w = 0;
      x = 0;
      y = 0;
      z = 0;
    }
    void input(char d, int inp) {
      //cout << inp << endl;
      //cout << inp % 10 << endl;
      //cout << inp / 10 << endl;
      set(d, inp);
    }
    long long int get(char d) {
      if (d == 'x') {
        return x;
      } else if (d == 'y') {
        return y;
      } else if (d == 'z') {
        return z;
      } else if (d == 'w') {
        return w;
      }
    }
    void set(char d, long long int i) {
      if (d == 'x') {
        x = i;
      } else if (d == 'y') {
        y = i;
      } else if (d == 'z') {
        z = i;
      } else if (d == 'w') {
        w = i;
      }
    }
    bool operator<(const State& lhs) const
    {
          return std::tie(x,y,z,w) < std::tie(lhs.x, lhs.y, lhs.z, lhs.w);
    }
    void print() const {
      cout << x << " " << y << " " << z << " " << w;
    }
};

vector<string> split (string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;
  while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
    token = s.substr (pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back (token);
  }
  res.push_back (s.substr (pos_start));
  return res;
}

State exe(State st, const string &cmd, int inp) {
  //cout << cmd << endl;
  auto ss = split(cmd, " ");
  char d = ss[1][0];
  if (ss[0] == "inp") {
    st.input(d, inp);
    //cout << st.get(d) << endl;
    return st;
  }
  int w;
  if (ss[2][0] >= 'w' && ss[2][0] <= 'z') w = st.get(ss[2][0]);
  else w = stoi(ss[2]);
  if (ss[0]  == "add") {
    st.set(d, st.get(d) + w);
    return st;
  }
  if (ss[0] == "mul") {
    st.set(d, st.get(d) * w);
    return st;
  }
  if (ss[0] == "div") {
    st.set(d, st.get(d) / w);
    return st;
  }
  if (ss[0] == "mod") {
    st.set(d, st.get(d) % w);
    return st;
  }
  if (ss[0] == "eql") {
    st.set(d, st.get(d) == w ? 1 : 0);
    return st;
  }
  //cout << "bad"  << endl;
}

map<pair<State, int>, bool> visited;

long long int run(State st, const vector<string> &cmds, int cmdi, int ii) {
  if (cmdi == cmds.size()) {
    if (st.get('z') == 0) {
      //cout << " yay! ";
      //st.print();
      return 0;
    }
    else {
      //cout << " nay ";
      //st.print();
      return -1;
    }
  }
  string cmd = cmds[cmdi];
  if (st.get('z') > 26*26*26*26 || visited[MP(st, cmdi)]) {
    //cout << "!";
    //st.print();
    //cout << endl;
    return -1;
  }
  visited[MP(st, cmdi)] = true;
  if (cmd[0] == 'i') {
    for (int i = 9; i > 0; --i) {
      State nst = exe(st, cmd, i);
      //cout << endl;
      //for (int iii = 0; iii < ii; ++iii) {
        //cout << " ";
      //}
      //cout << i;
      long long int r = run(nst, cmds, cmdi + 1, ii + 1);
      if (r != -1) {
        return r * 10 + i;
      }
    }
    return -1;
  }
  State nst = exe(st, cmd, 0);
  return run(nst, cmds, cmdi + 1, ii);
}

int main() {
  vector<string> cmds;
  string s;
  while(getline(cin, s)) {
    cmds.push_back(s);
  }
  State st;
  long long int ri = run(st, cmds, 0, 0);
  while (ri) {
    cout << ri % 10;
    ri /= 10;
  }
  cout << endl;
}

