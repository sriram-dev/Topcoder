#include<vector>
#include<iostream>
#include<string>
#include <sstream>
#include<map>
using namespace std;
class CityMap{
public:
string getLegend(vector <string> cityMap, vector <int> POIs) {
		int i;
		int j;
		map<char,int> mm;
		for(int i=0;i<cityMap.size();i++) {
			for(int j=0;j<cityMap[i].size();j++ ){
				if(cityMap[i][j] != '.') {
					if(mm.find(cityMap[i][j]) != mm.end()) 
						mm[cityMap[i][j]] += 1;
					else {
						mm.insert(pair<char,int>(cityMap[i][j], 1));
					}
				}
			}
		}
		
		char res[50];				
		std::map<char,int>::iterator it;
		for(i=0;i<POIs.size();i++){	
			//cout<<"POIs[i]" << POIs[i] << "\n";
			for(it = mm.begin();it != mm.end() ; it++) {
				//cout<< it->first << it->second<<"\n";
				if(it->second == POIs[i]){
					res[i] = it->first;
					//cout<<"adding " << res[i]<<"\n";
				}
			}
		}
		res[i] = '\0';
		string r(res);
		return r;
	}
};

int main() {
	vector<string> tosend;
	vector<int> ti;
	tosend.push_back("XXXXXXXZXYYY");
	//tosend.push_back("...R.M");
	//tosend.push_back("R..R.R");
	ti.push_back(1);
	ti.push_back(8);
	ti.push_back(3);
	CityMap cm;
	cout<<cm.getLegend(tosend,ti);
}