#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H

#include <iostream>
#include <string>

using namespace std;

class phoneDirectory{
private:
    string firstName, lastName, pnumber;
public:
    // constructors
    phoneDirectory(){
        firstName = ' ';
        lastName = ' ';
        pnumber = ' ';
    }

    phoneDirectory(string fname, string lname, string number){
        firstName = fname;
        lastName = lname;
        pnumber = number;
    }

    // accessor functions
    string getFName()const{
        return firstName;
    }
    string getLName()const{
        return lastName;
    }
    string getNum()const{
        return pnumber;
    }
    
    // operator overloading
    void operator=(const phoneDirectory &obj ){ 
        firstName = obj.firstName;
        lastName = obj.lastName;
        pnumber = obj.pnumber;
    }

    // destructor
    ~phoneDirectory(){};
};

#endif
