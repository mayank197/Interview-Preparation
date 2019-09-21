#include<bits/stdc++.h>
using namespace std;

// The Recursive Approach
int countStrings_Recursive(int n, int last_digit){
	
	if(n==0) return 0;
	
	if(n==1){
		// If last digit is 0, we can have 2 strings "0" and "1"
		if(last_digit==0)	
			return 2;
		if(last_digit==1)
			return 1;
	}
	
	if(last_digit==0)
		return countStrings_Recursive(n-1,0) + countStrings_Recursive(n-1,1);
	
	return countStrings_Recursive(n-1,0);
}

// DP Approach
int countStrings_DP(int n){
	
	// Here dp[i][j] will represent number of 'i' digit strings with 'j' as last digit 
	
	int dp[n+1][2];		
	
	dp[0][0] = 0;					
	dp[0][1] = 0;					
	
	dp[1][0] = 2;		// There can be two 1-digit strings : "0" and "1"
	dp[1][1] = 1;     // If 1 is the last digit, we can have only one string "1"
	
	for(int i=2;i<=n;i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	return dp[n][0];		
}

// Printing all strings 
void PrintAllStrings(int n, string result, int last_digit){
	if(n==0){
		cout<<result<<endl;
		return;
	}
	PrintAllStrings(n-1,result+"0",0);
	if(last_digit==0)
		PrintAllStrings(n-1,result+"1",1);
}

int main(){
	
	int n;
	cout<<"\nEnter n : ";
	cin>>n;
	
	cout<<"Number of "<<n<<" digit binary strings without consecutive 1's are : ";
	// cout<<countStrings_Recursive(n,0);		// Recursive 
	cout<<countStrings_DP(n);					// DP
	
	string result = "";
	cout<<"\n\nAll strings with "<<n<<" digits without consecutive 1's are : \n";
	PrintAllStrings(n,result,0);
	
}