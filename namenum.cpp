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

vs getValidName(vi keys, map<string, bool> dict, string keypad[10], bool *arrAdded, vector<bool> *posAdded, string r, vs ret){
    if(sz(r)==sz(keys)){
        if(dict.find(r)!=dict.end()){
            cout<<r<<endl;
            ret.pb(r);
        }
    }
    else{
        // fir(i,0,sz(keys)){
        //     cout<<arrAdded[i]<<" ";
        // }
        // cout<<endl;
        fir(i,0,sz(keys)){
            if(arrAdded[i]) continue;
            arrAdded[i]=true;
            string temp = r;
            fir(j,0,sz(keypad[keys[i]])){
                if(posAdded[i][j])  continue;
                posAdded[i][j] = true;
                string temp = r;
                r+=keypad[keys[i]][j];
                getValidName(keys,dict,keypad, arrAdded, posAdded,r, ret);
                posAdded[i][j] = false;
                r = temp;
            }
            arrAdded[i]=false;
            r = temp;
        }
    }
    return ret;
}

int main(){
	string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
	ifstream finDict("dict.txt"), fin("namenum.in");
	map<string, bool> dict;
	string temp;
	while(true){
        finDict>>temp;
        if(finDict.eof())   break;
		dict[temp]=true;
	}
	string n;
	fin>>n;
	vi keys;
	fir(i,0,sz(n)){
		keys.pb(n[i]-'0');
	}
    bool arrAdded[keys.size()];
    fir(i,0,keys.size()){
        arrAdded[i] = false;
    }
    vector<bool> *charAdded = new vector<bool>[sz(keys)];
    fir(i,0,sz(keys)){
        fir(j,0,sz(keypad[keys[i]])){
            charAdded[i].pb(false);
        }
    }
    cout<<n<<endl;
	vs ret; 
    ret = getValidName(keys,dict,keypad,arrAdded, charAdded,"",ret);
	ofstream fout("namenum.out");
	if(sz(ret)==0){
		fout<<"NONE"<<endl;
	}
	else{
		sort(all(ret));
		fir(i,0,sz(ret)){
			fout<<ret[i]<<endl;
		}
	}
	return 0;
}