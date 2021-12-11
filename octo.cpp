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

int octo[10][10];

void power(int i, int j, queue<pair<int,int>> &q, bool allowzero=false){
  if (i == -1 || i == 10 || j == -1 || j == 10) return;
  if (!allowzero && octo[i][j] == 0) return;
  if (++octo[i][j] > 9) {
    q.push(make_pair(i,j));
    octo[i][j] = 0;
  }
}

int main(){
  string s;
  int i=0, j=0;
  while(cin >> s) {
    cout << i << " " << s << endl;
    for (char c : s) {
      octo[i][j++] = c - '0';
    }
    ++i;
    j = 0;
  }
  for (i = 0; i < 10; ++i){
    for (j = 0; j < 10; ++j){
      cout << octo[i][j];
    }
    cout << endl;
  }
  for (int k = 0; true; ++k){
    int flashes = 0;
    queue<pair<int,int>> q;
    for (i = 0; i < 10; ++i){
      for (j = 0; j < 10; ++j){
        power(i,j,q, true);
      }
    }
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      i = p.first;
      j = p.second;
      ++flashes;
      power(i-1, j-1, q); 
      power(i-1, j, q); 
      power(i-1, j+1, q); 
      power(i, j-1, q); 
      power(i, j+1, q); 
      power(i+1, j-1, q); 
      power(i+1, j, q); 
      power(i+1, j+1, q); 
    }
    if (flashes == 100) {cout << k + 1 << endl; break;}
    /*
    cout << k+1 << ":" << endl;
    for (i = 0; i < 10; ++i){
      for (j = 0; j < 10; ++j){
        cout << octo[i][j];
      }
      cout << endl;
    }
    */
  }
}


