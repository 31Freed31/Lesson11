#include <iostream>
#include <string>

using namespace std;

bool isValidOctet(string octet) {
    if (octet.length() == 0 || octet.length() > 3) return false;

    if (octet.length() > 1 && octet[0] == '0') return false;

    for (int i = 0; i < octet.length(); i++) {
        if (octet[i] < '0' || octet[i] > '9') return false;
    }

    int num = stoi(octet);
    if (num < 0 || num > 255) return false;

    return true;
}

bool isValidIPAddress(string ip) {
    int dotCount = 0;
    string octet = "";

    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') {
            if (!isValidOctet(octet)) return false;
            octet = "";
            dotCount++;
        }
        else {
            octet += ip[i];
        }
    }

    if (!isValidOctet(octet)) return false;

    return dotCount == 3;
}

int main() {
    setlocale(LC_CTYPE, "rus");

    string ip;
    cout << "Введите IP-адрес: ";
    getline(cin, ip);

    if (isValidIPAddress(ip)) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
}
