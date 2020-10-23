#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


int* zapolnaem(int m)
{
    srand(time(NULL)*m);
    int *M=new int[m];
    for (int i=0; i<m; i++){
        M[i]= rand() % 6000000;
    }
    return M;
}

int trans(int* A, int c, int a){
    int i=0;
    while ((A[i]!=c)&&(i<a)) {i++; }
    if ((i==a)&&(A[i]!=c))
    {
        return (-1);
    }
    else {
        if (i!=0){
            int t;
            t = A[i]; A[i] = A[i-1]; A[i-1] = t;
            return i;
        }
    }
}

int binarysearch(int* A, int a, int n)
{
    int low, high, middle;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < A[middle])
            high = middle - 1;
        else if (a > A[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

int *sorte (int* x, int n)
{
    int i,j,r,t;
    for (r = n/2; r>0; r/= 2)
    {
        for (i = r; i < n; i++)
        {
            t = x[i];
            for (j = i; j >= r; j=j-r)
            {
                if (t < x[j - r])
                    x[j] = x[j - r];
                else
                    break;}
            x[j] = t;}}
    return x;
}


int main()
{
    srand(time(NULL));
    int *arr = new int[1000000], keys[40], answers[40];
    long int start, finish;
    for(int i = 0; i < 1000000; i++)
        arr[i]=rand()*(6000000/RAND_MAX) + rand()%(6000000/RAND_MAX);
    for(int i = 0; i < 40; i++)
        keys[i]=rand()*(6000000/RAND_MAX) + rand()%(6000000/RAND_MAX);

    start=clock();
    for(int i = 0; i<40; i++)
        answers[i]=trans(arr, 1000000, keys[i]);
    finish=clock();
    cout << "Indexes: ";
    for(int i = 0; i<40; i++)
        cout << answers[i] << " ";
    cout << endl << "Linear search with sentinel: " << finish-start << endl;

    start=clock();
    sorte(arr, *(arr+1000000));
    finish=clock();
    cout << endl << "Sorting time: " << finish-start << endl << endl;

    start=clock();
    for(int i = 0; i<40; i++)
        answers[i]=binarysearch(arr, 1000000, keys[i]);
    finish=clock();
    cout << "Indexes: ";
    for(int i = 0; i<40; i++)
        cout << answers[i] << " ";
    cout << endl << "Binary search: " << finish-start << endl;
    return 0;
}
