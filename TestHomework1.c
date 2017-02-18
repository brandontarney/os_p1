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
#include "minix/syslib.h"
#include "syslib.h"

#include <string.h>
#include <signal.h>

int main()
{
        printf("\nTest direct system call: \n");
        //Test the syscall which should just print a message to stdOut
        message m;
        memset(&m, 0, sizeof(m));
        (void)(_syscall(PM_PROC_NR, PM_HOMEWORK1, &m));

        printf("\nTest library system call: \n");
        //Test the syscall which should just print
        int isSystemCall = 1;
        int tmp = rand();
        bjt_SystemCall();

        printf("\nTest library kernel call: \n");
        //Test the syscall which should just print
        int isSystemCall = 1;
        bjt_SystemCall();

        /*
        printf("\nTest direct kernel call: \n");
        message m2;
        _kernel_call(SYS_SAMPLE, &m2);

        printf("\nTest library kernel call: \n");
        //Test the kernel call which should just print
        int result = sys_sample();

        printf("\n sanity library check I'm calling sys_exit\n");
        sys_exit();
        */


        return(1);
}
