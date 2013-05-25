#include<map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<numeric>
#include<vector>
#include<queue>
#define pb push_back
#define DEBUG1(a) cout<<a<<endl
#define DEBUG2(a, b) cout<<a<<"\t"<<b<<endl
#define DEBUG3(a, b, c) cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define FOR(i,c) for(i=0;i<c;i++)
#define FOR1E(i,c) for(i=1;i<=c;i++)
#define DISPVEC(i,vec) for(i=0;i<vec.size();i++) \
						cout<<i<<"\t"<<vec[i]<<"\n";

using namespace std;
int INF = 1000000009;
class CharacterBoard2{
	public:
		int countGenerators(vector <string> fragment, int W, int i0, int j0) {
			// from the algo given, it is clear that the value at any position is goin to depend 
			// on the nth position it is from leftmost corner
			long long i, j, k;
			long long res = 0, sum;
			bool ok = true;
			// for each of possible string lengths of generator 
			DISPVEC(i, fragment);
			for(i=1;i<=W;i++) {
				// iterate over fragment. 
				DEBUG2("i : " , i);
				string check(i,'?'); // str of len i initialized with ?
				DEBUG2("chk:" , check);
				ok = true;
				for(j=0;j<fragment.size();j++) {
					for(k=0;k<fragment[j].size();k++) {
						int idx = ((j + i0)*W + (j0 + k)) % i;
						if( i == 5)
							DEBUG2("idx : " , idx);
						if(check[idx] != '?' && fragment[j][k] != check[idx])
							ok = false;
						check[idx] = fragment[j][k];
					}
				}
				if(!ok) 
					continue;
				DEBUG2("i succeded", i); 				
				sum = 1;
				for(j=0;j<i;j++) {
					if(check[j] == '?')
						sum = (sum *26) % INF;
				}
				res += sum;
				res %= INF;
			}
			return res;
		}
};


int main() {
	string frag[] = {"dea", "abc"};
	vector<string> f(frag, frag+2);
	CharacterBoard2 cb;
	cout<<cb.countGenerators(f,7,1,1);
}
