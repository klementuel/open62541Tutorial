import time
import ftrobopy,sys
# Try to connect to the belt
try:
    belt = ftrobopy.ftrobopy('192.168.7.2', 65000)
    Motor1 = belt.motor(1)
    Motor1.setSpeed(512)
    time.sleep(3)
    Motor1.setSpeed(-512)
    time.sleep(3)
    Motor1.stop()
    belt.stopOnline()
finally:
    pass
    #sys.exit()