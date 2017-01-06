//#include "stdafx.h"
#include "CppUnitTest.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "calc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace calc_test
{		
	TEST_CLASS(calctests)
	{
	public:
		
		TEST_METHOD(ArithmeticOperators)
		{
         char *teststrs[4] = {"calc", "1", "2", "+"};
         double result = runcalcs(4, teststrs);
         Assert::AreEqual(3.0, result, L"addition operator");

         teststrs[3] = "-";
         result = runcalcs(4, teststrs);
         Assert::AreEqual(-1.0, result, L"subtraction operator");

         teststrs[3] = "x";
         result = runcalcs(4, teststrs);
         Assert::AreEqual(2.0, result, L"multiplication operator");

         teststrs[3] = "/";
         result = runcalcs(4, teststrs);
         Assert::AreEqual(0.5, result, L"division operator");
      }

      TEST_METHOD(MathFunctions)
      {
         char *teststrs[5] = { "calc", "100", "log", "", "" };
         double result = runcalcs(3, teststrs);
         Assert::AreEqual(2.0, result, L"log10");

         teststrs[2] = "ln";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(4.605170186, result, 0.000000001, L"log");

         teststrs[1] = "1";
         teststrs[2] = "invlog";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(10.0, result, L"invlog10");

         teststrs[2] = "invln";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(2.718281828, result, 0.000000001, L"invlog");

         teststrs[1] = "pi";
         teststrs[2] = "2";
         teststrs[3] = "/";
         teststrs[4] = "sin";
         result = runcalcs(5, teststrs);
         Assert::AreEqual(1.0, result, L"sin");

         teststrs[1] = "0";
         teststrs[2] = "cos";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(1.0, result, L"cos");

         teststrs[1] = "pi";
         teststrs[2] = "4";
         teststrs[3] = "/";
         teststrs[4] = "tan";
         result = runcalcs(5, teststrs);
         Assert::AreEqual(1.0, result, 0.000000001, L"tan");

         teststrs[1] = "1";
         teststrs[2] = "asin";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(M_PI_2, result, L"asin");

         teststrs[1] = "1";
         teststrs[2] = "acos";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(0.0, result, L"acos");

         teststrs[1] = "1";
         teststrs[2] = "atan";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(M_PI_4, result, L"atan");

         teststrs[1] = "9";
         teststrs[2] = "sqrt";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(3.0, result, L"sqrt");

         teststrs[1] = "8";
         teststrs[2] = "sq";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(64.0, result, L"sq");

         teststrs[1] = "8";
         teststrs[2] = "inv";
         result = runcalcs(3, teststrs);
         Assert::AreEqual(0.125, result, L"inv");

         teststrs[1] = "2";
         teststrs[2] = "4";
         teststrs[3] = "y^z";
         result = runcalcs(4, teststrs);
         Assert::AreEqual(16.0, result, L"y^z");
      }

      // test for extra chars in input
      // test for mismatch between operators and arguments
   };
}