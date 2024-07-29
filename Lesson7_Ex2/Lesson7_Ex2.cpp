#include <iostream>
#include <string>

using namespace std;

const string LOCAL_VALID_CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-/=?^_`{|}~.";
const string DOMAIN_VALID_CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";

bool isValidCharacter(char c, const string validCharacters) {
    return validCharacters.find(c) != -1;
}

bool isValidLocalPart(string local) {
    if (local.length() == 0 || local.length() > 64) return false;
    if (local[0] == '.' || local[local.length() - 1] == '.') return false;

    for (int i = 0; i < local.length(); i++) {
        if (!isValidCharacter(local[i], LOCAL_VALID_CHARACTERS)) return false;
        if (i > 0 && local[i] == '.' && local[i - 1] == '.') return false;
    }
    return true;
}

bool isValidDomainPart(string domain) {
    if (domain.length() == 0 || domain.length() > 63) return false;
    if (domain[0] == '.' || domain[domain.length() - 1] == '.') return false;

    for (int i = 0; i < domain.length(); i++) {
        if (!isValidCharacter(domain[i], DOMAIN_VALID_CHARACTERS)) return false;
        if (i > 0 && domain[i] == '.' && domain[i - 1] == '.') return false;
    }
    return true;
}

bool isValidEmail(string email) {
    int atPos = email.find('@');
    if (atPos == -1) return false;

    string localPart = email.substr(0, atPos);
    string domainPart = email.substr(atPos + 1);

    return isValidLocalPart(localPart) && isValidDomainPart(domainPart);
}

int main() {
    setlocale(LC_CTYPE, "rus");

    string email;
    cout << "Введите email-адрес: ";
    getline(cin, email);

    if (isValidEmail(email)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}