#include "community.h"
#include <regex>

Community::Community()
  : name(""), people(map<string,Person>()) {
}

Community::Community(string _name, map<string,Person> _people) 
  : name(_name), people(_people) {

  regex r("^[[:alpha:]][[:alnum:]]*$");
  if (_name.length() > 128 || !regex_match(_name, r)) {
    name = "";
    people = map<string,Person>();
  }
}

string Community::get_name() {
	return name;
}

bool Community::set_name(string _name) {
	regex r("^[[:alpha:]][[:alnum:]]*$");
  if (_name.length() <= 128 && regex_match(_name, r)) {
    name = _name;
    return true;
  } 
  return false;
}

int is_present(string username, map<string,Person> people) {
  int res = 0;
  for (map<string,Person>::iterator it = people.begin(); it!=people.end(); it++) {
    if (strcmp(it->second.get_username().c_str(),username.c_str()) == 0) {
      res = 1;
    } 
  }
  return res;
}

bool Community::add_person(Person _person) {
  contact to_add(_person.get_username(), _person);
  if ((is_present(_person.get_username(),people) == 0) && // if not present
      strcmp(_person.get_username().c_str(),"") != 0) { // and username isn't empty
    people.insert(to_add); // then insert
    return true;
  } else
    return false; // otherwise simply return false
}

// return the person object for a given username
Person& Community::get_member(string username) {
    if (people.find(username) != people.end()) {
    	return people[username];
    }
    else {
    	Person* p = new Person();
	return *p;
    }
}
    
list<string> Community::get_all_usernames() {
    list<string> usernames;
    for (map<string,Person>::iterator it=people.begin(); it!=people.end(); it++) {
      usernames.push_back(it->first);
    }
    return usernames;
}

void Community::print_all_usernames() {
  for (auto v : this->get_all_usernames()) {
    cout << v << "\n";
  }
}

list<Person> Community::find_member(string firstname) {
    list<Person> ret;
    for (map<string,Person>::iterator it=people.begin(); it!=people.end(); it++) {
      if (it->second.get_firstname() == firstname) {
        ret.push_back(it->second);
      }
    }
    return ret;
}

list<Person> Community::find_member(int age_lb, int age_ub) {
  list<Person> ret;
  int age;
  for (map<string,Person>::iterator it=people.begin(); it!=people.end(); it++) {
    age = it->second.get_age();
    if (age >= age_lb && age <= age_ub) {
      ret.push_back(it->second);
    }
  }
  return ret;
}

bool Community::send_msg(list<string> usernames, string msg) {
  bool allsend = true;
  for (std::list<string>::iterator it=usernames.begin(); it!=usernames.end(); it++) {
    Person& recipient = get_member(*it);
    if (recipient.get_username() != "") {
      recipient.get_msg(msg);
      recipient.get_msg_with_info(msg, NULL);
    }
    else {
      allsend = false;
    }
  }
  return allsend;
}

