#include<bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

void Display(int mat[R][C]){
	cout<<"\nMatrix : \n";
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Zigzag(int mat[R][C]){
	int count = 0;
	int row = 0, col = 0;
	cout<<"\nZigzag : ";
	while(row<R && col<C){
		if(row==0 && col%2==0){
			if(col!=C-1){
				cout<<mat[row][col++]<<" ";
			}
			else{
				cout<<mat[row++][col]<<" ";
			}
			while(col>0 && row<R){
				cout<<mat[row++][col--]<<" ";
			}
		}
		if(col==0){
			if(row==R-1){
				cout<<mat[row][col++]<<" ";
			}
			else{
				cout<<mat[row++][col]<<" ";		
			}
			while(row>0 && col<C){
				cout<<mat[row][col]<<" ";
				row--;
				if(col==C-1)
					break;
				col++;
			}
		}
	}
}

int main(){
	
	int mat[R][C] = {	{1,2,3,4},
							{5,6,7,8},
							{9,10,11,12},
							{13,14,15,16}};
	
	Display(mat);
	
	Zigzag(mat);
	
}