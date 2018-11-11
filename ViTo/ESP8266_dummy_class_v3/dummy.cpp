#include "dummy.h"
Dummyclass::Dummyclass() 
{

}

void Dummyclass::dummyfunction()
{
    delay(1);

}
void Dummyclass::sleepfunction(unsigned long functioSleeptime)
{
    delay(functioSleeptime);
    Serial.print(functioSleeptime);
    Serial.println("functioSleeptime");

}

