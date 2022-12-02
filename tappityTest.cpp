/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(PracticeTest, smoke_test)
{
	ASSERT_TRUE(true);
}

//length_difference() Tests:
TEST(PracticeTest, no_length_difference)
{
	std::string reference = "hello";
	tappity obj(reference);
	
	std::string input = "hello";
	obj.entry(input);
	ASSERT_EQ(obj.length_difference(), 0);
}

TEST(PracticeTest, 1_length_difference_input_short)
{
	std::string reference = "hello";
	tappity obj(reference);

	std::string input = "ello";
	obj.entry(input);
	ASSERT_EQ(obj.length_difference(), 1);
}

TEST(PracticeTest, 1_length_difference_reference_short)
{
	std::string reference = "ello";
	tappity obj(reference);

	std::string input = "hello";
	obj.entry(input);
	ASSERT_EQ(obj.length_difference(), 1);
}

TEST(PracticeTest, 2_length_difference_input_short)
{
	std::string reference = "hello";
	tappity obj(reference);

	std::string input = "hel";
	obj.entry(input);
	ASSERT_EQ(obj.length_difference(), 2);
}

TEST(PracticeTest, 2_length_difference_reference_short)
{
	std::string reference = "hel";
	tappity obj(reference);

	std::string input = "hello";
	obj.entry(input);
	ASSERT_EQ(obj.length_difference(), 2);
}

TEST(PracticeTest, 4_length_difference_no_reference)
{
	std::string reference = "";
	tappity obj(reference);

	std::string input = "what";
	obj.entry(input);
	ASSERT_EQ(obj.length_difference(), 4);
}

TEST(PracticeTest, 4_length_difference_no_input)
{
	std::string reference = "what";
	tappity obj(reference);

	std::string input = "";
	obj.entry(input);
	ASSERT_EQ(obj.length_difference(), 4);
}

//accuracy() Tests:
TEST(PracticeTest, accuracy_100)
{
	std::string reference = "hello world";
	tappity obj(reference);

	std::string input = "hello world";
	obj.entry(input);
	ASSERT_EQ(obj.accuracy(), 100);
}

TEST(PracticeTest, accuracy_80_input_longer)
{
	std::string reference = "abcdefgh";
	tappity obj(reference);

	std::string input = "abcdefghij";
	obj.entry(input);
	ASSERT_EQ(obj.accuracy(), 80);
}

TEST(PracticeTest, accuracy_80_reference_longer)
{
	std::string reference = "abcdefghij";
	tappity obj(reference);

	std::string input = "abcdefgh";
	obj.entry(input);
	ASSERT_EQ(obj.accuracy(), 80);
}

TEST(PracticeTest, accuracy_50_incorrect_letters)
{
	std::string reference = "abcdefghij";
	tappity obj(reference);

	std::string input = "abcdeZZZZZ";
	obj.entry(input);
	ASSERT_EQ(obj.accuracy(), 50);
}

TEST(PracticeTest, accuracy_50_incorrect_letters_every_other)
{
	std::string reference = "abcdefghij";
	tappity obj(reference);

	std::string input = "aZcQePgHiW";
	obj.entry(input);
	ASSERT_EQ(obj.accuracy(), 50);
}

TEST(PracticeTest, accuracy_0_empty_input)
{
	std::string reference = "abcdefghij";
	tappity obj(reference);

	std::string input = "";
	obj.entry(input);
	ASSERT_EQ(obj.accuracy(), 0);
}

TEST(PracticeTest, accuracy_50_capital_letters)
{
	std::string reference = "AbCd";
	tappity obj(reference);

	std::string input = "abcd";
	obj.entry(input);
	ASSERT_EQ(obj.accuracy(), 50);
}