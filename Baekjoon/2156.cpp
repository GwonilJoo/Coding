// 포도주 시식

#include<iostream>
using namespace std;

const int MAX = 10001;

int n, a[MAX], D[MAX];

int getmax(int a, int b){return a>b?a:b;}

void solution(){
	D[1] = a[1];
	D[2] = a[1]+a[2];

	for(int i=3;i<=n;i++){
		// 1. 이전 와인을 마시는 경우: a[i] + a[i-1] + D[i-3]
		// 2. 전전 와인을 마시는 경우: a[i] + D[i-2]
		// 3. 현재 와인을 안마시는 경우: D[i-1]
		
		D[i] = a[i] + getmax(a[i-1] + D[i-3], D[i-2]);
		D[i] = getmax(D[i], D[i-1]);
	}
}

void show(){
	for(int i=1;i<=n;i++){
		printf("%d ", D[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}

	solution();
	show();
	
	printf("%d\n", D[n]);
	return 0;
}
