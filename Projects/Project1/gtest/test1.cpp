#include "gtest/gtest.h"
#include "proj1.hpp"
#include "ver.hpp" 
#include <map>
#include <string>


/*
 
Note that this IS NOT a comprehensive set of test cases.
You should still write additional test cases.

This is to get you started and serve as a sanity check.

 */


namespace{

TEST(SimpleCases, PotPanBib){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("POT", "PAN", "BIB", puzzle) ) ;
}

TEST(SimpleCases, NeatFind){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("UCI", "ALEX", "MIKE", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("UCI", "ALEX", "MIKE", puzzle) );
} 


TEST(SimpleCases, FirstNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("LARRY", "CAREER", "LEGEND", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, SecondNo){
	
	std::map<char, unsigned> puzzle;
	
	bool p1 = puzzleSolver("ICSICI", "CSITAH", "AOHIHZ", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("ICSICI", "CSITAH", "AOHIHZ", puzzle) );
}

TEST(SimpleCases, ThirdNo){
	
	std::map<char, unsigned> puzzle;
	
	bool p1 = puzzleSolver("ICS", "CSI", "AOH", puzzle);
    EXPECT_TRUE( p1  &&  gradeYesAnswer("ICS", "CSI", "AOH", puzzle) );
}

TEST(SimpleCases, FourthNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("ICSICI", "CSITAH", "AOHIHZ", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("ICSICI", "CSITAH", "AOHIHZ", puzzle) );
}

TEST(SimpleCases, FifthNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("ICSICI", "", "AOHIHZ", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, SixthNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("", "CAT", "DOG", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, SeventhNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("", "", "HELLOO", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, EighthNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("", "", "", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("", "", "", puzzle) );
}

TEST(SimpleCases, NinthNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("TAR", "TAR", "DOG", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("TAR", "TAR", "DOG", puzzle) );
}

TEST(SimpleCases, TenthNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("BYE", "WHAT", "HELLOO", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, EleventhNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("BYE", "", "HELLOO", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, TwelvethNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("", "HELLOO", "WHILE", puzzle);
    EXPECT_FALSE( p1 );
}

} // end namespace
