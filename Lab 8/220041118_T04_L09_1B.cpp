#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

// sir, this is ai generated cause i didn't know pairs don't have builtin hash function,
// and I don't know hoe to build one
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

int main(){
    unordered_map<pair<double, double>, double, pair_hash> um;
    vector<pair<double,double>> vp;
    int n;
    cin>>n;
    while(n--) {
        double x,y;
        cin>>x>>y;
        vp.push_back({x,y});
    }
    n = vp.size();
    double slope;
    for(int i=0;i<n-1;i++) {
        double x1,x2,y1,y2;
        x1 = vp[i].first;
        x2 = vp[i].second;
        y1 = vp[i+1].first;
        y2 = vp[i+1].second;

        slope = (y2 - y1)/(x2 - x1);
        um[vp[i]] = slope;
        um[vp[i+1]] = slope;
    }

    return 0;
}