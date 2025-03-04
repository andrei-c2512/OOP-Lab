#include "Movie.h"


namespace Utility{
    template <typename T>
    int cmp(const T& lhs , const T& rhs) noexcept{
        if(lhs > rhs)
            return 1;
        else if(lhs == rhs)
            return 0;
        else 
            return -1;
    }
    int movie_compare_year(const Movie& m1 , const Movie& m2) noexcept;
    int movie_compare_score(const Movie& m1 , const Movie& m2) noexcept;
    int movie_compare_length(const Movie& m1 , const Movie& m2) noexcept;
    int movie_compare_passed_years(const Movie& m1 , const Movie& m2) noexcept;
    int movie_compare_name(const Movie& m1 , const Movie& m2) noexcept;
}
