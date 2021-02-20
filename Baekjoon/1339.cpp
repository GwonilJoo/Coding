#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int n, cnt[26], ans;
string str[10];

void show(){
	for(int i=0;i<n;i++){
		cout << str[i] << endl;
	}
	
	for(int i=0;i<21;i++){
		printf("%d ", cnt[i]);
	}	
	printf("\n");
}

bool compare(int a, int b){
	return a > b;
}

void solution(){
	for(int i=0;i<n;i++){
		for(int j=0;j<str[i].length();j++){
			char ch = str[i][j];
			cnt[ch-'A'] += pow(10, str[i].length() - j - 1);
		}
	}
	
	sort(cnt, cnt+26, compare);
	
	for(int i=0;i<=9;i++){
		ans += cnt[i] * (9-i);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		cin >> str[i];
	}
	
	solution();
	
	printf("%d\n", ans);
	//show();
}
