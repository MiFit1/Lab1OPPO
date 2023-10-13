#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab1OPPO\date.h"
#include "..\Lab1OPPO\Income.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(TestException1)
		{
			Date date;
			std::string TextError = "Ошибка при чтении даты, не удалось преобразовать в число.";
			try {
				std::string textToCheck = "2005.. ";
				std::istringstream istStr(textToCheck);
				date.ReadDate(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}
		
		TEST_METHOD(TestException2)
		{
            Date date;
			std::string TextError = "Не удалось считать дату, так как строка пустая.";
			try {
				std::string textToCheck = "\n";
				std::istringstream istStr(textToCheck);
				date.ReadDate(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(TestException3)
		{
			Date date;
			std::string TextError = "Неккоректная дата.";
			try {
				std::string textToCheck = "500.02.29 \"Org5\" 135";
				std::istringstream istStr(textToCheck);
				date.ReadDate(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(TestException4)
		{
            Date date;
			std::string TextError = "Неккоректная дата.";
			try {
				std::string textToCheck = "0.05.2 \"Org8\" 1231";
				std::istringstream istStr(textToCheck);
                date.ReadDate(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(TestException5)
		{
            Date date;
			std::string TextError = "Неккоректная дата.";
			try {
				std::string textToCheck = "1.08.32 \"Org9\" 145";
				std::istringstream istStr(textToCheck);
                date.ReadDate(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(TestException6)
		{
            Date date;
			std::string TextError = "Неккоректная дата.";
			try {
				std::string textToCheck = "1.06.31 \"Org10\" 12314";
				std::istringstream istStr(textToCheck);
                date.ReadDate(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(TestException7)
		{
			Income inc;
			std::string TextError = "Ошибка при чтении организации, неверный формат записи.";
			try {
				std::string textToCheck = "\"Org12 123 ";
				std::istringstream istStr(textToCheck);
				inc.ReadSource(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(TestException8)
		{
			Income inc;
			std::string TextError = "Ошибка при чтении суммы, так как поле пусто.";
			try {
				std::string textToCheck = "";
				std::istringstream istStr(textToCheck);
				inc.ReadSum(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
		}

		TEST_METHOD(TestException9)
		{
			Income inc;
			std::string TextError = "Поле суммы слишком велико.";
			try {
				std::string textToCheck = "8123987192387679679069";
				std::istringstream istStr(textToCheck);
				inc.ReadSum(istStr);
			}
			catch (const std::runtime_error& e)
			{
				Assert::AreEqual(TextError.c_str(), e.what());
			}
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
            Date date(2003,1,31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003, 3, 31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003,5,31);
            Assert::IsTrue(date.CheckDateCorrect()); 
            date.SetDate(2003,7,31);
            Assert::IsTrue(date.CheckDateCorrect()); 
            date.SetDate(2003,8,31);
            Assert::IsTrue(date.CheckDateCorrect()); 
            date.SetDate(2003,10,31);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003,12,31);
            Assert::IsTrue(date.CheckDateCorrect()); 
            date.SetDate(2003,4,30);
            Assert::IsTrue(date.CheckDateCorrect()); 
            date.SetDate(2003,6,30);
            Assert::IsTrue(date.CheckDateCorrect()); 
            date.SetDate(2003,9,30);
            Assert::IsTrue(date.CheckDateCorrect());
            date.SetDate(2003,11,30);
            Assert::IsTrue(date.CheckDateCorrect()); 
            date.SetDate(2003,2,28);
            Assert::IsTrue(date.CheckDateCorrect());

        }
	};

