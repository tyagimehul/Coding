// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int n){
    /*Your code here */
    pair<int,int> arrPos[n];
    for(int i=0;i<n;i++){
        arrPos[i].first=arr[i];
        arrPos[i].second=i;
    }
    sort(arrPos,arrPos+n);
    
    vector<bool> vis(n,false);
    int ans=0;
    for(int i=0;i<n;i++){
        if(vis[i]==1 || arrPos[i].second==i)
            continue;
        int cycle = 0;
        int j=i;
        while(vis[j]!=1){
            vis[j]=true;
            j=arrPos[j].second;
            cycle++;
        }
        if(cycle>0){
            ans+=(cycle -1);
        }
    }
    return ans;
}
