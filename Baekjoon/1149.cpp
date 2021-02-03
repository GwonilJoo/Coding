// RGB거리

#include<iostream>
using namespace std;

const int MAX = 1000;
int getmin(int a, int b){return a<b? a:b;}

int n, D[MAX+1][3];

int solution(){
	for(int i=2;i<=n;i++){
		D[i][0] += getmin(D[i-1][1], D[i-1][2]);
		D[i][1] += getmin(D[i-1][0], D[i-1][2]);
		D[i][2] += getmin(D[i-1][0], D[i-1][1]);
	}
	
	return getmin(D[n][0], getmin(D[n][1], D[n][2]));
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d", &D[i][0], &D[i][1], &D[i][2]);
	}
	
	printf("%d\n", solution());
}
