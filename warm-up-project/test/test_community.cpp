#include "gtest/gtest.h"
#include "person.h"
#include "community.h"

// this class is used for testing public methods in class Community
class test_community: public ::testing::Test {
protected:
	Community community;
};

// you should complete the following test cases
// you should add more if you see fit

// test get_name
TEST_F(test_community, get_name) {
	EXPECT_STREQ(community.get_name().c_str(),"legitcommunity");
}

// test set_name
TEST_F(test_community, set_name) {
	EXPECT_FALSE(community.set_name("morethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowed")); // more than 128 (135 here) characters. should fail. 
	EXPECT_FALSE(community.set_name("community!")); // contains non alphanumeric characters. should fail.
	EXPECT_FALSE(community.set_name("3community")); // starts with a digit. should fail. 
	EXPECT_FALSE(community.set_name("")); // empty string. should fail. 
	EXPECT_TRUE(community.set_name("legitcommunity")); // should pass.
}

// test add_person
TEST_F(test_community, add_person) {
	

	// below we add the new person
	Person* new_person = new Person("csiluser3", "Tim", "Cook", 2, 30, "AwesomePossum");
	community.add_person(*new_person);
	// below we test if the new person has been successfully added
	Person retrieved_person = community.get_member("csiluser3");
	EXPECT_STREQ(retrieved_person.get_username().c_str(),"csiluser3");
	EXPECT_STREQ(retrieved_person.get_firstname().c_str(),"Tim");
	EXPECT_STREQ(retrieved_person.get_lastname().c_str(),"Cook");
	EXPECT_EQ(retrieved_person.get_age(),30);
}

// test get_all_usernames
//   there's no EXPERT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
}

// test find_member by first name and age range
TEST_F(test_community, find_member) {

	// below we add the new person
	Person* new_person = new Person("csiluser4", "Eric", "Smith", 2, 30, "AwesomePossum");
	community.add_person(*new_person);

	// below we set up containers for testing
	list<Person> found_list;
	Person found_person;	
	
	// below we test if we can find the member, by firstname
	found_list = community.find_member("Eric");
	if (!found_list.empty()) {
		found_person = found_list.front();
	}
	EXPECT_STREQ(found_person.get_firstname().c_str(),"Eric");

	// below test if we can find the member, by agerange
	found_list = community.find_member(20,30);
	if (!found_list.empty()) {
		
	}



}

// test get_member
TEST_F(test_community, get_member) {
}

// test send_msg
TEST_F(test_community, send_msg) {
}

