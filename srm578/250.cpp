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
int inf = 1e9;
class DeerInZooDivTwo{
public:
	vector <int> getminmax(int N, int K) {
		int smallest = 0, largest = 0;
		vector<int> res;
		if(K !=0) {			
			smallest = K/1;
			if(K%2 ==0)
				largest = K / 2;
			else
				largest = (K/2) +1;
		}
		res.pb(max((N - smallest), 0));
		res.pb(max((N - largest), 0));		
		return res;
	}	
};

int main() {

}