
  
  // defines the pin values for each component
  int blue1 = 12;
  int green = 11;
  int yellow = 10;
  int red = 9;
  int blue2 = 8;
  int buzzer = 7;
  int button1 = 13;
  int button2 = 6;
  int startButton = 5;
  bool buttonPressed = 0;

// setup code
void setup() {
  
  // define each component as an output
  pinMode(blue1, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // defines buttons as switches
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);


  // allows for randomization
  randomSeed(analogRead(A0));

}

// main code which runs repeatedly
void loop() {

// checks if the start button has been pressed - the game will not start otherwise
if (digitalRead(startButton) == 0)  
{

  digitalWrite(green, HIGH); // turns on the green LED
  digitalWrite(buzzer, HIGH); // turns on the buzzer
  delay(250); // 250 ms delay
  digitalWrite(buzzer, LOW); // turns buzzer off
  delay(750); // 750 ms delay
  digitalWrite(green, LOW); // turns off green LED
  digitalWrite(yellow, HIGH); // turns on the green LED
  digitalWrite(buzzer, HIGH); // turns on the buzzer
  delay(250); // 250 ms delay
  digitalWrite(buzzer, LOW); // turns buzzer off
  delay(750); // 750 ms delay
  digitalWrite(yellow, LOW); // turns off yellow LED
  digitalWrite(red, HIGH); // turns on red LED
  digitalWrite(buzzer, HIGH); // turns on buzzer
  delay(250); // 250 ms delay
  digitalWrite(buzzer, LOW); // turns off buzzer
  delay(random(400, 4901)); // generates a random delay for the red light
  digitalWrite(red, LOW); // turns off red LED
 

 while(buttonPressed == 0) // executes if no button is pressed
 {
  digitalWrite(blue1, HIGH); // turns on first blue LED
  digitalWrite(blue2, HIGH); // turns on second blue LED
  if (digitalRead(button1) == 0) // checks if first button has been pressed
  {
    buttonPressed = 1; // sets the buttonPressed flag high
    digitalWrite(blue2, LOW); // turns off second blue LED
    digitalWrite(buzzer, HIGH); // turns buzzer on
    delay(1000); // 1 sec delay
    digitalWrite(buzzer, LOW); // turns  buzzer off
  }
  else if (digitalRead(button2) == 0) // checks if second button has been pressed
  {
    buttonPressed = 1; // sets the buttonPressed flag high
    digitalWrite(blue1, LOW); // turns off first blue LED
    digitalWrite(buzzer, HIGH); // turns buzzer on
    delay(1000); // 1 sec delay
    digitalWrite(buzzer, LOW); // turns  buzzer off
  }
 }

digitalWrite(blue1, LOW); // turns off first blue LED
digitalWrite(blue2, LOW); // turns off second blue LED
buttonPressed = 0; // sets the buttonPressed flag low 
delay(1000); // 1 sec delay

}

}
