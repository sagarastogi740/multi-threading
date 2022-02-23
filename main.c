#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

static void * thread_function_callback(void *arg){
    char *input = (char *)arg;
    int a=0;
    while(a<10){
        printf("input string=%s\n",input);
        a++;
        sleep(1);
    }
    pthread_exit(0);
}

void thread_create(){
    pthread_t pthread;
    static const char str[]="I am thread 1";
    int rc = pthread_create(&pthread,NULL,thread_function_callback,(void *)str);
    if(rc!=0){
        printf("Error occurred, thread could not be created, error_no=%d\n",rc);
        exit(0);
    }
}

int main(int argc, char **argv){
    thread_create();
    printf("Main function paused\n");
    pthread_exit(0);
    return 0;
}