#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <typeinfo> 
using namespace std;
string reverse(string s){
	string aux = "";
	for (int i=s.length();i>=0;i--){
		char temp = s[i];
		aux = aux + temp;
	}
	return aux;
}
int getx (string array,char x){
	int final = 0;
	int lengthArray = array.length();
	for (int i = 0;i <= lengthArray;i++ ){
		if (x == array[i]){
			final = i;
		}

	}
	return final;
}
string d_to_base (int n, int base){
	string alfabeth [26] = {"A","B","C","D","E","F","G","H","I","J",
							"K","L","M","N","O","P","Q","R","S","T",
							"U","V","W","X","Y","Z"};
	int number = n;
	int aux1;
	string aux2,basenumberstring = "";
	
	int count = 0;
	bool is_negative = false;
	if (n < 0){
		is_negative = true;
		number = number * -1;
	}
	if (base < 1){
		cout << "Base invalida. \n";
		return "Base invalida";
	}
	else if (base > 1 && base <= 10){
		while(true){
			aux1 = number % base;
			aux2 = to_string(aux1);
			if (number < base){
				basenumberstring += aux2;
				if (is_negative){
					basenumberstring += "-";
				}
				return reverse(basenumberstring);
			}
			basenumberstring += aux2;
			number = number/base;
		}
	}
	else if (base > 10 && base <= 26){
		while(true){
			aux1 = number % base;
			aux2 = to_string(aux1);
			if (number < base){
				
				if (aux1 > 9) {
					basenumberstring = basenumberstring + alfabeth[aux1-10];
				}
				else {
					basenumberstring = basenumberstring + aux2;
				}
				if (is_negative){
					basenumberstring += "-";
				}
				return reverse(basenumberstring);
			}
			if (aux1 > 9) {
				basenumberstring = basenumberstring + alfabeth[aux1-10];
				}
			else {
				basenumberstring = basenumberstring + aux2;
			}
			number = number/base;

		}
	}
	else{
		return "Base muito grande (maior que 26) \n";
	}
	
}