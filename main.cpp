/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#include <iostream>
#include <ctime>
using namespace std;

void algorithm1( int* arr1, unsigned int size, int* arr2, int*& arr3, int &size3)
{
    size3 = 2 * size;
    arr3 = new int[size3];

    for( unsigned int i = 0; i < size; ++i)
        arr3[i] = arr1[i];

    unsigned int count = size;

    for( unsigned int i = 0; i < size; ++i)//arr2
    {
        for(unsigned int j = 0; j < count; ++j)
        {
            if( arr3[j] > arr2[i] && (j + 1) < size)
            {
                for( unsigned int k = count; k > j; --k)
                    arr3[k] = arr3[k - 1];
                arr3[j] = arr2[i];
                count++;
                break;
            }
        }
    }

    int count2 = count - size, sizeC = size;


    while( sizeC > count2)
        arr3[count++] = arr2[count2++];
}

void algorithm2( int* arr1, unsigned int size, int* arr2, int*& arr3, int &size3)
{
    size3 = 2 * size;
    arr3 = new int[size3];

    int index1 = 0, index2 = 0, index3 = 0;

    for( index1 = 0, index2 = 0; index1 < size && index2 < size;)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr3[index3] = arr1[index1];
            index1++;
            index3++;
        }
        if (arr1[index1] >= arr2[index2])
        {
            arr3[index3] = arr2[index2];
            index2++;
            index3++;
        }
    }

    for(;index1 < size;)
    {
        arr3[index3] = arr1[index1];
        index1++;
        index3++;
    }
    for(;index2 < size;)
    {
        arr3[index3] = arr2[index2];
        index2++;
        index3++;
    }
}

void calculateTimeAlgo1(int* arr1, unsigned int size, int* arr2, int*& arr3, int &size3, int times) //calculate time for algorithm 1 where the algorithm is repeated "times" times
{
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    //Code block
    for( int i = 0; i < times; ++i)
        algorithm1(arr1, size, arr2, arr3, size3);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / (CLOCKS_PER_SEC * times);
    cout << "Execution took " << duration << " milliseconds. (Algorithm 1)" << endl;
}

void calculateTimeAlgo2(int* arr1, unsigned int size, int* arr2, int*& arr3, int &size3, int times) //calculate time for algorithm 2 where the algorithm is repeated "times" times
{
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    //Code block
    for( int i = 0; i < times; ++i)
        algorithm2(arr1, size, arr2, arr3, size3);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / (CLOCKS_PER_SEC * times);
    cout << "Execution took " << duration << " milliseconds. (Algorithm 2)" << endl;
}

int main()
{
    int size = 0, count = 0, size3 = 0;
    int* arr1, *arr2, *arr3;
    string s;
    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           (i)                                        //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    s = "(i)";
    cout << "-------------------------(i)------------------------------------" << endl;
    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 10                                    //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 10;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 10000);

    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10000);

    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 100                                   //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 100;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 10000);

    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10000);

    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;


    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 1000                                  //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 1000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 100);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 1000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 10000                                 //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 10000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 100);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 1000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 100000                                //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 100000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 1);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 100);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 1000000                               //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 1000000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 1);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           (ii)                                       //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    s = "(ii)";
    cout << "-------------------------(ii)------------------------------------" << endl;
    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 10                                    //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 10;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 10000);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 1000                                  //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 1000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 100);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 1000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 10000                                 //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 10000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 100);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 1000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 100000                                //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 100000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 1);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 1000000                               //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 1000000;

    arr1 = new int[size];
    arr2 = new int[size];

    count = 0;
    for(int i = 1; i <= size; ++i)
    {
        arr2[count] = i;
        ++count;
    }

    count = 0;
    for(int i = size + 1; i <= 2 * size; ++i)
    {
        arr1[count] = i;
        ++count;
    }

    size3 = 0;

    cout << "FOR (i) SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 1);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    int count1 = 0, count2 = 0;
    ////////////////////////////////////////////////////////////////////////
    //                                                                    //
    //                                                                    //
    //                             (iii)                                  //
    //                                                                    //
    //                                                                    //
    ////////////////////////////////////////////////////////////////////////
    s = "(iii)";
    cout << "-------------------------(iii)------------------------------------" << endl;
    ////////////////////////////////////////////////////////////////////////
    //                                                                    //
    //                                                                    //
    //                         SIZE 10                                    //
    //                                                                    //
    //                                                                    //
    ////////////////////////////////////////////////////////////////////////
    size = 10;

    arr1 = new int[size];
    arr2 = new int[size];

    count1 = 0, count2 = 0;
    for(int i = 1; i <= 2 * size; ++i)
    {
        if(i % 2 == 0)
            arr2[count2++] = i;

        else
            arr1[count1++] = i;
    }


    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 10000);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 1000                                  //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 1000;

    arr1 = new int[size];
    arr2 = new int[size];

    count1 = 0, count2 = 0;
    for(int i = 1; i <= 2 * size; ++i)
    {
        if(i % 2 == 0)
            arr2[count2++] = i;

        else
            arr1[count1++] = i;
    }


    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 100);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 1000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 10000                                 //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 10000;

    arr1 = new int[size];
    arr2 = new int[size];

    count1 = 0, count2 = 0;
    for(int i = 1; i <= 2 * size; ++i)
    {
        if(i % 2 == 0)
            arr2[count2++] = i;

        else
            arr1[count1++] = i;
    }


    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 100);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 1000);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 100000                                //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 100000;

    arr1 = new int[size];
    arr2 = new int[size];

    count1 = 0, count2 = 0;
    for(int i = 1; i <= 2 * size; ++i)
    {
        if(i % 2 == 0)
            arr2[count2++] = i;

        else
            arr1[count1++] = i;
    }


    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 1);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    //////////////////////////////////////////////////////////////////////////
    //                                                                      //
    //                                                                      //
    //                           SIZE 1000000                               //
    //                                                                      //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////
    size = 1000000;

    arr1 = new int[size];
    arr2 = new int[size];

    count1 = 0, count2 = 0;
    for(int i = 1; i <= 2 * size; ++i)
    {
        if(i % 2 == 0)
            arr2[count2++] = i;

        else
            arr1[count1++] = i;
    }


    size3 = 0;

    cout << "FOR " << s << " SIZE = " << size << endl;
    calculateTimeAlgo1(arr1, size, arr2, arr3, size3, 1);
    delete[] arr3;
    calculateTimeAlgo2(arr1, size, arr2, arr3, size3, 10);
    delete[] arr3;

    delete[] arr1;
    delete[] arr2;

    cout << endl;


    return 0;
}
