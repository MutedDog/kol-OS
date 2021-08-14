int input=0;
int pin=0;
int func=0;
String mode="";
void setup() {
  Serial.begin(9600);
  Serial.println("Starting kol-OS v1.2...");
  Serial.println("made by Kolos");
  Serial.println();
  Serial.println("Type h for help!");
  delay(200);
}

void loop() {

  if (Serial.available() > 0) {
    input = Serial.read();
    if (input==104 or input==72) //Help
    {
      Serial.println("h-Help");
      Serial.println("p-Set pinMode for a pin");
      Serial.println("w-DigitalWrite a pin");
      Serial.println("r-DigitalRead a pin");
      Serial.println("b-read byte");
    }
    if (input==112 or input==80) //PinMode
    {
      Serial.println("Please type wich pin you want to set mode for:");
      delay(3500);
      pin = Serial.parseInt();
      Serial.println("Please type which mode you want the pin to be set to(0-input 1-output):");
      delay(3500);
      func = Serial.parseInt();
      if (func==0)
      {
        mode="INPUT";
      }
      else{
        mode="OUTPUT";
      }
      pinMode(pin,func);
      Serial.print("Succesfuly set pin ");
      Serial.print(pin);
      Serial.println(" to " + mode);
    }
    if (input==119 or input==87) //DigitalWrite
    {
      Serial.println("Please type wich pin you want to write:");
      delay(3500);
      pin = Serial.parseInt();
      Serial.println("Please type which mode you want the pin to be set to(0-OFF 1-ON):");
      delay(3500);
      func = Serial.parseInt();
      digitalWrite(pin,func);
      Serial.print("Succesfuly set pin ");
      Serial.print(pin);
      Serial.print(" to ");
      Serial.println(func);
    }
    if (input==114 or input==82) //DigitalRead
    {
      Serial.println("Please type wich pin you want to read:");
      delay(3500);
      pin = Serial.parseInt();
      func = digitalRead(pin);
      Serial.print("I recived ");
      Serial.print(func);
      Serial.print(" on pin ");
      Serial.print(pin);
    }
    if (input==98 or input==66) //Byte read
    {
      Serial.println("Reading bytes:");
      delay(5000);
      input = Serial.parseInt();
      Serial.print("Read bytes:");
      Serial.println(input);
    }
  }
}