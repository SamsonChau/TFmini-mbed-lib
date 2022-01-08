#ifndef TFMINI_H
#define TFMINI_H

#include "mbed.h"

#define DATA_BUFFER_SIZE    7
#define TFMINI_BAUDRATE     115200
#define DATA_FRAME_HEADER   0x59
#define COMMAND_HEADER      0x425702


class tfmini{
    public:
        void tfmini_init(UnbufferedSerial* _serial);
        uint16_t getDistance();
        uint16_t getStrength();
        uint8_t get_mode();

        void set_data_format();
        void set_frequency();
        void set_unit();
        void set_pattern();
        void set_distance();
        void set_range();
        void set_min_strength();
        void set_max_strength();

        UnbufferedSerial* serial;
        void on_rx_interrupt();

    private:
        uint8_t data;
        uint8_t frame[DATA_BUFFER_SIZE];
        uint8_t checksum;
        uint8_t flag;

        uint16_t distance;
        uint16_t strength;
        uint8_t mode;
};

#endif