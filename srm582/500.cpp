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
#define DISPVEC(i,vec) for(i=0;i<vec.size();i++) \
						cout<<vec[i]<<"\t"; \
						cout << "\n";

using namespace std;

class SpaceWarDiv2 {
public:
	int minimalFatigue(vector <int>, vector <int>, vector <int>);
	int findGirlIndex(vector <int> str, vector<int> fat, int s);
};

int SpaceWarDiv2::minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector <int> enemyCount) {
	//among the magical girls that can defeat an enemy choose one which has lowest fatigue
	//deal each enemy from lowest strength to highest 
	// if no girl can defeat return -1 
	//map strength to count of enemies and order in asc order(order is always asc based on key)(chk once)
	map<int, int> strength;
	int z;
	vector<int> fatigue(magicalGirlStrength.size(), 0);
	for(int i=0;i<enemyStrength.size();i++) {
		if(strength.find(enemyStrength[i]) == strength.end())
			strength[enemyStrength[i]] = enemyCount[i];
		else
			strength[enemyStrength[i]] += enemyCount[i];
	}
	//print map elems 
	std::map<int, int>::reverse_iterator iter;
	//for(iter = strength.begin();iter != strength.end(); ++iter) {
		//cout<<"key : " << iter->first <<"val : " << iter->second;
	//}
	//tackle all enemies 
	for(iter = strength.rbegin();iter != strength.rend(); iter++) {
		int count = iter->second;
		int str = iter->first;
		cout<<"Count : " << count <<endl;
		cout<<"str:" << str<<endl;
		//find all girls that has strength >= str 
		while(count > 0) {
			int k = findGirlIndex(magicalGirlStrength,fatigue ,str);
			cout<<"k: " <<k<<endl;
			if( k == -1)
				return -1;
			fatigue[k] += 1;
			count--;
		}
	}
	int maxfat = 0;
	for(int i=0;i<fatigue.size();i++) {
		if(fatigue[i] > maxfat)
			maxfat = fatigue[i];
	}
	return maxfat;
}

int SpaceWarDiv2::findGirlIndex(vector <int> str, vector<int> fat, int s) {		
	//find the capable ones. choose which has lowest fatigue
	vector<int> capableIndices;
	for(int i=0;i<str.size();i++) {
		if(str[i] >= s)
			capableIndices.push_back(i);
	}
	if(capableIndices.size() == 0)
		return -1;
	int minfatIndex = 0;
	int minval = 99999;
	for(int i=0;i<capableIndices.size();i++) {
		if(fat[capableIndices[i]] < minval) {
			minfatIndex = capableIndices[i];
			minval = fat[capableIndices[i]];
		}
	}
	return minfatIndex;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!