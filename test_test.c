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
        printf("Test system call:\n");

        //Test the "test" syscall which should just print a message to stdOut
        message m;
        memset(&m, 0, sizeof(m));
        (void)(_syscall(PM_PROC_NR, PM_TEST, &m));

        printf("\nTest system library:\n");
        //Test the "test" syscall which should just print
        //test();
        return(1);
}
