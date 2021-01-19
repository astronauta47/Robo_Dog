import pygame
import time
import serial

pygame.init()

screen = pygame.display.set_mode((800,600))
ser=serial.Serial("/dev/ttyACM0",9600)


while True:

    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:

            if event.key == pygame.K_w:
                ser.write(b'1')
                ser.write(b'3')
            if event.key == pygame.K_s:
                ser.write(b'5')
                ser.write(b'7')
            if event.key == pygame.K_a:
                ser.write(b'1')
                ser.write(b'7')
            if event.key == pygame.K_d:
                ser.write(b'3')
                ser.write(b'5')

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_w:
                ser.write(b'2')
                ser.write(b'4')
            if event.key == pygame.K_s:
                ser.write(b'6')
                ser.write(b'8')
            if event.key == pygame.K_a:
                ser.write(b'2')
                ser.write(b'8')
            if event.key == pygame.K_d:
                ser.write(b'4')
                ser.write(b'6')


    time.sleep(0.01)