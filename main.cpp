#include <iostream>
#include <stack>

using namespace std;


void wellBalancedExpresion(string expression) {

    stack<char> pila;

    bool error = 0;

    for(char& c : expression) {
        if(c == '[' || c == '(') {
            pila.push(c);
        } else {
            if(c == ']') {

                if (!pila.empty() && '[' == pila.top())
                    pila.pop();
                else
                    error = 1;
            } else if(c == ')') {
                if (!pila.empty() && '(' == pila.top())
                    pila.pop();
                else
                    error = 1;
            }
        }
    }
    // que passa si queden parentisi oberts
    if (!pila.empty())
        error = 1;


    if (error==1)
        cout << expression << "  Error!" << endl;
    else
        cout << expression << "  WELL BALANCED!" << endl;
}


void BinaryRepresentationOfNumber(int number){

    cout << number << endl;
/**/
    char a = number;
    std::bitset<8> x(a);
    std::cout << "bitset:\t" << x << endl;

    std::cout << "div by 2:\t";
    while (number>1) {
        std::cout << number%2;
        number = number/2;
    }
    std::cout << number << endl;

}

void multipop() {


}


int main() {

    std::cout << "Check Well balanced expression" << std::endl;

    wellBalancedExpresion("");
    wellBalancedExpresion("[]");
    wellBalancedExpresion("[a]");
    wellBalancedExpresion("[(())]");

    wellBalancedExpresion(")");
    wellBalancedExpresion("[");
    wellBalancedExpresion("[)");
    wellBalancedExpresion(")]");
    wellBalancedExpresion("[((])");
    wellBalancedExpresion("[[((])]");


    std::cout << "Binary Representation Of a Number" << std::endl;

    BinaryRepresentationOfNumber(5);
    BinaryRepresentationOfNumber(31);
    BinaryRepresentationOfNumber(64);


    return EXIT_SUCCESS;
}


