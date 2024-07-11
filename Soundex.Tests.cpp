#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
  generateSoundex("AX" ,soundex);
  ASSERT_STREQ(soundex,"A200");
}
 
TEST(SoundexTest, BasicTest) {
    char soundex[5];
    generateSoundex("Robert", soundex);
    EXPECT_STREQ(soundex, "R163");
    generateSoundex("Rupert", soundex);
    EXPECT_STREQ(soundex, "R163");
    generateSoundex("Rubin", soundex);
    EXPECT_STREQ(soundex, "R150");
}
 
 
TEST(SoundexTest, SimilarStarting) {
    char soundex[5];
    generateSoundex("Ashcraft", soundex);
    EXPECT_STREQ(soundex, "A261");
    generateSoundex("Ashcroft", soundex);
    EXPECT_STREQ(soundex, "A261");
}
 
 
TEST(SoundexTest, DiffLengths) {
    char soundex[5];
    generateSoundex("Pfister", soundex);
    EXPECT_STREQ(soundex, "P123");
    generateSoundex("Tymczak", soundex);
    EXPECT_STREQ(soundex, "T520");
    generateSoundex("Honeyman", soundex);
    EXPECT_STREQ(soundex, "H500");
}
 
 
TEST(SoundexTest, NoMatchingConsonant) {
    char soundex[5];
    generateSoundex("Euler", soundex);
    EXPECT_STREQ(soundex, "E460");
    generateSoundex("Ellery", soundex);
    EXPECT_STREQ(soundex, "E460");
}
 
 
TEST(SoundexTest, RepeatedLetter) {
    char soundex[5];
    generateSoundex("Bobby", soundex);
    EXPECT_STREQ(soundex, "B100");
    generateSoundex("Booby", soundex);
    EXPECT_STREQ(soundex, "B100");
}
 
 
TEST(SoundexTest, EdgeCase) {
    char soundex[5];
    generateSoundex("A", soundex);
    EXPECT_STREQ(soundex, "A000");
    generateSoundex("E", soundex);
    EXPECT_STREQ(soundex, "E000");
    generateSoundex("I", soundex);
    EXPECT_STREQ(soundex, "I000");
    generateSoundex("O", soundex);
    EXPECT_STREQ(soundex, "O000");
    generateSoundex("U", soundex);
    EXPECT_STREQ(soundex, "U000");
}
 
 
TEST(SoundexTest, NonAlphabetChar) {
    char soundex[5];
    generateSoundex("O@Malley", soundex);
    EXPECT_STREQ(soundex, "O540");
    generateSoundex("D@Angelo", soundex);
    EXPECT_STREQ(soundex, "D524");
 
   generateSoundex("D2Angelo", soundex);
    EXPECT_STREQ(soundex, "D524");
}
TEST(SoundexTest, Shortname) {
    char soundex[5];
    generateSoundex("OM", soundex);
    EXPECT_STREQ(soundex, "O500");
    generateSoundex("DA", soundex);
    EXPECT_STREQ(soundex, "D000");
 
  
}
 
TEST(SoundexTest, ConsecutiveSameCode) {
    char soundex[5];
    generateSoundex("Jackson", soundex);
    EXPECT_STREQ(soundex, "J250");
 
    generateSoundex("Jxson", soundex);
    EXPECT_STREQ(soundex, "J250");
}
 
 
TEST(SoundexTest, ConsecutiveDifferentCodes) {
    char soundex[5];
    generateSoundex("Lindsay", soundex);
    EXPECT_STREQ(soundex, "L532");
 
    generateSoundex("Lindzay", soundex);
    EXPECT_STREQ(soundex, "L532");
}
 
 
 
TEST(SoundexTest, UpperLower) {
    char soundex[5];
    generateSoundex("Robert", soundex);
    EXPECT_STREQ(soundex, "R163");
    generateSoundex("robert", soundex);
    EXPECT_STREQ(soundex, "R163");
    generateSoundex("RObert", soundex);
    EXPECT_STREQ(soundex, "R163");
}
