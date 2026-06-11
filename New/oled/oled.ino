#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128   //in pixels
#define SCREEN_HEIGHT 64 

#define OLED_RESET    -1  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define SSD1306_I2C_ADDRESS 0x3C


const int buttonup = 25;
const int buttondown = 26;
const int buttonOk = 27;

int currentMenuIndex = 0;
const int menuItems = 3 ; // how many items?

String menu[menuItems] = {"Anis","Delegue","Foufou"};

void setup() {
  
  Serial.begin(115200);
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  pinMode(buttonup, INPUT_PULLUP);
  pinMode(buttondown, INPUT_PULLUP);
  pinMode(buttonOk, INPUT_PULLUP);

  displayMenu();
}

void loop() {
  if(digitalRead(buttonup) == LOW) {
    currentMenuIndex--;
    if(currentMenuIndex < 0) {
      currentMenuIndex = menuItems - 1;
    }
    displayMenu();
    delay(200); 
  }

  if(digitalRead(buttondown) == LOW) {
    currentMenuIndex++;
    if(currentMenuIndex >= menuItems) {
      currentMenuIndex = 0;
    }
    displayMenu();
    delay(200); 
  }

  if(digitalRead(buttonOk) == LOW) {
    executeMenuAction(currentMenuIndex);
    delay(200); 
  }
}

void displayMenu() {
  display.clearDisplay();
  for(int i = 0; i < menuItems; i++) {
    if(i == currentMenuIndex) {
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); 
    } else {
      display.setTextColor(SSD1306_WHITE, SSD1306_BLACK); 
    }
    display.setCursor(0, i*10);
    display.print(menu[i]);
  }
  display.display();
}

void executeMenuAction(int index) {
  switch(index) {
    case 0:
      Serial.println("Anis");
      break;
    case 1:
      Serial.println("Delegue");
      break;
    case 2:
      Serial.println("Foufou");
      break;
  }
}
