#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int x, y, z;
	// Data input
	cout << "Enter number x:" << endl;
	cin >> x;
	cout << "Enter number y:" << endl;
	cin >> y;
	cout << "Enter number z:" << endl;
	cin >> z;
	// Data checking
	if ((x != 1 && x != 0) || (y != 1 && y != 0) || (z != 1 && z != 0))
	{
		cout << " Error, numbers can be only 1 or 0" << endl;
		cout << "Try again :" << endl;
		cout << "Enter number x:" << endl;
		cin >> x;
		cout << "Enter number y:" << endl;
		cin >> y;
		cout << "Enter number z:" << endl;
		cin >> z;
		cout << " Here are results :" << endl;
	}
	else
	{
		cout << " Here are results:" << endl;
	}
	// Results output
	if (x == 0 && y == 0 && z == 0)
	{
		cout << "y v z   : 0" << endl;
		cout << "-( y ^ z )   : 1" << endl;
		cout << "x ~ ( y v z)   : 1" << endl;
		cout << "x ~ -( y ^ z )   : 0" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 0" << endl;
	}
	else if (x == 0 && y == 0 && z == 1) {
		cout << "y v z   : 1" << endl;
		cout << "-( y ^ z )   : 1" << endl;
		cout << "x ~ ( y v z)   : 0" << endl;
		cout << "x ~ -( y ^ z )   : 0" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 1" << endl;
	}
	else if (x == 0 && y == 1 && z == 0) {
		cout << "y v z   : 1" << endl;
		cout << "-( y ^ z )   : 1" << endl;
		cout << "x ~ ( y v z)   : 0" << endl;
		cout << "x ~ -( y ^ z )   : 0" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 1" << endl;
	}
	else if (x == 0 && y == 1 && z == 1) {
		cout << "y v z   : 1" << endl;
		cout << "-( y ^ z )   : 0" << endl;
		cout << "x ~ ( y v z)   : 0" << endl;
		cout << "x ~ -( y ^ z )   : 1" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 0" << endl;
	}
	else if (x == 1 && y == 0 && z == 0) {
		cout << "y v z   : 0" << endl;
		cout << "-( y ^ z )   : 1" << endl;
		cout << "x ~ ( y v z)   : 0" << endl;
		cout << "x ~ -( y ^ z )   : 1" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 0" << endl;
	}
	else if (x == 1 && y == 0 && z == 1) {
		cout << "y v z   : 1" << endl;
		cout << "-( y ^ z )   : 1" << endl;
		cout << "x ~ ( y v z)   : 1" << endl;
		cout << "x ~ -( y ^ z )   : 1" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 1" << endl;
	}
	else if (x == 1 && y == 1 && z == 0) {
		cout << "y v z   : 1" << endl;
		cout << "-( y ^ z )   : 1" << endl;
		cout << "x ~ ( y v z)   : 1" << endl;
		cout << "x ~ -( y ^ z )   : 1" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 1" << endl;
	}
	else {
		cout << "y v z   : 1" << endl;
		cout << "-( y ^ z )   : 0" << endl;
		cout << "x ~ ( y v z)   : 1" << endl;
		cout << "x ~ -( y ^ z )   : 0" << endl;
		cout << "( x ~ ( y v z ) ) ~ ( x ~ -( y ^ z ) )   : 0" << endl;
	}
	system("pause");
	return 0;

}
