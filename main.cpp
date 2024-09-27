#include <iostream>
#include <string>

using namespace std;

class Reversi {
public:
    void printRevese(int number) {
        string str = to_string(number);
        for (int i = str.length(); i >=0; i--) {
            cout << str[i];
        }
        cout << " = 1st Number reversed." << endl;
    }
    /* using to_string method to first make it into a string
     * then using for loop to reverse the value*/
};

class commonDiv {
    public:
    void findCommonDiv(int number, int num2) {
        int common;
        int temp;
        int a;

        if(number<num2) {a = num2;}

        else {a = number;}

        for (int i = 1; i <= a; i++) {
            if (number % i == 0 && num2%i == 0) {
                temp = i;
            }
        }
        common = temp;
        cout << "highest Common divisor: " << common << endl;
    }
    /* has a counter that marks all common divisors starting from 0 to
     * the larger of the two numbers */
};
class checkPalindrome {
    public:
    void isPalindrome(int number) {
        bool isPalindrome = true;

        string str = to_string(number);
        for (int i = 0; i < str.length()/2; i++) {

            if (str[i] != str[str.length() - i - 1] || str.length() % 2 != 0) {
                isPalindrome = false;
            }
        }

        if (isPalindrome == true) {
            cout << "Palindrome" << endl;
        }
        else {cout << "Not a palindrome" << endl;}
    }
    /* switches it to a string using same method as the reversi func then
     * using for loops i compare the first and last values of the string
     * and repeat until i am at the center*/

};
class powerFunc {
public:
    int getPow(int base, int exponent) {
        int result = 1;
        int temp = exponent;
        if (exponent % 2 == 0) {
            for (int i = 1; i <= temp/2; i++) {
                result *= base;
            }
            result *= result;
        }
        else {
            result *=base;
            for (int i = 1; i <= (temp - 1) /2; i++) {
                result *= base;
            }
            result *= result;
        }

        return result;
        /*
         * this method has a O(long n) as by using the properties of exponentials
         * it allows us to do near half the calculations while still achieving the same
         * results by squaring the base and halving the exponent in case of even exponents
         * similarly when the exponent is odd we simply need to reduce it by 1 and then
         * start with that number from the beginning as the result and do as we did for the even number
         * thus reducing the time copmplexity from linear to exponential
         */
    }
};

class powerOfTwo {
    public:
    bool isPO2(int k) {
        if ((k > 0) && ((k & (k - 1)) == 0)) {
            return true;
        }
        else{return false;}
    }
    /* bitmanipulation first we enure k is greater that 0 then we use the bit wise AND operation
     *on k and k-1 which will always give zero in the case of a power of 2
     * right most 1 bit becomes 0 and all following bits become 1 when AND(ing) this
     * with the origional value of k it becomes 0 */
};

int main() {
    int number;
    int num2;

    cout << "Enter 2 numbers: ";
    cin >> number;
    cin >> num2;
    cout << "Number: " << number << endl;
    cout << "Number2: " << num2 << endl;

    Reversi re;
    re.printRevese(number);

    commonDiv cd;
    cd.findCommonDiv(number, num2);

    checkPalindrome cp;
    cp.isPalindrome(number);

    int base;
    int exponent;

    cout << "Enter base num and exponent: " << endl;

    cin >> base;
    cin >> exponent;

    powerFunc pf;
    int a = pf.getPow(base, exponent);
    cout << " base" << base << " to the power of " << exponent << " = " << a << endl;

    int k;

    cout << "enter K: " << endl;

    cin >> k;

    powerOfTwo pt;
    cout << "Is " << k << " a power of 2? " << (pt.isPO2(k)  ? "Yes" : "No") << endl;

    return 0;
}

