#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    printf(1, "count of processes in system %d\n", info(1));
    printf(1, "count of syscalls %d\n", info(2));
    printf(1, "memory pages %d\n", info(3));

    exit();
}
