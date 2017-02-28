import serial
import time

sender = '1'
sender2 = '2'

s = serial.Serial(port='/dev/tty.usbmodem1421', baudrate=9600)
#time.sleep(3)
#s.write(sender)
time.sleep(2)
s.write(sender2)
#s.read()
#s.readline()
