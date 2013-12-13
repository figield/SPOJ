#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

int main(){
  int p, Q,groups = 0;
  cin >> Q;
  map <int, int> positions;
  while(Q--){
    cin >> p; 
    positions[p]=1;
    if (positions[p-1]==0 && positions[p+1]==0)
      groups++;
    else if (positions[p-1]==1 && positions[p+1]==1)
      groups--;     
    cout << groups << endl;
  }
  cout << "Justice" << endl;
}
