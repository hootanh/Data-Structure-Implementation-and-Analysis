#include "gtest/gtest.h"
#include "proj0.hpp"
#include <map>
#include <string>

namespace{

TEST(VerifySolution, First){
    std::string s1 = "POT";
    std::string s2 = "PAN";
    std::string s3 = "BIB";

    std::map<char, unsigned> solution = { {'A', 7}, {'B', 5}, 
        {'I', 0}, {'N', 4}, {'O', 3}, {'P', 2}, {'T', 1}
    };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
}

TEST(VerifySolution, Second){

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "PIG";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test two

TEST(VerifySolution, Third){

    std::string s1 = "CAT";
    std::string s2 = "";
    std::string s3 = "CAT";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test three

TEST(VerifySolution, Fourth){

    std::string s1 = "";
    std::string s2 = "";
    std::string s3 = "";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test four

TEST(VerifySolution, Fifth){

    std::string s1 = "";
    std::string s2 = "CAT";
    std::string s3 = "CAT";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test five

TEST(VerifySolution, Sixth){

    std::string s1 = "ICS";
    std::string s2 = "CSI";
    std::string s3 = "AOH";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'T', 0}, {'I', 3}, {'S', 4}, {'H', 7}, {'O', 6} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test six

TEST(VerifySolution, Seventh){

    std::string s1 = "ICSICI";
    std::string s2 = "CSITAH";
    std::string s3 = "AOHIHZ";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'T', 0}, {'I', 3}, {'S', 4}, {'H', 7}, {'O', 6}, {'Z', 10} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test seven

} // end namespace
