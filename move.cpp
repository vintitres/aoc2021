
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main(){
  int d=0, f=0,a=0,x;
  string s;
  while(cin >>s  >> x){
    if (s[0]=='f'){f+=x;d+=a*x;}
    else if(s[0]=='d')a+=x;
    else a-=x;
  }
  cout << d*f << endl;
}
