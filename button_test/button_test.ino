
const int button = 2; 
const int red = 5;
const int green = 6;
const int blue = 7;
/*
Mode 1 - working; colour = blue
Mode 2 - reading; color = light blue (blue + green)
Mode 3 - game time; color = purple (red + blue)
Mode 4 - meditation time; color = green
*/
const String mode[] = {"Work Mode", "Reading mode", "Game Mode", "Meditation mode"};
volatile int current_mode_index = 0;

void setup(){
    Serial.begin(115200);
    pinMode(button, INPUT_PULLUP);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(button), buttonPressed, FALLING); //WHEN UNPRESSED, THE BUTTON DIGITAL READ = 1. When pressed, the button digital read is 0
    Serial.println("Setup done");
}
void loop(){

    switch(current_mode_index){
        case 0:
            setColor(LOW, LOW, HIGH); // BLUE
            break;
        case 1:
            setColor(LOW, HIGH, HIGH); // LIGHT BLUE
            break;
        case 2:
            setColor(HIGH, LOW, HIGH); // PURPLE
            break;
        default:
            setColor(LOW, HIGH, LOW); // GREEN
            break;
    }
    
}

void buttonPressed(){
    current_mode_index = (current_mode_index + 1) % 4;
}


/*Current module does not support analog write to rgb pins, will turn on the red/green/blue pin completely*/
void setColor(uint8_t red_value, uint8_t green_value, uint8_t blue_value){
    digitalWrite(red, red_value);
    digitalWrite(green, green_value);
    digitalWrite(blue, blue_value);

}