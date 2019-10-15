#include <math.h>
#include <iostream>

using namespace std;

int main() {
	char uni[200] = { '\0' };
	int size_u = 0;
	int arr1[100] = { 0 };
	int size1;
	int arr2[100] = { 0 };
	int size2;
	int arr3[200] = { 0 };
	int size3 = 0;
	char sign;
	///////////////////// input size1 ///////////////////////////////
	cout << "                  Enter the size of first array :\t";
	cin >> size1;
	do{
		if (size1 > 100 || size1 < 0){
			cout << "  ERROR, size may be only from 1 to 100. Try again :\t";
			cin >> size1;
		}
	} while (size1 > 100 || size1 < 0);
	cout << "======================================================================" << endl;
	////////////////////// input elements1 //////////////////////////////
	for (int i = 0; i < size1; i++) {
		cout << "                  Enter the " << i + 1 << " element of first array :\t";
		cin >> sign;
		int element = -1;
		for (int j = 0; j < size_u; j++) {
			if (sign == uni[j]) {
				element = j;
				break;
			}
		}
		if (element >= 0) {
			arr1[element] = 1;
		}
		else {
			arr1[size_u] = 1;
			uni[size_u] = sign;
			size_u++;
		}
	}
	cout << endl <<"======================================================================" << endl;
	//////////////////// input size2 /////////////////////////////////////
	cout << "                  Enter the size of second array :\t";
	cin >> size2;
	do {
		if (size2 > 100 || size2 < 0) {
			cout << "  ERROR, size may be only from 1 to 100. Try again :\t";
			cin >> size2;
		}
	} while (size2 > 100 || size2 < 0);
	cout << "======================================================================" << endl;
	////////////////////// input elements2 //////////////////////////////
	for (int i = 0; i < size2; i++) {
		cout << "                  Enter the " << i + 1 << " element of second array :\t";
		cin >> sign;
		int element = -1;
		for (int j = 0; j < size_u; j++) {
			if (sign == uni[j]) {
				element = j;
				break;
			}
		}
		if (element >= 0) {
			arr2[element] = 1;
		}
		else {
			arr2[size_u] = 1;
			uni[size_u] = sign;
			size_u++;
		}
	}

	cout << endl <<"======================================================================" << endl;
	
	for (int i = 0; i < size_u; i++) {
		if (arr1[i] == 1 || arr2[i] == 1) {
			arr3[i] = 1;
			size3++;
		}
	}
	char output[100] = { '\0' };
	for (int i = 0, j = 0; i < size_u; i++) {
		if (arr3[i] == 1) {
			output[j] = uni[i];
			j++;
		}
	}
	////////////////////// output /////////////////////////////////
	//cout << " Universum is  " << uni << endl;
	cout << "                  The association = { ";
	for (int i = 0; i < size3; i++) {
		if (i < size3 - 1) {
			cout << output[i]<< ", ";
		}
		else {
			cout << output[i];
		}
	}
	cout << " } " << endl;
	cout << "        |Association| = " << size3 << endl;
	cout << endl << "======================================================================" << endl;
	/////////////////// boolean //////////////////////////////////
	int size_b;
	size_b = (int)pow(2, size3);
	cout << "   Boolean = { ";
	for (int i = 0; i < size_b; i++) {
		cout << " { ";
		for (int j = 0; j < size3; j++) {
			if (i & (1 << j)) {
				cout << output[j] << " ";   
			}
		}
		if (i != size_b - 1) {
			cout << " }, ";
		} else {
			cout << " } } " << endl;
		}
	}
	cout << "        |Boolean| = " << size_b << endl;
	cout << endl;
	cout << "======================================================================" << endl;

	system("pause");
	return 0;
}