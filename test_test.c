#include <sys/cdefs.h>
#include <lib.h>
#include "namespace.h"

#include <string.h>

#include <unistd.h>


void test_test(void)
{
        //Test the "test" syscall which should just print
        message m;
        memset(&m, 0, sizeof(m));
        return(_syscall(PM_PROC_NR, PM_TEST, &m));
}
