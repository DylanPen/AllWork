#include <iostream>

using namespace std;

void function(int num, int ctr, int &r) {
  int i;
  for(i = 2;i <= num/2; i++){
    if(num % i==0){ //if remainder is 0 then adds 1 to ctr to flag that there is a prime number
      ctr++;
      break;
    }
  }
  if(ctr == 0 && num != 1)
    r = 1;
  
  else
    r = 0;
}

int main(){

  int num, ctr = 0, r = -1;
  cout << "Input a number: ";
  cin >> num;
  
  function(num, ctr, r);
  cout << r << endl;; //print 1 or 0, 1 being its a prime number, 0 being that its not

  return 0;
}