
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int p[3] = {INT_MAX,INT_MAX,INT_MAX};
  int i =0,s=0,x;
  while(cin >> x){
    int im=i%3;
    if (x>p[im])++s;
    p[im]=x;
    ++i;
  }
  cout << s << endl;
}
