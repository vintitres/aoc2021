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

typedef tuple<int,int,int> XYZ;

vector<vector<int>> perms1 = {{0,1,2},{1,2,0},{2,0,1}};
vector<vector<int>> perms2 = {{0,2,1},{1,0,2},{2,1,0}};


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

XYZ rot(const XYZ &p,  const vector<int> &r, const vector<int> &rs) {
  int x, y, z;
  tie(x, y, z) = p;
  vector<int> pp { x, y, z };
  return make_tuple(pp[rs[0]] * r[0], pp[rs[1]] * r[1], pp[rs[2]] * r[2]);
}

XYZ shift(const XYZ &p, const XYZ &s) {
  int x, y, z;
  tie(x, y, z) = p;
  int xs, ys, zs;
  tie(xs, ys, zs) = s;
  return make_tuple(x + xs, y + ys, z + zs);
}

void rotshift(vector<XYZ> &vp, const XYZ &s, const vector<int> &r, const vector<int> &rs) {
  for (int i = 0; i < vp.size(); ++i) {
    vp[i] = shift(rot(vp[i],r,rs), s);
    //int x,y,z;
    //tie(x,y,z) = vp[i];
    //cout << x << "," << y << "," << z << endl;
  }
}


tuple<bool, XYZ> match(const vector<XYZ> &s1, const vector<XYZ> &s2, const vector<int> &r, const vector<int> &rs) {
  int x1,y1,z1,x2,y2,z2;
  for (XYZ p1 : s1) {
    for (XYZ p2 : s2) {
      int points = 0;
      tie(x1,y1,z1) = p1;
      tie(x2,y2,z2) = rot(p2, r, rs);
      //cout << x2 << "," << y2 << "," << z2 << endl;
      XYZ sh = make_tuple(x1 - x2, y1 - y2, z1 -z2);
      vector <XYZ> ss2(s2);
      rotshift(ss2, sh, r, rs);
      sort(ss2.begin(), ss2.end());
      auto it = ss2.begin();
      int i = 0;
      for (XYZ pp1 : s1) {
        it = lower_bound(it, ss2.end(), pp1);
        if (*it == pp1) {
          if (++points == 12) {  // 12
            return make_tuple(true, sh);
          }
        }
        if (s1.size() - (++i) < 12 - points) break; 
      }
    }
    //cout << endl;
  }
  return make_tuple(false, make_tuple(0,0,0));
}


int main(){
  string s;
  vector<vector<XYZ>> scanners;
  vector<bool> done;
  int i = -1;
  while (getline(cin, s)) {
    if (s.size() == 0) continue;
    if (s.substr(0, 4) == "--- ") {
      scanners.resize(++i + 1);
      done.push_back(false);
    } else {
      auto ss = split(s, ",");
      scanners[i].push_back(make_tuple(stoi(ss[0]), stoi(ss[1]), stoi(ss[2])));
    }
  }
  queue<int> q;
  q.push(0);
  done[0] = true;
  sort(scanners[0].begin(), scanners[0].end());
  vector<XYZ> scannersxyz;
  scannersxyz.push_back(make_tuple(0,0,0));
  while (!q.empty()) {
    i = q.front();
    q.pop();
    for (int j = 0; j < scanners.size(); ++j) {
      if (done[j]) continue;
      vector<int> r(3), rs(3);
      bool found = false;
      for (r[0] = -1; r[0] <= 1 && !found; r[0] += 2) {
        for (r[1] = -1; r[1] <= 1 && !found; r[1] += 2) {
          for (r[2] = -1; r[2] <= 1 && !found; r[2] += 2) {
            bool permparity = r[0]*r[1]*r[2] == 1;
            for(auto rs : (permparity ? perms1 : perms2)) {
              XYZ sh;
              tie(found, sh) = match(scanners[i], scanners[j], r, rs);
              if (found) {
                rotshift(scanners[j], sh, r, rs);
                scannersxyz.push_back(sh);
                sort(scanners[j].begin(), scanners[j].end());
                q.push(j);
                done[j] = true;
                break;
              }
            }
          }
        }
      }
    }
  }
  int maxd = 0;
  for (auto it1 = scannersxyz.begin(); it1 != scannersxyz.end(); ++it1) {
    for (auto it2 = scannersxyz.begin(); it2 != scannersxyz.end(); ++it2) {
      int x1,x2,y1,y2,z1,z2;
      tie(x1,y1,z1) = *it1;
      tie(x2,y2,z2) = *it2;
      int d = abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
      maxd = d > maxd ? d : maxd;
    }
  }
  cout << maxd << endl;
}

