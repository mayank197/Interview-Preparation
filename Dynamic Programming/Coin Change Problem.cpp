#include<bits/stdc++.h>
using namespace std;

int Ways(vector<int> arr, int n, int sum){
	if(sum==0)
		return 1;
	if(sum<0)
		return 0;
	if(n<=0 && sum>=1)
		return 0;
	// a) Exclude the last item
	// b) Include the last item
	return Ways(arr,n-1,sum) + Ways(arr,n,sum-arr[n-1]);
}

int Ways_DP(vector<int> arr, int sum){
	int n = arr.size();
	vector<vector<int>> dp(sum+1, vector<int>(n));
	for(int i=0;i<n;i++)
		dp[0][i] = 1;
	for(int i=1;i<=sum;i++){
		for(int j=0;j<n;j++){
			int x = (i-arr[j]>=0) ? dp[i-arr[j]][j] : 0;
			int y = (j>=1) ? dp[i][j-1] : 0;
			dp[i][j] = x+y;
		}
	}	
	return dp[sum][n-1];
}


int main(){

	vector<int> denominations = {1,2,3};
	int sum = 4;
	int n = denominations.size();
	cout<<"\nNo. of ways to make "<<sum<<" : "<<Ways(denominations,n,sum);
	cout<<"\nNo. of ways to make "<<sum<<" : "<<Ways_DP(denominations,sum);
	
}