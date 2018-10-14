#include "person.h"
#include <regex>
#include <iostream>
#include <fstream>

bool str_isalpha(const string str){
    for(int i = 0; i < str.size(); i++)
    	if((isalpha(str[i]) == 0) || (str[i] == ' '))
    		return false;
    return true;
}


bool str_isalnum(const string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/*
bool atleastone_alnum(const string str)
// helper function to check for at least >1 digit and alphabet
{
  int num = 0;
  int alpha = 0;
  for(int i = 0; i < str.size(); i++) {
    if (isdigit(str[i]) == 1) {
      num = 1;
    }
    if (isalpha(str[i]) == 1) {
      alpha = 1;
    }
  }
  if (num == 1 && alpha == 1) {
    return true;
  } else {
    return false;
  }
}
*/
Person::Person() 
  : username(""), firstname(""), lastname(""), gender(0), age(0), tagline("") {
} // why do we need this one in addition to the line below

Person::Person(string _username, string _firstname, string _lastname, 
               int _gender, int _age, string _tagline)
  : username(_username), firstname(_firstname), lastname(_lastname),
    gender(_gender), age(_age), tagline(_tagline) {

  if (set_info(_username, _firstname, _lastname, _age, _tagline, _gender) == false) {
    username = "";
    firstname = "";
    lastname = "";
    gender = 0;
    age = 0;
    tagline = ""; // if set info fails, return a Person with empty fields
  }
}

string Person::get_username() {
    return username;
}
string Person::get_firstname() {
    return firstname;
}
string Person::get_lastname() {
    return lastname;
}
int Person::get_gender(){
    return gender;
}
int Person::get_age() {
    return age;
}
string Person::get_tagline() {
    return tagline;
}
string Person::get_info() {
	string ret = "";
    return ret;
}

bool Person::set_username(string _username) {
  regex r("^[[:alpha:]]+[[:digit:]]+[[:alnum:]]*$");
  if (_username.length() <= 64 && regex_match(_username, r)) {
    username = _username;
    return true;
  } 
  else {
    return false;
  }
}

bool Person::set_firstname(string _firstname) {
  regex r("^[[:alpha:]]+$");
  if (_firstname.length()<= 64 && regex_match(_firstname, r)) {
    firstname = _firstname;
    return true;
  }
  else {
    return false;
  }
} //--------------DONE--------------//


bool Person::set_lastname(string _lastname) {
  regex r("^[[:alpha:]]+$");
  if (_lastname.length()<= 64 && regex_match(_lastname, r)) {
    lastname = _lastname;
    return true;
  }
  else {
    return false;
  }
} //--------DONE----------//

bool Person::set_gender(int _gender){
  if (_gender == 1 || _gender == 2) {
    gender = _gender;
    return true;
  } 
  else {
    return false;
  }
} // --------DONE---------- //

bool Person::set_age(int _age) {
  if (_age>=18 && _age<=100) {
    age = _age;
    return true;
  }
  else {
    return false;
  }
} // ----------DONE-----------//


bool Person::set_tagline(string _tagline) {
  if (_tagline.length() <= 128) {
    tagline = _tagline;
    return true;
  }
  else {
    return false;
  }
}


bool Person::set_info(string _username, string _firstname, string _lastname,
                      int _age, string _tagline, int _gender) {
  string old_username = username;
  string old_firstname = firstname;
  string old_lastname = lastname;
  int old_age = age;
  string old_tagline = tagline;
  int old_gender = gender;

  if (set_username(_username) &&
      set_firstname(_firstname) &&
      set_lastname(_lastname) &&
      set_gender(_gender) &&
      set_age(_age) &&
      set_tagline(_tagline)) {
    return true;
  }
  
  username = old_username;
  firstname = old_firstname;
  lastname = old_lastname;
  age = old_age;
  tagline = old_tagline;
  gender = old_gender;
  return false;
}

bool Person::send_msg(Person &recipient, string msg) {
	if (recipient.get_msgstat(*this) > 10) {
    return false;
  }
  else {
    recipient.get_msg(msg);
    recipient.get_msg_with_info(msg, this);
    return true;
  }
}

void Person::get_msg(string msg) {
	inbox.push(msg);
}

int Person::get_msgstat(Person recipient){
	queue<pair<string,Person*> > inbox_stat_copy = inbox_stat;
  int result = 0;
  pair<string,Person*> entry;
  while (!inbox_stat_copy.empty()) {
    if (inbox_stat_copy.front().first == recipient.username) {
      result++;
    }
    inbox_stat_copy.pop();
  }
  return result;
}

void Person::get_msg_with_info (string msg, Person* sender){
  inbox_stat.push(make_pair(msg,sender));
}

bool Person::read_msg() {
	if (inbox.empty() || inbox_stat.empty()) {
    return false;
  }
  else {
    inbox.pop();
    inbox_stat.pop();
    return true;
  }

}

