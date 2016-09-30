#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string str;
    cin >> str;
    
    bool flag = false;
    for(int i=0;i<str.length()-1;i++)
    {
      if(str[i] == str[i+1]){
        flag = true;
        break;
      }
    }
    
    if(!flag) 
      cout << str;
    else
    {
      vector<char> stk;

      stk.push_back(str[0]);
      for(unsigned i=1;i<str.length();i++)
      {
        if(stk.back() == str[i])
          stk.pop_back();
        else
          stk.push_back(str[i]);
      }
      
      for(int i=0;i<stk.size();i++)
        cout << stk[i];
      
    }
  
    return 0;
}
