#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

enum OPERATION{
	MULTIPLY , ADD , FILLER_1 , SUBTRACT , FILLER_2 , DIVIDE , COUNT
};
typedef int (*func)(int, int);

struct Content {
    int p1;
    int p2;
};

int Sum(int a, int b) noexcept;
int Dif(int a, int b) noexcept;
int Mul(int a, int b) noexcept;
int Div(int a, int b);
