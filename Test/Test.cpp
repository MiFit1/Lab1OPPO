// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab1OPPO\date.h"
#include "..\Lab1OPPO\Income.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace TestCore {
    TEST_CLASS(Test)
    {
    public:

        TEST_METHOD(TestReadDate1)
        {
            const auto func = [] {
                auto sin = std::istringstream{"2005.. "};
                Date date;  date.ReadDate(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate2)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "\n" };
                Date date;  date.ReadDate(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate3)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "500.02.29 \"Org5\" 135" };
                Date date;  date.ReadDate(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate4)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "0.05.2 \"Org8\" 1231" };
                Date date;  date.ReadDate(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate5)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "1.08.32 \"Org9\" 145" };
                Date date;  date.ReadDate(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate6)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "1.06.31 \"Org10\" 12314" };
                Date date;  date.ReadDate(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(ReadSource1)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "\"Org12 123 " };
                Income inc;  inc.ReadSource(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(ReadSource2)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "\"Org?12\"" };
                Income inc;  inc.ReadSource(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(ReadSum1)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "" };
                Income inc;  inc.ReadSum(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(ReadSum2)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "8123987192387679679069" };
                Income inc;  inc.ReadSum(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(ReadSum3)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "-1" };
                Income inc;  inc.ReadSum(sin);
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(LeapYearTest)
        {
            Date date;
            Assert::IsTrue(!date.CheckLeapYear(500));
            Assert::IsTrue(date.CheckLeapYear(2004));
            Assert::IsTrue(!date.CheckLeapYear(2003));
        }

        TEST_METHOD(CorrectDate)
        {
            Date date(2003, 1, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 3, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 5, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 7, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 8, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 10, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 12, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 4, 30);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 6, 30);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 9, 30);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 11, 30);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 2, 28);
            Assert::IsTrue(date.CheckDateCorrect());

        }
    };
}
