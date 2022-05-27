/*-----------------------------------------------------------------------------
Classes to use for testing two sorting algorithms (Selection and Quick sort). 

The class has methods to support experimenting and analyzing sorting
algorithms performance. 
-----------------------------------------------------------------------------*/

#include<iostream>
#include<cstdlib>
#include<algorithm>
#include <chrono>
#include <iomanip>

using namespace std;

// --- Sorter CLASS ---
class Sorter{
public:
    virtual void Sort(int *arr, int n){}
};

//--- Selection sort
class SelectionSorter: public Sorter{
public:
    void Sort(int *arr, int n){
        int i, j, minIndex, tmp;
        for(i=0; i<n-1; i++){
            minIndex = i;
            for(j=i+1; j<n; j++){
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            if (minIndex != i) {
                tmp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = tmp;
            }
        }
    }


};

//--- Quick sort
class QuickSorter: public Sorter{
    void Sort(int *arr, int n){
        quickSort(arr,0, n-1);
    }
    int *quickSort(int *arr, int left, int right){
        int i = left, j = right;
        int tmp;
         int pivot = arr[(left + right) / 2];

        while (i <= j) {
            while (arr[i]<pivot)
                i++;
            while (arr[j]>pivot)
                j--;
            if (i <= j){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }
        if (left < j)
            quickSort(arr, left, j);
        if (i < right)
            quickSort(arr, i, right);
        return arr;
    }

};

// --- TestBed CLASS ---
class Testbed{
private:
    Sorter* sortobj;
public:
    int *GenerateRandomList(int Min, int Max,int Size){
        int* arr = new int[Size];

        int Random_number;
        for (int i=0; i<Size; i++){
            /// Random_number is put in the loop to generate different number within range not equal
            Random_number = rand()%(Max-Min + 1) + Min;
            arr[i] = Random_number;
        }
        return arr;
    }

    int *GenerateReverseOrderedList(int Min,int Max,int Size){
        int* arr = new int[Size];
        int Random_number;
        for (int i=0; i<Size; i++){
            Random_number = rand()%(Max-Min + 1) + Min;
            arr[i] = Random_number;
        }
        /// Used for sorting ascending order
        sort(arr,arr+Size);
        /// Used for sorting descending order
        reverse(arr,arr+Size);
        return arr;
    }

// returns : elapsed time
    int RunOnce(int sorter, int *data, int size){
        // if sorter = 0 then Selection Sort
        // if sorter = 1 then Quick Sort

        // selection
        if(sorter==0){
            Sorter* sort_ptr;
            SelectionSorter selection;
            sort_ptr = &selection;

            auto start= chrono::high_resolution_clock::now();

            sort_ptr->Sort(data, size);

            auto endt= chrono::high_resolution_clock::now();
            auto elapsedtime = chrono::duration_cast<chrono::microseconds>(endt-start).count();
            return elapsedtime;
        }
        // quick
        else{
            Sorter* sort_ptr;
            QuickSorter quicksort;
            sort_ptr = &quicksort;

            auto start= chrono::high_resolution_clock::now();

            sort_ptr->Sort(data, size);

            auto endt= chrono::high_resolution_clock::now();
            auto elapsedtime = chrono::duration_cast<chrono::microseconds>(endt-start).count();
            return elapsedtime;
        }
    }

    int RunAndAverage(int sorter, int type, int min, int max, int size, int sets_num){
        // random if type = 0
        // reverse if type = 1
        // if sorter = 0 then Selection Sort
        // if sorter = 1 then Quick Sort

        int total_time = 0, avg_time;
        // random
        if(type==0){
            for(int i=0; i<sets_num; i++){
                int *arr = GenerateRandomList(min, max, size);
                total_time += RunOnce(sorter, arr, size);
            }
        }
        // reverse
        else{
            for(int i=0; i<sets_num; i++){
                int *arr = GenerateReverseOrderedList(min, max, size);
                total_time += RunOnce(sorter, arr, size);
            }
        }

        avg_time = total_time/sets_num;
        return avg_time;
    }

    void RunExperient(int sorter, int type, int min, int max, int min_val, int max_val, int sets_num, int step){
        int  size = min_val, avg_time;

        // selection sort
        if(sorter == 0){
            cout<<"----------------------------------"<<endl;
            cout<<"SELECTION SORT"<<endl;
            cout<<"----------------------------------"<<endl;
        }
        else{
            cout<<"----------------------------------"<<endl;
            cout<<"QUICK SORT"<<endl;
            cout<<"----------------------------------"<<endl;
        }
        cout<<setw(11)<<left<<"[ Size ]"<<setw(7)<<"|"<<setw(5)<<"[ Average Time ]"<<endl;

        for(int size = min_val; size<max_val; size+=step){
            avg_time = RunAndAverage(sorter, type, min, max, size, sets_num);
            cout<<setw(11)<<left<<size<<setw(7)<<"|"<<setw(5)<<avg_time;
            cout<<setw(20)<<" msec"<<setw(20)<<endl;
        }
    }

    ~Testbed(){
        delete sortobj;
    }
};

// --- MAIN ---
int main()
{
    Testbed b;

        // Random List if type = 0
        // Reverse Ordered List if type = 1

        // Selection Sort if sorter = 0
        // Quick Sort if sorter = 1

    // ---- DEMO ----
    int sorter, type, minimum = 1, 
                      maximum = 1100000, 
                      min_val = 5000, 
                      max_val = 50000, 
                      sets_num = 5, 
                      step = 5000, 
                      sz = 10000;
    cout<<endl;
    cout<< "********** RANDOM LIST **********"<<endl;
    // Selection Sort using Random List
        sorter = 0, type = 0;
        b.RunExperient(sorter,  type,  minimum,  maximum,  min_val,  max_val,  sets_num,  step);
        cout<<"----------------------------------\n";

    // Quick Sort using Random List
        sorter = 1, type = 0;
        b.RunExperient(sorter,  type,  minimum,  maximum,  min_val,  max_val,  sets_num,  step);
        cout<<"----------------------------------\n";
    //------------------------------------------------------------------
    cout<<endl;
    cout<< "****** REVERSE ORDERED LIST ******"<<endl;
    // Selection Sort using Reverse Ordered List
        sorter = 0, type = 1;
        b.RunExperient(sorter,  type,  minimum,  maximum,  min_val,  max_val,  sets_num,  step);
        cout<<"----------------------------------\n";

    // Quick Sort using Reverse Ordered List
        sorter = 1, type = 1;
        b.RunExperient(sorter,  type,  minimum,  maximum,  min_val,  max_val,  sets_num,  step);
        cout<<"----------------------------------\n";
}
