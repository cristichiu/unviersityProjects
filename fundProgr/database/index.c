#include <stdio.h>
#include "extern/db_q.h"

int main() {
    stiva_q *idk = test(10,1);
    printf("%d", isEmpty_q(idk));
    return 0;
}