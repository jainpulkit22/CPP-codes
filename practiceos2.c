#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

typedef struct{
	int position;
	int count;
	sem_t* leftfork;
	sem_t* rifghtfork;
}philosopher_t;

void createfork(sem_t* forks, int num_philosopher);
void startthreads(pthread_t* threads, sem_t* forks, int num_philosopher);
void* philosophercallback(void* arg);
void eat(philosopher_t* philosopher);
void think(philosopher_t* philosopher);
void takefork(philosopher_t* philosopher);
void returnfork(philosopher_t* philosopher);
int shouldtakeleftfork(philosopher_t* philosopher);
int getrandomnumber(int min,int max);

int main()
{
	int n=getrandomnumber(5,20);
	sem_t forks[n];
	pthread_t threads[n];
	createfork(forks,n);
	startthreads(threads,forks,n);
	pthread_exit(NULL);
	return 0;
}

void createfork(sem_t* forks, int num_philosopher)
{
	for(int i=0;i<num_philosopher;i++)
	{
		sem_init(&forks[i],0,1);
	}
}

void startthreads(pthread_t* threads, sem_t* forks, int num_philosopher)
{
	for(int i=0;i<num_philosopher;i++)
	{
		philosopher_t* philosopher=(philosopher_t *)malloc(sizeof(philosopher_t));
		philosopher->position=i;
		philosopher->count=num_philosopher;
		philosopher->leftfork=&forks[i];
		philosopher->rifghtfork=&forks[(i+1)%num_philosopher];
		pthread_create(&threads[i], NULL, philosophercallback, (void *)philosopher);
	}
}

void* philosophercallback(void* arg)
{
	philosopher_t philosopher=(philosopher_t *)arg;
	while(1)
	{
		think(philosopher);
		takefork(philosopher);
		eat(philosopher);
		returnfork(philosopher);
	}
}