#include<bits/stdc++.h>
using namespace std;

// Rat in a Maze (Backtracking)
#define N 4

void PrintSolution(int arr[N][N]){
	cout<<"\nSolution : \n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}	
}

bool Safe(int i, int j, int mat[N][N]){
	return (i>=0 && j>=0 && i<N && j<N && mat[i][j]==1);
}

bool solveMazeUtil(int maze[N][N], int i, int j, int sol[N][N]){
	if(i==N-1 && j==N-1){
		sol[i][j] = 1;
		return true;
	}
	if(Safe(i,j,maze)){
		sol[i][j] = true;
		
		if(solveMazeUtil(maze,i,j+1,sol))
			return true;
			
		if(solveMazeUtil(maze,i+1,j,sol))
			return true;
		
		// Backtrack
		sol[i][j] = 0;
		return false;
	}
	return false;
}

void solveMaze(int maze[N][N]){
	int sol[N][N];
	memset(sol,0,sizeof sol);
	
	if(solveMazeUtil(maze,0,0,sol)==false){
		cout<<"\nSolution doesn't exist";
		return;
	}
	else{
		PrintSolution(sol);
	}
}

int main(){
	
	int maze[N][N] = {
								{1,0,0,0},
								{1,1,0,1},
								{0,1,0,0},
								{1,1,1,1}
	};
	
	solveMaze(maze);
	
}