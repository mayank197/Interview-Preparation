#include<bits/stdc++.h>
using namespace std;

// Left Cell, Top Cell, Right Cell, Bottom Cell
int rows[] = {0,-1,0,1};
int cols[] = {-1,0,1,0};

bool Valid(int i, int j){
	if(i==3 && (j==0 || j==2))
		return false;
	return (i>=0 && i<=3 && j>=0 && j<=2);
}

void keyPadFill(multimap<int,int> &mymap){
	char keyPad[4][3] = {
									{'1','2','3'},
									{'4','5','6'},
									{'7','8','9'},
									{'*','0','#'}
	};
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<4;k++){
				int r = i + rows[k];
				int c = j + cols[k];
				if(Valid(i,j) && Valid(r,c))
					mymap.insert(make_pair(keyPad[i][j] - '0', keyPad[r][c] - '0'));
			}
		}
	}
}

int getCount(multimap<int,int> keymap, int i, int n){
	
	// If only 1 digit, then one answer only
	if(n==1)
		return 1;
		
	
	
	
}

int main(){
	
	int n = 3;
	multimap<int,int> mymap;
	keyPadFill(mymap);
	
	int count = 0;
	for(int i=0;i<=9;i++){
		count += getCount(mymap,i,n);
	}
	
	cout<<"\nTotal Combinations : "<<count;
		

}