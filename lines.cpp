#include<iostream>
#include<map>
#include<list>
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

class Line {
  public:
  int x1, y1, x2, y2;
  Line(int xx1, int yy1,int xx2, int yy2){
    x1=xx1;y1=yy1;x2=xx2;y2=yy2;
  }
};
    int water[1000][1000];

int main(){
  string from, sep, to;
  vector <Line> lines;
  int maxx = 0, maxy= 0;
  while(cin >> from >> sep >> to){
    auto vfrom = split(from, ","), vto = split(to, ",");
    int x1 = stoi(vfrom[0]), y1=stoi(vfrom[1]), x2=stoi(vto[0]),y2=stoi(vto[1]);
    if (x1 != x2&& y1 != y2)continue;
    if (x1 > maxx) maxx = x1;
    if (y1 > maxy) maxy = y1;
    if (x2 > maxx) maxx = x2;
    if (y2 > maxy) maxy = y2;
    lines.push_back(Line(x1,y1,x2,y2));

  }

  cout<<maxx<<" "<<maxy<<endl;
  cout<<"aa";
  for (int i =0; i< maxx; ++i){
  for (int j =0; j< maxy; ++j){
      water[i][j]=0;
  }
  }
  cout<<"a";
  for (auto line : lines) {
    int x1 = line.x1, x2=line.x2, y1=line.y1, y2=line.y2;
    for (int i=x1, j=y1; true; x1==x2 ? (y1<y2 ? ++j : --j) : (x1<x2?++i:--i)){
      ++water[i][j];
      if (i == x2 && j == y2) break;
    }

  }
  cout<<"b";
  int c = 0;
  for (int i =0; i< maxx; ++i){
  for (int j =0; j< maxy; ++j){
    cout << water[i][j]<< " ";
      if(water[i][j]>1)++c;
  }
  cout<<endl;
  }
  cout << c <<endl;

}

