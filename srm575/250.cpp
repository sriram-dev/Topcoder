#include<map>
#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
#include<numeric>
#include<vector>
#define pb push_back
#define DEBUG1(a) cout<<a<<endl
#define DEBUG2(a, b) cout<<a<<"\t"<<b<<endl
#define DEBUG3(a, b, c) cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define FOR(i,c) for(i=0;i<c;i++)
#define FOR1E(i,c) for(i=1;i<=c;i++)
#define DISPVEC(i,vec) for(i=0;i<vec.size();i++) \
						cout<<vec[i]<<"\t";
						
using namespace std;
int INF = 10000000;
class TheSwapsDivTwo{
public:
	int find(vector <int> sequence) {
		int cnt = 1;
		if(sequence.size() <= 2)
			return cnt;
		for(int i=0;i<sequence.size();i++) {
			for(int j=i+1;j<sequence.size();j++) {
				if(sequence[i] != sequence[j])
					cnt++;
			}			
		}		
		return cnt;
	}
	
};

int main() {
	vector<int> s;
	s.pb(4);
	s.pb(7);
	s.pb(4);
	TheSwapsDivTwo ts;
	cout<<ts.find(s);
}
//232 points submitted 
