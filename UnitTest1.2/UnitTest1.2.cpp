

#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.2/SetInt.h"
#include "../Lab_1.2/SetInt.cpp"
#include "../Lab_1.2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12
{
	TEST_CLASS(UnitTest12)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			SetInt set[2] = {
						SetInt(5,	1, 2, 3, 4, 5),
						SetInt(3,	1, 2, 6)
			};
			SetInt* _merge = SetInt::merge(set[0], set[1]);
			const int out_merge[] = { 1, 2, 3, 4, 5, 6 };

			Assert::AreEqual(memcmp(out_merge, _merge->GetSet(), _merge->GetSize() * sizeof(int)), 0);

		}
	};
}
