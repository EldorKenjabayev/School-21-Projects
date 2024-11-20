// #include <stdio.h>
// #include <stdlib.h>
// int MaxFactor(int N)
// {
//     if (N < 2) return -1;  // некорректное значение
//     int * v = calloc(N+1,sizeof(int));
//     for(int k = 2; k <= N; ++k)
//     {
//         if (v[k]) continue;
//         for(int m = k*2; m <= N; m += k)
//             v[m] = k;
//     }
//     N = v[N] ? v[N] : N;
//     free(v);
//     return N;
// }

// int main(){
//     int num;
//     scanf("%d", &num);
//     num = MaxFactor(num);
//     printf("%d", num);

// }
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
  if (n <= 1) {
    return 0; 
  }
  if (n <= 3) {
    return 1; 
  }

  for (int divisor = 2; divisor <= n; divisor++) {
    while (n >= divisor && n > 0) {
      n -= divisor;
    }
    if (n > 0) {
      
      return 0;
    }
  }
  return 1;
}

int largest_prime_divisor(int n) {
  if (n <= 1) {
    return -1;
  }
  int largest_divisor = -1;
  for (int divisor = 2; n > 1; divisor++) {
    while (n >= divisor && is_prime(n)) {
      n -= divisor;
      largest_divisor = divisor;
    }
  }
  return largest_divisor;
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("n/a\n");
    return 1;
  }

  int largest_prime = largest_prime_divisor(n);
  if (largest_prime == -1) {
    printf("n/a\n");
  } else {
    printf("Largest prime divisor of %d: %d\n", n, largest_prime);
  }

  return 0;
}
