/* This C++ code is able to convert between many number systems,
such as decimal,binary,octal and hexa*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Decimal to Binary Conversion
string decimalToBinary(int num) {
    if (num == 0) return "0";

    string binary = "";
/* use while loop to divide by 2 repeatedly until the result is 0
if there is a remainder, 1 is stored
if no remainder, 0 is stored
finally it will reverse the order of digits*/
    while (num > 0) {
        binary += (num % 2) + '0';
        num /= 2;
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

// Binary to Decimal Conversion
int binaryToDecimal(string binary) {
    int decimal = 0;
/* start from left to right
multiply number by 2
add the bit*/
    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }

    return decimal;
}

// Decimal to Octal Conversion
string decimalToOctal(int num) {
    if (num == 0) return "0";

    string octal = "";
/* divide by 8 
store the remainder
finally, reverse the string */
    while (num > 0) {
        octal += (num % 8) + '0';
        num /= 8;
    }

    reverse(octal.begin(), octal.end());
    return octal;
}

// Octal to Decimal Conversion
int octalToDecimal(string octal) {
    int decimal = 0;
/*start from left
multiply by 8 
add the current digit
*/
    for (char digit : octal) {
        decimal = decimal * 8 + (digit - '0');
    }

    return decimal;
}

// Decimal to Hexadecimal Conversion
string decimalToHex(int num) {
    if (num == 0) return "0";

    string hex = "";
    string digits = "0123456789ABCDEF";
/*divide by 16 repeatedly,
convert the remainder to hexa which is from 0-9 and A-F
reverse the final string */
    while (num > 0) {
        hex += digits[num % 16];
        num /= 16;
    }

    reverse(hex.begin(), hex.end());
    return hex;
}

// Hexadecimal to Decimal Conversion
int hexToDecimal(string hex) {
    int decimal = 0;
/*start from left to right
multiply by 16 repeatedly
convert the characters to 0-9 and A-F*/
    for (char c : hex) {
        if (c >= '0' && c <= '9')
            decimal = decimal * 16 + (c - '0');
        else if (c >= 'A' && c <= 'F')
            decimal = decimal * 16 + (c - 'A' + 10);
        else if (c >= 'a' && c <= 'f')
            decimal = decimal * 16 + (c - 'a' + 10);
    }

    return decimal;
}

int main() {
    int choice;

    do {
        cout << "\n===== NUMBER SYSTEM CONVERTER =====\n";
        cout << "1. Decimal to Binary\n";
        cout << "2. Binary to Decimal\n";
        cout << "3. Decimal to Octal\n";
        cout << "4. Octal to Decimal\n";
        cout << "5. Decimal to Hexadecimal\n";
        cout << "6. Hexadecimal to Decimal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int num;
            cout << "Enter decimal number: ";
            cin >> num;
            cout << "Binary: " << decimalToBinary(num) << endl;
            break;
        }

        case 2: {
            string binary;
            cout << "Enter binary number: ";
            cin >> binary;
            cout << "Decimal: " << binaryToDecimal(binary) << endl;
            break;
        }

        case 3: {
            int num;
            cout << "Enter decimal number: ";
            cin >> num;
            cout << "Octal: " << decimalToOctal(num) << endl;
            break;
        }

        case 4: {
            string octal;
            cout << "Enter octal number: ";
            cin >> octal;
            cout << "Decimal: " << octalToDecimal(octal) << endl;
            break;
        }

        case 5: {
            int num;
            cout << "Enter decimal number: ";
            cin >> num;
            cout << "Hexadecimal: " << decimalToHex(num) << endl;
            break;
        }

        case 6: {
            string hex;
            cout << "Enter hexadecimal number: ";
            cin >> hex;
            cout << "Decimal: " << hexToDecimal(hex) << endl;
            break;
        }

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}