/*
 * Example of System Call
 * @author Brandon Tarney
 * @since 2/12/2017
 */

#include <sys/cdefs.h>
//#include "namespace.h"
#include <lib.h>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <signal.h>

int main()
{
        printf("Test system call: \n");
        //Test the "test" syscall which should just print a message to stdOut
        message m;
        memset(&m, 0, sizeof(m));
        (void)(_syscall(PM_PROC_NR, PM_HOMEWORK1, &m));

        printf("\nTest system library call: \n");
        //Test the "test" syscall which should just print
        //homework1();

        printf("Test kernel call: \n");
        //call _kernel_call()

        printf("Test system library kernel call: \n");
        //modify "test()" to take an optional boolean input flag:
        //Either make the system call or make the kernel call 

        return(1);
}
