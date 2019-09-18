#include<bits/stdc++.h>
using namespace std;

int countStrings(int n, int last_digit){
	
	if(n==0) return 0;
	
	if(n==1){
		// If last digit is 0, we can have 2 strings "0" and "1"
		if(last_digit==0)	
			return 2;
		if(last_digit==1)
			return 1;
	}
	
	if(last_digit==0)
		return countStrings(n-1,0) + countStrings(n-1,1);
	
	return countStrings(n-1,0);
}

int main(){
	
	int n;
	cin>>n;
	
	cout<<"\nNumber of "<<n<<" digit binary strings without consecutive 1's are : ";
	cout<<countStrings(n,0);		// Sending last digit as 0
	
}