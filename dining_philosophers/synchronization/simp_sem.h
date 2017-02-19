/*
 * Provide a simpler and easier to understand interface to the System V
 * semaphore system calls.  There are 7 routines available to the user:
 *
 *	id = sem_create(key, initval);	# create with initial value or open
 *	id = sem_open(key);		# open (must already exist)
 *	sem_wait(id);			# wait = P = down by 1
 *	sem_signal(id);			# signal = V = up by 1
 *	sem_op(id, amount);		# wait   if (amount < 0)
 *					# signal if (amount > 0)
 *	sem_close(id);			# close
 *	sem_rm(id);			# remove (delete)
 *
 */


int
sem_create (key_t key, int initval);

/********************************************************************
 * Open a semaphore that must already exist.
 * This function should be used, instead of sem_create(), if the caller
 * knows that the semaphore msust already exist.  For example a client
 * from a client-server pair would use this, if its the server's
 * responsibility to create the semaphore.
 * We return the semaphore ID if all OK, else -1.
 */

int
sem_open (key_t key);

/********************************************************************
 * Remove a semaphore.
 * This call is intended to be called by a server, for example,
 * when it is being shut down , as we do an IPC_RMID on the semaphore,
 * regardless whether other process may be using it or not.
 * Most other processes should use sem_close() below.
 */

void
sem_rm (int id);


/********************************************************************
 * Close a semaphore.
 * Unlike the remove function above, this function is for a process
 * to call before it exits, when it is done with the semaphore.
 * We "decrement" the counter of processes using the semaphore, and
 * if this was the last one, we can remove the semaphore.
 */

void
sem_close (int id);

/********************************************************************
 * Wait until a semaphore's value is greater than 1, then decrement
 * it by 1 and return.
 * Dijkstra's P operation.  Tannenbaum's DOWN operation.
 */
void
sem_wait (int id);

/********************************************************************
 * Increment a semaphore by 1.
 * Dijkstra's V operation.  Tannenbaum's UP operation.
 */

void
sem_signal (int id);

/********************************************************************
 * General semaphore operation.  Increment or decrement by a user-specified
 * amount (positive or negative; can't be zero).
 */

void
sem_op (int id, int value);
