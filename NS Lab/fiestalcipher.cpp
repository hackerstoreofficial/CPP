#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string Encrypt(string plaintext,int round,int key[])
{
	int n = plaintext.length();
	// string of size 2n
	string X = plaintext + plaintext;
	for (int j = 0; j < round; j++)
	{
		string left = X.substr(0, n);
		string right = X.substr(n, n);
		// key mixing
		string temp = "";
		for (int i = 0; i < n; i++)
			temp += (char)((int)left[i] ^ key[j]);
		// permutation
		temp = right.substr(n - 2, 2) + temp.substr(2, n - 2) + temp.substr(0, 2);
		X = temp + right;
	}
	return X;
}

string Decrypt(string cipher, int round, int key[])
{
	int n = cipher.length() / 2;
	string X = cipher;
	for (int j = round - 1; j >= 0; j--)
	{
		string left = X.substr(0, n);
		string right = X.substr(n, n);
		// permutation
		string temp = right.substr(0, 2) + left.substr(2, n - 2) + left.substr(n - 2, 2);
		// key mixing
		for (int i = 0; i < n; i++)
			temp[i] = (char)((int)temp[i] ^ key[j]);
		X = temp + right;
	}
	return X.substr(0, n);
}

int main()
{
	int round;
	string plaintext;
	int key[8]; // 8-bit key
	cout << "Enter the 8-bit key : ";
	for (int i = 0; i < 8; i++)
		cin >> key[i];
	cout << "Enter the round : ";
	cin >> round;
	cout << "Plaintext : ";
	cin >> plaintext;

	string cipher = Encrypt(plaintext, round, key);
	cout << "Ciphertext : " << cipher << endl;
	cout << "Decrypted Text : " << Decrypt(cipher, round, key);
	return 0;
}