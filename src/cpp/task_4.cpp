#include <iostream>
#include <string>

using namespace std;

class Problem4 {
public:
    string multiplyNumbers(const string& num1, const string& num2) {
        string result;

        // Q1: Start state
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        while (j >= 0) {
            int digit2 = num2[j] - '0';

            if (digit2 == 1) {
                result = addUnaryNumbers(result, num1);

                // Q2: Move to the next position
                i = num1.length() - 1;
            }

            // Q3: Move to the next digit
            j--;
        }

        return result;
    }

private:
    string addUnaryNumbers(const string& num1, const string& num2) {
        string result;
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 2;
            int digit = sum % 2;

            result.insert(result.begin(), digit + '0');

            // Q4: Move to the next position
            i--;
            j--;
        }

        return result;
    }
};

int main() {
    string num1 = "111111";
    string num2 = "11111";

    Problem4 problem;
    string product = problem.multiplyNumbers(num1, num2);
    cout << "Product: " << product << endl;

    return 0;
}
