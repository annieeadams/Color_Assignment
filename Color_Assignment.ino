
// for NeoPixel
#include <Adafruit_NeoPixel.h>
#define LED_PIN    6
#define LED_COUNT 10
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int r=0, g=0, b=0;

// For LDR
#define LDR_PIN A0

void setup() 
{
 // for NeoPixel
  strip.begin();          
  strip.show();           
  strip.setBrightness(50);
  // for LDR
 Serial.begin(9600);
}




void loop() 
{
  int LDRValue = analogRead(LDR_PIN); 
  if (LDRValue > 510) LDRValue=510;


//red
if ((LDRValue > 425) && (LDRValue <= 510)) r=r+.5*LDRValue; 


if ((LDRValue > 340) && (LDRValue <= 425)) r=r+.5*LDRValue; 


if ((LDRValue > 255) && (LDRValue <= 340)) g=g+.2*LDRValue; 
if ((LDRValue > 255) && (LDRValue <= 340)) r=r+.3*LDRValue; 


if ((LDRValue > 170) && (LDRValue <= 255)) g=g+.5*LDRValue;

 
if ((LDRValue > 85) && (LDRValue <= 170)) g=g+.25*LDRValue;
if ((LDRValue > 85) && (LDRValue <= 170)) b=b+LDRValue; 

 
if ((LDRValue > 0) && (LDRValue <= 85)) r=r+LDRValue;
if ((LDRValue > 0) && (LDRValue <= 85)) b=b+2*LDRValue; 


  Serial.println(LDRValue);
 
  // for NeoPixel
  strip.setPixelColor(0, r, g, b); 
  strip.setPixelColor(1, r, g, b); 
  strip.setPixelColor(2, r, g, b); 
  strip.setPixelColor(3, r, g, b); 
  strip.setPixelColor(4, r, g, b); 
  strip.setPixelColor(5, r, g, b); 
  strip.setPixelColor(6, r, g, b); 
  strip.setPixelColor(7, r, g, b); 
  strip.setPixelColor(8, r, g, b); 
  strip.setPixelColor(9, r, g, b); 
  

   delay (1000);
    strip.show();

}
