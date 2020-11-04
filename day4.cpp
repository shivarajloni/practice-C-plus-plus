#include <iostream>
 
  using namespace std;
  int main() {
    int totalHotDog = 400;
    int totalHotDogperContainer = 8;
    int totalContainer = 0;
     while (totalHotDog >= totalHotDogperContainer)
     {
         totalHotDog -= totalHotDogperContainer;
         totalContainer += 1;
     }
       cout<<"Jack buy total " <<totalContainer<<" containers";
     
     
      return 0;
  }