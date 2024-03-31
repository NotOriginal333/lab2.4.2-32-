#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.4.2(32)/Set.h"
#include "../lab2.4.2(32)/Set.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetUnitTest
{
	TEST_CLASS(SetUnitTest)
	{
	public:

		TEST_METHOD(TestSetOperations)
		{
			Set set1, set2;

			set1.add('a');
			set1.add('b');
			set1.add('c');

			set2.add('c');
			set2.add('d');
			set2.add('e');

			Assert::IsTrue(set1.contains('a'));
			Assert::IsTrue(set2.contains('d'));
		}
	};
}
