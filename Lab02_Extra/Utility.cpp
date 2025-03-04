#include "Utility.hpp"
#include <cstring>

int Utility::movie_compare_passed_years(const Movie& m1 , const Movie& m2) noexcept
{
    int lhs = m1.age();
    int rhs = m2.age();

    return cmp(lhs , rhs);
}

int Utility::movie_compare_score(const Movie& m1 , const Movie& m2) noexcept
{
    int lhs = m1.score();
    int rhs = m2.score();

    return cmp(lhs , rhs);
}

int Utility::movie_compare_length(const Movie& m1,  const Movie& m2) noexcept
{
    int lhs = m1.length();
    int rhs = m2.length();

    return cmp(lhs , rhs);
}

int Utility::movie_compare_name(const Movie& m1 , const Movie& m2)  noexcept
{
    return strcmp(m1.name()  , m2.name());
}

int Utility::movie_compare_year(const Movie& m1 , const Movie& m2) noexcept{
    int lhs = m1.year();
    int rhs = m2.year();

    return cmp(lhs , rhs);
}
