#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int Median(int mat[R][C]){
	
	int min_val = INT_MAX;
	int max_val = INT_MIN;
	
	for(int i=0;i<R;i++){
		if(mat[0][i] < min_val)
			min_val = mat[0][i];
		
		if(mat[i][C-1] > max_val)
			max_val = mat[i][C-1];
	}
	
	int desired = (R*C+1)/2;
	
	while(min_val < max_val){
		int mid = min_val + (max_val - min_val)/2;
		int total = 0;
		
		for(int i=0;i<R;i++){
			total += upper_bound(mat[i],mat[i]+C,mid) - mat[i];
		}
		
		if(total < desired)
			min_val = mid + 1;
		else
			max_val = mid;
	}
	return min_val;
}

int main(){
	
	int mat[R][C] = {{1,3,5},{2,6,9},{3,6,9}};
	cout<<"\nMedian : "<<Median(mat);
	
}