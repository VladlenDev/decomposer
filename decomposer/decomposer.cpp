//

#include <iostream>
#include <string>

using namespace std;

bool is_int(string str) {
    if (str.length() > 9)
        return false;
    string::const_iterator it = str.begin();
    while (it != str.end() && (isdigit(*it) || *it == '-')) ++it;
    return !str.empty() && it == str.end();
}

string decompose(string str_num) {
    int num = stoi(str_num);
    int length, pos;
    string str_out;

    if (str_num[0] == '-') {
        str_out = "-";
        length = str_num.length() - 1;
        pos = 1;
    }
    else {
        length = str_num.length();
        pos = 0;
    }

    for (pos; pos < str_num.length(); pos++) {
        str_out += str_num[pos];
        --length;
        for (int i = 0; i < length; i++) {
            str_out += '_';
        }
    }

    return str_out;
}

int main()
{
    string str_num("INVALID_NUMBER");

    while (str_num != "q") {

        cout << "Enter integer. To exit enter 'q'.\n";
        cin >> str_num;

        if (str_num == "q") {
            break;
        }
        else if (!is_int(str_num)) {
            cout << "It is not an integer. Try again.\n";
        }
        else {
            cout << decompose(str_num) << endl;
        }
    }
    return 0;
}