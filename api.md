# Hardware
### Global settings
Global settings can be found in **Teris.ino**, includes:
- LED_PIN: The port for connecting leds
- NUM_LEDS: The number of leds
- LED_TYPE\*: The type of leds
* LED_TYPE is a param of `FastLED.addLeds` in setup function, change the param in order to change LED_TYPE

### Description
#### leds [Array]
leds is used to store the status of leds. To change the kth led, try `leds[k-1] = TheValueYouWant;`. Mention that leds start from 0, which means the first led's status is store in led[0].

**More**: If you want to assign a color to an led, do it like this:
```cpp
leds[k] = CRGB(255, 255, 255); // Red, Green, Blue
```
Or:
```cpp
leds[k] = CRGB::Black;
```
**Do not forget** to use `FastLED.show()` to apply the changes.

### File Description
The following files which do not have a suffix are `.ino` files.
#### Tetris
Main file contains `setup` and `loop` functions.

### US.h
This file contains defination of the class `US`(which means `ultrasonic sensor`), mainly be used to fix coding problem.

### US
This file gives the defination of functions in class `US`.

### PauseResume
This file defines `pause` and `resume` functions, which is used to control the game's status. In `loop` funciton of `Tetris`(main file), it was called like this:

```cpp
void loop()
{
	// ...
	if (distance < 10 && isPaused) {
		resume();
	} else if (distance > 10 && !isPaused) {
		pause();
	}
	// ...
}
```
This program uses **ultrasonic sensor** to detect if player is still playing. Variable `distance` is calculated by function `US::detect()`.

### Classes
#### US
##### static init() : [BOOL]
Init serial at `9600` and `pinMode` in order to use ultrasonic sensor normally.
##### static detect(int delaySeconds=500) : [DOUBLE]
Send pulse and return the distance.

### Functions
#### Convert(row, col) : [INT]
This function is used to change a coordinate to the corresponding number in led array.

You may use it like this:
```cpp
leds[Convert(16, 5)] = CRGB::Black;
```
It is the same as:
```cpp
leds[10] = CRGB::Black;
```
**Notice**: This program assume that the led array is 18x8(18 rows and 8 columns)