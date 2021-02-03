// 1로 만들기

#include<iostream>
using namespace std;

const int MAX = 1000000;

int getmin(int a, int b){return a<b?a:b;}

int n, D[MAX+1];

void solution(){
	D[1] = 0; 
	for(int i=2;i<=n;i++){
		D[i] = MAX;
	}
	for(int i=1;i<=n;i++){
		if(i*3 <= n) D[i*3] = getmin(D[i] + 1, D[i*3]);
		if(i*2 <= n) D[i*2] = getmin(D[i] + 1, D[i*2]);
		if(i+1 <= n) D[i+1] = getmin(D[i] + 1, D[i+1]);
	}
}

int main(){
	scanf("%d", &n);
	solution();
	printf("%d\n", D[n]);
}
