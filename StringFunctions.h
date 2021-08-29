#ifndef STRINGFUNCTIONS_H_INCLUDED
#define STRINGFUNCTIONS_H_INCLUDED

/**
 * This function convert string (type: string) into number (type: int)
 * @param [in] array, which you want to convert
 * @param [out] number from the string
*/
int myAtoi(const char* str);

/**
 * This function convert string (type: string) into number (type: int)
 * It works only with positive numbers
 * @param [in] array, which you want to convert
 * @param [out] number from the string
*/
int convertToNumber(const char* str, const int stringLength);

/**
 * This function convert number (type: int) into string (type: string)
 * @param [in] number - the number you want to convert
 * @param [in] base - the system of numeration
 * @param [out] str - string. Into this string we put the converted number
*/
char* myItoa(int number, const int base);

/**
 * This function counts the number of digits
 * @param [in] The number in which we want to know the amount of digits
 * @param [out] number of digits
*/
int amountOfDigits(int number);

/**
 * This function compare to strings. If both string are equal it
 * returns 0. This function returns positive number if
 * first string bigger inlexicographical order.
 * Otherwise it returns negative number.
 * @param [in] first string
 * @param [in] second string
 * @param [out] positive number if first string bigger string in lexicographical order
 *              negative number else
 *              Zero if the both strings are equal
*/
int myStrcmp(const char* firstString, const char* secondString);

/**
 * This function prints the string
 * @param [in] str - string that we want to print
 * @param [out] If we can`t print the string, it returns EOF
 *              Otherwise it returns positive number
*/
int myPuts(const char* str);
#endif // STRINGFUNCTIONS_H_INCLUDED
