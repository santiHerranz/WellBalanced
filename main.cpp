


#include <iostream>
#include <stack>
#include "cua_amb_2_piles.h"

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






char* PopKElements(stack<char> pila, int count) {

    char* str = (char *) malloc(count+1 * sizeof(char));

    for (int i = 0; i < count ; ++i) {
        str[i] = pila.top();
        pila.pop();
    }
    str +='\0';

    return str;

}






int main() {

    std::cout << "***Binary Representation Of a Number" << std::endl;

    BinaryRepresentationOfNumber(5);
    BinaryRepresentationOfNumber(31);
    BinaryRepresentationOfNumber(64);



    std::cout << "\n\n***Pop K Elements\n" << std::endl;

    stack<char> pila;

    pila.push('t');
    pila.push('a');
    pila.push('t');
    pila.push('i');
    pila.push('s');
    pila.push('r');
    pila.push('e');
    pila.push('v');
    pila.push('i');
    pila.push('n');
    pila.push('U');

    char* result = PopKElements(pila, 7);
    std::cout << "result: " << result <<"\n\n" << std::endl;



    std::cout << "\n\n***Queue Using Two Stacks" << std::endl;
    queueUsingTwoStacks();

    return EXIT_SUCCESS;
}



