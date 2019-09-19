/*
product.cpp
Project 6
Samuel lamb
cop3330
4/1/2019
*/

#include <cstringdiff.h>
#include <product.h>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>

Product::Product() : code_(0), cost_(0.0) //constructor
{
    SetName("#"); //name ser to "#"
}

Product::Product(const char * name, uint32_t code, float cost) : code_(code), cost_(cost)
{
   SetName(name);
}

Product::Product(const Product& p) : code_(p.GetBarCode()), cost_(p.GetCost())
{
    SetName(p.GetName());
}

void Product::SetName(const char * name)
{
    name_ = new char[std::strlen(name)];
    std::strcpy(name_, name);
}

void Product::SetCost(float cost)
{
    cost_ = cost;
}

void Product::SetBarCode (uint32_t code)
{
    code_ = code;
}

const char * Product::GetName() const
{
    return name_;
}

uint32_t Product::GetBarCode() const
{
    return code_;
}

float Product::GetCost() const
{
    return cost_;
}

std::ostream& operator << (std::ostream& os , const Product& p)
{
  std::ios_base::fmtflags flags = os.flags();
  os.setf(std::ios::fixed | std::ios::showpoint); // prep for $ output
  os.precision(2);
  os << p.GetName() << '\t' 
     << std::hex << std::uppercase << std::setfill('0') << std::setw(8) // prep for hex output
     << p.GetBarCode() 
     << std::dec << std::setfill(' ') << '\t'          // return dec output
     << p.GetCost();
  os.setf(flags); // return flags to previous states
  return os;
}

int c = 122;
std::istream& operator >> (std::istream& is, Product& p)
{
    char name[c];
    uint32_t code;
    float cost;
    is >> std::setw(c) >> name;
    is >> std::hex >> code;
    is >> cost;
    p.SetName(name);
    p.SetBarCode(code);
    p.SetCost(cost);
    return is;
}

bool operator < (const Product& p1, const Product& p2)
{
    int d = DictionaryDiff(p1.GetName(), p2.GetName()); //comparing names of products
    if (d<0) //specifications given within the project page
    {
        return true;
    }
    if (d>0)
    {
        return false;
    }
    return (p1.GetCost() < p2.GetCost()); //if the names are the same look at the cost
}
