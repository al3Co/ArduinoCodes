#!/usr/bin/python
"""
    Connect to /dev/tty.usbmodem1421 wuth 9600 bps
"""

import serial
import time

sender = '1'
sender2 = '2'

s = serial.Serial(port='/dev/tty.usbmodem1421', baudrate=9600)
try:
    time.sleep(3)
    s.write(sender)
    time.sleep(2)
    s.write(sender2)
    #break
except ValueError:
    print (ValueError)
#s.read()
#s.readline()
