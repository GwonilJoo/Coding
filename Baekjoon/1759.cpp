#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int l,c;	
char ch[15];
bool visit[15];

void show(){
	for(int i=0;i<c;i++){
		printf("%c ", ch[i]);
	}
	printf("\n");
}

// check: 자음 모음 개수 확인
bool check(int start, string s){ 
	int x = 0, y = 0; // x: 자음 개수, y: 모음 개수
	
	if(s == ""){
		for(int i=start;i<c;i++){
			if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' 
			|| ch[i] == 'o' || ch[i] == 'u')
			{
				x++;
			}
			else{
				y++;
			}
		}
	}
	else{
		for(int i=0;i<s.length();i++){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' 
			|| s[i] == 'o' || s[i] == 'u')
			{
				x++;
			}
			else{
				y++;
			}
		}
	}
	
	
	if(x >= 1 && y >= 2){
		return true;
	}
	else{
		return false;
	}
}

void dfs(int cur, string s){
	// 체크인
	visit[cur] = true;
	s += ch[cur];
	
	// 목적지?
	if(s.length() == l){
		if(check(0, s)){
			cout << s << "\n";
		}
	}
	else{
		// 순회
		for(int i=cur+1;i<c;i++){
			// 갈 수 있는가?
			if(!visit[i]){
				// 간다
				dfs(i, s);
			}
		}
	}
	
	// 체크아웃
	visit[cur] = false;
}

int main(){
	scanf("%d%d", &l, &c);
	
	for(int i=0;i<c;i++){
		scanf(" %c", &ch[i]);
	}
	
	sort(ch, ch+c);
	
	for(int i=0;i<=c-l;i++){
		if(check(i, "")){
			dfs(i, "");
		}
	}
}
