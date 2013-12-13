#include <cstdio>
int candies[10000];

int main(){
  for(int Avg, Mvs, N, SUM; scanf("%d", &N) && N != -1; ){
    SUM = 0;
    Mvs = 0;
    for (int p,i=0; i<N; i++){
      scanf("%d", &p);
      candies[i]=p;
      SUM+=p;      
    }
    if (!(SUM % N)){
      Avg = SUM / N;
      for (int j=0; j<N; j++)
        Mvs += Avg < candies[j] ? candies[j] - Avg : 0;
      printf("%d\n", Mvs);
    } else printf("-1\n");
  }
}
