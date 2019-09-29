#include<bits/stdc++.h>
using namespace std;

// Knight's Tour Problem (Backtracking)
#define N 8

int xmoves[8] = {2,1,-1,-2,-2,-1, 1, 2}; 
int ymoves[8] = {1,2, 2, 1,-1,-2,-2,-1}; 

bool Safe(int i, int j, int solution[N][N]){
	return (i>=0 && j>=0 && i<N && j<N && solution[i][j]==-1);
}

void PrintMatrix(int solution[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<solution[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool KnightTour_Helper(int i, int j, int move_number, int solution[N][N]){
	int x,y;
	if(move_number==N*N)
		return true;
		
	for(int k=0;k<8;k++){
		x = i + xmoves[k];
		y = j + ymoves[k];
		if(Safe(x,y,solution)){
			solution[x][y] = move_number;
			if(KnightTour_Helper(x,y,move_number+1,solution)==true)
				return true;
			else
				solution[x][y] = -1;		// Backtrack
		}
	}
	return false;
}

void KnightTour(){
	int solution[N][N];
	memset(solution,-1,sizeof solution);
	
	// Knight is at the first block
	solution[0][0] = 0;
	if(KnightTour_Helper(0,0,1,solution)==false){
		cout<<"\nSolution doesn't exist";
	}
	else{
		cout<<"\nSolution : ";
		PrintMatrix(solution);
	}
}

int main(){
	
	KnightTour();
	
}
