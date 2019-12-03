#include <iostream>
#include <math.h>

using namespace std;


void Print(int* a, int n)
{
	 static int num = 1;                  
	cout <<"\t\t\t"<< num++ << ":  ";
	for (int i = 0; i < n; i++) {            // вивід комбінацій
		cout << a[i] << " ";
	}
	cout << endl;
}

////////////// лексикографічний порядок /////////////////
bool Set(int* a, int n, int m)
{
	int j = m - 1;                              // перший елемент справа
	while (j >= 0 && a[j] == n) j--;
	if (j < 0) return false;
	if (a[j] >= n) j--;
	a[j]++;
	if (j == m - 1) return true;
	for (int k = j + 1; k < m; k++) {
		a[k] = 1;
	}
	return true;
}
//////////////////////////////////////////////////////////

int factorial(int a) {                             // функція факторіалу
	if (a == 1) {
		return a;
	}
	else if (a == 0)
	{
		return 1;
	}
	return a * factorial(a - 1);
}

long long int koef(int n, int k) {                                  // значення С
	return factorial(k) / (factorial(n) * factorial(k - n));
}

int main()
{
	/////////////// first part /////////////////////

	cout << endl << "\t______________FIRST_TASK________________" << endl<<endl;
	int n, m, * a;
	cout << "\tEnter N : ";                         // із скількох елементів будемо вибирати
	cin >> n;
	cout << "\tENTER M : ";                         // по скільки елементів будемо вибирати
	cin >> m;
	int size = n > m ? n : m;                       // обирається розмір масиву
	a = new int[size];
	for (int i = 0; i < size; i++) {                // створення масиву вибірки
		a[i] = 1;
	}
	Print(a, m);
	while (Set(a, n, m)) {
		Print(a, m);
	}
	cout << endl;

	////////////////// second part ///////////////////
	cout << endl << "\t______________SECOND_TASK________________" << endl;
	long long int x, y;
	cout << endl << "\tEnter X:";
	cin >> x;
	cout << "\tEnter Y:";
	cin >> y;
	cout << endl << "   THE RESULT : " << endl << endl;
	if (x == y) {                                          // випадок, коли х та у рівні
		cout << "(x + y)^7 = 0";
		return 0;
	}
	long long int bin = 0;
	int p = 7;                                             // степінь до якого підносимо
	for (int i = 0; i <= p; ++i)                           // обчислення бінома
	{
		bin += koef(i, p) * pow(x, i) * pow(y, p - i);
	} 
	cout << "(x + y)^7 = ";
	for (int i = 0; i < p; ++i) {                          // розкладання
		if (i % 2)  cout << " - "; 
		else {
			cout << " + ";
		}  
		cout << koef(i, p) << " * (x^" << i << ") * (y^" << p - i << ")";
	} 
	cout << " = " << bin << "\n";
	cout << endl << endl << endl;
	
	system("pause");
	return 0;
}