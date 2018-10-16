#include "gtest/gtest.h"
#include "person.h"

// this class is used for testing public methods in class Person
class test_person: public ::testing::Test {
protected:
	Person person;
	Person recipient;
};

// test get_username and set_username
TEST_F(test_person, test_username) {
  EXPECT_FALSE(person.set_username("morethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtymorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfourmorethansixtyfour")); // more than 64 chars, and no numbers
  EXPECT_FALSE(person.set_username("201820182018")); // no alphabets
  EXPECT_FALSE(person.set_username("nonumbersatall")); // no numbers
  EXPECT_FALSE(person.set_username("themaroongreat!")); // non alphanumeric exclamation mark
  EXPECT_FALSE(person.set_username("123maroonusername")); // starts with number
  EXPECT_FALSE(person.set_username(""));
  EXPECT_FALSE(person.set_username("2boy"));
}

// test get_firstname and set_firstname
TEST_F(test_person, test_firstname) {
  EXPECT_FALSE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvmxyzabcdefghijklm"));
  EXPECT_TRUE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
  EXPECT_STREQ(person.get_firstname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");
  EXPECT_FALSE(person.set_lastname("abcdefg0"));
  EXPECT_FALSE(person.set_lastname("abcdefg;"));
  EXPECT_FALSE(person.set_lastname(""));
} 


// test get_lastname and set_lastname
TEST_F(test_person, test_lastname) {
 	EXPECT_FALSE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"));
	EXPECT_TRUE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
 	EXPECT_STREQ(person.get_lastname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");
	EXPECT_FALSE(person.set_lastname("abcdefg0"));
	EXPECT_FALSE(person.set_lastname("abcdefg;"));
	EXPECT_FALSE(person.set_lastname(""));
}

TEST_F(test_person, test_age) {
	EXPECT_FALSE(person.set_age(-1));
	EXPECT_TRUE(person.set_age(18));
	EXPECT_EQ(person.get_age(), 18);
	EXPECT_FALSE(person.set_age(149));
}

//test get_gender and set_gender
TEST_F(test_person,test_gender){
  EXPECT_TRUE(person.set_gender(1));
  EXPECT_TRUE(person.set_gender(2));
  EXPECT_FALSE(person.set_gender(11));
  EXPECT_FALSE(person.set_gender(22));
  EXPECT_FALSE(person.set_gender(0));
}

// test get_tagline and set_tagline
TEST_F(test_person, test_tagline) {

  // test set_tagline
  EXPECT_TRUE(person.set_tagline("sleepisfortheweak"));
  EXPECT_TRUE(person.set_tagline("2018isagreatyear"));
  EXPECT_FALSE(person.set_tagline("toomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanycharstoomanychars"));
  EXPECT_TRUE(person.set_tagline("goodtagline"));

  // test get_tagline
  EXPECT_STREQ(person.get_tagline().c_str(),"goodtagline");
}

// test get_info and set_info
TEST_F(test_person, test_info) {
  
  // test set_info
  EXPECT_FALSE(person.set_info("fakename","John","Smith",30,"gomaroons",2));
  EXPECT_TRUE(person.set_info("allowedname01","John","Smith",30,"gomaroons",2));
  
  // test get_info
  EXPECT_STREQ(person.get_info().c_str(),"Username: allowedname01, Firstname: John, Lastname: Smith, Age: 30, Tagline: gomaroons, Gender: 2");
}

// test get_msgstat, send_msg and read_msg
//   to make your code shorter, we suggest combining these tests together; you
//   can also separate them into several test cases
TEST_F(test_person, test_msg) {
}

