#include<bits/stdc++.h>
using namespace std;

int MaxProfit_Recursive(vector<int> prices, int n){
	if(n<=0)
		return 0;
	int max_val = INT_MIN;
	for(int i=0;i<n;i++){
		max_val = max(max_val, prices[i] + MaxProfit_Recursive(prices,n-i-1));
	}
	return max_val;
}

int MaxProfit_DP(vector<int> prices){
	int n = prices.size();
	vector<int> dp(n+1,0);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		int max_val = INT_MIN;
		for(int j=0;j<i;j++){
			max_val = max(max_val,prices[j]+dp[i-j-1]);
		}
		dp[i] = max_val;
	}	
	return dp[n];
}

int main(){
	
	vector<int> prices = {1,5,8,9,10,17,17,20};
	cout<<"\nMax Profit : "<<MaxProfit_Recursive(prices, prices.size());
	cout<<"\nMax Profit : "<<MaxProfit_DP(prices);

}