#include <iostream>




int main() {



  using namespace std;


  std::cout << "Hello World!\n";
  int size = 5;
  int list[size];
  int * ptr = list;
  for (int i = 0; i < size; ++i) {
      list[i] = 10 * i;
  }
  
  for (int i = 0; i < size; ++i) {
      std::cout << list[i] << ',';
      std::cout << ptr << '\n';
      ptr++;
      
  }
  int count = 0;
  ptr = list;
  while(1) {
    ptr++;
    std::cout << ptr << '\n';

    std::cout << *ptr << endl;
    std::cout << "COUNT IS :" << count << endl;
    std::cout << "BYTES OF MEMORY IS :" << count*4 << endl;

    ++count;
  }
  std::cout << "I can read any memory?" << endl;
   
}
