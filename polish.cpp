#include <bits/stdc++.h>

using namespace std;

vector<string> tokens;
int stac[10000];
int top=-1;

int op(char c){
    if(c=='+') return 1;
    else if(c=='-')return 2;
    else if(c=='*')return 3;
    else if(c=='/')return 4;
    else return 0;
}

void push(int c){
    stac[++top]=c;
}

int pop(){
    return stac[top--];
}

int main(){
    vector<string>token;
    for(int i=0;i<tokens.size();i++){
        string c;
        c=tokens[i];
        int t;
        if(c.length()==1){
            int t=op(c[0]);
        }
        else t=0;
        if(t!=0){
            int op2=pop();
            int op1=pop();
            int result;
            if(t==1) result=op1+op2;
            else if(t==2) result=op1-op2;
            else if(t==3) result=op1*op2;
            else if(t==4) result=op1/op2;
            cout<<result<<endl;
            push(result);
        }
        else{
            int x=stoi(c,0,c.length());
            push(x);
        }
    }
    cout<<stac[0]<<endl;
}