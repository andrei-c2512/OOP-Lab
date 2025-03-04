#pragma once

class Movie{
public:
   void set_name(const char* name) noexcept;
   void set_year(int year) noexcept;
   void set_length(int minutes) noexcept;
   void set_score(double score) noexcept;
   
   const char* name() const noexcept;
   double score() const noexcept; 
   int year() const noexcept;
   int length() const noexcept;
   int age() const noexcept;

   void print() const noexcept;
private:
    char _name[256];
    int _releaseYear;
    double _IMDBScore;
    int _length; 
};
