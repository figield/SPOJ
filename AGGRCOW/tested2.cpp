#include <cstdio>
#include <algorithm>
int pos[100001];


bool check(int M, int n, int c){
    int cnt = 1;
    for(int b = 0, i = 1; i < n && cnt < c; ++i) 
      if(pos[i] - pos[b] >= M) ++cnt, b = i;  
    return cnt == c;
}

bool check2(int M, int n, int c){
    int cnt = 1;
    for(int b = 0, i = 1; i < n && cnt < c; ++i){      
      if(pos[i] - pos[b] >= M)
        printf("pos[%d](%d) - pos[%d](%d) = %d, ok\n",i,pos[i], b, pos[b],pos[i] - pos[b]),
          ++cnt, 
          b = i;
      else
        printf("pos[%d](%d) - pos[%d](%d) = %d\n",i,pos[i], b, pos[b],pos[i] - pos[b]);
    }
    printf("possible: %s\n",cnt == c ? "TRUE":"FALSE");
    return cnt == c;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    printf("%d\n",T);
    int n,c;
    scanf("%d %d\n", &n, &c);
    printf("%d %d\n", n, c);
    for (int i=0; i < n && scanf("%d", &pos[i])==1 ;i++);
    std::sort(pos,pos + n);
    // binary search
    int L = 1;
    int R = pos[n-1] - pos[0];
    int M;
    while (L < R){
      M = (L + R)>>1; // div by 2
      printf("M(%d,%d)=%d\n", L,R,M);
      if (check(M,n,c)) L = M + 1;
      else R = M;
    }
    printf("M=%d\n", M);
    printf("L=%d, %d\n=================================\n", L, L - !check2(L, n, c));
  }
}
