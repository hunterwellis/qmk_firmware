# commands used to compile and flash to promicro
qmk compile -kb custom/scylla/promicro -km default -e MASTER=right
qmk compile -kb custom/scylla/promicro -km default -e MASTER=left
avrdude -p atmega32u4 -c avr109 -P /dev/ttyACM0 -b 57600 -D -U flash:w:./.build/custom_scylla_promicro_default.hex:i
