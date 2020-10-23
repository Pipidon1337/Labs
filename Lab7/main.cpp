/**
    @brief 4-th lab
    @author Maximov Dmitry
*/
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T> class Stack
{
    std::vector<T> storage;
public:
    inline bool empty() const;
    inline size_t size() const;
    void push(T element);
    T pop();
    T top() const;
};
template<typename T> inline bool Stack<T>::empty() const
{   return storage.empty();
}
template<typename T> inline size_t Stack<T>::size() const
{   return storage.size();
}
template<typename T> void Stack<T>::push(T element)
{   storage.push_back(element);
}
template<typename T> T Stack<T>::pop()
{   if(empty())
        throw std::out_of_range("Stack is empty");
    T last = storage.back();
    storage.pop_back();
    return last;
}
template<typename T> T Stack<T>::top() const
{   if(empty())
        throw std::out_of_range("Stack is empty");
    else return storage.back();
}

int main()
{
    Stack<int> si;
    for(int i = 0; i < 10; ++i)
        si.push(10-i);
    while(!si.empty())
        cout << si.pop() << ' ';
    cout << endl;

    Stack<double> sd;
    for(int i = 0; i < 5; ++i)
        sd.push(i*0.5), cout << sd.top() << ' ';
    cout << endl;

    Stack<std::string> ss;
    try
    {   ss.pop();
    }
    catch(exception &e)
    {   cout << "Error: " << e.what();
    }
}
