#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include "matrix.h"
#ifndef MATRIXMENU_H
#define MATRIXMENU_H
using namespace std;
template <class T>
class MatrixCalculator
{

public:
    MatrixCalculator() {}
    void menu()
    {
        bool x = true;
        int n, r1, c1, r2, c2;
        cout<<"Welcome to Matrix Calculator!"<<endl;
        while(x)
        {
            cout<<"------------------------------------------\n";
            cout<<"1- Perform Matrix Addition\n2- Perform Matrix Subtraction\n3- Perform Matrix Multiplication\n4- Matrix Transpose\n5- Exit\n\nSelect the operation you want: ";
            cin>>n;
            // Input validation and if the user typed a char instead of int
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(512, '\n');
            }
            while(n!=1 && n!=2 && n!=3 && n!=4 && n!=5)
            {
                cout<<"\nInvalid input. Please pick a number from 1 to 5."<<endl;
                cin>>n;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(512, '\n');
                }
            }
            Matrix<T> matrix1;
            Matrix<T> matrix2;

            switch(n){

            case 1:   // Matrix Addition
                cout<<"\n--------------------\n";
                cout<<"First matrix: \n";
                cout<<"--------------------\n";
                cin>>matrix1;
                cout<<"\n--------------------\n";
                cout<<"Second matrix: \n";
                cout<<"--------------------\n";
                cin>>matrix2;
                if (matrix1.get_row()!= matrix2.get_row() || matrix1.get_col()!= matrix2.get_col())
                {
                    cout<<"\nMatrix 1 and 2 need to be the same in size, try again and enter a valid size\n\n";
                    break;
                }
                cout<<"\nResult of addition = "<<matrix1+matrix2<<"\n";
                break;

            case 2:  // Matrix Subtraction
                cout<<"\n--------------------\n";
                cout<<"First matrix: \n";
                cout<<"--------------------\n";
                cin>>matrix1;
                cout<<"\n--------------------\n";
                cout<<"Second matrix: \n";
                cout<<"--------------------\n";
                cin>>matrix2;
                if (matrix1.get_row()!= matrix2.get_row() || matrix1.get_col()!= matrix2.get_col())
                {
                    cout<<"\nMatrix 1 and 2 need to be the same in size, try again and enter a valid size\n\n";
                    break;
                }
                cout<<"\nResult of subtraction = "<<matrix1-matrix2;
                break;

            case 3:  // Matrix Multiplication
                cout<<"\n--------------------\n";
                cout<<"First matrix: \n";
                cout<<"--------------------\n";
                cin>>matrix1;
                cout<<"\n--------------------\n";
                cout<<"Second matrix: \n";
                cout<<"--------------------\n";
                cin>>matrix2;
                if (matrix1.get_col()!= matrix2.get_row())
                {
                    cout<<"Matrix 1 column and Matrix 2 row need to be the same, try again and enter a valid size\n\n";
                    break;
                }
                cout<<"\nResult of multiplication = "<<matrix1*matrix2;
                break;

            case 4: // Matrix Transpose
                cout<<"\n--------------------\n";
                cout<<"Matrix: \n";
                cout<<"--------------------\n";
                cin>>matrix1;
                cout<<endl;
                cout<<"Transpose = "<<matrix1.transpose();
                cout<<"before break"<<endl;
                break;

            case 5:  // Exit
                cout<<"\nTurning off your matrix calculator, goodbye\n";
                x=false;
                break;
            }
            cout<<"broke out of case.... x = "<<x<<endl;
        }
        cout<<"out of while loop";
    }
};
#endif
