#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
class Person {

  private:

    string username;
    string firstname;
    string lastname;
    int gender;
    int age;
    string tagline;

    // store received messages
    // ignore classifications
    // when a message is retrieved, delete it immediately
    queue<string> inbox;
    // store received messages
    // similar as inbox, except also recording sender 
    // when a message is retrieved, delete it immediately
    queue<pair<string,Person> > inbox_stat;    
  public:
   
    // record how many messages have been received from others
    map<string,int> msg_stat;      
    Person();
    Person(string _username, string _firstname, string _lastname, 
           int _gender, int _age, string _tagline);

    string get_username();
    string get_firstname();
    string get_lastname();
    int get_gender();
    int get_age();
    string get_tagline();
    string get_info();

    bool set_username(string _username);
    bool set_firstname(string _firstname);
    bool set_lastname(string _lastname);
    bool set_gender(int _gender);
    bool set_age(int _age);
    bool set_tagline(string _tagline);
    bool set_info(string _username, string _firstname, string _lastname,
                  int _age, string _tagline, int _gender);

    bool send_msg(Person &recipient, string msg);
    void get_msg(string msg);
    int  get_msgstat(Person recipient); //return how many unread messages from recipent in inbox
    void get_msg_with_info (string msg, Person* sender); //the recipient receives messages from the sender
    bool read_msg(); //return value indicates whether the inbox is empty or not
};

bool str_isalpha(const string str);
bool str_isalnum(const string str);

#endif /* COMMUNITY_H */

