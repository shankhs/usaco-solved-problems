/*
ID: shankho3
PROG: ride
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
	ifstream fin("ride.in");
	string comet;
	string grps;

	fin>>comet;
	fin>>grps;

	long long iComet=1, iGrps=1;

	fir(i,0,sz(comet)){
		iComet*=(comet[i]-'A')+1;
		//cout<<comet[i]<<" "<<(comet[i]-'A')+1<<endl;
	}
	fir(i,0,sz(grps)){
		iGrps*=(grps[i]-'A')+1;
		//cout<<grps[i]<<" "<<(grps[i]-'A')+1<<endl;
	}

	//cout<<iComet<<" "<<iGrps<<endl;

	string ret = (iComet%47 == iGrps%47)?"GO":"STAY";

	ofstream fout("ride.out");
	fout<<ret<<endl;
	return 0;
}