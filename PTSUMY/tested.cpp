#include <cstdio>	
#include <stdlib.h>
using namespace std;

struct listofrows{
  int * row;
  struct listofrows * next;
};

struct listofrows * myheader;
int n;

void printrows(){
  struct listofrows * tmpele = myheader;  
  while (tmpele != NULL){
    for(int j=0;j<n;j++) 
      if (tmpele->row[j]) printf("%d ", tmpele->row[j]);
    printf("\n");    
    tmpele = tmpele->next;
  }
}

bool checksum(int * row){
  int sum = 0;
  for(int i = 0; i < n; i++) sum+= row[i];
  return sum==n;
}

bool checkorder(int k, int lvl, int * row){
  bool ok = true;
  int i = n-1;
  while (row[i]==0) i--;
  for (int j = i-1; j >=0 and ok; j--)
    if(row[j]>row[j+1] or row[j]== 0) ok = false;
  return ok;
}

int * copyrow(int * row){
  int * row2 = (int *) malloc(n * sizeof(int));
  for(int i = 0; i<n; i++) row2[i]=row[i];
  return row2;
}

bool tmp_is_smaller(struct listofrows * tmpele, struct listofrows * newele){
  bool is_smaller = true;
  for(int i=0; i<n and is_smaller ;i++){
    if ((tmpele->row)[i] > (newele->row)[i]){
      is_smaller = false;
      break;
    } else if ((tmpele->row)[i] < (newele->row)[i]) {
      break;
    } 
  }
  return is_smaller;
}

void add_to_chain(struct listofrows * newele){
  struct listofrows * tmpele = myheader;
  struct listofrows * prvtmpele = myheader;
  while (tmp_is_smaller(tmpele,newele)){
    prvtmpele = tmpele;
    tmpele = tmpele->next;
  }
  if (tmpele == prvtmpele){ // first one
    newele->next = myheader;
    myheader = newele;
  } else if (tmpele->next == NULL){ // the last one
    tmpele->next = newele;
  } else {
    prvtmpele->next = newele;
    newele->next = tmpele;
  }
}

void insertrow(int * row){
  if (myheader == NULL){ 
    myheader = new listofrows;
    myheader->row = copyrow(row);
    myheader->next= NULL;
  } else {
    struct listofrows * newele = new listofrows;
    newele->row = copyrow(row);
    add_to_chain(newele);
  }
}

void recloop(int lvl, int * row){  
  if (lvl > 0 ){
    int to = n-lvl + 1; 
    for(int k = (row[lvl]==0 ? 0 : 1); k <=to; k++){
      for(int i = 0; i<(lvl-1); i++) row[i] = 1;
      row[lvl-1] = k;
      if (checkorder(k, lvl, row)){
        if (checksum(row)){
          insertrow(row);
        } else
          recloop(lvl-1, row);
      }
    }
  }
}

int main(){
  int t;
  for(scanf("%d", &t); t--; ){
    scanf("%d", &n);
    int * row = (int *) malloc((n+1) * sizeof(int));
    for (int i = 0; i<n; i++) row[i] = 1;
    row[n] = 0;
    myheader = NULL;
    recloop(n, row);
    printrows();
  }
}
