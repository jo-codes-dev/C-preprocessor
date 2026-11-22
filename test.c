#include <stdio.h>

// Simple (object-like) macros
#define PI 3.14159
#define MAX_LIMIT 100

/*
 * Function-like (parameterized) macros
 * Multi-line comment test
 */
#define SQUARE(x) ((x) * (x))
#define SUM(a, b) ((a) + (b))

int main() {
    int radius = 5;
    int PI_COUNT = 10; // Should NOT be replaced by PI (whole-word check)

    // Test object-like and function-like macros
    double area = PI * SQUARE(radius);
    int total = SUM(MAX_LIMIT, PI_COUNT);

    /* Test comments and macro names inside string literals */
    printf("URL: http://example.com /* not a comment */\n");
    printf("Escaped quote: \"// still inside string\"\n");
    printf("Macro name in string: PI = %.2f\n", area);
    printf("Total: %d\n", total);

    return 0;
} // End of main
