#include<bits/stdc++.h>
#include<string>
using namespace std;

int Appearances(string a, string b, int x, int y){
	
	if(x==1 && y==1 && a[0]==b[0])
			return 1;
	
	if(x==0)
		return 0;
	
	if(y==0)
		return 1;
	
	if(y>x)
		return 0;
	
	return ((a[x-1]==b[y-1]) ? Appearances(a,b,x-1,y-1) : 0) 
				+ Appearances(a,b,x-1,y);
}

int Appearances_DP(string str, string patt){
	int X = str.length();
	int Y = patt.length();
	vector<vector<int>> dp(X+1, vector<int>(Y+1));
	
	for(int i=0;i<=X;i++)
		dp[i][0] = 1;
	
	for(int i=1;i<=Y;i++)
		dp[0][i] = 0;
	
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			dp[i][j] = ((str[i-1]==patt[j-1]) ? dp[i-1][j-1] : 0) + dp[i-1][j];
		}
	}
	return dp[X][Y];
}

int main(){
	
	string str = "subsequence";
	string patt = "sue";
	
	cout<<"\nNo. of times the pattern \'"<<patt<<"\' appears in \'"<<str<<"\' : ";
//	cout<<Appearances(str,patt,str.length(),patt.length());
	cout<<Appearances_DP(str,patt);
	
}