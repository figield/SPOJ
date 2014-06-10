#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int is_prime(unsigned long p)
{
  unsigned long r = sqrt(p);
  unsigned long i = 2;
  while(i <= r) if(!(p % i++)) return false;
  return true;
}

// 1 + p^1 + p^2 + ... + p^n 
unsigned long sum_pimes(int p, int n){
  unsigned long sum = 1;
  for (int i = 1; i<=n; i++) sum += pow(p,i);
  return sum;
}

bool if_knum(unsigned long a){
  if (a==1) return false;
  if (a==2) return true;
  if (a==3) return false;
  if (a==4) return true;
  int count_primes = 0;
  for(int p = sqrt(a);p>=2;p--){
    if(is_prime(p) && count_primes < 2){
      for(int n = 2;;n++){
        int aa = pow(p,n);
        if (a == aa){
          if (is_prime(sum_pimes(p,n))) count_primes++;}
        else if (aa > a) break;        
      }
    }
  }
  return count_primes == 1;
}

int main(){
  int T;
  unsigned long a, b;
  cin >> T;
  while(T--)
    {
      cin >> a >> b;
      unsigned long ai;
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
