/*-----------------------------------------------------------------------------------------

Matrix class specifications.

Overloaded standard operators and I/O operators to enable Matrix class with 
addition, subtraction and multiplication and suitable input and output capabilities. 
Also added a method for matrix transpose.

-----------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

template <class T>
class Matrix
{
private:
    T ** mat;
    int row, col;
public:
    //Constructor
    Matrix() {}
    Matrix(int r, int c)
    {
        row = r;
        col = c;
        mat = new T*[row];
        // Initialize pointer to pointer
        mat = new T*[row];

        // Create the matrix (empty)
        for (int i=0; i<row; i++)
        {
            mat[i] = new T[col];
        }
    }
    // Getters for rows and columns
    int get_row()
    {
        return row;
    }
    int get_col()
    {
        return col;
    }

// operator overloading -- input n output kinda from github

    // input
    friend istream &operator >>(istream& input, Matrix<T> &m)
    {
        cout<<"Enter the number of rows and columns respectively: ";
        input>>m.row>>m.col;
        m.mat = new T*[m.row];
        // create matrix rows
        for(int i=0; i < m.row; i++)
        {
            m.mat[i] = new T[m.col];
        }
        // input elements in matrix
        cout<<"\nEnter the values of matrix:"<<endl;
        for(int i=0; i < m.row; i++)
        {
            for(int j=0; j < m.col; j++)
            {
                input>> m.mat[i][j];
            }
        }
        return input;
    }
    // output
    friend ostream &operator <<(ostream& output, const Matrix<T>&m)
    {   
        cout<<endl;
        for(int i=0; i<m.row; i++)
        {
            for(int j=0; j < m.col; j++)
            {
                output<<setw(5)<<left<<m.mat[i][j]<<setw(5);
            }
            output<<endl;
        }
        return output;
    }
    // Addition
    Matrix<T> operator+(const Matrix<T> &m)
    {
        Matrix<T>sum(row, col);

        for(int i=0; i<sum.row; i++)
        {
            for(int j=0; j<sum.col; j++)
            {
                sum.mat[i][j] = (mat[i][j]+m.mat[i][j]);
            }
        }
        return sum;
    }
    // Subtraction
    Matrix<T> operator-(const Matrix<T> &m)
    {
        Matrix<T> diff(row,col);
        for(int i=0; i<m.row; i++)
        {
            for(int j=0; j<m.col; j++)
            {
                diff.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return diff;
    }
    // Multiplication
    Matrix<T> operator*(const Matrix<T> &m)
    {
        Matrix<T> prod(row, col);

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < m.col; j++)
            {
                for(int k = 0; k < col; k++)
                {
                    prod.mat[i][j] += mat[i][k]*m.mat[k][j];
                }
            }
        }
        return prod;
    }
    // Transpose
    Matrix<T> transpose()
    {
        Matrix<T> trans(col, row);

        for (int i=0; i<row; ++i){
            for (int j=0; j<col; ++j){
                trans.mat[j][i] = mat[i][j];
            }
        }

        return trans;
    }

//------------------------------
    //Destructor
    ~Matrix()
    {
        for (int i=0; i<row; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
};
