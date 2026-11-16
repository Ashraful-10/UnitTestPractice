/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
    ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}

TEST(PasswordTest, repeated_characters)
{
    Password my_password;
    ASSERT_EQ(3, my_password.count_leading_characters("AAAabc"));
}

TEST(PasswordTest, all_characters_same)
{
    Password my_password;
    ASSERT_EQ(4, my_password.count_leading_characters("BBBB"));
}

TEST(PasswordTest, different_case)
{
    Password my_password;
    ASSERT_EQ(1, my_password.count_leading_characters("AaAa"));
}

TEST(PasswordTest, empty_string)
{
    Password my_password;
    ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, mixed_case_password)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("Hello"));
}

TEST(PasswordTest, uppercase_only)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("HELLO"));
}

TEST(PasswordTest, lowercase_only)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("hello"));
}

TEST(PasswordTest, mixed_case_with_numbers)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("Hello123"));
}

TEST(PasswordTest, numbers_only)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("12345"));
}

TEST(PasswordTest, uppercase_and_lowercase_with_numbers)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("a1B2"));
}

TEST(PasswordTest, empty_password)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case(""));
}
