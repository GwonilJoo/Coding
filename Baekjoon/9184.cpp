// 신나는 함수 실행

#include<iostream>
using namespace std;

int D[101][101][101];
bool visit[101][101][101];

void func(int a, int b, int c){
  int A = a+50, B = b+50, C = c+50; // -50~50 이므로 인덱스를 50씩 더하기
  
  if(a <= 0 || b <= 0 || c <= 0) {
    D[A][B][C] = 1; 
  }
  
  else if(a>20 || b>20 || c>20){
    if(!visit[70][70][70]){		// 방문한 적이 없다면 값이 없으므로 재귀호출
      func(20,20,20);
    }
    
    D[A][B][C] = D[70][70][70]; 
  }
  
  else if(a<b && b<c){
    if(!visit[A][B][C-1]) {
      func(a,b,c-1); 
    }
    if(!visit[A][B-1][C-1]){
      func(a,b-1,c-1); 
    }
    if(!visit[A][B-1][C]){
      func(a,b-1,c); 
    }
    
    D[A][B][C] = D[A][B][C-1] + D[A][B-1][C-1] - D[A][B-1][C]; 
  }
  
  else{
    if(!visit[A-1][B][C]) {
      func(a-1,b,c); 
    }
    if(!visit[A-1][B-1][C]){
      func(a-1,b-1,c); 
    }
    if(!visit[A-1][B][C-1]){
      func(a-1,b,c-1); 
    }
    if(!visit[A-1][B-1][C-1]){
      func(a-1,b-1,c-1); 
    }
    
    D[A][B][C] = D[A-1][B][C] + D[A-1][B-1][C] + D[A-1][B][C-1] - D[A-1][B-1][C-1];
  }
  
  visit[A][B][C] = true; // 방문 체크
}


int main(){
  // init
  for(int i=-50;i<=50;i++)
    for(int j=-50;j<=50;j++)
      for(int k=-50;k<=50;k++){
        if(!visit[i+50][j+50][k+50])
          func(i,j,k);
      }

  while(true){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    
    if(a==-1 && b ==-1 && c==-1) break;
    
    printf("w(%d, %d, %d) = %d\n", a,b,c,D[a+50][b+50][c+50]); // 인덱스는 0부터이므로 50 더하기
  }

  return 0;
}
