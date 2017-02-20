/*
 * This program will test a solution to the dining philosophers
 * - 5 philosophers can think, get hungry, or eat. They need 2 forks to eat, on on each sid eof their plate
 * - This program implements the testing of an algorithm which will not only synchronize and provide mutual exclusion for the forks but also optimally use them (so they don't go to waste)
 * - The solution tested creates a thread for each dining philosopher and uses semaphores (mutexs) to lock/unlock forks for the philosophers to eat. Each philosopher/thread will attempt to eat up to 5 times resulting in each eating once. 
 *
 * @Author  Brandon Tarney
 * @Date    02/18/2017    
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "diners.h"

int main(int argc, char *argv[])
{
    mutex = sem_create(1, 1);
    s[0] = sem_create(2,1);
    s[1] = sem_create(3,1);
    s[2] = sem_create(4,1);
    s[3] = sem_create(5,1);
    s[4] = sem_create(6,1);
    printf("Mutex id = %d \n", mutex);
    if (mutex == -1) 
    {
            printf("MUTEX ERROR");
    }
	pthread_t diner1, diner2, diner3, diner4, diner5;
	int rtn_val;
    int id1 = 0;
    int id2 = 1;
    int id3 = 2;
    int id4 = 3;
    int id5 = 4;

            if (rtn_val = 
                            pthread_create( &diner1, NULL, philosopher, (void*) &id1) ||
                            pthread_create( &diner2, NULL, philosopher, (void*) &id2) ||
                            pthread_create( &diner3, NULL, philosopher, (void*) &id3) ||
                            pthread_create( &diner4, NULL, philosopher, (void*) &id4) ||
                            pthread_create( &diner5, NULL, philosopher, (void*) &id5) 
                        ) 
            {
                    fprintf (stderr, "pthread_create: Error %d (%d)\n", rtn_val, errno);
            }

    pthread_join (diner1, NULL);
    pthread_join (diner2, NULL);
    pthread_join (diner3, NULL);
    pthread_join (diner4, NULL);
    pthread_join (diner5, NULL);

    exit(0);
}

