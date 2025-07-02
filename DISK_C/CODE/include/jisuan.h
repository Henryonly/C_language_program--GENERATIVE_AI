#ifndef _calculate_h_
#define _calculate_h_

void reverse(char *str);
int compare(char *num1,char *num2);
void add(char *num1,char *num2,char *result);
void subtract(char *num1,char *num2,char *result);
void real_add(char *num1,char *num2,char *result);
void multiply(char *num1,char*num2,char *result);
void real_multiply(char *num1, char *num2, char *result);
void reciprocal(char *input,char *output);
int isPrime(long long int num);
long long int gcd(long long int a,long long int b);

#endif
