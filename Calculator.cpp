#include<string>
#include <iostream>
#include"Header.h"
#include<stack>

using namespace std;

int main()
{
	/*string s;
	cout << "enter primer: ";
	cin >> s;
	cout << evaluate(s);*/
	cout << evaluate("3^(2+1)+3");
	cout << endl;
	cout << evaluate("3*4+5") << " = 17" << endl;
	cout << evaluate("3+4+5") << " = 12" << endl;
	cout << evaluate("3+4*5") << " = 23" << endl;
	cout << evaluate("(3+4)*5") << " = 35" << endl;

	cout << evaluate("(25/5)+3") << " = 8";
	return 0;
}



