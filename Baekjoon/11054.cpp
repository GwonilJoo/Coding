// 가장 긴 증가하는 부분 수열

#include<iostream>
using namespace std;

const int MAX = 1000;

int a[MAX+1], n, dp[MAX+1], ans;

int getmax(int a, int b){return a>b?a:b;}

void solution(){
	for(int i=1;i<=n;i++){
		// 이전의 숫자들과 비교. 자신보다 작으면 dp 비교
		for(int j=1;j<i;j++){
			if(a[i] > a[j]){
				dp[i] = getmax(dp[i], dp[j]+1);
			}
		}
		
		ans = getmax(dp[i], ans); // update ans
	}
}

void show(){
	for(int i=1;i<=n;i++){
		printf("%d ", dp[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		dp[i] = 1;
	}
	
	solution();
	show();
	
	printf("%d\n", ans);
	return 0;
}
