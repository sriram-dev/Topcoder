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
class GooseInZooDivTwo{
public:
	int count(vector <string> field, int dist) {
		// all abt grping
		vector<string> newfield;
		int ngrp =0 , total =0, nothers = 0, ningrp = 0;
		int i;
		for(i=0;i<field.size();i++)
			newfield.pb(field[i]);
		DISPVEC(i, newfield);
		for(i=0;i<newfield.size();i++) {
			for(int j=0;j<newfield[i].size();j++) {	
				if(field[i][j] == 'v')
					total++;
			}
		}
		for(i=0;i<newfield.size();i++) {
			for(int j=0;j<newfield[i].size();j++) {				
				if(newfield[i][j] == 'v') {										
					queue< pair<int,int> > q;
					q.push(make_pair(i,j));
					newfield[i][j] = '.';
					ngrp++;
					//ningrp++;
					while(!q.empty()){
						pair<int, int> qfront;
						qfront = q.front();
						q.pop();						
						int currenti = qfront.first;
						int currentj = qfront.second;
						DEBUG2("currenti", currenti);
						DEBUG2("currentj", currentj);
						for(int k=0;k<newfield.size();k++) {
							for(int l = 0;l<newfield[k].size();l++) {
								DEBUG2("newk", k);
								DEBUG2("new ", l);								
								if(newfield[k][l] == 'v') {									
									if( (abs(k-currenti) + abs(l-currentj)) <= dist) {
										q.push(make_pair(k,l));
										//ngrp++;
										//ningrp++;
										newfield[k][l] = '.';
										DEBUG1("found element at less than tht dist");
									}
								}
							}
						}
					}
				}
			}
		}		
		int res = 1;
		for(i=0;i<ngrp;i++)
			res = ((res*2) %mod);		
		return (res - 1)%mod;
	}
};

int main() {
	GooseInZooDivTwo gz;
	string f[] = {"vvv"};
	vector<string> field(f, f+1 );
	cout<<gz.count(field,0);
}