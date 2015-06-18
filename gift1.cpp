/*
ID: shankho3
PROG: gift1
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
	ifstream fin("gift1.in");
	int np;
	vs people;
	map<string, int> amt;

	fin>>np;
	fir(i,0,np){
		string invdl;
		fin>>invdl;
		people.pb(invdl);
		amt[invdl]=0;
	}

	while(true){
		string person;
		int giftAmt;
		int nFrnds;
		fin>>person;
		if(fin.eof()){
			break;
		}
		fin>>giftAmt;
		fin>>nFrnds;
		if(nFrnds==0){
			continue;
		}
		amt[person]-=giftAmt;

		int gift = giftAmt/nFrnds;
		
		int rem = giftAmt - (gift*nFrnds);
		amt[person]+=rem;
		fir(i,0,nFrnds){
			string frnd;
			fin>>frnd;
			amt[frnd]+=gift;
		}
	}

	ofstream fout("gift1.out");

	fir(i,0,sz(people)){
		fout<<people[i]<<" "<<amt[people[i]]<<endl;
	}
	return 0;
}