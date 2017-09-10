import RPi.GPIO as GPIO
import os

GPIO.setmode(GPIO.BOARD)
GPIO.setup(12,GPIO.IN) 

count = 0; #setup a counting variable so you don't spam your email with a ton of messages

while True: #we want this to run forever
    if GPIO.input(12) == 0: #if the pin returns 0 the circuit will be broken and we assume door is open
        print "Open" #this is so I can see what's happening on the screen, unimportant otherwise
        if count == 0: #nested if- if pin returns 0 and count variable = 0 run contents
            os.system("chmod +x email.sh") #these two lines just send out the email from the bash script
            os.system("./email.sh")
            count = 1 #after an email is sent the count is set to 1 so if door remains open it wont continue emailing
        
    elif GPIO.input(12) == 1: #if pin returns value of 1 the circuit is complete, door is closed
        count = 0 #sets count variable back to 0 so if door is opened again it can email you
        print "Closed" #same as other print, not needed, just so I can see what's going on
