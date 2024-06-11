#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

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
                if (b <= 0) {
                    cout << "Error: Division by zero" << endl;
                    return static_cast<T>(0);
                }
                return a / b;
            default:
                cout << "Error: Invalid operator" << endl;
                return static_cast<T>(0);
        }
    }

    bool isInteger(const string &s) {
        for (char const &ch : s) {
            if (!isdigit(ch) && ch != '-') return false;
        }
        return true;
    }

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
        do {
            cout << "Enter operator: ";
            cin >> C.op;
        } while (C.op != '+' && C.op != '-' && C.op != '*' && C.op != '/');
        cout << "Enter your second number: ";
        cin >> C.secondStr;

        cout << "=========================" << endl;

        if (isInteger(C.firstStr) && isInteger(C.secondStr)) {
            int first = stoi(C.firstStr);
            int second = stoi(C.secondStr);
            int calcResult = calculate(first, second, C.op);
            A.result = to_string(calcResult);
            // cout << "The result is: " << A.result << endl;
        } else if (isDouble(C.firstStr) && isDouble(C.secondStr)) {
            double first = stod(C.firstStr);
            double second = stod(C.secondStr);
            double calcResult = calculate(first, second, C.op);
            A.result = to_string(calcResult);
            // cout << "The result is: " << A.result << endl;
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
