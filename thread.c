

void *mult(void *arg)
{
	int *data = (int *)arg;
	int k = 0, i = 0;

	int x = data[0];
	for (i = 1; i <= x; i++)
		k += data[i] * data[i + x];

	int *p = (int *)malloc(sizeof(int));
	*p = k;

	//Used to terminate a thread and the return value is passed as a pointer
	pthread_exit(p);
}
