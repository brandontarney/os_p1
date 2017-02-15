/*
 * Test Library Function: Example of System Call
 * @author Brandon Tarney
 * @since 2/12/2017
 */

#include <sys/types.h>
#include <stdlib.h>
/*
 * Makes a system call
 */
void std_doHomework1(int isSystemCall)
{
        if (isSystemCall == 1)
        {
                //Test the "test" syscall which should just print a message to stdOut
                message m;
                memset(&m, 0, sizeof(m));
                (void)(_syscall(PM_PROC_NR, PM_HOMEWORK1, &m));
        }
        else
        {
                //make kernel call
        }
}
