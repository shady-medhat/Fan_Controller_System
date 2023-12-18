# Fan_Controller_System
# Overview
This project aims to design a temperature-controlled fan system using the ATmega32 microcontroller. The system monitors temperature using the LM35 temperature sensor, converts analog readings to digital values using the ADC, and controls a fan's speed based on predefined temperature thresholds. The project follows a layered architecture, with separate drivers for various components.

# System Requirements
Microcontroller: Utilize the ATmega32 microcontroller with a 16MHz clock frequency.

Temperature Sensor: Incorporate the LM35 to provide continuous analog temperature output.

Analog-to-Digital Conversion (ADC): Convert the analog temperature output to digital values for processing.

Temperature Calculations: Implement temperature calculations within the microcontroller.

Display: Display the temperature on an LCD.

Fan Speed Control: Control the fan speed based on temperature as follows:

Below 30°C: Turn off the fan.
30-59°C: Run the fan at 25% speed.
60-89°C: Run the fan at 50% speed.
90-119°C: Run the fan at 75% speed.
Above 120°C: Run the fan at 100% speed.
Layered Architecture: Organize the project using a layered architecture model for modularity and maintainability.

# Development Environment
IDE: Developed using Eclipse.
Microcontroller: ATmega32.
Programming Language: C.
# ADC Driver Requirements
ADC Driver: Implement a full ADC driver with a polling design.
Configuration Structure: Modify the ADC_init function to accept a configuration structure, ADC_ConfigType.
Configuration Structure: Define the ADC_ConfigType structure with fields for reference voltage and prescaler settings.
ADC Configuration: Configure the ADC to use an internal reference voltage of 2.56V and a prescaler of F_CPU/128.
# GPIO Driver Requirements
GPIO Driver: Utilize the GPIO driver implemented in the course for general-purpose input/output operations.
# LCD Driver Requirements
LCD Driver: Use the LCD driver implemented for a 2x16 display with a 4-bit data mode to display temperature and fan state.
# Temperature Sensor Driver Requirements
Temperature Sensor Driver: Implement the temperature sensor driver as taught in the course.
Sensor Connection: Connect the LM35 temperature sensor to ADC channel 0.
# DC-Motor Driver Requirements
DC-Motor Driver: Implement a comprehensive DC-Motor driver.
Initialization: Create an DcMotor_Init function that initializes the motor and stops it initially.
Control: Develop a DcMotor_RotateWithControl function that rotates the motor clockwise (CW), counter-clockwise (CCW), or stops it based on the state input and speed.
Additional Control: Optionally, create a DcMotor_RotateWithoutControl function that allows the motor to rotate at maximum speed or stop without specific control.
# PWM Driver Requirements
PWM Driver: Utilize the PWM Timer0 function implemented in the course to control the DC motor's speed.
PWM Configuration: Implement a PWM_Timer0_Start function to configure Timer0 for PWM mode. This function should set the PWM mode, prescaler, duty cycle, and pin direction for controlling the motor's speed.
# Acknowledgments
The inspiration for this project came from this video tutorial.
