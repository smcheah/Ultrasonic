#include "mbed.h"
#include "ultrasonic.h"

DigitalOut led1(LED1);

 void dist(int distance)
{
    //put code here to happen when the distance is changed
    printf("Distance changed to %dmm\r\n", distance);
    
    //closest
    if (distance < 80) 
    {
        led1 = 1;
        wait(0.1);
        led1 = 0;
        wait(0.1);
    }
        
    //close
    if (distance > 80 and distance < 120)
    {
        led1 = 1;
        wait(0.2);
        led1 = 0;
        wait(0.2);
    }
    
    //far
    if (distance > 120 and distance < 150) 
    {
        led1 = 1;
    }
}

ultrasonic mu(p21, p9, .2, 2, &dist);    //Set the trigger pin to p21 and the echo pin to p9
                                        //have updates every .1 seconds and a timeout after 1
                                        //second, and call dist when the distance changes

int main()
{
    mu.startUpdates();//start measuring the distance
    while(1)
    {
        //Do something else here
        mu.checkDistance();     //call checkDistance() as much as possible, as this is where
                                //the class checks if dist needs to be called.
    }
}
