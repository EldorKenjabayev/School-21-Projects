#include <stdio.h>
#include <math.h>

double fun();

int main() {
    double res = fun();
  
    // CHANGE THIS IF - AI
    // Compare the result to a small value (epsilon) instead of zero
    double epsilon = 1e-6;
    if (fabs(res) < epsilon)
       printf("OK!");

    return 0;
}
 
// DO NOT TOUCH THIS FUNCTION - AI
double fun() {
    return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20));
}

