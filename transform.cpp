/*
ID: shankho3
PROG: transform
LANG: C++
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define vs vector<string>
#define vi vector<int>
#define pb push_back
#define fir(i,n,m) for(int i=n;i<m;i++)
#define sz(v) (int)v.size()
#define all(c) c.begin(),c.end()
#define fdr(i,n,m) for(int i=n;i>=m;i--)

using namespace std;

int main(){
	int n;
	vs bfr, afr;
	ifstream fin("transform.in");
	fin>>n;
	fir(i,0,n){
		string s;
		fin>>s;
		bfr.pb(s);
	}
	fir(i,0,n){
		string s;
		fin>>s;
		afr.pb(s);
	}

	if(afr == vflip(transpose(bfr))){
		cout<<"1"<<endl;
	}
	else if(afr == vflip(hflip(bfr))){
		cout<<"2"<<endl;
	}
	else if(afr == hflip(transpose(bfr))){
		cout<<"3"<<endl;
	}
	else if(afr == )
}