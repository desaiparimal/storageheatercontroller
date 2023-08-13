#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int tRunning = 0;

struct stream_data{
  ssize_t length;
  char *string;
  size_t buffer_size;
};

void* pollstdin (void* info)
{
    struct stream_data *stream = (struct stream_data *)malloc(sizeof(struct stream_data));
    stream->string = NULL;
    stream->length = 0;
    stream->buffer_size = 0 ;
    while((stream->length = getline(&(stream->string), &(stream->buffer_size), stdin)) != -1 ){
        if (stream->length > 0)
            printf ("\n  read %zd chars from stdin, allocated %zd bytes for line : %s\n",
                     stream->length, stream->buffer_size, stream->string);
        if(stream->length != 49){
            printf("Enter 48digits only\n");
            continue;
        } else{
            for (int i = 0 ;i < stream->length - 1 ; i++){
                int status = stream->string[i] - '0';
                if(!(status == 0 || status == 1)){
                    printf("Enter either 0 or 1 digits only \n");
                    continue;
                }
            }
        }
        tRunning = 1;
        return (void*) stream;
    }
    return (void *)stream;
}
void *timer(void *vargp)
{
    struct stream_data *new = (struct stream_data *) vargp;
    if(new == NULL)
        pthread_exit(pthread_self());

	unsigned int x_seconds=0;
	unsigned int x_milliseconds=0;
	unsigned int count_down_time_in_secs=0,time_left=0;
	clock_t x_startTime,x_countTime;
	count_down_time_in_secs=1800;  // 1 minute is 60, 1 hour is 3600
    tRunning = 0 ;
    for (int i = 0 ; i < new->length - 1 ; i++ ){
        x_seconds=0 ; 
        if(new->string[i] - '0')
            printf("ON\n");
        else    
            printf("OFF\n");

        x_startTime=clock();  // start clock
        time_left=count_down_time_in_secs-x_seconds;   // update timer

        while (time_left > 0 && !tRunning) {
            x_countTime=clock(); // update timer difference
            x_milliseconds=x_countTime-x_startTime;
            x_seconds=(x_milliseconds/(CLOCKS_PER_SEC));

            time_left=count_down_time_in_secs-x_seconds; // subtract to get difference 
            if(tRunning == 1)
                pthread_exit(pthread_self());

        }
        printf( "  Time's out\n");
    }
    return (void*) 0;
}
   
int main(){
    struct stream_data *new = NULL ;
    //unsigned minutes = 0;

    //printf ("\nEnter minutes for heater timer \n");
    //scanf("%u",&minutes);
    printf ("\nEnter schedule in a string below and enter ,press [ctrl + d] to quit\n");

    pthread_t thread_id1,thread_id2;

    while (1) {

        pthread_create(&thread_id1, NULL, pollstdin, NULL);
        pthread_join(thread_id1, (void **)&new);

        if(new ==  NULL || new->length == -1){
            tRunning = 1; //stopping the timer thread
            return 0;
        }

        pthread_create(&thread_id2, NULL, timer, (void *)new);
    }    
    return 0;
}