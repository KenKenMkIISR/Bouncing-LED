# Bouncing LED by KenKen for Raspberry Pi Pico
# Download ws2812b.py from below and save it to Raspberry Pi Pico with the same name.
#  https://github.com/benevpi/pico_python_ws2812b

import time
import ws2812b

LED_NUM = 144  # Number of NeoPixels
DIN_GPIO = 0   # Pin where NeoPixels are connected
REVERSE = True # If True, LED block will fall off from the end of the LED strip

BLOCK = 8      # Length of LED block
BRIGHT = 60    # LED brightness
GRAVITY = 20   # Gravitational acceleration

# Bounce coefficient = R1/R2
R1 = 3         # Bounce coefficient 1
R2 = 5         # Bounce coefficient 2
REFMINV = -80  # Minimum bounce speed (Adjust when the bounce does not end)

strip = ws2812b.ws2812b(LED_NUM, 0, DIN_GPIO)

def set_block(pos, c):
# Set a LED block
# pos: The beginning position of the LED block
# c: Color 0=off, 1=red ... 8=green ... 16=blue ... 24=red
    if c == 0:
        r = 0; g = 0; b = 0
    elif c <= 8:
        r = (8 - c) * BRIGHT >> 3
        g = c * BRIGHT >>3
        b = 0
    elif c <= 16:
        r = 0
        g = (16 - c) * BRIGHT >> 3
        b = (c - 8) * BRIGHT >> 3
    elif c <= 24:
        r = (c - 16) * BRIGHT >> 3
        g = 0
        b = (24 - c) * BRIGHT >> 3
    else:
        return
    for i in range(BLOCK):
        if pos < 0:
            return
        if REVERSE:
            strip.set_pixel(LED_NUM - pos -1, r, g, b)
        else:
            strip.set_pixel(pos, r, g, b)
        pos -= 1

col = 1 # Color of falling LED block
while True:
    # Notice: Position and velocity are 8-bit left shifted to work with integers
    bottom = LED_NUM << 8 # Set the bottom to the end of the LED strip

    # Loop each block falls
    while bottom >0:      # Repeat until the bottom exceeds the top of the LED strip
        y = 0             # Head position of LED block
        v = 0             # Falling velocity
        while y < bottom: # Repeat while the LED block is above the bottom
            set_block(y >> 8, col) # Set LEDs
            strip.show()
            time.sleep_ms(5)
            set_block(y >> 8, 0)   # Clear LEDs
            v += GRAVITY           # Update falling velocity
            y += v                 # Update position
            if y >= bottom:        # When reach the bottom
                y = bottom - 256   #  Set the LED block position to one above the bottom
                v = -v * R1 // R2  #  Bounce
                if v > REFMINV:    #  Stop when the bounce speed is less than REFMINV
                    set_block((bottom >> 8) - 1, col) # Fix the LED block one above the bottom
                    bottom -= BLOCK << 8         # Raise the bottom by one block
                    col = (col + 18) % 24 + 1    # Change to the next color

    strip.show()
    time.sleep_ms(500)

    y = 0 # The position of the tip of the tail
    v = 0 # Falling velocity

    # Loop the entire of the blocks fall
    while y < (LED_NUM << 8): # Repeat until the tip of the tail disappears
        y += v                # Update the position
        v += GRAVITY // 2     # Update falling velocity (with friction)
        for i in range(LED_NUM-1, (y >> 8) - 1, -1):
            y1 = (i << 8) + (y & 0xff) - v # Current position of LED coming to position i
            if y1 >= y:       # Copy LED color position y1 to i
                if REVERSE:
                    strip.pixels[LED_NUM - i -1] = strip.pixels[LED_NUM - (y1 >> 8) -1]
                else :
                    strip.pixels[i] = strip.pixels[y1 >> 8]
            else:             # Turn off LEDs above the tip of the tail
                if REVERSE:
                    strip.set_pixel(LED_NUM - i -1, 0, 0, 0)
                else :
                    strip.set_pixel(i, 0, 0, 0)
        strip.show()
        time.sleep_ms(5)

    time.sleep_ms(500)
