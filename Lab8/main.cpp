//файл должен начинаться со слова, между словами один пробел
#include <stdio.h>
#include <iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string s1;
    string s[30];
    ifstream ifs("file1.txt");
    int count=0;
    while(getline(ifs, s1, ' ')){
        s[count]=s1;
        count++;
    }
    ifs.close();
    string temp;
    for(int i=0;i<30;i+=2){
        temp=s[i];
        s[i]=s[i+1];
        s[i+1]=temp;
    }
    for(int i=0;i<30;i++){
        cout<<s[i]<<" ";
    }
    getch();
}
