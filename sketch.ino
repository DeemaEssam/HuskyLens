#include "HUSKYLENS.h"
HUSKYLENS huskylens;
//HUSKYLENS green line >> SDA; blue line >> SCLvoid printResult(HUSKYLENSResult result);
const int led = 7;
void setup() {//digitalWrite(led, HIGH);
    Serial.begin(115200);    Wire.begin();
    while (!huskylens.begin(Wire))    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));        Serial.println(F("2.Please recheck the connection."));
        delay(100);    }
}
void loop() {    if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned())       Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available())       digitalWrite(led,LOW);
    else
    {        Serial.println(F("###########"));
        while (huskylens.available())        {
            HUSKYLENSResult result = huskylens.read();            printResult(result);
        }        }
}
void printResult(HUSKYLENSResult result){    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);        digitalWrite(led, HIGH);
    }    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);        digitalWrite(led, HIGH);
    }    else{
        Serial.println("Object unknown!");    }
}
