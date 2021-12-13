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

void add(int c1, int c2, set<pair<int,int>> &points1, set<pair<int,int>> &points2) {
  cout << "add " << c1 << " " << c2 << endl;
  points1.insert(make_pair(c1,c2));
  points2.insert(make_pair(c2,c1));
}

void fold(int c, set<pair<int,int>> &points1, set<pair<int,int>> &points2) {
  cout << "fold " << c << endl;
  set<pair<int,int>> newpoints;
  for(auto it = points1.lower_bound(make_pair(c,0)); it!=points1.end();) {
    auto p = *it;
    int c1 = p.first, c2 = p.second;
    cout << "infold " << c1 << " " << c2 << endl;
    it = points1.erase(it);
    points2.erase(make_pair(c2,c1));
    int newc1 = c - (c1 - c);
    newpoints.insert(make_pair(newc1, c2));
  }
  for (auto p : newpoints) {
    add(p.first, p.second, points1, points2);
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
      cout << p[0] << endl;
      if(p[0] == "x"){
        fold(stoi(p[1]), pointsx, pointsy);
      }else{
        fold(stoi(p[1]), pointsy, pointsx);
      }
      break;
    } else {
      auto p = split(s,",");
      add(stoi(p[0]),stoi(p[1]),pointsx,pointsy);
    }
  }

  cout << pointsx.size() << endl;

}


