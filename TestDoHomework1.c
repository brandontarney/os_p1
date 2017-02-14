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
        printf("Test direct system call: \n");
        //Test the syscall which should just print a message to stdOut
        message m;
        memset(&m, 0, sizeof(m));
        (void)(_syscall(PM_PROC_NR, PM_HOMEWORK1, &m));

        printf("\nTest library system call: \n");
        //Test the syscall which should just print
        //std_doHomework1(true);

        printf("Test direct kernel call: \n");
        //call _kernel_call()

        printf("Test library kernel call: \n");
        //Test the kernel call which should just print
        //std_doHomework1(false);

        return(1);
}
