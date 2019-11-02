#include <iostream>
#include <math.h>

using namespace std;

void Output(int arr[], int size);
int fact(int n);

int main() {
	int A[50];
	int size_a;
	int B[50];
	///////////////// creation ///////////////////
	cout << endl << "\t============CREATION_OF_SETS============" << endl << endl;

	cout << "\tChoose a size of sets (n*n) : ";
	cin >> size_a;
	//Check(size_a, 1, 50);
	do {
		if (size_a > 50 || size_a < 0) {
			cout << "  ERROR, try again :\t";
			cin >> size_a;
		}
	} while (size_a > 50 || size_a < 0);

	cout << "\tFill A-set of numbers : " << endl;
	for (int i = 0; i < size_a; i++) {
		cout << "\t";
		cin >> A[i];
	}
	cout << "    .................................................." << endl;

	cout << "\tFill B-set of numbers : " << endl;
	for (int i = 0; i < size_a; i++) {
		cout << "\t";
		cin >> B[i];
	}
	//////////////// output ///////////////////
	cout << "\t\t   YOUR_SETS_ARE : " << endl << endl;
	cout << "\t\tA = ";
	Output(A, size_a);
	cout << "\t\tB = ";
	Output(B, size_a);

	//////////// creation of relation ////////////////
	cout <<endl << "\t============BINARY_RELATION============" << endl;
	cout << endl << "\tCartesian  product of A and B ( A * B ) is :" << endl << endl;

	for (int i = 0; i < size_a; i++) {                             // output of product
		for (int j = 0;  j < size_a;  j++)
		{
			cout << "\t";
			cout << "(" << A[i] << ", " << B[j] << ")";
		}
		cout << endl;
	}
	cout << endl;
	cout << "    .................................................." << endl;
	cout << "\tCouples which satisfy the condition :" << endl;      // output of couples which satisfy the condition
	int counter = 0;
	for (int i = 0; i < size_a; i++) {
		for (int j = 0; j < size_a; j++)
		{
			if ((A[i] + 2) > 3 * B[j]) {
				cout << "(" << A[i] << ", " << B[j] << ")" << "    ";
			}
			else {
				counter++;
			}
		}
	}
	if (counter == size_a * size_a) {
		cout << " Couples are not found...";
	}
	cout << endl << endl;
	////////////// matrix of relation /////////////
	cout << "\t============MATRIX_OF_RELATION============" << endl << endl;
	int prod[100][100];
	for (int i = 0; i < size_a; i++)                  // filling with appropriate values
	{
		for (int j = 0; j < size_a; j++)
		{
			if ((A[i] + 2) > 3 * B[j]) {
				prod[i][j] = 1;
			}
			else {
				prod[i][j] = 0;
			}

		}
	}

	for (int i = 0; i < size_a; i++)              // output of matrix
	{
		cout << "\t";
		for (int j = 0; j < size_a; j++)
		{
			cout << prod[i][j] << "    ";
		}
		cout << endl;
	}
	cout << endl << endl;
	//////// types of relation ///////////
	cout << "\t===========Types_of_relation============" << endl << endl;
	cout << "\tThis relation is :" << endl;
	if (counter == size_a * size_a) {
		cout << "\tEmpty";
	}
	else {
		/////////// reflexive ///////////////
		int ref = 0;
		for (int i = 0; i < size_a; i++)
		{
			if (prod[i][i] == 1) {
				ref++;
			}
		}
		if (ref == size_a) {
			cout << "\t\tReflexive " << endl;
		}

		///////////// antireflexive //////////////
		int aref = 0;
		for (int i = 0; i < size_a; i++)
		{
			if (prod[i][i] == 0) {
				aref++;
			}
		}
		if (aref == size_a) {
			cout << "\t\tAntireflexive " << endl;
		}

		///////////// symmetrical /////////////////
		int sym = 0;
		for (int i = 0; i < size_a; i++)
		{
			for (int j = 0; j < size_a; j++)
			{
				if ((prod[i][j] == prod[j][i]) && i!=j ) {
					sym++;
				}
			}
		}
		if (sym == pow(size_a, 2) - size_a ) {
			cout << "\t\tSymmetrical" << endl;
		}

		///////// antisymmetrical ///////////////
		int asym = 0;
		for (int i = 0; i < size_a; i++)
		{
			for (int j = 0; j < size_a; j++)
			{
				if (prod[i][j] == prod[j][i]) {
					asym++;
				}
			}
		}

		if (asym == 0) {
			cout << "\t\tAntisymmetrical" << endl;
		}

		//////////// transitive //////////////
		int tranz = 0;

		for (int i = 0; i < size_a; i++)
		{
			for (int j = 0; j < size_a; j++)
			{
				if (prod[i][j] == 1)
				{
					for (int k = 0; k < size_a; k++)
					{
						if (prod[j][k] == 1)
						{
							if (prod[i][k] == 1)
							{
								tranz = 1;
							}
							else {
								tranz = 0;
							}
						}
					}
				}
			}
		}

		if (tranz == 1) {
			cout << "\t\tTransitive" << endl;
		}
		if (tranz == 0) {
			cout << "\t\tNot transitive" << endl;
		}
	
		if (ref == size_a && sym == pow(size_a, 2) && tranz == 1)
		{
			cout << "\tThe type of relation is : " << endl <<"\t\tEquivalence" << endl;
		}
		if (ref == size_a && sym == pow(size_a, 2))
		{
			cout << "\tThe type of relation is : " << endl << "\t\tCompatibility" << endl;
		}
		if (ref == size_a && asym == 0 && tranz == 1)
		{
			cout << "\tThe type of relation is : " << endl << "\t\tPartial order" << endl;
		}
		if (aref == size_a && asym == 0 && tranz == 1)
		{
			cout << "\tThe type of relation is : " << endl << "\t\tFull order" << endl;
		}
	}
	cout << endl << endl;
	cout << "    .................................................." << endl;

	system("pause");
	return 0;
}
void Output(int arr[], int size) {
	cout << " { ";
	for (int i = 0; i < size; i++) {
		if (i == (size - 1)) {
			cout << arr[i] << " ";
		}
		else {
			cout << arr[i] << ", ";
		}
	}
	cout << "} " << endl;
}
