#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}

string longestPalindrome(string S) {
    // code here
    int n=S.size();
    bool dp[n+1][n+1]={0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0||i==1) {
            	dp[i][j]=1;
            	dp[1][0]=0;
            	continue;
            }
            if(j<i) dp[i][j]=0;
            else{
                if((S[j-1]==S[j-i]) && dp[i-2][j-1]==1)
                    dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
    }
    string ans;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=n;j++){
            if(dp[i][j]==1){
            	int k=j-i;
                while(k<j){
                    ans.push_back(S[k]);
                    k++;
                }
                return ans;
            }
        }
    }
    return "-1";
}
