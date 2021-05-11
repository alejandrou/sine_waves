float slope, count, interval, sin_wave;
int minFreq, maxFreq;

void setup() {
  Serial.begin(9600);
  minFreq = 2;
  maxFreq = 50;
  slope = (maxFreq - minFreq) / 2;
  pinMode(LED_BUILTIN, OUTPUT);
  interval = 0.08;
  count = -interval;
}

void loop() {  
  digitalWrite(LED_BUILTIN, HIGH);
  count += interval;
  delay(1000/(slope*(sin_wave = sin(2*PI*count/3)+1) + minFreq));
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000/(slope*sin_wave + minFreq));
}
