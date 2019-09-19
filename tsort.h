/*
tsort.h
Project 6
Samuel lamb
cop3330
4/1/2019
*/

#ifndef _TSORT_H
#define _TSORT_H

#include <iostream>

template <typename T>
void Display (const T* beg, const T* end, char ofc = '\0')
{
  while (beg != end)
  {
    //output
    std::cout << *beg;
    //if ofc isnt null print it
    if (ofc != '\0')
    {
      std::cout << ofc;
    }
    ++beg;
    //increment beg
  }
}

template <typename T>
void Swap (T& a, T& b) //swapping the T type elements
{
  T temp;
  temp = a;
  a = b;
  b = temp;
}

template <typename T>
void InsertionSort (T* beg, T* end) //InsertionSort
{
  //begin i = 1
  T * i = (beg + 1);
  //run i to end
  while(i < end)
  {
    T * I = i;
    while(I > beg && *(I) < *(I - 1)) //swap I is applicable
    {
      Swap(*I, *(I - 1));
      --I; //decrement
    }
    ++i; //increment
  }
}

#endif
