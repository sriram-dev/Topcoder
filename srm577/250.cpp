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

class EllysNewNickname{
public:
	int getLength(string nickname) {
		char vow[] = {'a','e','i','o','u','y'};
		vector<char> vvow(vow, vow+6);
		int tlen = nickname.length();
		int tr  = 0;
		for(int i=0;i<nickname.length() -1 ;i++) {
			if((find(vvow.begin(), vvow.end(), nickname[i]) != vvow.end()) && (find(vvow.begin(), vvow.end(), nickname[i+1]) != vvow.end()) ) {
				tr++;
			}
		}
		return (tlen - tr);
	}
};

int main() {
	EllysNewNickname enn;
	cout<<enn.getLength("naaaaaaaanaaaanaananaaaaabaaaaaaaatmaaaaan");
}