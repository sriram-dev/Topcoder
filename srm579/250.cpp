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
#include<queue>
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
int mod = 1000000007;
class PrimalUnlicensedCreatures{
public:
	int maxWins(int initialLevel, vector <int> grezPower) {
		sort(grezPower.begin(), grezPower.end());
		int maxw = 0;
		for(int i=0;i<grezPower.size();i++) {
			if(initialLevel > grezPower[i]){
				maxw++;
				initialLevel += (grezPower[i]/2);
			}
			else
				break;
		}
		return maxw;
	}
	
};

int main() {

}