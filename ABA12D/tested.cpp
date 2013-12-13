#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
typedef int LUI;
const LUI MAX = 1000000;
bool isnotprime[10000000] = {1,1};
LUI Primes[3000000], nPrimes=0;
LUI knum[100];
int kn = 0;

void init_primes()
{
  for (LUI i = 2; i*i <= 4*MAX; ++i ){
      if (isnotprime[i] == true) continue;
      for (LUI j = 2*i ; j <= 4*MAX; j += i) isnotprime[j] = true; 
  }
  for(LUI i=0;i<4*MAX;i++)
    if(!isnotprime[i]){
      Primes[nPrimes++]=i;    
    }
}


bool if_knum(LUI a){
  if (a==1) return false;
  if (a==2) return true;
  if (a==3) return false;
  if (a==4) return true;
  int count_primes = 0;
  LUI nr = 0; 
  int sqrta = sqrt(a);
  while((Primes[nr] <= sqrta) && (count_primes < 2)){
    LUI p = Primes[nr++];
    LUI aa = p*p;
    int n = 2;
    while(aa <= a){
      if ((a == aa) && (!isnotprime[(LUI)((pow(p,n+1)-1)/(p-1))])) count_primes++;
      aa = aa * p;
      n++;
    }
  }
  return count_primes == 1;
}

void find_kn(){
  knum[kn++]=2;
  for(LUI i=2;i*i<=MAX;i++){        
    if (if_knum(i*i)) {
      knum[kn++] = i*i;
    }
  }
}

int main(){
  int T;
  int a, b;
  init_primes();
  find_kn();
  cin >> T;
  while(T--){
    cin >> a >> b;
    int ai,bi; 
    for(ai=0;ai<kn && knum[ai]<a;ai++);	
    for(bi=kn-1;bi>=0 && knum[bi]>b;bi--);
    cout << bi-ai+1 << endl;
  }
  return 0;
}
