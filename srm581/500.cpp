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


using namespace std;

class SurveillanceSystem {
public:
	string getContainerInfo(string, vector <int>, int);
	int findval(string containers, int from, int to);
	vector<int> findcommon(vector < pair< int, int > > vec, int free); 
	
};

vector<int> SurveillanceSystem::findcommon(vector < pair< int, int > > vec, int free) {
	vector<int> common;
	int minmatches = vec.size() - free;
	for(int i=0;i<50;i++) {
		int nmatches  = 0;
		for(int j=0;j<vec.size();j++) {
			if((i >= vec[j].first && i <= vec[j].second)) {
				nmatches++;				
			}
		}
		if(nmatches>= minmatches)
			common.push_back(i);
	}
	return common;
}

int SurveillanceSystem::findval(string containers, int from, int to) {
	int n=0;
	for(int i=from;i<=to;i++) {
		if(containers[i] == 'X')
			n++;
	}
	return n;	
}

string SurveillanceSystem::getContainerInfo(string containers, vector <int> reports, int L) {
	map<int, vector< pair<int, int> > > mp;
	vector<char> out(containers.length(), '-');
	//generate all poss
	for(int i=0;i<containers.length();i++) {
		for(int j=i;(j+L-1)<containers.length();j+=L) {
			int val = findval(containers, j, (j+L -1));
			if( find(mp[val].begin(), mp[val].end(),make_pair(j, j+L -1)) == mp[val].end())
				mp[val].push_back(make_pair(j, j+L -1)); 
		}
	}
	map<int, vector< pair<int, int> > >::iterator it;
	for(it = mp.begin();it != mp.end(); it++) {
		cout<<it->first<<":\t";
		for(int j=0;j<it->second.size();j++)
			cout<<it->second[j].first << " \t" << it->second[j].second << "\n";		
	}
	
	for(int i =0;i<reports.size();i++) {
		// among all poss 
		// find common elem and mark as X
		// mark the rest of pos as ? if its - 
		vector< pair< int, int> > posc;
		int nmat = 0;
		for(int j=0;j<reports.size();j++) {
			if(reports[j] == reports[i])
				nmat++;
		}
		posc = mp[reports[i]];
		vector<int> commonpos = findcommon(posc, nmat-1);
		for(int i= 0;i<posc.size();i++) {
			for(int j=posc[i].first;j<=posc[i].second;j++) {
				if(out[j] == '-')
					out[j] = '?';
			}
		}
		for(int i= 0;i<commonpos.size();i++) {
			out[commonpos[i]] = '+';
		}
	}
	string ret(out.begin(), out.end());
	return ret;
}


//Powered by [KawigiEdit] 2.0!