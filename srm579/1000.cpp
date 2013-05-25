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
class MarblePositioning{
public:	
	double totalWidth(vector <int> radius) {
		sort(radius.begin(), radius.end());
		int i;		
		long double minw = mod;
		do {
			long double tot = 0;
			DEBUG1("------------");
			for(i=0;i<radius.size()-1;i++) {
				tot += (double)(2 * sqrt((double)radius[i] * (double)radius[i+1]));
				DEBUG2("tot", tot);
			}
			minw = min(minw, tot);
		}while(next_permutation(radius.begin(), radius.end()));
		return minw;
	}
};

int main() {
	MarblePositioning mp;
	int a[] = {100, 100,11,11,25};
	vector<int> arr(a, a+5);
	cout<<mp.totalWidth(arr);
}