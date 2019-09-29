#include<bits/stdc++.h>
using namespace std;

#define N 8

void PrintSolution(int mat[N][N]){
	cout<<"\nSolution : \n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool Safe(int board[N][N], int row, int col){
	for(int i=0;i<col;i++){
		if(board[row][i])
			return false;
	}
	for(int i=row,j=col;i>=0 && j>=0; i--,j--){
		if(board[i][j])
			return false;
	}	
	for(int i=row,j=col;j>=0 && i<N; i++,j--){
		if(board[i][j])
			return false;
	}
	return true;
}

bool SolveNQueen_Helper(int board[N][N], int col){
	if(col>=N)
		return true;
	for(int i=0;i<N;i++){
		if(Safe(board,i,col)){
			board[i][col] = 1;
			if(SolveNQueen_Helper(board,col+1))
				return true;
			// Backtrack
			board[i][col] = 0;
		}
	}
	return false;
}

void SolveNQueen(){
	
	int chessBoard[N][N];
	memset(chessBoard,0,sizeof chessBoard);
	
	if(SolveNQueen_Helper(chessBoard,0)==false){
		cout<<"\nNo Solution exists";
		return;
	}
	else{
		PrintSolution(chessBoard);
	}
}

int main(){
	
	SolveNQueen();
	
}