#include "person.h"

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

Person::Person() 
  : username(""), firstname(""), lastname(""), gender(0), age(0), tagline("") {
}

Person::Person(string _username, string _firstname, string _lastname, 
               int _gender, int _age, string _tagline)
  : username(_username), firstname(_firstname), lastname(_lastname),
    gender(_gender), age(_age), tagline(_tagline) {
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
  if (_username.length()<65
      //&& str_isalnum(_username)
      //&& isalpha(_username.at(0))
      //&& (_username.length()!=0))
      && atleastone_alnum(_username)) {
    return true;
  } else {
    return false;
  }
}

bool Person::set_firstname(string _firstname) {
  if ((_firstname.length()<65)
      && str_isalpha(_firstname)
      && (_firstname.length()!=0)) {
        firstname = _firstname;
        return true;
    }
    else {
        return false;
    }
} //--------------DONE--------------//


bool Person::set_lastname(string _lastname) {
  if ((_lastname.length() < 65)
      && str_isalpha(_lastname)
      && (_lastname.length()!= 0)) {
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
  } else {
    return false;
  }
} // --------DONE---------- //

bool Person::set_age(int _age) {
  if (_age>15 && _age<100) {
    Person::age = _age;
    return true;
  }
  else {
    return false;
  }
} // ----------DONE-----------//


bool Person::set_tagline(string _tagline) {
	// TODO
    if (0/* fill in any necessary tests here */) {
        tagline = _tagline;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_info(string _username, string _firstname, string _lastname,
                      int _age, string _tagline, int _gender) {
    // TODO
	// set the information for
	// 1) username
	// 2) firstname
	// 3) lastnam3
	// 4) age
	// 5) tagline
    // 6) gender
	return false;
}

bool Person::send_msg(Person &recipient, string msg) {
	// TODO
	// send message
	return false;
}

void Person::get_msg(string msg) {
	// TODO
	// get message
}

int Person::get_msgstat(Person recipient){
	return 0;
}

bool Person::read_msg() {
	// TODO
	// print the message if there any message inbox
    return false;

}

