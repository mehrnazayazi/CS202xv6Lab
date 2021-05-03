#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    printf(1, "num of processes %d\n", info(1));
    printf(1, "count of syscalls %d\n", info(2));
    printf(1, "page table  %d\n", info(3));
    exit();
}