#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int timecalc(int minutes){
    unsigned int x_seconds=0;
	unsigned int x_milliseconds=0;
	unsigned int count_down_time_in_secs=0,time_left=0;
	clock_t x_startTime,x_countTime;
	count_down_time_in_secs=minutes*60;  // 1 minute is 60secs, 1 hour is 3600

 
    x_startTime=clock();  // start clock
    time_left=count_down_time_in_secs-x_seconds;   // update timer

	while (time_left>0)	{
		x_countTime=clock(); // update timer difference
		x_milliseconds=x_countTime-x_startTime;
		x_seconds=(x_milliseconds/(CLOCKS_PER_SEC));

		time_left=count_down_time_in_secs-x_seconds; // subtract to get difference

		//printf( "\nYou have %d seconds left ( %d ) count down timer ",time_left,
        //          count_down_time_in_secs);
	}


	printf( "\n\n\nTime's out\n\n\n");
    return 0;

}

int main(){
    char *str = NULL;
    size_t len = 0;     /* ignored when line = NULL */
    ssize_t read;
    unsigned minuets = 0;

    printf ("\nEnter minutes for heater timer \n");
    scanf("%u",&minuets);
    printf ("\nEnter schedule in a string below [ctrl + d] to quit\n");

    while ((read = getline(&str, &len, stdin)) != -1) {

        if (read > 0)
            printf ("\n  read %zd chars from stdin, allocated %zd bytes for line : %s\n", read, len, str);

        // convert first string char to int
        if(timecalc(30))
            //if times out read next int from string
            
        printf ("Enter string below [ctrl + d] to quit\n");
    }    
    return 0;
}