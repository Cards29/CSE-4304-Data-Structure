#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
    string str;
    unordered_map<string,ll> um;
    while(getline(cin,str)){
        stringstream ss(str);
        string word;
        while(ss>>word){
            ll sz=word.size();
            while(sz--)
                if(word.back()=='.' || word.back()==',' || word.back()=='\'') word.pop_back();
            sz=word.size();
            while(sz--)
                if(word.front()=='.' || word.front()==',' || word.front()=='\'') word=word.substr(1);
            um[word]++;
        }
    }
    for(auto i:um){
        if(i.second>1)
            cout<<i.first<<' '<<i.second<<endl;
    }
    return 0;
}
/*
This refers to an exam where James had written 'had had' where John had written just ' had'. The examiner had approved James' version.
*/