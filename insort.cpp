#include <iostream>
#include <cstdlib>
#include <tsort.h>

const size_t maxSize = 1000;

// int data type
typedef int ElementType;
char ofc=' ';   
// */

/* // char data type
typedef char ElementType;
char ofc='\0';   
// */

/* // std::string data type
#include <string>
typedef std::string ElementType;
char ofc=' ';    
// */

/* // ID data type
#include <id.h> // defines type ID
typedef ID ElementType;
char ofc = '\n';
// */

int main()
{
  ElementType A [maxSize];
  ElementType t;
  size_t count = 0;
  while (count < maxSize && std::cin >> t)
  {
    A[count] = t;
    ++count;
  } 
  std::cout << "<" << " A as entered:  " << '\n';;
  Display(A, A + count,ofc); std::cout << '\n';
  InsertionSort(A, A + count);
  std::cout << "<" << " A after sort:  " << '\n';;
  Display(A, A + count,ofc); std::cout << '\n';
}
