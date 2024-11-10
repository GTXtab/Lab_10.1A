#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.1 A/Lab_10.1 A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{ 
            Student students[3] = {
                { "Ivanenko", 2, RI, 3, 4, 5 },
                { "Petrenko", 3, IK, 2, 3, 4 },
                { "Sydorenko", 1, SSHI, 5, 5, 5 }
            };
            int N = sizeof(students) / sizeof(Student);

            int expectedIndex = 1; 
            int actualIndex = FindStudentWithMinAverage(students, N);

            Assert::AreEqual(expectedIndex, actualIndex);
        }
	};
}