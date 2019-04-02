#define led 9
#define button 7
int state = 0;
int old = 0;
int buttonPoll = 0;
int brightness = 0;
int fadeAmount = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  

}

void loop() {
                                        // put your main code here, to run repeatedly:
  buttonPoll = digitalRead(button);
  if(buttonPoll == 1)
  {
    delay (50);
    buttonPoll = digitalRead(button);
    if(buttonPoll == 0)
    {
      state = old + 1;
    }
  }
  else{
    delay(100);
  }
switch (state) {
  case 1:
    //LED High
    analogWrite(led, 125);
    old = state;
    break;
  case 2:
    //LED Low
    analogWrite(led, 80);
    old = state;
    break;
  case 3:
   
    /*LED strobe
     
    analogWrite(led, 125);
    delay(500);
    analogWrite(led, 0);
    delay(500);
    old = state;
    break;
    */
    
  case 4:
    //LED fade
    analogWrite(led, brightness);

    brightness = brightness + fadeAmount;

    if (brightness == 0 || brightness == 125) {
    fadeAmount = -fadeAmount;
    old = state;
  }
  delay(60);
    break;
  default:
    //LED off
    digitalWrite(led, LOW);
    old = 0;
  break;
  
}



  
}
