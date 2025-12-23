//Program tp incrypt and decrypt text using block cipher
#include <iostream> 
#include <string> 
using namespace std; 

// This function takes a string as input and returns an encrypted string 
string encrypt(string text, int s) 
{ 
	string result = ""; 

	// traverse text 
	for (int i=0;i<text.length();i++) 
	{ 
		// apply transformation to each character 
		// Encrypt Uppercase letters 
		if (isupper(text[i])) 
			result += char(int(text[i]+s-65)%26 +65); 

	// Encrypt Lowercase letters 
	else
		result += char(int(text[i]+s-97)%26 +97); 
	} 

	// Return the resulting string 
	return result; 
} 

// This function takes a string as input and returns a decrypted string 
string decrypt(string text, int s) 
{ 
	string result = ""; 

	// traverse text 
	for (int i=0;i<text.length();i++) 
	{ 
		// apply transformation to each character 
		// Decrypt Uppercase letters 
		if (isupper(text[i])) 
			result += char(int(text[i]-s-65)%26 +65); 

		// Decrypt Lowercase letters 
		else
			result += char(int(text[i]-s-97)%26 +97); 
	} 

	// Return the resulting string 
	return result; 
} 

// Driver program to test the above functions 
int main() 
{ 
	string text="ATTACK_ON_DEAN"; 
	int s = 4; 
	cout << "Text : " << text; 
	cout << "\nShift: " << s;  
	string encrypted = encrypt(text, s); 
	cout << "\nEncrypted text: " << encrypted; 
	string decrypted = decrypt(encrypted, s); 
	cout << "\nDecrypted text: " << decrypted; 
	return 0; 
}

// Code contributed by Devesh