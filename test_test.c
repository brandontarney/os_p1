/*
 * Example System Call
 * @author Brandon Tarney
 * @since 2/12/2017
 */

#include <sys/cdefs.h>
//#include "namespace.h"
#include <lib.h>

#include <string.h>
#include <signal.h>

int main()
{
        //Test the "test" syscall which should just print
        message m;
        memset(&m, 0, sizeof(m));
        return(_syscall(PM_PROC_NR, PM_TEST, &m));
}
