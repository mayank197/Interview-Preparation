#include<bits/stdc++.h>
using namespace std;

#define R 4
#define C 6

void Display(int mat[R][C]){
	cout<<"\nMatrix : \n";
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int MaxPathSum(int mat[R][C]){
	// No need to consider the 0th row
	for(int i=1;i<R;i++){
		for(int j=0;j<C;j++){
			
			if(j>0 && j<C)
				mat[i][j] += max(mat[i-1][j-1], max(mat[i-1][j], mat[i-1][j+1]));
			
			else if(j>0)
				mat[i][j] += max(mat[i-1][j-1], mat[i-1][j]);
			
			else if(j<C)
				mat[i][j] += max(mat[i-1][j], mat[i-1][j+1]);
			
		}
	}
	// Explore the last row 
	int max_sum = 0;
	for(int i=0;i<C;i++)
		max_sum = max(max_sum,mat[R-1][i]);
	
	return max_sum;
}

int main(){
	
	int mat[R][C] = {	{10,10,2,0,20,4},
							{1,0,0,30,2,5},
							{0,10,4,0,2,0},
							{1,0,2,20,0,4}};
	
	Display(mat);
	
	cout<<"\nMax Path Sum from 1st Row to Last : "<<MaxPathSum(mat)<<endl;
	
}