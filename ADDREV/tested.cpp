#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char num1[100];
char num2[100];

int reverse(char * word){
  int len=strlen(word);
  char temp;
  for (int i=0;i<len/2;i++){
      temp=word[i];
      word[i]=word[len-i-1];
      word[len-i-1]=temp;
  }
  return atoi(word);
}
  
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%s %s\n", num1, num2);
    sprintf(num1, "%d", reverse(num1) + reverse(num2));
    printf("%d\n", reverse(num1));
  }
}
