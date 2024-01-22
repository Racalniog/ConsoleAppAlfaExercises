//#include "Header.h"
//
////#include <gtest/gtest.h>
////TODO use Cmake for google test framework
//
//class PalindromeTest : public ::testing::Test {
//protected:
//    Palindrome palindrome;
//};
//
//TEST_F(PalindromeTest, EmptyStringIsPalindrome) {
//    std::string input = "";
//    EXPECT_EQ("true", palindrome.execute(input));
//}
//
//TEST_F(PalindromeTest, SingleCharacterStringIsPalindrome) {
//    std::string input = "a";
//    EXPECT_EQ("true", palindrome.execute(input));
//}
//
//TEST_F(PalindromeTest, NonAlphanumericCharactersAreIgnored) {
//    std::string input = "A man, a plan, a canal, Panama!";
//    EXPECT_EQ("true", palindrome.execute(input));
//}
//
//TEST_F(PalindromeTest, NonPalindromeString) {
//    std::string input = "hello";
//    EXPECT_EQ("false", palindrome.execute(input));
//}
//
//TEST_F(PalindromeTest, PalindromeString) {
//    std::string input = "Able was I ere I saw Elba";
//    EXPECT_EQ("true", palindrome.execute(input));
//}
//
////int main(int argc, char** argv) {
////    ::testing::InitGoogleTest(&argc, argv);
////    return RUN_ALL_TESTS();
////}
