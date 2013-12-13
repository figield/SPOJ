#include <cstdio>
#include <cstring>
const int LEN = 200;
char line[LEN];

int add(int a, int b){
  __asm__ __volatile__("addl  %%ebx,%%eax"
                       :"=a"(a)
                       :"a"(a), "b"(b)
                       );
  return a;
}


int sub(int a, int b){
  __asm__ __volatile__("subl  %%ebx,%%eax"
                       :"=a"(a)
                       :"a"(a), "b"(b)
                       );
  return a;
}

int main(){
  int T;
  scanf("%d\n", &T);
  while(T--){
    while(strlen(fgets(line, LEN, stdin))<3);
    int i=0,a,b,c;
    for(char *p=line;*p!='m';p++) if (*p=='+'||*p=='=') i++;
    if (i == 0){
      sscanf(line, "%*s + %d = %d",&b, &c);
      a = sub(c, b);
    } else if (i==1){
      sscanf(line, "%d + %*s = %d",&a, &c);
      b = sub(c, a);
    } else {
      sscanf(line, "%d + %d = %*s",&a, &b);
      c = add(a, b);
    }
    printf("%d + %d = %d\n",a,b,c);    
  }
}
