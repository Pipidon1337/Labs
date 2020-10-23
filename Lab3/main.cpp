#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;


int main() //начало функции main
{
    ifstream dataFile;
    ofstream resFile;
    dataFile.open("data.txt");
    if (!dataFile.is_open())
    {
        return 23;
    }
    resFile.open("res.txt", ios::out | ios::trunc);
    if (!resFile.is_open())
    {
        return 45;
    }
    string number;
    string operation;
    string type_operands;
    string operand1;
    string operand2;
    string type_res;
    string prev_number = "qk";
    {
        dataFile >> number;
        if (number == prev_number)
        {
            break;
        }
        dataFile >> operation;
        dataFile >> operand1;
        dataFile >> operand2;
        dataFile >> type_res;
        resFile << number << ' ';
        int i;
        if (operation == "+") i = 1
        if (operation == "-") i = 2;
        if (operation == "*") i = 3;
        if (operation == "/") i = 4;
        if (operation == "pow") i = 5;
        switch (i)
        {
            case 1:
            {
                if (type_operands == "int")
                {
                    stringstream streamOp1(operand1);
                    int x = 0;
                    streamOp1 >> x;
                    stringstream streamOp2(operand2);
                    int y = 0;
                    streamOp2 >> y;
                    resFile << x+y << ' ';
                }
                else
                {
                    if (type_operands == "float")
                    {
                        stringstream streamOp1(operand1);
                        float x = 0;
                        streamOp1 >> x;
                        stringstream streamOp2(operand2);
                        float y = 0;
                        streamOp2 >> y;
                        if (type_res == "int")
                        {
                            float res_float = x+y;
                            int res_int = static_cast<int>(res_float+0.5);
                            resFile << res_int << ' ';
                        }
                        else
                        {
                            resFile << x+y << ' ';
                        }
                    }
                    else
                    {
                        resFile << operand1+operand2 << ' '
                    }
                }
                break;
            }
            case 2:
            {
                if (type_operands == "int")
                {
                    stringstream streamOp1(operand1);
                    int x = 0;
                    streamOp1 >> x;
                    stringstream streamOp2(operand2);
                    int y = 0;
                    streamOp2 >> y;
                    resFile << x-y << ' ';
                }
                else
                {
                    stringstream streamOp1(operand1);
                    float x = 0;
                    streamOp1 >> x;
                    stringstream streamOp2(operand2);
                    float y = 0;
                    streamOp2 >> y;
                    if (type_res == "int")
                    {
                        float res_float = x-y;
                        int res_int = static_cast<int>(res_float+0.5);
                        resFile << res_int << ' ';
                    }
                    else
                    {
                        resFile << x-y << ' ';
                    }
                }
                break;
            }
            case 3:
            {
                if (type_operands == "int")
                {
                    stringstream streamOp1(operand1);
                    int x = 0;
                    streamOp1 >> x;
                    stringstream streamOp2(operand2);
                    int y = 0;
                    streamOp2 >> y;
                    resFile << x*y << ' ';
                }
                else
                {
                    stringstream streamOp1(operand1);
                    float x = 0;
                    streamOp1 >> x;
                    stringstream streamOp2(operand2);
                    float y = 0;
                    streamOp2 >> y
                    if (type_res == "int")
                    {
                        float res_float = x*y;
                        int res_int = static_cast<int>(res_float+0.5);
                        resFile << res_int << ' ';
                    }
                    else
                    {
                        resFile << x*y << ' ';
                    }
                }
                break;
            }
            case 4:
            {
                if (!(operand2 == "0"))
                {
                    if (type_operands == "int")
                    {
                        stringstream streamOp1(operand1);
                        int x = 0;
                        streamOp1 >> x;
                        stringstream streamOp2(operand2
                        int y = 0;
                        streamOp2 >> y;
                        resFile << x/y << ' ';
                    }
                    else
                    {
                        stringstream streamOp1(operand1);
                        float x = 0;
                        streamOp1 >> x;
                        stringstream streamOp2(operand2);
                        float y = 0;
                        streamOp2 >> y;
                        if (type_res == "int")
                        {
                            float res_float = x/y;
                            int res_int = static_cast<int>(res_float+0.5);
                            resFile << res_int << ' ';
                        }
                        else
                        {
                            resFile << x/y << ' ';
                        }
                    }
                }
                else
                {
                    resFile << "NaN" << ' ';
                }
                break;
            }
            case 5:
            {
                if (type_operands == "int")
                {
                    stringstream streamOp1(operand1);
                    int x = 0;
                    streamOp1 >> x;
                    stringstream streamOp2(operand2);
                    int y = 0;
                    streamOp2 >> y;
                    resFile << pow(x, y) << ' ';
                }
                else
                {
                    stringstream streamOp1(operand1);
                    float x = 0;
                    streamOp1 >> x;
                    stringstream streamOp2(operand2);
                    float y = 0;
                    streamOp2 >> y;
                    if (type_res == "int")
                    {
                        float res_float = pow(x, y);
                        int res_int = static_cast<int>(res_float+0.5);
                        resFile << res_int << ' ';
                    }

                    else
                    {
                        resFile << pow(x, y) << ' ';
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
        resFile << type_res << endl;
        prev_number = number;
    }
    resFile.close();
    dataFile.close();
    return 0;
}
