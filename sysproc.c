#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
    myproc()->sysnum +=1;
    return fork();
}

int
sys_exit(void)
{
    myproc()->sysnum +=1;
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
    myproc()->sysnum +=1;
  return wait();
}

int
sys_kill(void)
{
    myproc()->sysnum +=1;
    int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
    myproc()->sysnum +=1;
  return myproc()->pid;
}

int
sys_sbrk(void)
{
    myproc()->sysnum +=1;
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
    myproc()->sysnum +=1;
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
    myproc()->sysnum +=1;
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int
sys_info(void)
{
    myproc()->sysnum +=1;
    int func;
    if(argint(0, &func) < 0)
        return -1;
    if(func == 1){
        return getNumProc();
    }
    else if (func == 2){
        return myproc()->sysnum;
    }
    else if(func == 3){
        return myproc()->sz/PGSIZE;
    } else{
        return -1;
    }

}

int sys_settickets(void)
{
    myproc()->sysnum +=1;
    int n;
    if(argint(0, &n) < 0)
        return -1;
    myproc()->tickets = n;
    return n;
}

int sys_setstrides(void)
{
    myproc()->sysnum +=1;
    int n;
    if(argint(0, &n) < 0)
        return -1;
    myproc()->default_stride = n;
    myproc()->stride = n;
    return n;
}