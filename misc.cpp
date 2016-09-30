/**
 * Misc Coding Problems
 * Ref: GeeksForGeeks
 */

#include <set>
#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int countSquares(int a,int b)
{
	return floor(sqrt(b)) - ceil(sqrt(a)) + 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str;
    std :: map<char, bool> count;
    cin >> str;
    cout << str;
    count[tolower(str[0])] = true;
    for(char &ch: str)
    	count[ch] = true;

    for(char ch=92;ch<=122;ch++)
    	if(count[ch])
    		cout << endl << count[ch];
    
    return 0;
}