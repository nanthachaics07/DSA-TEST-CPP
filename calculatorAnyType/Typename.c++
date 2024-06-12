#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <type_traits>

using namespace std;

class Calculator {
private:
    template<typename T>
    T calculate(T a, T b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b == 0) {
                    cout << "Error: Division by zero" << endl;
                    return static_cast<T>(0);
                }
                return a / b;
            case '%':
                // Modulus operator only applicable to integers
                if (!isIntegerType<T>()) {
                    cout << "Error: Modulus operator '%' can only be used with integers" << endl;
                    return static_cast<T>(0);
                }
                return a % b;
            default:
                cout << "Error: Invalid operator" << endl;
                return static_cast<T>(0);
        }
    }

    // Check if T is an integer type
    template<typename T>
    bool isIntegerType() {
        return is_same<T, int>::value || is_same<T, long>::value || is_same<T, long long>::value ||
               is_same<T, unsigned int>::value || is_same<T, unsigned long>::value ||
               is_same<T, unsigned long long>::value || is_same<T, short>::value ||
               is_same<T, unsigned short>::value || is_same<T, char>::value;
    }

    // Check if the string represents a valid integer
    bool isInteger(const string &s) {
        for (char const &ch : s) {
            if (!isdigit(ch) && ch != '-') return false;
        }
        return true;
    }

    // Check if the string represents a valid double
    bool isDouble(const string &s) {
        istringstream iss(s);
        double d;
        char c;
        return iss >> d && !(iss >> c);
    }

    struct Answer {
        string result;

        Answer(string S = "") : result(S) {}
    };
    Answer A;

    struct ConAns {
        string firstStr, secondStr;
        char op;
    };
    ConAns C;

public:
    Calculator& insertNums() {
        cout << "Enter your first number: ";
        cin >> C.firstStr;

        // Validate operator
        do {
            cout << "Enter operator (+, -, *, /, %): ";
            cin >> C.op;
        } while (C.op != '+' && C.op != '-' && C.op != '*' && C.op != '/' && C.op != '%');

        cout << "Enter your second number: ";
        cin >> C.secondStr;

        cout << "=========================" << endl;

        // Validate input and perform calculation
        if (isInteger(C.firstStr) && isInteger(C.secondStr)) {
            int first = stoi(C.firstStr);
            int second = stoi(C.secondStr);
            int calcResult = calculate(first, second, C.op);
            A.result = to_string(calcResult);
        } else if (isDouble(C.firstStr) && isDouble(C.secondStr)) {
            double first = stod(C.firstStr);
            double second = stod(C.secondStr);
            double calcResult = calculate<double>(first, second, C.op);
            A.result = to_string(calcResult);
        } else {
            A.result = "Error: Inconsistent or invalid number types";
        }
        return *this;
    }

    void pstring() {
        cout << "The result is: " << A.result << endl;
    }
};

int main() {
    Calculator C;
    C.insertNums().pstring();
    return 0;
}
