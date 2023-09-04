#include <iostream>
#include "baseconverter.h"

int main (){
	int number;
	string bin,oct,hex;
	cout << "Digite um numero em decimal: ";
	cin >> number;
	bin = d_to_base (number,2);
	oct = d_to_base (number,8);
	hex = d_to_base (number,16);
	cout << "Binario: "<<bin << endl << "Octal: " << oct << endl << "Hexadecimal: " << hex << endl ;
	return 0;
}