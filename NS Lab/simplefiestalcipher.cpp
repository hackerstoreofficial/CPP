#include <iostream>
#include <string>

using namespace std;

string encrypt(string plainText, string key)
{
    int n = plainText.length();
    string left = plainText.substr(0, n/2);
    string right = plainText.substr(n/2, n);
    string newRight;
    for(int i = 0; i < n/2; i++)
    {
        newRight += (left[i]^key[i]);
    }
    string cipherText = right + newRight;
    return cipherText;
}

string decrypt(string cipherText, string key)
{
    int n = cipherText.length();
    string left = cipherText.substr(0, n/2);
    string right = cipherText.substr(n/2, n);
    string newLeft;
    for(int i = 0; i < n/2; i++)
    {
        newLeft += (right[i]^key[i]);
    }
    string plainText = newLeft + left;
    return plainText;
}

int main()
{
    string plainText = "This is a plain text";
    string key = "mynameisdev";
    string cipherText = encrypt(plainText, key);
    cout << "Encrypted Text: " << cipherText << "\n";
    string decryptedText = decrypt(cipherText, key);
    cout << "Decrypted Text: " << decryptedText << "\n";
    return 0;
}