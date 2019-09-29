#include<bits/stdc++.h>
using namespace std;

#define R 5
#define C 5

bool Safe(int mat[R][C], int row, int col, bool visited[R][C]){
	return (row>=0 && row<C && col>=0 && col<C && mat[row][col]==1 && !visited[row][col]);
}

void Display(int mat[R][C]){
	cout<<"\nMatrix : \n";
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

void DFS(int mat[R][C], int row, int col, bool visited[R][C]){
	
	int rows[] = {-1,-1,-1,0,0,1,1,1};
	int cols[] = {-1,0,1,-1,1,-1,0,1};
	
	cout<<"\nWe're at row "<<row<<" and column "<<col;			// Will help track DFS status
	
	visited[row][col] = true;
	
	for(int k=0;k<8;k++){
		if(Safe(mat,row+rows[k],col+cols[k],visited))
			DFS(mat,row+rows[k],col+cols[k],visited);
	}
	
}

void BFS(int mat[R][C], int row, int col, bool visited[R][C]){
	
	int rows[] = {-1,-1,-1,0,0,1,1,1};
	int cols[] = {-1,0,1,-1,1,-1,0,1};
	
	queue<pair<int,int>> q;
	q.push(make_pair(row,col));
	visited[row][col] = true;
	
	while(!q.empty()){
		
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		
		for(int k=0;k<8;k++){
			if(Safe(mat,a+rows[k],b+cols[k],visited)){

				visited[a+rows[k]][b+cols[k]] = true;
				q.push(make_pair(a+rows[k], b+cols[k]));
				
			}
		}
	}
}

int Islands(int mat[R][C]){
	
	bool visited[R][C];
	memset(visited,false,sizeof(visited));

	int count = 0;
		
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			
			if(mat[i][j]==1 && !visited[i][j]){
				
				// DFS(mat,i,j,visited);							// Using DFS
				
				BFS(mat,i,j,visited);							// Using BFS
				
				count++;
			}				
		}
	}
	
	return count;
}

int main(){
	
	int mat[R][C] = {	{1,1,0,0,0},
							{0,1,0,0,1},
							{1,0,0,1,1},
							{0,0,0,0,0},
							{1,0,1,0,1}};
	
	Display(mat);
	
	cout<<"\nNumber of Islands : "<<Islands(mat)<<endl;
	
}