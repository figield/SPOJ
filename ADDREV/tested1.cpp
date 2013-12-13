#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    string num1;
    string num2;
    cin >> num1 >> num2;
    num1 = string(num1.rbegin(), num1.rend());
    num2 = string(num2.rbegin(), num2.rend());
    sprintf((char*)num1.c_str(), "%d", atoi(num1.c_str()) + atoi(num2.c_str()));
    string str = num1.c_str();    
    cout << atoi(string(str.rbegin(), str.rend()).c_str()) << endl;
  }
}
