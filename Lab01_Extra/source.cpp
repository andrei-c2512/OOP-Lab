#include "header.h"
#include <assert.h>
#include <iostream>
#include <conio.h>

int Sum(int a, int b) noexcept { return a + b; }
int Dif(int a, int b) noexcept { return a - b; }
int Mul(int a, int b) noexcept { return a * b; }
//nu il marchez cu noexcept in caz de apare impartire la 0 , bine , in programul asta nu are cum sa apara dar na
//in caz de , you know 
int Div(int a, int b) {
	assert(b);
	return a / b;
}
//marchez functia asa deoarece poate poate o sa-si ia optimize away la compilare. Bine , oricum , fiindca input-ul e stiut la compilare , cam
//tot poate fi facut la compilare
constexpr int DoNothing([[maybe_unused]] int a ,[[maybe_unused]] int b) noexcept { return 0; }


int main()
{
	try{
		std::string_view input = "---H***E+++L+++L///O---P+++O/+-**O---";
		func Operatori[(int)OPERATION::COUNT] = {&Mul,&Sum , &DoNothing , &Dif , &DoNothing ,  &Div}; 
		Content caseArr[(int)OPERATION::COUNT] = { { 3 , 3 } , { 7 , 5 } , {0 , 0} , { 10 , 1} , {0 , 0} , { 8 , 4} } ;
		int S = 0;
		std::cout <<"Test\n";
		for (const char& ch : input)
		{
			int idx = int(ch) - 42;
			if( idx >= 0 && idx < (int)OPERATION::COUNT)
			{
				const auto& content = caseArr[idx];
				S = S + Operatori[idx](content.p1 , content.p2);
			}
		}

		//S=337
		std::cout << "Result: " << S << '\n';
		printf("S = %d\n", S);

		while(_kbhit() == false);
	}
	catch(std::exception& e){
		std::cout << e.what() << '\n';
	}
	return 0;
}
