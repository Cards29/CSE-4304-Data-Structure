#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
    ll t;
    vi v;
    unordered_map<ll,ll> um;
    vector<pair<ll,ll>> vp;
    while(cin>>t && t!=-1){
        v.push_back(t);
        um[t]++;
    }
    ll target;
    cin>>target;
    for(auto i:v){
        if(um[target-i]>0){
            um[target-i]--;
            um[i]--;
            if(um[target-i]>=0 && um[i]>=0)
                vp.push_back({i,target-i});
        }
    }
    ll sz=vp.size(), i;
    if(sz==0){
        cout<<"No pairs found"<<endl;
        return 0;
    }
    for(i=0;i<sz-1;i++){
        cout<<"(" <<vp[i].first<<','<<vp[i].second<<"), ";
    }
    cout<<"(" <<vp[i].first<<','<<vp[i].second<<")";
    return 0;
}