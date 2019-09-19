/*
cstringdiff.cpp
Project 6
Samuel lamb
cop3330
4/1/2019
*/

#include <cstdlib>
#include <cstringdiff.h>
#include <cctype>

int LexDiff (const char* s1, const char* s2) 
{
  size_t i=0;
  char First = *s1;
  char Second = *s2;
  while (First != '\0' && Second != '\0')
  {
    int Diff = (First - Second);
    if (Diff != 0)
    {
      return Diff;
    }
    ++i;
    First = * (s1 + i);
    Second = * (s2 + i);
  }
  return (First - Second);
}

int DictionaryDiff (const char* s1, const char* s2)
{
  size_t i=0;
  char First = *s1;
  char Second = *s2;
  while (First != '\0' && Second != '\0')
  {
    int Diff = (tolower(First) - tolower(Second));
    if (Diff != 0)
    {
      if (Diff < 0) return -1;
      if (Diff > 0) return 1;
    }
    ++i;
    First = * (s1 + i);
    Second = * (s2 + i);
  }
  return 0;
}

bool LexLT (const char* s1, const char* s2)
{
  return(LexDiff(s1,s2)<0); //uses LexDiff to determins is string 1 is less than string 2
} //if s1 < s2, return true

bool DictionaryLT (const char* s1, const char* s2)
{
  return(DictionaryDiff(s1,s2)<0);
} //if s1 < s2, return true
