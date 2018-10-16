#include "gtest/gtest.h"
#include "person.h"
#include "community.h"

// this class is used for testing public methods in class Community
class test_community: public ::testing::Test {
protected:
	Community community;
};

// test get_name
TEST_F(test_community, get_name) {
	community.set_name("community2018");
	EXPECT_STREQ(community.get_name().c_str(),"community2018");
}

// test set_name
TEST_F(test_community, set_name) {
	EXPECT_FALSE(community.set_name("morethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowedmorethanallowed")); // more than 128 (135 here) characters. should fail. 
	EXPECT_FALSE(community.set_name("community!")); // contains non alphanumeric characters. should fail.
	EXPECT_FALSE(community.set_name("3community")); // starts with a digit. should fail. 
	EXPECT_FALSE(community.set_name("")); // empty string. should fail. 
	EXPECT_TRUE(community.set_name("legitcommunity")); // should pass.
}

// Scott edits!
// test add_person
TEST_F(test_community, add_person) {
	

	// add the new person
	Person* new_person = new Person("csiluser3", "Tim", "Cook", 2, 30, "AwesomePossum");
	Person* new_person2 = new Person("csiluser4", "John", "Boyer", 2, 55, "AwesomePossum");
	Person* new_person3 = new Person("csiluser5", "Steve", "Jobs", 2, 55, "AwesomePossum");
	Person* new_person4 = new Person("csiluser6", "Rob", "Zimmer", 2, 60, "AwesomePossum");
	
	community.add_person(*new_person);
	community.add_person(*new_person2);
	community.add_person(*new_person3);
	community.add_person(*new_person4);

	// test if adding a new person is successful
	Person retrieved_person = community.get_member("csiluser3");
	EXPECT_STREQ(retrieved_person.get_username().c_str(),"csiluser3");
	EXPECT_STREQ(retrieved_person.get_firstname().c_str(),"Tim");
	EXPECT_STREQ(retrieved_person.get_lastname().c_str(),"Cook");
	EXPECT_EQ(retrieved_person.get_age(),30);

	retrieved_person = community.get_member("csiluser4");	
	EXPECT_STREQ(retrieved_person.get_username().c_str(),"csiluser4");
	EXPECT_STREQ(retrieved_person.get_firstname().c_str(),"John");
	EXPECT_STREQ(retrieved_person.get_lastname().c_str(),"Boyer");
	EXPECT_EQ(retrieved_person.get_age(),55);

	// test if adding an existing person will not alter the community
        EXPECT_FALSE(community.add_person(*new_person));

	// test if adding a person with null username "" will not alter the community
	Person* new_person5 = new Person("", "Ex", "Libris", 2, 50, "Possum");
	EXPECT_FALSE(community.add_person(*new_person5));
}


// Scott's edit! This is a hlper function for testing find_member.
// https://stackoverflow.com/questions/16747591/how-to-get-an-element-at-specified-index-from-c-list
string get_element_in_list(list<string> _list, int _i) {
	list<string>::iterator it = _list.begin();
	for (int i = 0; i<_i; i++) {
		++it;
	}
	return *it;
} 

// Scott's edit! This is a hlper function for testing find_member.
// https://www.geeksforgeeks.org/check-if-two-arrays-are-equal-or-not/
bool lists_are_equal_for_persons(list<Person> list1, list<Person>list2) {
	
	list<string> usernames1;
	list<string> usernames2;

	// build list of usernames
	for (list<Person>::iterator it = list1.begin(); it!=list1.end(); it++) {
		usernames1.push_back((*it).get_username());
	}

	for (list<Person>::iterator it = list2.begin(); it!=list2.end(); it++) {
		usernames2.push_back((*it).get_username());
	}

	int n = usernames1.size();
	int m = usernames2.size();
	
	if (n != m)
		return false;
	
	usernames1.sort();
	usernames2.sort();

	for (int i = 0; i<n; i++) {
		if (strcmp(get_element_in_list(usernames1, i).c_str(), 
			get_element_in_list(usernames2, i).c_str()) != 0)
			return false;
	}
	return true;
}

bool lists_are_equal_for_strings(list<string> string_list1, list<string> string_list2) {
  int n = string_list1.size();
  int m = string_list2.size();
  if (n!=m)
    return false;
  string_list1.sort();
  string_list2.sort();
  for (int i = 0; i < n; i++) {
    if (strcmp(get_element_in_list(string_list1,i).c_str(),
	       get_element_in_list(string_list2,i).c_str()) != 0)
      return false;
  }
  return true;
}

// test get_all_usernames
//   there's no EXPECT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
  Person* new_person3 = new Person("csiluser3", "Tim", "Cook", 2, 30, "Possum");
  Person* new_person4 = new Person("csiluser4", "Tim", "Boyer", 2, 55, "Possum");
  community.add_person(*new_person3);
  community.add_person(*new_person4);

  list<string> found_list;
  found_list = community.get_all_usernames();
  list<string> correct_list;
  correct_list.push_back("csiluser3");
  correct_list.push_back("csiluser4");
  EXPECT_TRUE(lists_are_equal_for_strings(found_list, correct_list));
  
}

