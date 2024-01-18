#include <iostream>
#include <string>

using namespace std;

class Problem3 {
public:
    string compareNumbers(const string& num1, const string& num2) {
        string result;

        // Q1: Start state
        if (num1.length() < num2.length()) {
            result = "11";
        } else if (num1.length() > num2.length()) {
            result = "1";
        } else {
            int i = 0;

            // Q2: Compare digits
            while (i < num1.length()) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[i] - '0';

                if (digit1 < digit2) {
                    result = "11";
                    break;
                } else if (digit1 > digit2) {
                    result = "1";
                    break;
                }

                // Q3: Move to the next digit
                i++;
            }

            // Q4: Numbers are equal
            if (i == num1.length()) {
                result = "1";
            }
        }

        return result;
    }
};

int main() {
    string num1 = "10101";
    string num2 = "1001";

    Problem3 problem;
    string comparisonResult = problem.compareNumbers(num1, num2);
    cout << "Comparison Result: " << comparisonResult << endl;

    return 0;
}
