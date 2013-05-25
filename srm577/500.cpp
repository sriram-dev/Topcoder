#include<map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<numeric>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>
#define pb push_back
#define DEBUG1(a) cout<<a<<endl
#define DEBUG2(a, b) cout<<a<<"\t"<<b<<endl
#define DEBUG3(a, b, c) cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define FOR(i,c) for(i=0;i<c;i++)
#define FOR1E(i,c) for(i=1;i<=c;i++)
#define DISPVEC(i,vec) for(i=0;i<vec.size();i++) \
						cout<<vec[i]<<"\t"; \
						cout << "\n";
#define ll unsigned long long
using namespace std;

class EllysRoomAssignmentsDiv2{
public:
	double getProbability(vector <string> ratings) {
		string fstr = "";
		int i,j;
		for(i=0;i<ratings.size()-1 ;i++)
			fstr += ratings[i] + "";
		fstr += ratings[ratings.size()-1];
		//= accumulate(ratings.begin(), ratings.end(),"");
		cout<<fstr;
		vector<int> intq ;
		
		char *p;
		char *writable = new char[fstr.size() + 1];
		std::copy(fstr.begin(), fstr.end(), writable);
		writable[fstr.size()] = '\0';

		i = 0;
		p = strtok(writable, " ");
		cout<<"\n";
		while( p!= NULL) {
			DEBUG3("i p:", i , p);
			i++;
			if(find(intq.begin(), intq.end(), atoi(p)) ==  intq.end())
				intq.push_back(atoi(p));			
			p = strtok(NULL, " ");
		}
		
		DISPVEC(i, intq);
		int current = intq[0];
		// sort the input
		sort(intq.rbegin(), intq.rend());
		DISPVEC(i, intq);
		int sz = intq.size();
		// find no. of rooms 
		int nrooms = 0, newpos;
		DEBUG2("sz", sz);
		if( sz % 20 == 0)
			nrooms = sz/20;
		else
			nrooms = sz/20 + 1;
		
		DEBUG2("nrooms", nrooms);
		for(i=0;i<intq.size();i++) {
			if(intq[i] == current)
				newpos = i;
		}		
		int minperroom = sz/ nrooms;
		DEBUG2("newpos" , newpos);
		//shld consider the case where no. of elements of input is less than 20 
		// and the case where she has the highest rating number 
		if(sz <= 20 || current == intq[0])
			return 1;
		if(newpos < nrooms)
			return (double)0;
		else
			return (((double)1/nrooms));
	}
};

int main() {
	EllysRoomAssignmentsDiv2 er;	
	string rat[] = {"1066 229 242 57 435 872 504 87 974 916 939 481 199", " 493 963 697 926 5 695 420 1109 169 9 878 530 947 ", "1079 1122 630 532 55 731 83 802 1070 739 846 1148 ", "12 436 506 1168 215 378 38 774 745 627 559 608 274", " 769 228 46 763 472 1068 1157 230 1054 726 757 748", " 330 610 1191 595 204 848 961 668 283 488 450 704 ", "1147 194"};
	vector<string> ratings(rat, rat+7);
	int k;
	//DISPVEC(k, ratings);
	cout<<er.getProbability(ratings);
}