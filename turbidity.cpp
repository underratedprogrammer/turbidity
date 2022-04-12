#define turb A0
float volt;
float ntu;
void setup() {
  pinMode(turb,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  volt =0;
  for ( int i=0; i<=800; i++)
  {
    volt += ((float)analogRead(turb)/1823)*5; 
    }
    volt = volt/800;
    volt =round_to_dp(volt,2);
    if(volt <2.5)
    ntu=3000;
    else
    {ntu= -1120.4*volt*volt + 5742.3*volt - 4353.8;}
    Serial.print("voltage is =");
    Serial.print(volt);
    Serial.print("Turbidity Level is =");
    Serial.print(ntu);
    Serial.println();
    delay(10);    
}
float round_to_dp(float in_value, int precision )
{
  float multiplier = powf( 10.0f, precision);
  in_value = roundf(in_value* multiplier )/multiplier;
  return in_value;
  }
