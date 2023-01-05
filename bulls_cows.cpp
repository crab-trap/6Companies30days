#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arr[10];
    string getHint(string secret, string guess) {
        int bull=0;
        int cow=0;
        for(int i=0;i<secret.length();i++){
            arr[secret[i]-48]++;        
        }
        for(int i=0;i<guess.length();i++){
            if(secret[i]==guess[i]){
                if(cow>0&&arr[guess[i]]==0){
                    cow--;
                    bull++;
                }
                else if(arr[guess[i]]>0){
                    bull++;
                    arr[guess[i]]--;
                }
            }
            else if(arr[guess[i]-48]>0){
                cow++;
                arr[guess[i]]--;
            }
        }
        string s1=to_string(bull);
        s1.append("A");
        s1.append(to_string(cow));
        s1.append("B");
        return s1;
    }
};