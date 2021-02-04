// 쉬운 계단 수

#include<iostream>
using namespace std;

typedef long long ll;
const ll INF = 1000000000;

ll D[101][10];

ll solution(int n){
	// n==1인 경우의 초기화
	for(int i=1;i<=9;i++){
		D[1][i] = 1;
	}
	
	// n==2부터 시작
	for(int i=2;i<=n;i++){
		for(int j=0;j<=9;j++){
			// 0이 오려면 이전 숫자는 1
			if(j==0){
				D[i][j] = D[i-1][j+1];
			}
			// 9가 오려면 이전 숫자는 8
			else if(j==9){
				D[i][j] = D[i-1][j-1];
			}
			// j가 오려면 이전 숫자는 j-1,j+1
			else{
				D[i][j] = (D[i-1][j-1] + D[i-1][j+1])%INF; // 오버플로우 방지
			}
		}
	}
	
	ll ans = 0;
	for(int i=0;i<=9;i++){
		printf("%lld ", D[n][i]);
		ans += D[n][i];
	}
	printf("\n");
	return ans%INF;
}

int main(){
	int n;
	scanf("%d", &n);
	
	printf("%lld\n", solution(n));
}
