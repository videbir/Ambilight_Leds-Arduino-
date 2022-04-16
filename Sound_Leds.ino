int analogPin = A1;
float analogVal;

int startLeds = 5;
int leds_N = 11;
  
float ledsVal;

int offSet = 510;
int tolerance = 20;

int minVal,maxVal;

int delayVal = 70;
int TimeDelay;

void setup() {
  Serial.begin(2000000);
  int Leds[leds_N];
  
  for(int i=0;i<leds_N;i++){
    Leds[i]=i;
    pinMode(i,OUTPUT);
  }
  TimeDelay = delayVal/leds_N;
  minVal = offSet - tolerance;
  maxVal = offSet + tolerance;
  
  for(int i=startLeds;i<(startLeds+2);i++){
    digitalWrite(i,HIGH);
  }
}

void loop() {
  while(1){
    analogVal = analogRead(analogPin);
    
    ledsVal = map(analogVal,minVal,maxVal,0,leds_N);
    
    for(int i=startLeds;i<(ledsVal);i++){
      digitalWrite(i,HIGH);
      delay(TimeDelay);
    }
    
    for(int i=(ledsVal+1);i>(startLeds+1);i--){
      digitalWrite(i,LOW);
      delay(TimeDelay);
    }
  }
}
