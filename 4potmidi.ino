int val = 0; //Our initial pot values. We need one for the first value and a second to test if there has been a change made. This needs to be done for all 3 pots.
int lastVal = 0;
int val2 = 0;
int lastVal2 = 0;
int val3 = 0;
int lastVal3 = 0;
int val4 = 0;
int lastVal4 = 0;




void setup()
{

  
  Serial.begin(38400);       // Set the baud rate of the midi port to the same as in the Hairless Midi software 
}

void loop()
{
  val = analogRead(0)/8;   // Divide by 8 to get range of 0-127 for midi
  val2 = analogRead(1)/8;   // Divide by 8 to get range of 0-127 for midi
  val3 = analogRead(2)/8;   // Divide by 8 to get range of 0-127 for midi
  val3 = analogRead(3)/8;   // Divide by 8 to get range of 0-127 for midi
  

  if (val != lastVal) // If the value does not = the last value the following command is made. This indicates the potentiometer has been turned, meaning no output is sent if they have not been turned.
  {
    MIDImessage(176,1,val);
  }         // 176 = channel 1 - control change, 1 = Which Controller/dial, val = value read from Potentionmeter
  lastVal = val;
  

  if (val2 != lastVal2) 
  {
    MIDImessage(176,2,val2);
  }         
  lastVal2 = val2;
  

  if (val3 != lastVal3) 
  {
    MIDImessage(176,3,val3);
  }         
  lastVal3 = val3;


  if (val4 != lastVal4) 
  {
    MIDImessage(176,4,val4);
  }         
  lastVal4 = val4;
  
  delay(10); //A shor delay which prevents small changes caused by analogue noise or small movements.
}

void MIDImessage(byte command, byte data1, byte data2) //send values as a standard Midi Command
{
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}
