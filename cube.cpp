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

vector<string> split (string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  vector<string> res;
  while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
    res.push_back(s.substr (pos_start, pos_end - pos_start));
    pos_start = pos_end + delim_len;
  }
  res.push_back (s.substr (pos_start));
  return res;
}

typedef pair<int,int> BE;

int recount(map<int,int> &coords) {
  int i = 0;
  for (auto &&c : coords) {
    c.second = i++;
  }
  return i;
}

int main(){
  string onoffs, s;
  map<int,int> xxx, yyy, zzz;
  vector<tuple<BE,BE,BE,bool>> cubesdef; 
  while (cin >> onoffs) {
    getline(cin, s);
    auto ss = split(s, ",");
    int b[3], e[3];
    for (int i = 0; i < 3; ++i) {
      auto sss = split(split(ss[i], "=")[1],"..");
      b[i] = stoi(sss[0]);
      e[i] = stoi(sss[1]);
      if (b[i] > e[i]) swap(b[i], e[i]);
    }
    int bx = b[0], ex = e[0] + 1, by = b[1], ey = e[1] + 1, bz = b[2], ez = e[2] + 1;
    //if (bx < -50 || ex > 50 || by < -50 || ey > 50 || bz < -50 || ez > 50) continue;
    cubesdef.push_back(MT(MP(bx,ex),MP(by,ey),MP(bz,ez),onoffs == "on"));
    xxx[bx] = 1;
    xxx[ex] = 1;
    yyy[by] = 1;
    yyy[ey] = 1;
    zzz[bz] = 1;
    zzz[ez] = 1;
  }
  int xs = recount(xxx);
  int ys = recount(yyy);
  int zs = recount(zzz);
  vector<vector<vector<bool>>> reactor;
  reactor.resize(xs);
  for (int i = 0; i < xs; ++i) {
    reactor[i].resize(ys);
    for (int j = 0; j < ys; ++j) {
      reactor[i][j].resize(zs, false);
    }
  }
  for (auto &&[xr, yr, zr, onoff] : cubesdef) {
    for (int i = xxx[xr.first]; i < xxx[xr.second]; ++i) {
      for (int j = yyy[yr.first]; j < yyy[yr.second]; ++j) {
        for (int k = zzz[zr.first]; k < zzz[zr.second]; ++k) {
          reactor[i][j][k] = onoff;
        }
      }
    }
  }
  long long cnt = 0;
  for (auto itx = xxx.begin(); true;) {
    auto &&[x, i] = *itx;
    ++itx;
    if (itx == xxx.end()) break;
    auto &&[xx, ii] = *itx;
    for (auto ity = yyy.begin(); true;) {
      auto &&[y, j] = *ity;
      ++ity;
      if (ity == yyy.end()) break;
      auto &&[yy, jj] = *ity;
      for (auto itz = zzz.begin(); true;) {
        auto &&[z, k] = *itz;
        ++itz;
        if (itz == zzz.end()) break;
        auto &&[zz, kk] = *itz;
        if (reactor[i][j][k]) {
          cnt += (long long)(xx - x) * (long long)(yy - y) * (long long)(zz - z);
        }
      }
    }
  }
  cout << cnt << endl;
}

