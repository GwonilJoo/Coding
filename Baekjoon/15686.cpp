#include<iostream>
#include<algorithm>
using namespace std;

struct Info{
	int row, col, dist_sum;
};

Info chicken[13];
int n, m, cnt, ans;
int map[50][50];

int getabs(int a){return a<0?-a:a;}

void show(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

bool compare(Info a, Info b){
	return a.dist_sum < b.dist_sum;
}

void solution(){
	for(int i=0;i<cnt;i++){
		for(int row=0;row<n;row++){
			for(int col=0;col<n;col++){
				if(map[row][col] != 1) continue;
				
				chicken[i].dist_sum += getabs(chicken[i].row - row);
				chicken[i].dist_sum += getabs(chicken[i].col - col);
			}
		}
	}
	
	sort(chicken, chicken+cnt, compare);
	
	for(int i=m;i<cnt;i++){
		map[chicken[i].row][chicken[i].col] = 0;
	}
	
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &map[i][j]);
			
			if(map[i][j] == 2){
				chicken[cnt] = {i,j,0};
				cnt++;
			}
		}
	}
	
	//show();
}
