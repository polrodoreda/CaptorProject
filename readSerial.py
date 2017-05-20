#-*- encoding:utf-8 -*-
import sys
import serial

try:
    ser = serial.Serial('/dev/cu.usbmodem1411', 9600)
except:
    print 'Error de conexión'
    sys.exit()

data_file = sys.argv[1]
f = open(data_file, "w")

while True:
    try:
        f.write(ser.readline())
    except (KeyboardInterrupt):
        f.close()
        sys.exit()

#https://playground.arduino.cc/Interfacing/Python
