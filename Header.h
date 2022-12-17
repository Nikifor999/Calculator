#pragma once
#include<string>
#include <iostream>
#include<stack>

using namespace std;

bool isDigit(char c);
bool isOp(char c);
int getPrecedence(char c);
double operate(double val1, double val2, char c);
double evaluate(string s);
