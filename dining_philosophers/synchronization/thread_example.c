/*
 * this program prints out a familar message using two threads.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void *print_message_function( void *ptr ); 

int
main(int argc, char *argv[])
{
	pthread_t thread1, thread2;
	int rtn_val;
	char *message1 = "Hello ";
	char *message2 = "World\n";

	if ((rtn_val = pthread_create( &thread1, NULL,
		    print_message_function, (void*) message1)) != 0)
	{
		fprintf (stderr, "pthread_create1: Error %d (%d)\n", rtn_val, errno);
	}
	if ((rtn_val = pthread_create(&thread2, NULL, 
		    print_message_function, (void*) message2)) != 0)
	{
		fprintf (stderr, "pthread_create2: Error %d (%d)\n", rtn_val, errno);
	}

	pthread_join (thread1, NULL);
	pthread_join (thread2, NULL);

	exit(0);
}
  
void *print_message_function( void *ptr )
{
	char *message;
	message = (char *) ptr;
	printf("%s", message);
}
