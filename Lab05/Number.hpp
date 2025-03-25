#pragma once

class Number
{
public:
   Number(const char * value, int base); // where base is between 2 and 16 
   Number(const Number&);
   Number& operator=(const Number&);
   Number(Number&&);
   Number& operator=(Number&&) noexcept;
   ~Number();

   void SwitchBase(int newBase);
   void Print() const;
   int  GetDigitsCount() const; // returns the number of digits for the current number
   int  GetBase() const; // returns the current base
   void toBaseTen();
private:
   // operator overloads
   bool operator>(const Number& num) const;
   bool operator<(const Number& num) const;
   bool operator>=(const Number& num) const;
   bool operator<=(const Number& num) const;
   bool operator==(const Number& num) const;
private:
    char* _pNumStr = nullptr;
    size_t _capacity = 0;
    size_t _size = 0;
    int _base = 0;
};
