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
	setlocale(LC_ALL, "Russian");
	string str = "x5+x4";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	str = polin.PolinomToString();

	EXPECT_EQ("x^5+x^4",str);
}

TEST(Polinoms, can_create_polinom_and_sort)
{
	setlocale(LC_ALL, "Russian");
	string str = "x4+x5";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	str = polin.PolinomToString();

	EXPECT_EQ("x^5+x^4", str);
}

TEST(Polinoms, can_calculate)
{
	setlocale(LC_ALL, "Russian");
	string str = "x5y3+2x4-1";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);

	EXPECT_EQ(9.0,polin.Calculate(1,2,0)) ;
}

TEST(Polinoms, can_summ_2_polinoms)
{
	setlocale(LC_ALL, "Russian");
	string str = "x5y3+2x4-1";
	string str2 = "-x5y3+x2z2+4";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	TPolinom polin2(str2);
	TPolinom tmp = polin + polin2;

	EXPECT_EQ("2,000000x^4+x^2z^2+3,000000", tmp.PolinomToString());
}

TEST(Polinoms, can_multiply_by_var)
{
	setlocale(LC_ALL, "Russian");
	string str = "x5y3+2x4-1";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	polin = polin * 2;

	EXPECT_EQ("2,000000x^5y^3+4,000000x^4-2,000000", polin.PolinomToString());
}

TEST(Polinoms, can_differentiate)
{
	setlocale(LC_ALL, "Russian");
	string str = "x5y3+2x4-1";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	TPolinom tmpP;
	tmpP = polin.Differentiate(1);

	EXPECT_EQ("5,000000x^4y^3+8,000000x^3", tmpP.PolinomToString());
}

TEST(Polinoms, can_Integrate)
{
	setlocale(LC_ALL, "Russian");
	string str = "x5y3+2x4-1";
	TPolinom::SetMaxDegree(10);
	TPolinom polin(str);
	TPolinom tmpP;
	tmpP = polin.Integrate(1);

	EXPECT_EQ("0,166667x^6y^3+0,400000x^5-1,000000x", tmpP.PolinomToString());
}