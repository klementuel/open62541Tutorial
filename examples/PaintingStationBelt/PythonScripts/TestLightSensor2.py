import time
import ftrobopy,sys
# Try to connect to the belt
try:
    belt = ftrobopy.ftrobopy('192.168.7.2', 65000)
    # Lamp definition
    lamp = belt.output(3)
    # right photorisistor difinition
    R1 = belt.resistor(2)
    # left photorisistor difinition#
    #R2 = belt.resistor(2)
    lamp.setLevel(512)
    time.sleep(0.5)
    check = True
    while check:
        R1_value = R1.value()
        time.sleep(0.08)
        if R1_value > 1000:
            check = False
    lamp.setLevel(0)
    time.sleep(0.3) 
    lamp.setLevel(512)
    time.sleep(0.3)
    lamp.setLevel(0)
    time.sleep(0.3)
    lamp.setLevel(512)
    time.sleep(0.3)
    lamp.setLevel(0)
    time.sleep(0.3)
    lamp.setLevel(512)
    time.sleep(0.3)
    lamp.setLevel(0)
    belt.stopOnline()
finally:
    pass
    #sys.exit()