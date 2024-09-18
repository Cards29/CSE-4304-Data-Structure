#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int front_index = 0;
int back_index = 0;
int count_element;

bool compare(queue<char> q1, queue<char> q2){
    while(!q1.empty()){
        if(q1.front()!=q2.front())
            return false;
        q1.pop();
        q2.pop();
    }
    return true;
}

int main() {
    int count_rotation=0;
    queue<char> q1,q2;

    string s1,s2;

    cin>>s1;
    cin.ignore();
    cin>>s2;


    for (auto &&i : s1){
        q1.push(i);
    }
    for (auto&& i : s2) {
        q2.push(i);
    }
    

    int sz=q1.size()+1;
    while(sz--){
        if(compare(q1,q2)){
            if(!count_rotation){
                cout << "Yes. Rotation not needed.";
                return 0;
            }
            cout << "Yes. After "<<count_rotation<<" clockwise rotations"<<endl;
            return 0;
        }
        char temp=q2.front();
        q2.pop();
        q2.push(temp);
        count_rotation++;
    }

    cout<<"No"<<endl;


    return 0;
}