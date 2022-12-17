#include<string>
#include <iostream>
#include "Header.h"
#include<stack>


using namespace std;

//check if char c is a digit
bool isDigit(char c)
{
	return ((c >= '0' && c <= '9') || c == '.');
}
//check if char c is a operator
bool isOp(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')' || c == '^' || c == '%');
}

//determine the precedence of an operator
int getPrecedence(char c) {
	switch (c)
	{
	case '+':
	case '-': return 1;
	case '*':
	case '%':
	case '/': return 2;
	case '(':
	case ')': return 3;
	case '^': return 4;
	default: return -1;
	}
}
// evaluete an expression 
double operate(double val1, double val2, char c) {
	if (c == '+') return val1 + val2;
	if (c == '-') return val1 - val2;
	if (c == '*') return val1 * val2;
	if (c == '%')return ((val1 * val2) / 100);
	if (c == '^') return pow(val1, val2);
	return val1 / val2;
}
// evaluate a string 
double evaluate(string s) {

	stack <double> vals;
	stack <char> ops;

	double val = 0;
	int pos = 0;
	int i = 1;
	while (pos < s.length())
	{
		char spot = s[pos];
		if (isDigit(spot))
		{
			if (spot == '.')
			{
				pos++;
				spot = s[pos];
				while (isDigit(spot))
				{
					double x = (double)((int)(spot - '0'));
					val = val + (x / pow(10, i));
					i++;
					pos++;
					spot = s[pos];
				}
				i = 1;
				pos--;
			}
			else
				val = (val * 10) + (int)(spot - '0');
		}

		else if (isOp(spot))
		{
			if (spot == '(')
			{
				ops.push(spot);
				val = 0;
			}
			else if (vals.empty())
			{
				vals.push(val);
				ops.push(spot);
				val = 0;
			}
			else if (spot == ')')
			{
				vals.push(val);
				while (ops.top() != '(')
				{
					spot = ops.top();
					ops.pop();
					val = vals.top();
					vals.pop();
					double prev = vals.top();
					vals.pop();
					val = operate(prev, val, spot);
					vals.push(val);
				}
				ops.pop();
				vals.pop();
			}
			else
			{
				char prev = ops.top();

				if (prev == '(')
				{                                 //  
					vals.push(val);               //
					ops.push(spot);               //  добавленный код
					val = 0;                      // 
				}                                 //   

				else if (getPrecedence(prev) < getPrecedence(spot))
				{
					vals.push(val);
					ops.push(spot);
					val = 0;
				}
				else
				{
					double prevval = vals.top();
					vals.pop();
					int prevop = ops.top();
					ops.pop();
					prevval = operate(prevval, val, prevop);
					vals.push(prevval);
					ops.push(spot);
					val = 0;
				}
			}
		}
		pos++;
	}
	while (!ops.empty())
	{
		double prev = vals.top();
		vals.pop();
		char spot = ops.top();
		ops.pop();
		val = operate(prev, val, spot);
	}
	return val;
}