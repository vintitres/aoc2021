#include<iostream>
#include<vector>
using namespace std;

void f(const string &s, vector<int> &v) {
  for (int i =0; i <= s.size(); ++i){
    if(s[i]=='0')++v[i];
    else --v[i];
  }
}

  int main(){
    string s;
    cin>>s;
    vector<int> x(s.size());
    f(s,x);
      while (cin >> s) {
        f(s, x);
      }
    int d = 1, v=0;
    for (auto it=x.begin(); it!=x.end(); ++it){
      cout <<*it <<endl;
      if (*it>0) ++v;
      v=v<<1;
    }
    v=v>>1;
     int vv =  ((1<<(x.size()))-1)^v;
        cout << v << endl<< vv << endl <<
      v * vv<< endl;
  }

