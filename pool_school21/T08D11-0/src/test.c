#include <stdio.h>
#include <limits.h>

int main() {
    int a = ~(1 << (8 * sizeof(int)-1));
    printf("%x", a);
    return 0;
}