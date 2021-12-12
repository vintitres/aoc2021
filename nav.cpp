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

  map <string, vector<string>> caves;
  map <string, bool> visited;

  int paths = 0;
void add(string a, string b) {
  if(caves.find(a) == caves.end()) {
    vector<string> v;
    caves[a] = v;
    visited[a] = false;
  }
  caves[a].push_back(b);
}
bool twice = false;
void go(string s){
  if (s == "end") {
    ++paths;
    return;
  }
  bool vis = visited[s];
  if (s[0] >= 'a' && s[0] <= 'z') {
    visited[s] = true;
  }
  for (string ss : caves[s]){
      if(!visited[ss]) go(ss);
      else if (!twice && ss != "start") {
        twice = true;
        go(ss);
        twice = false;
      }
  }
  if (s[0] >= 'a' && s[0] <= 'z') {
    visited[s] = vis;
  }
}

int main(){
  string s;
  while(cin >> s) {
    auto p = split(s,"-");
    string from = p[0], to=p[1];
    add(from, to);
    add(to, from);
  }
  go("start");

  cout << paths << endl;

}


