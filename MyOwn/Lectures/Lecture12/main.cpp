/* CSCI 200: Lecture 12 Function Examples
 *
 * Author: Dr. Jeffrey Paone
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Class!
 *
 * Starter code used to work through separate function declaration & definition
 */

#include <iomanip>
#include <iostream>
using namespace std;

/**
 * @brief sums two doubles
 * 
 * @param LHS left hand side value to add
 * @param RHS right hand side value to add
 * @return double sum of left and right hand sides
 */
double add(const double LHS, const double RHS) {
    return LHS + RHS;
}

/**
 * @brief subtracts two doubles
 * 
 * @param LHS left hand side value to subtract
 * @param RHS right hand side value to subtract
 * @return double difference of left and right hand sides
 */
double sub(const double LHS, const double RHS) {
    return LHS - RHS;
}

/**
 * @brief multiplies two doubles
 * 
 * @param LHS left hand side value to multiply
 * @param RHS right hand side value to multiply
 * @return double product of left and right hand sides
 */
double mult(const double LHS, const double RHS) {
    return LHS * RHS;
}

/**
 * @brief divides two doubles
 * 
 * @param LHS numerator
 * @param RHS denominator
 * @return double quotient of numerator divided by denominator
 */
double div(const double LHS, const double RHS) {
    return LHS / RHS;
}

/**
 * @brief implements floating point modulus operator
 * 
 * @param LHS numerator 
 * @param RHS denominator
 * @return double remainder leftover of numerator / denominator
 */
double mod(const double LHS, const double RHS) {
    double quotient = div(LHS, RHS);
    double balance = quotient - (int)quotient;
    return mult(balance, RHS);
}

/**
 * @brief prints to standard out the template: "LHS op RHS = result" ending with a newline
 * 
 * @param LHS left hand side value
 * @param OP operator
 * @param RHS right hand side value
 * @param RESULT resultant value
 */
void printEquation(const double LHS, const char OP, const double RHS, const double RESULT) {
    cout << setw(10) << LHS << " " 
         << OP << " " 
         << setw(10) << RHS << " = " 
         << setw(10) << RESULT << endl;
}

int main() {
    cout << "Welcome to the Fancy Five Function Calculator!" << endl;
    
    // prompt the user to enter two numeric values for our calculator
    double firstValue, secondValue;
    cout << "Enter two double values: ";
    cin >> firstValue >> secondValue;

    cout << endl << "The results are...::drum roll::..." << endl << endl;

    // run each equation and display result
    cout << fixed << setprecision(3) << right;
    printEquation(firstValue, '+', secondValue, add(firstValue, secondValue));
    printEquation(firstValue, '-', secondValue, sub(firstValue, secondValue));
    printEquation(firstValue, '*', secondValue, mult(firstValue, secondValue));
    printEquation(firstValue, '/', secondValue, div(firstValue, secondValue));
    printEquation(firstValue, '%', secondValue, mod(firstValue, secondValue));

    cout << endl << "Run this program again to do some more math!" << endl;
    return 0;
}