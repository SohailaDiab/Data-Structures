/*--------------------------------------------------------------------------------------------------------

 A program that handles an address book program.
 
The main program uses a simple text-based interface to give the user access to the directory. In 
a while loop, the program presents the user with a menu of options.

--------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include "PhoneDirectory.h"

using namespace std;

// --- Function definitions ---
void addEntry(vector<phoneDirectory>&);
void listEntries(const vector<phoneDirectory>&);
void fNameSearch(const vector<phoneDirectory>&, string);
void numberSearch(const vector<phoneDirectory>&, string);
void delEntry(vector<phoneDirectory>&, string);

void insertionSort(vector<phoneDirectory>&);
void shellSort(vector<phoneDirectory>&);
void bubbleSort(vector<phoneDirectory>&);


// --- Main ---
int main()
{
    cout<<"Address Book Program"<<endl;
    cout<<"----------------------";

    vector<phoneDirectory> phoneClass;

    int n, sortnum;
    string lookup;
    bool x = true;
    while(x){
        cout<<"\nPlease pick the number (1 to 6) of the operation to be performed"<<endl;
        cout<<"1. Add an entry to the directory\n2. Look up a phone number \n3. Look up by first name\n4. Delete an entry by first name\n5. List all entries in phone directory\n6. Exit this program\n";
        cin>>n;
        // Input validation and if the user typed a char instead of int
        if (cin.fail()){
            cin.clear(); cin.ignore(512, '\n');
        }
        while(n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6){
            cout<<"Invalid input. Please pick a number from 1 to 6."<<endl;
            cin>>n;
            if (cin.fail()){
                cin.clear(); cin.ignore(512, '\n');
            }
        }
        //-------
        switch(n){
            case 1: // Add an entry to the dir
                addEntry(phoneClass);
                cout<<endl;
                break;

            case 2: // Look up a phone number
                cout<<"Please enter the phone number that you want to look up: ";
                cin>>lookup;
                numberSearch(phoneClass,lookup);
                cout<<endl;
                break;

            case 3: // Look up by first name
                cout<<"Please enter the first name that you want to look up: ";
                cin>>lookup;
                fNameSearch(phoneClass,lookup);
                cout<<endl;
                break;

            case 4: // Delete an entry by first name
                cout<<"Please enter the first name of the entry that you want to delete: ";
                cin>>lookup;
                delEntry(phoneClass,lookup);
                cout<<endl;
                break;

            case 5: // List all entries in directory (sorted)
                cout<<"Please type the number of the algorithm to be used:"<<endl;
                cout<<"1. Bubble sort\n2. Insertion sort\n3. Shell sort"<<endl;

                cin>>sortnum;
                // Input validation and if the user typed a char instead of int
                if (cin.fail()){
                    cin.clear(); cin.ignore(512, '\n');
                }
                while(sortnum!=1 && sortnum!=2 && sortnum!=3){
                    cout<<"Invalid input. Please pick a number from 1 to 3."<<endl;
                    cin>>sortnum;
                    if (cin.fail()){
                        cin.clear(); cin.ignore(512, '\n');
                    }
                }
                cout<<endl;

                switch(sortnum){
                    case 1:
                        bubbleSort(phoneClass);
                        listEntries(phoneClass);
                        break;
                    case 2:
                        insertionSort(phoneClass);
                        listEntries(phoneClass);
                        break;
                    case 3:
                        shellSort(phoneClass);
                        listEntries(phoneClass);
                        break;
                }
                cout<<endl;
                break;

            case 6: // Exit program
                x=false;
                break;
        }
    }
    return 0;
}


// --- Function definitions ---


// 1. Add an entry to the directory
// Fill in phone dir vector
void addEntry(vector<phoneDirectory>& entry){
    string fname, lname, num;
    cout<<"First name: ";
    cin>>fname;

    cout<<"Last name: ";
    cin>>lname;

    cout<<"Phone number: ";
    cin>>num;

    phoneDirectory newEntry(fname, lname, num);
    entry.push_back(newEntry);
}

//2. look up by phone number
void numberSearch(const vector<phoneDirectory>& directory, string lookup){
    bool found = false;
    for(unsigned int i=0; i<directory.size(); i++){
        if(lookup == directory[i].getNum()){
            cout<<"First name: "<<directory[i].getFName()<<endl;
            cout<<"Last name: "<<directory[i].getLName()<<endl;
            cout<<"Phone number: "<<directory[i].getNum()<<endl;
            found = true;
            break;
        }
    }
    if(found==false)
        cout<<"This phone number was not found in the directory.";
}

//3. look up by first name
void fNameSearch(const vector<phoneDirectory>& directory, string lookup){
    bool found = false;
    for(unsigned int i=0; i<directory.size(); i++){
        if(lookup == directory[i].getFName()){
            cout<<"First name: "<<directory[i].getFName()<<endl;
            cout<<"Last name: "<<directory[i].getLName()<<endl;
            cout<<"Phone number: "<<directory[i].getNum()<<endl;
            found = true;
            break;
        }
    }
    if(found==false)
        cout<<"This name was not found in the directory.";
}


//4. Delete an entry by first name
void delEntry(vector<phoneDirectory>& directory, string lookup){
    bool found = false;
    for(unsigned int i=0; i<directory.size(); i++){
        if(lookup == directory[i].getFName()){
            directory.erase(directory.begin()+i);
            found = true;
            break;
        }   
    }
    if(found==false)
        cout<<"This name was not found in the directory.";
}

//5. List all entries in phone directory (sorted)

// Print all entries in the phone directory
void listEntries(const vector<phoneDirectory>& entries){
    //int size = entries.size();
    for(unsigned int i=0; i<entries.size(); i++){
        cout<<"First name: "<<entries[i].getFName()<<endl;
        cout<<"Last name: "<<entries[i].getLName()<<endl;
        cout<<"Phone number: "<<entries[i].getNum()<<endl;
        cout<<endl;
    }
}
// Insertion sort
void insertionSort(vector<phoneDirectory>& directory) {
    int j;
    phoneDirectory key;
    for(int i=1; i<directory.size(); i++){
        key = directory[i];
        j = i-1;

        while (j>=0 && directory[j].getFName()>key.getFName()){
            directory[j+1]=directory[j];
            j--;
        }
        directory[j+1]=key;
    }
}
// Shell sort
void shellSort(vector<phoneDirectory>& directory){
    int gap, i, j;
    phoneDirectory temp;

    for (gap = directory.size()/2; gap > 0; gap /= 2){
        for (i = gap; i < directory.size(); i++){
            for (j=i-gap; j>=0 && directory[j].getFName()> directory[j+gap].getFName(); j-=gap) {
                temp = directory[j];
                directory[j] = directory[j+gap];
                directory[j+gap] = temp;
            }
        }
    }
}
// Bubble sort
void bubbleSort(vector<phoneDirectory>& directory){
    phoneDirectory tmp;
    for (int i = 0; i < directory.size()-1; i++){
        for (int j = directory.size()-1; j > i; --j){
            if (directory[j].getFName() < directory[j-1].getFName()){
                swap (directory [j], directory [j - 1]);
            }
        }
    }
}
