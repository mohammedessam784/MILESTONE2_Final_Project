Milestone_2; //Door Locker Security System

Expanding the Door Locker Security System with Two MCUs.

System Overview:
• MCU1: ATmega32 at 8 MHz (HMI - Human Machine Interface)
• Handles user input via a keypad.
• Displays messages to the user on the LCD.
• Communicates with MCU2 via UART for password verification
and system control.
• Also monitors temperature using the LM35 sensor and
controls fan speed based on temperature.

• MCU2: ATmega32 at 8 MHz (Control Unit)
• Controls the motor and buzzer.
• Stores the password in RAM (volatile memory).
• Validates the password and triggers system actions based on
the result.
