// 파도반 수열

#include<iostream>
using namespace std;

#define MAX 100
typedef long long ll;

ll D[MAX+1] = {0,1,1,1,2,2,};

void solution(){
	for(int i=6;i<=MAX;i++){
		D[i] = D[i-1] + D[i-5];
	}
}

int main(){
	solution();
	
	for(int i=1;i<=100;i++){
		printf("%lld\n", D[i]);
	}
	
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		
		// 출력
		printf("%lld\n", D[n]);
	}
}
