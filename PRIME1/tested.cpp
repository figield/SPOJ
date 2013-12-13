#include <iostream>
#include <stdlib.h>

using namespace std;
typedef unsigned long int LUI;
bool primes[100001];

void find_primes(LUI m, LUI n){
  LUI count=0;
  for (LUI i=0;i<n-m+1;i++) primes[i]=0;
  for (LUI p=2;p*p<=n;++p){
    if (p != 2 && p % 2 == 0) continue;
    LUI less = m / p;
    less *= p;
    for (int j = less;j <= n; j += p)
      if (j != p && j >= m)
        primes[j-m] = 1;
  }
  for(LUI i=0;i<n-m+1;i++)
    if(primes[i]==0 && m + i !=1)
      cout << m+i << endl;
  cout << endl;
}

int main(){
  int T;
  LUI a, b;
  cin >> T;
  while(T--){
    cin >> a >> b;
    find_primes(a,b);
  }
  return 0;
}
