#include <cstdio>
#include <algorithm>
int pos[100001];

bool check(int M, int n, int c){
    int cnt = 1;
    for(int b = 0, i = 1; i < n && cnt < c; ++i) 
      if(pos[i] - pos[b] >= M) ++cnt, b = i;  
    return cnt == c;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int n,c;
    scanf("%d %d\n", &n, &c);
    for (int i=0; i < n && scanf("%d", &pos[i])==1 ;i++);
    std::sort(pos,pos + n);
    // binary search
    int L = 1;
    int R = pos[n-1] - pos[0];
    int M;
    while (L < R){
      M = (L + R)>>1; // div by 2
      if (check(M,n,c)) L = M + 1;
      else R = M;
    }
    printf("%d\n", L - !check(L, n, c));
  }
}