// Scott's edit!
// test find_member by first name and age range
TEST_F(test_community, find_member) {

	Person* new_person3 = new Person("csiluser3", "Tim", "Cook", 2, 30, "Possum");
	Person* new_person4 = new Person("csiluser4", "Tim", "Boyer", 2, 55, "Possum");
	Person* new_person5 = new Person("csiluser5", "Steve", "Jobs", 2, 55, "Possum");
	Person* new_person6 = new Person("csiluser6", "Rob", "Zimmer", 2, 100, "Possum");
	Person* new_person7 = new Person("csiluser7", "Tim", "Rogers", 2, 60, "Possum");
	community.add_person(*new_person3);
	community.add_person(*new_person4);
	community.add_person(*new_person5);
	community.add_person(*new_person6);
	community.add_person(*new_person7);

	Person found_person;	
	list<Person> found_list;
	list<Person> correct_list;
	
	// Testing firstname
	found_list = community.find_member("Tim");
	correct_list.push_back(*new_person3);
	correct_list.push_back(*new_person4);
	correct_list.push_back(*new_person7);
	if (lists_are_equal_for_persons(found_list,correct_list) == true) 
		EXPECT_TRUE(1); // if lists are equal, then test will generate true
	else
		EXPECT_TRUE(0); // if lists are not equal, then test will generate false
	correct_list.clear();

	found_list = community.find_member("Rob");
	correct_list.push_back(*new_person6);
	if (lists_are_equal_for_persons(found_list,correct_list) == true) 
		EXPECT_TRUE(1); 
	else
		EXPECT_TRUE(0); 
	correct_list.clear();

	// Testing age
	found_list = community.find_member(25,70);
	correct_list.push_back(*new_person3);
	correct_list.push_back(*new_person4);
	correct_list.push_back(*new_person5);
	correct_list.push_back(*new_person7);
	if (lists_are_equal_for_persons(found_list,correct_list) == true) 
		EXPECT_TRUE(1); 
	else
		EXPECT_TRUE(0); 
	correct_list.clear();

	found_list = community.find_member(50,70);
	correct_list.push_back(*new_person4);
	correct_list.push_back(*new_person5);
	correct_list.push_back(*new_person7);
	if (lists_are_equal_for_persons(found_list,correct_list) == true) 
		EXPECT_TRUE(1); 
	else
		EXPECT_TRUE(0); 
	correct_list.clear();

}

// Scott's edit! 
// test get_member
TEST_F(test_community, get_member) {
	Person* new_person3 = new Person("csiluser3", "Tim", "Cook", 2, 30, "Possum");
	Person* new_person4 = new Person("csiluser4", "Tim", "Boyer", 2, 55, "Possum");
	community.add_person(*new_person3);
	community.add_person(*new_person4);

	// Need to test existing Person, and creation of new Person
	// Check an existing person
	Person found_person;
	found_person = community.get_member("csiluser3");
	string found_firstname = found_person.get_firstname();
	string found_lastname = found_person.get_lastname();
	int found_age = found_person.get_age();
        string found_tagline = found_person.get_tagline();
	int found_gender = found_person.get_gender();
	EXPECT_STREQ(found_firstname.c_str(),"Tim");
	EXPECT_STREQ(found_lastname.c_str(),"Cook");
	EXPECT_EQ(found_age,30);
	EXPECT_EQ(found_gender,2);
	EXPECT_STREQ(found_tagline.c_str(),"Possum");

	// Check creation of new person, upon lookup of non-existent person
	Person new_person = community.get_member("csiluser_new");
	found_firstname = new_person.get_firstname();
	found_lastname = new_person.get_lastname();
	found_age = new_person.get_age();
	found_tagline = new_person.get_tagline();
	found_gender = new_person.get_gender();
	EXPECT_STREQ(found_firstname.c_str(),"");
	EXPECT_STREQ(found_lastname.c_str(),"");
	EXPECT_EQ(found_age,0);
	EXPECT_EQ(found_gender,0);
	EXPECT_STREQ(found_tagline.c_str(),"");	
}

// test send_msg
TEST_F(test_community, send_msg) {
  Person* new_person3 = new Person("csiluser3", "Tim", "Cook", 2, 30, "Possum");
  Person* new_person4 = new Person("csiluser4", "Tim", "Boyer", 2, 55, "Possum");
  
  community.add_person(*new_person3);
  community.add_person(*new_person4);
  
  string sender_username = "csiluser3";
  string rec_username = "csiluser4";
  
  Person sender_person = community.get_member("csiluser3");
  Person rec_person = community.get_member("csiluser4"); 
  
  // Test sending to csiluser4
  bool res = sender_person.send_msg(rec_person, "heydude");
  EXPECT_TRUE(res);
  
  // Test receiving the email correctly
  // queue<string> res2 = rec_person.inbox;
  
  
  
  
}

