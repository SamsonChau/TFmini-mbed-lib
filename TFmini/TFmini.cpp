#include "mbed.h"
#include "TFmini.h"

void tfmini::tfmini_init(UnbufferedSerial* _serial){
    serial = _serial;
    serial -> baud(TFMINI_BAUDRATE);
    serial -> format(8, SerialBase::None, 1);
    serial -> attach(callback(this, &tfmini::on_rx_interrupt), SerialBase::RxIrq);
    distance = 0;
    strength = 0;
    mode = 0x02;
    flag = 0;
};
void tfmini::on_rx_interrupt(){
    serial->read(&data, 1);
    if (flag <2 && data == DATA_FRAME_HEADER) {
        flag++;
    }
    else if (flag >= 2 && flag < 9){
        frame[flag-2]= data;
        flag++;
    }
    else if(flag >= 9){
        distance = (frame[1] << 8) + frame[0];
        strength = (frame[3] << 8) + frame[2];
        mode = frame[4];
        checksum = frame[6];
        flag = 0;
    }
    else{
        flag = 0;
    }
};
uint16_t tfmini::getDistance(){
    return distance;
}
uint16_t tfmini::getStrength(){
    return strength;
}
uint8_t tfmini::get_mode(){
    return mode;
}