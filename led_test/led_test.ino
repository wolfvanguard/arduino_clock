/*
Author: Keertikumar Kubareea
Testin the RGB LED module with 3 pins
Digital pin 2 -> red pin on module
Digital pin 3 -> green pin on module
Digital pin 4 -> blue pin on module
*/

int red = 2;
int green = 3;
int blue = 4;

void setup(){
    Serial.begin(115200);

    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);

}

void loop(){
    //LED displays only RED colour
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
}