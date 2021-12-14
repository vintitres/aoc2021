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

void add(int c1, int c2, set<pair<int,int>> &points1, set<pair<int,int>> &points2) {
  points1.insert(make_pair(c1,c2));
  points2.insert(make_pair(c2,c1));
}

void fold(int c, set<pair<int,int>> &points1, set<pair<int,int>> &points2) {
  for(auto it = points1.lower_bound(make_pair(c,0)); it!=points1.end();) {
      int c1 = it->first, c2 = it->second;
    it = points1.erase(it);
    points2.erase(make_pair(c2,c1));
    add(c-(c1-c), c2, points1, points2);
  }
}

int main(){
  set<pair<int,int>> pointsx, pointsy;
  string s;
  while(cin >> s) {
    if (s == "fold") {
      cin >> s; //"along"
      cin >> s;
      auto p = split(s,"=");
      if(p[0] == "x"){
        fold(stoi(p[1]), pointsx, pointsy);
      }else{
        fold(stoi(p[1]), pointsy, pointsx);
      }
    } else {
      auto p = split(s,",");
      add(stoi(p[0]),stoi(p[1]),pointsx,pointsy);
    }
  }
  int maxx = pointsx.rbegin()->first, maxy = pointsy.rbegin()->first;
  auto it = pointsy.begin();
  for (int y = 0; y <= maxy; ++y) {
    for (int x = 0; x <= maxx; ++x) {
      if (it != pointsy.end() && x == (*it).second && y == (*it).first) {
        cout << "#";
        ++it;
      } else cout << ".";
    }
    cout << endl;
  }
}


