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

string getStr(int n){
	string s;
	fir(i,0,n){
		s+=' ';
	}
	return s;
}

vs vflip(vs v){
	int n = sz(v);
	vs v2;
	string s = getStr(n);
	fir(i,0,n){
		v2.pb(s);
	}
	fir(i,0,n){
		fir(j,0,n){
			v2[n-1-i][j] = v[i][j];
		}
	}
	// cout<<"######################\n";
	// fir(i,0,n){
	// 		cout<<v2[i];
	// 	cout<<endl;
	// }
	// cout<<"######################\n";
	return v2;
}

vs hflip(vs v){
	int n = sz(v);
	vs v2;
	string s = getStr(n);
	fir(i,0,n){
		v2.pb(s);
	}
	fir(i,0,n){
		fir(j,0,n){
			v2[i][n-1-j] = v[i][j];
		}
	}
	// cout<<"---------------------\n";
	// fir(i,0,n){
	// 	fir(j,0,n){
	// 		cout<<v2[i][j];
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"---------------------\n";
	return v2;
}

vs transpose(vs v){
	vs v2;
	int n = sz(v);
	string s = getStr(n);
	fir(i,0,n){
		v2.pb(s);
	}
	fir(i,0,n){
		fir(j,0,n){
			v2[j][i] = v[i][j];
		}
	}
	return v2;
}

bool equals(vs v1, vs v2){
	if(sz(v1)!=sz(v2))	return false;
	int n = sz(v1);
	fir(i,0,n){
		// cout<<v1[i]<<" "<<v2[i]<<endl;
		if(v1[i]!=v2[i]){
			return false;
		}
	}
	return true;
}

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
		// cout<<afr[i]<<endl;
	}
	ofstream fout("transform.out");
	if(equals(afr , hflip(transpose(bfr)))){
		fout<<"1"<<endl;
	}
	else if(equals(afr , vflip(hflip(bfr)))){
		fout<<"2"<<endl;
	}
	else if(equals(afr, vflip(transpose(bfr)))){
		fout<<"3"<<endl;
	}
	else if(equals(afr,hflip(bfr))){
		fout<<"4"<<endl;
	}
	else if(equals(afr,bfr)){
		fout<<"6"<<endl;
	}
	else if(equals(afr,hflip(transpose(hflip(bfr))))||equals(afr , vflip(hflip(hflip(bfr))))||equals(afr , hflip(hflip(bfr)))){
		fout<<"5"<<endl;
	}
	else{
		fout<<"7"<<endl;
	}
	return 0;
}