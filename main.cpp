#include "mbed.h"
#include "TFmini.h"

DigitalOut led1(LED1);
BufferedSerial pc(USBTX, USBRX,115200);
UnbufferedSerial usart1(PB_6, PB_7, TFMINI_BAUDRATE);
tfmini sensor;

int main() {
    int distance = 0; 
    int strength = 0;
    int mode = 0;
    sensor.tfmini_init(&usart1);

  while (true) {
    distance = (int) sensor.getDistance();
    strength = (int) sensor.getStrength();
    mode = (int) sensor.get_mode();
    printf("distance: %d cm, strength: %d mode: %x  \n", distance, strength, mode);
  }
}
