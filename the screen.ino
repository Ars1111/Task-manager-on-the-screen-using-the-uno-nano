#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String cpuUsage = "CPU: 0%";
String ramUsage = "Ram: 0%";
String netUsage = "Net: 0%";

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();


  display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE); 
  display.setTextSize(2);
  display.setTextColor(BLACK); 
  display.setCursor((SCREEN_WIDTH - 48) / 2, (SCREEN_HEIGHT - 16) / 2);
  display.print("ARS1");
  
  display.display(); 
  delay(1000); 

  display.clearDisplay();
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    
    // Разделяем данные на части
    int cpuIndex = data.indexOf("CPU:");
    int ramIndex = data.indexOf("Ram:");
    int netIndex = data.indexOf("Net:");

    // Извлекаем значения
    if (cpuIndex != -1) {
      cpuUsage = data.substring(cpuIndex, data.indexOf(" ", cpuIndex));
    }
    if (ramIndex != -1) {
      ramUsage = data.substring(ramIndex, data.indexOf(" ", ramIndex));
    }
    if (netIndex != -1) {
      netUsage = data.substring(netIndex);
    }

    // Очищаем дисплей и отображаем всю информацию одновременно
    display.clearDisplay();
    
    display.setTextSize(2);
    display.setTextColor(WHITE);
    
    display.setCursor(0, 0);
    display.print(cpuUsage);
    
    display.setCursor(0, 20); // Позиция для RAM
    display.print(ramUsage);

    display.setTextSize(1);
    display.setCursor(0, 40); // Позиция для сети
    display.print(netUsage); // Используем тот же размер текста

    display.display(); // Обновляем дисплей
  }
}

