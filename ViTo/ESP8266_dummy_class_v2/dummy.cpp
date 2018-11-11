#include "dummy.h"
Dummyclass::Dummyclass() 
{

}

void Dummyclass::dummyfunction()
{
    delay(100);
    Serial.print("print");
    Serial.println("println");

}

