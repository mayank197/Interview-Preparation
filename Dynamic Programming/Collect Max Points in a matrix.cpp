#include<bits/stdc++.h>
using namespace std;

void Display(vector<vector<int>> vect, int rows, int cols){
	cout<<"\nMatrix : \n";
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<vect[i][j]<<" ";
		}
		cout<<endl;
	}
}

int MaxPoints(vector<vector<int>> vect,int rows,int cols){
	vector<vector<int>> dp(rows+1, vector<int>(cols+1,0));
	for(int i=1;i<=rows;i++){
		// If odd row
		if(i&1){
			for(int j=1;j<=cols;j++){
				if(vect[i-1][j-1]!=-1)
					dp[i][j] = vect[i-1][j-1] + max(dp[i-1][j], dp[i][j-1]);
			}
		}
		else{	
			for(int j=cols;j>=1;j--){
				if(vect[i-1][j-1]!=-1)
						dp[i][j] = vect[i-1][j-1] + max(dp[i-1][j], dp[i][j+1]);
			}
		}
	}
	Display(dp,rows,cols);
	// Get maximum value from matrix
	int i=1,j=1;
	int result = dp[i][j];
	
	while(i<=rows && j<=cols && j>=0){
		if(dp[i][j]==dp[i+1][j] || dp[i][j]+1 == dp[i+1][j])
			i++;
		else if(dp[i][j]==dp[i][j+1] || dp[i][j]+1==dp[i][j+1])
			j++;
		else if(dp[i][j]==dp[i][j-1] || dp[i][j]+1==dp[i][j-1])
			j--;
		else
			break;
		result = dp[i][j];
	}
	return result;
}

int main(){

	vector<vector<int>> vect = {
											{1,1,-1,1,1},
											{1,0,0,-1,1},
											{1,1,1,1,-1},
											{-1,-1,1,1,1},
											{1,1,-1,-1,1}
	};
	
	int rows = vect.size();
	int cols = vect[0].size();
	
	Display(vect,rows,cols);
	
	cout<<"\nMaximum Points that can be collected : "<<MaxPoints(vect,rows,cols);
	
}