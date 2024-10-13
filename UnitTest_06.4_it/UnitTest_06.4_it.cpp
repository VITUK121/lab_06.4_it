#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06.4_it/lab_06.4_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest064it
{
	TEST_CLASS(UnitTest064it)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { -1,0.31,8,-14,-0.222,-0.77,4 };
			double res = sum_between_two(arr, 7);
			Assert::AreEqual(res,8.31);
		}
	};
}
