/*
 * Test Library Function: Example of System Call
 * @author Brandon Tarney
 * @since 2/12/2017
 */

#include <sys/types.h>
#include <stdlib.h>
void test(void)
{
        //Test the "test" syscall which should just print a message to stdOut
        message m;
        memset(&m, 0, sizeof(m));
        (void)(_syscall(PM_PROC_NR, PM_TEST, &m));
}