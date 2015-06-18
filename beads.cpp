/*
ID: shankho3
PROG: beads
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

int fwd(string beads, int start){
	char recentColor = beads[start];
	int total=0;
	//cout<<start<<" ";
	while(total < sz(beads) && (recentColor=='w' || (recentColor!='w'&&(beads[start]==recentColor||beads[start]=='w')))){
		start++;
		total++;
		if(start==sz(beads)){
			start=0;
		}
		if(recentColor=='w'){
			recentColor = beads[start];
		}
	}
	//cout<<total<<endl;
	return total;
}

int bckwd(string beads, int start){
	start--;
	if(start==-1){
		start = sz(beads)-1;
	}
	char recentColor = beads[start];
	int total = 0;
	//cout<<start<<" ";
	while(total<sz(beads)&&(recentColor=='w'|| (recentColor!='w'&&(beads[start]==recentColor || beads[start]=='w')))){
		start--;
		total++;
		if(start==-1){
			start = sz(beads)-1;
		}
		if(recentColor=='w'){
			recentColor = beads[start];
		}
	}
	//cout<<total<<endl;
	return total;
}

int main(){
	ifstream fin("beads.in");
	int n;
	string beads;
	fin>>n>>beads;

	int res = 0;

	fir(i,0,sz(beads)){
		res = max(res, min(sz(beads),fwd(beads,i)+bckwd(beads,i)));
	}
	ofstream fout("beads.out");
	fout<<res<<endl;
	return 0;
}