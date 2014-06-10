#include <cstdio>	
#include <stdlib.h>
using namespace std;


int nextfreerow(int ** tab){
  int i =0;
  while(tab[i][0]!=0) i++;
  return i;
}

void printtab(int n, int ** tab){
  int i=0;
  while(tab[i][0]!=0){
    printf("%d: ",i+1);
    for(int j=0;j<n;j++) 
      printf("%d ", tab[i][j]);
    printf("\n");
    i++;
  }
}

void printrow(int n, int * row){
  for(int j=0;j<n;j++) 
    printf("%d ", row[j]);
  printf("\n");
}

bool checksum(int n, int * row){
  int sum = 0;
  for(int i = 0; i < n; i++) sum+= row[i];
  return sum==n;
}

bool checkorder(int k, int lvl, int n, int * row){
   
  bool ok = true;
  //for (int i = 0; i < lvl-2 and ok; i++) 
  //  if (row[i] > row[i+1] or row[i]==0){ 
  //    ok = false;
  //  }

  //for (int i = lvl; i < n and ok; i++) if (row[i]!=0) ok = false;
  
  return ok;
}

void recloop(int lvl, int * row, int n, int ** tab){  
  //printrow(n,row);
  if (lvl > 0 ){
    for(int k = 0; k <=n; k++){
      row[lvl-1] = k;
      if (checkorder(k, lvl, n, row)){
        if (checksum(n,row)){
          printrow(n,row);
        }
        recloop(lvl-1, row, n, tab);
      }
    }
  }
}

int * make_row(int n){
  return (int *) malloc(n * sizeof(int));
}

int main(){
  int t;
  for(scanf("%d", &t); t--; ){
    int n;
    scanf("%d", &n);
    int ** tab = (int **)malloc(100 * sizeof(int *)); // dynamically ?
    //tab[0] = make_row(n);
    int * row = make_row(n+1);
    //for (int i = 0; i<n; i++) tab[0][i] = 1;
    for (int i = 0; i<n+1; i++) row[i] = 1;
    //printtab(n,tab);
    recloop(n, row, n, tab);
    //printtab(n,tab);	
  }
}
