#include <cstdio>

int main(){
  for(int A,B; scanf("%d %d", &A, &B) == 2 && A != -1 && B != -1; )
    printf("%d+%d%s%d\n",A,B, A==1 || B ==1 ? "=" : "!=",A+B);
}
