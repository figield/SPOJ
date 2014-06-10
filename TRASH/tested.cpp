#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

const long unsigned int MAX = 1000000;
bool isnotprime[10000000] = {0};
//long unsigned int Primes[3000000], nPrimes=0;


void init_primes()
{
  for (long unsigned int i = 2; i*i <= 4*MAX; ++i ){
      if (isnotprime[i] == true) continue;
      for (long unsigned int j = 2*i ; j <= 4*MAX; j += i) isnotprime[j] = true; 
  }
  // for(long unsigned int i=0;i<4*MAX;i++)
  //   if(!isnotprime[i]){
  //     Primes[nPrimes++]=i;
  //     cout << i  << ", ";
  //   }
}

// 1 + p^1 + p^2 + ... + p^n 
//\sum_{i=0}^{n}x^i = \frac{x^{n+1}-1}/{x-1}}
long unsigned int sum_pimes(long unsigned int p, int n){
  //long unsigned int sum = 1;
  //for (int i = 1; i<=n; i++) sum += pow(p,i);
  //return sum;
  return (pow(p,n+1)-1)/(p-1);
}

bool if_knum(long unsigned int a){
  if (a==1) return false;
  if (a==2) return true;
  if (a==3) return false;
  if (a==4) return true;
  int count_primes = 0;
  for(int p = sqrt(a);p>=2;p--){
    if(!isnotprime[p] && count_primes < 2){
      for(int n = 2;;n++){
        int aa = pow(p,n);
        if (a == aa){
          if (!isnotprime[(int)((pow(p,n+1)-1)/(p-1))]) count_primes++;}
        else if (aa > a) break;        
      }
    }
  }
  return count_primes == 1;
}

int main(){
  int T;
  int a, b;
  init_primes();
  cin >> T;
  while(T--)
    {
      cin >> a >> b;
      int ai;
      int counter = 0;
      for(ai=a;ai<=b;ai++){        
        if (if_knum(ai)) {
          counter++;
          cout << ai << ", ";
        }
      }
      cout << "Counter:" << counter << endl;
    }
  return 0;
}
