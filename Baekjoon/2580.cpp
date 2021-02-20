#include<iostream>
using namespace std;

struct Info{
	int row, col;
};


Info Empty[81];
int map[10][10], cnt;

void show(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

bool check(int row, int col, int x){
	// row & col
	for(int i=1;i<=9;i++){
		if(map[row][i] == x || map[i][col] == x) return false;
	}
	
	// section
	row = ((row-1)/3)*3+1;
	col = ((col-1)/3)*3+1;
	
	for(int i=row;i<row+3;i++){
		for(int j=col;j<col+3;j++){
			if(map[i][j] == x) return false;
		}
	}
	
	return true;
}

void dfs(int cur, int value){
	// 체크인
	int row = Empty[cur].row;
	int col = Empty[cur].col;
	map[row][col] = value;
	
	// 목적지?
	if(cur == cnt-1){
		show();
		exit(0);
	}
	
	// 순회
	for(int i=1; i<=9; i++){
		// 갈 수 있는가?
		Info next = Empty[cur+1];
		if(check(next.row, next.col, i)){
			// 간다
			dfs(cur+1, i);
		}
	}
	
	// 체크아웃
	map[row][col] = 0;
}

int main(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			scanf("%d", &map[i][j]);
			
			if(map[i][j] == 0){
				Empty[cnt] = {i,j};
				cnt++;
			}
		}
	}
	
	for(int i=1;i<=9;i++){
		Info start = Empty[0];
		if(check(start.row, start.col, i)){
			dfs(0, i);
		}
	}
}
