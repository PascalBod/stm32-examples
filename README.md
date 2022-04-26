# STM32 code examples

The code examples below are for a NUCLEO_L476RG board. They were written for the 2022 edition of the [IMT Atlantique presentation about embedded software development](https://github.com/PascalBod/IMTAtlantique-2022).

* `blinky`: 
  * configures TIM3 timer
  * configures UART2
  * makes the LED blink
  * displays a version string at application startup
  * see the above presentation for more information
* `serial`:
  * in addition to `blinky`, configures UART2 for interrupt-driven RX
  * displays any received character
* `serial-buffer`:
  * in addition to `serial`, uses a circular buffer to transfer received characters to the background task
* `serial-buffer-atomic`:
  * in addition to `serial-buffer`, use atomic access to the circular buffer