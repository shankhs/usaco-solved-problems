/*
ID: shankho3
PROG: milk2
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

struct time{
	int start;
	int end;
};

typedef struct time Time;

bool comp(Time t1, Time t2){
	return t1.start<=t2.start;
}

int main(){
	ifstream fin("milk2.in");
	int n;
	fin>>n;
	vector<Time> vt;
	ofstream fout("milk2.out");
	if(n==0){
		fout<<0<<" "<<0<<endl;
		return 0;
	}
	fir(i,0,n){
		Time t;
		fin>>t.start>>t.end;
		vt.pb(t);
	}
	
	sort(all(vt),comp);
	int maxct=vt[0].end-vt[0].start,maxit=0;
	int currStart=vt[0].start;
	int currEnd = vt[0].end;
	fir(i,1,sz(vt)){
		if(vt[i].start<=currEnd){
			currEnd = max(vt[i].end,currEnd);
		}
		else{
			maxit = max(maxit,vt[i].start-currEnd);
			currStart = vt[i].start;
			currEnd = vt[i].end;
		}
		maxct = max(maxct, currEnd-currStart);

	}
	
	fout<<maxct<<" "<<maxit<<endl;
	return 0;
}