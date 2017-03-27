#include "Polinoms.h"
#include <gtest.h>
#include <string>

using namespace std;

TEST(Polinoms, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom polin());
}

TEST(Polinoms, can_create_polinom_from_string)
{
	string str = "x5+x4";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	str = polin.PolinomToString();

	EXPECT_EQ("x^5+x^4",str);
}

TEST(Polinoms, can_calculate)
{
	string str = "x5y3+2x4-1";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);

	EXPECT_EQ(9,polin.Calculate(1,2,0)) ;
}

TEST(Polinoms, can_differentiate)
{
	string str = "x5y3+2x4-1";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	TPolinom tmpP;
	tmpP = polin.Differentiate(1);
	str = tmpP.PolinomToString();

	EXPECT_EQ("5,000000x^4y^3+8,000000x^3", str);
}

TEST(Polinoms, can_Integrate)
{
	string str = "x5y3+2x4-1";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	TPolinom tmpP;
	tmpP = polin.Integrate(1);
	str = tmpP.PolinomToString();

	EXPECT_EQ("0,166667x^6y^3+0,400000x^5-1,000000x", str);
}