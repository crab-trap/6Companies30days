#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

vector<vector<int>> result;
int limit_n;
int limit_k;
int flag=0;
int ans=0;

void dfs(int parent,int count,int sum,vector<int>a){
    sum+=parent+1;
    count++;
    a.push_back(parent+1);
    if(count>limit_k) {
        a.pop_back();
        return;
    }
    if(sum>limit_n) {
        a.pop_back();
        return;
    }
    if(sum==limit_n&&count==limit_k){
        result.push_back(a);
        a.pop_back();
        return;
    }
    for(int i=parent+1;i<9;i++){
        dfs(i,count,sum,a);
    }
}

int arr[9][9];
    vector<vector<int>> combinationSum3(int k, int n) {
        limit_n=n;
        limit_k=k;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(i+j+2>n) arr[i][j]=0;
                else if(j>i) arr[i][j]=1;
                else arr[i][j]=0;
            }
        }
        vector<int>a;
        for(int i=0;i<9;i++){
            dfs(i,0,0,a);
        }
    return result;
    }
};