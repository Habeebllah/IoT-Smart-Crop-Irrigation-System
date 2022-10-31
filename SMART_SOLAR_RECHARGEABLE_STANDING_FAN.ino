int power = 8;
int light = 7;
int speed_up = 13;
int speed_down = 3;
String readString;

void setup() {
  Serial.begin(9600);            //Set rate for communicating with phone

  pinMode(power, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(speed_up, OUTPUT);
  pinMode(speed_down, OUTPUT);


}

void loop() {
  while (Serial.available())   //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#') {
      break;                   //Stop the loop once # is detected after a word
    }
    readString = c;                //Means readString = readString + c
  }

  if (readString.length() > 0) 
  {
    Serial.println(readString);
    if (readString == "4") {
      digitalWrite(power, HIGH);
      delay(1000);
    }

    else if (readString == "2") {
      digitalWrite(power, LOW);
      delay(1000);
    }

    else if (readString == "3") {
      digitalWrite(light, HIGH);
      delay(1000);
    }

    else if (readString == "1") {
      digitalWrite(light, LOW);
      delay(1000);
    }

    else if (readString == "5") {
      digitalWrite(speed_up, HIGH);
      delay(1000);
    }

    
    else if (readString == "6") {
      digitalWrite(speed_up, LOW);
      delay(1000);
    }

    
    else if (readString == "7") {
      digitalWrite(speed_down, HIGH);
      delay(1000);
    }

  
    else if (readString == "8") {
      digitalWrite(speed_down, LOW);
      delay(1000);
    }
    

   
    }
}
