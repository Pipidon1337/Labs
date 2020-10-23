#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

void bublesorting(int *array, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void quicksorting(int *array, int size, int first, int last)
{
    int mid, temp;
    int f = first, l = last;
    mid = array[(f+l)/2];
    do
    {
        while (array[f]<mid)
        {
            f++;
        }
        while (array[l]>mid)
        {
            l--;
        }
        if(f<=l)
        {
            temp = array[f];
            array[f] = array[l];
            array[f] = temp;
            f++;
            l--;
        }
    }
    while (f<l);
    {
        if(first<l)
        {
            quicksorting(array, size, first, l);
        }
        if(f<last)
        {
            quicksorting(array, size, f, last);
        }
    }
}

int main()
{
    int *array;
    int size, first = 0, last;
    cout << "Enter size of array " << endl;
    cin >> size;
    last = size - 1;
    array = new int [size];
    srand(time(NULL)); // заполнение массива слуачайными числами
    for(int i = 0; i < size; i++)
    {
        array[i] = 1 + rand() % 1000;
    }
    ofstream ent("entered.txt");
    for(int i = 0; i < size; i++)
    {
        ent << array[i] << " ";
    }
    ent.close();
    double start1 = clock();
    bublesorting(array, size);
    ofstream bl("bublesorted.txt");
    for(int i = 0; i < size; i++)
    {
        bl << array[i] << " ";
    }
    bl.close();
    double end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("The time of bublesorting: %f seconds\n", seconds1);
    double start2 = clock();
    quicksorting(array, size, first, last);
    ofstream qs("quicksorted.txt");
    for(int i = 0; i < size; i++)
    {
        qs << array[i] << " ";
    }
    qs.close();
    double end2 = clock();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("The time quicksorting: %f seconds\n", seconds2);
    return 0;
}
