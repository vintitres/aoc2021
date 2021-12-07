#include<iostream>
#include<cmath>
#include<map>
#include<list>
#include<climits>
#include<set>
#include<sstream>
#include<vector>
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

int cost(int pos, map<int,int> &crabs) {
  int cost=0;
  for (auto c : crabs) {
    int dist = abs(c.first - pos);
    cost += (dist*(dist+1)/2)*c.second;
  }
  return cost;
}

int main(){
  string s;
  cin >> s;
  map <int,int> crabs;
  int sum =0, count=0;
  for (auto sn : split(s, ",")) {
    int crab=stoi(sn);
    auto it = crabs.find(crab);
    if (it == crabs.end()) {
      crabs.insert(pair<int,int>(crab, 1));
    }
      else {++(crabs[crab]);}
    sum += crab;
    ++count;
  }
  for (int b = crabs.begin()->first, e = crabs.rend()->first; b <= e;){
    int x=b+(e-b)/2;
    int c1 = cost(x-1, crabs);
    int c2 = cost(x, crabs);
    int c3 = cost(x+1, crabs);
    if (c2 < c3 && c2 < c1) {
      cout << c2 << endl;
      break;
    }
    if (c1 > c2) b = x + 1;
    else e = x - 1;
    cout << x << ": " <<c2 << endl;
  }
}


