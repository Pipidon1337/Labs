#include <iostream>

using namespace std;


template <typename A>
A sum_seq(A *array, int n){
    A sum = 0;
    for(int i = 0; i < n; i++){
        sum+= array[i];
    }
    return sum;
}

template <typename A>
A average_seq(A *array, int n){
    A sum = 0;
    for(int i = 0; i < n; i++){
        sum+= array[i];
    }
    sum = sum/n;
    return sum;
}

template <typename A>
A max_element(A *array, int n){
    A max = -1000;
    for (int i = 0; i < n ; i++){
        if (array[i]>max)
        {
            max=array[i];
        }
    }
    return max;
}

template <typename A>
A min_element(A *array, int n){
    A min = 1000;
    for (int i = 0; i < n ; i++){
        if (array[i]<min)
        {
            min=array[i];
        }
    }
    return min;
}

int main(){
    int n = 5;

    int array[n] = {1, 3, 6, 8, 9};

    cout << "Sum of all elements is " << sum_seq(array, n) << endl;
    cout << "Minimum element is " << min_element(array, n)<< endl;
    cout << "Maximum element is " << max_element(array, n)<< endl;
    cout << "Average arithmetic number is " << average_seq(array, n) << endl;
}
