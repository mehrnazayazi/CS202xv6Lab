#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char *argv[]) {
    settickets(5);
    setstrides(30);
    int i,k;
    const int loop=43000;
    for(i=0;i<loop;i++) {
        printf(1,"prog3 %d\n",i);// write your own function here
        asm("nop"); //in order to prevent the compiler from optimizing the for loop
        for(k=0;k<loop;k++) {
            asm("nop");
        }
    }
    exit();
}