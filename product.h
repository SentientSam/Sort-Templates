/*
product.h
Project 6
Samuel lamb
cop3330
4/1/2019
*/

#ifndef _Product_H
#define _Product_H

#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <string>


class Product //Initializing a new class, Product
{
    public: 
    Product(); //Constructor
    Product(const char *, uint32_t, float); //3 Argument-Constructor
    Product(const Product &p); //Copy Constructor
    void SetName(const char *); //set name
    void SetBarCode (uint32_t); //set barcode
    void SetCost(float); //set cost
    const char * GetName() const;
    uint32_t GetBarCode() const; //returns bu value
    float GetCost() const;
    private:
    char * name_;
    uint32_t code_; //name, barcode (code), and cost to be used by product
    float cost_;
};

std::ostream& operator<< (std::ostream& os, const Product& p);
std::istream& operator>> (std::istream& is, Product& p);
bool          operator<  (const Product& p1, const Product& p2);


#endif
