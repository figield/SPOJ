#include <cstdio>


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

int move(int &a, int &b){
  __asm__ __volatile__("movl %1, %%eax;\n\t" 
                        "movl %%eax, %0;\n\t"
                       :"=r"(b)        /* output */
                       :"r"(a)         /* input */
                       :"%eax"         /* clobbered register */
                       ); 
  return b;
}

int main(){

  printf("\n==========================\nsub(A,B)'==%d\n", sub(5,2));

  printf("foo+bar=%d\n", add(100, 999));
  int A = 11;
  printf("A=%d\n", A);
  int B = 99;
  printf("B=%d\n", B);
  printf("A+B=%d\n", add(A, B));
  printf("A=%d\n", A);
  printf("B=%d\n", B);



  printf("\n==========================\nmove(A,B)'==%d\n", move(A,B));
  printf("A'=%d\n", A);
  printf("B'=%d\n", B);
  printf("A''=%d\n", A=222);
  printf("B''=%d\n", B);
  return 0;
}


