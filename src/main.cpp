#include "mbed.h"
#include "USBSerial.h"

int main() {
USBSerial serial;
SPI motion(PA_7,PA_6,PA_5);
DigitalOut chip(PE_3);

  while(1) {
    chip = 0;
    motion.write(0x0F);
    int whoami = motion.write(0x00);
    serial.printf("Who Am I: %d",whoami);
    chip = 1;
    wait(1);
  }
}