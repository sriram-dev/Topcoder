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

class BlackAndWhiteSolitaire {
public:
	int minimumTurns(string);
};

int BlackAndWhiteSolitaire::minimumTurns(string cardFront) {
	//case for white as first 
	int nsteps = 0, maxsteps = 1000;
	for(int i=0;i<cardFront.length();i++) {
		if(i%2 == 0 ) {
		 if(cardFront[i] != 'W') 
			nsteps++;
		}
		else {
			if(cardFront[i] != 'B')
				nsteps++;
		}			 
	}
	maxsteps = min(nsteps, maxsteps);
	cout<<"nsteps " << nsteps ;
	nsteps = 0;
	for(int i=0;i<cardFront.length();i++) {
		if(i%2 == 0 ) {
		 if(cardFront[i] != 'B') 
			nsteps++;
		}
		else {
			if(cardFront[i] != 'W')
				nsteps++;
		}			 
	}
	cout<<"nsteps " << nsteps;
	maxsteps = min(nsteps, maxsteps);
	return maxsteps;
}


//Powered by [KawigiEdit] 2.0!