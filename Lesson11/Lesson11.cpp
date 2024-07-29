#include <iostream>
#include <string>

using namespace std;

string encrypt_caesar(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        }
        result += c;
    }
    return result;
}

string decrypt_caesar(string text, int shift) {
    return encrypt_caesar(text, -shift);
}

int main() {
    string text;
    int shift;

    cout << "Enter the text to encrypt: ";
    getline(cin, text);
    cout << "Enter the shift: ";
    cin >> shift;

    string encrypted = encrypt_caesar(text, shift);
    string decrypted = decrypt_caesar(encrypted, shift);

    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

}
