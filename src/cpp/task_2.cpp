#include <iostream>
#include <string>

using namespace std;

class Problem2 {
public:
    string addUnaryNumbers(const string& num1, const string& num2) {
        string result;
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        // Q1: Start state
        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 2;
            int digit = sum % 2;

            result.insert(result.begin(), digit + '0');

            // Q2: Move to the next position
            i--;
            j--;
        }

        return result;
    }
};

int main() {
    string num1 = "111111";
    string num2 = "111111";

    Problem2 problem;
    string sum = problem.addUnaryNumbers(num1, num2);
    cout << "Sum: " << sum << endl;

    return 0;
}
