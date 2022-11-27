/* 
Show a joystick postition in a signle 7-segment display


Code for the joystick control taken from here: 
https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0
*/



int VRx = A0;
int VRy = A1;
int SW = 3;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int displayLeftB = 13;
int displayBottom = 12;
int displayRightB = 11;
int displayPoint = 10;

int displayRightT = 8;
int displayTop = 7;
int displayLeftT = 6;
int displayCenter = 5;

// Save state (on/off) of point in display
bool isPointOn = false;
// Used to disrupt repeating changes of point status when button is pressed
bool buttonLock = false;

int allDisplayPins[] = {displayLeftB, displayBottom, displayRightB, displayRightT, displayTop, displayLeftT, displayCenter};


void clearDisplay() {
  for (int i=0; i<7; i++) {
    digitalWrite(allDisplayPins[i], LOW);
  }
}


void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}




void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, 0, 3);
  mapY = map(yPosition, 0, 1023, 0, 2);
  
  // Debug information
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);


  clearDisplay();
  if (mapY == 0) {
    // Left bars in display
    if (mapX <= 1) {
      digitalWrite(displayLeftB, HIGH);
    } else {
      digitalWrite(displayLeftT, HIGH);      
    }
  } else if (mapY == 1) {
    // Center bars in display
    if (mapX == 0) {
      digitalWrite(displayBottom, HIGH);
    } else if (mapX == 3) {
      digitalWrite(displayTop, HIGH);
    } else {
      digitalWrite(displayCenter, HIGH);
    }
  } else {
    // Top bars in display
    if (mapX <= 1) {
      digitalWrite(displayRightB, HIGH);
    } else {
      digitalWrite(displayRightT, HIGH);      
    }
  }

  if (SW_state == 0 && !buttonLock) {
    buttonLock = true;
    isPointOn = !isPointOn;
    if (isPointOn) {
      digitalWrite(displayPoint, HIGH);
    } else {
      digitalWrite(displayPoint, LOW);
    }
  } else {
    buttonLock = false;
  }

  delay(100);
  
}
