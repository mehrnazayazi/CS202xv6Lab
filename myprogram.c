#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    printf(1, "num of processes %d\n", getnum(1));
    printf(1, "count of syscalls %d\n", getnum(2));
    printf(1, "page table  %d\n", getnum(3));
    exit();
}