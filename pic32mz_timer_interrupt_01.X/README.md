# Milestone 02: Hardware Timer Interrupts and LED Control

## Overview

Built on the GPIO and firmware workflow established in Milestone 01 by implementing **hardware timer based LED control** on the Microchip PIC32MZ EF Starter Kit.

## Objective

Use a hardware timer and an interrupt service routine (ISR) to control an onboard LED without relying on continuous LED timing checks in the main application loop.

## Hardware and tools

* Microchip PIC32MZ EF Starter Kit, PIC32MZ2048EFM144
* MPLAB X IDE
* XC32 compiler
* Embedded C
* Harmony peripheral support, including the Timer 2 peripheral library

## Work completed

1. Configured the hardware timer peripheral.
2. Configured interrupt handling for the timer event.
3. Implemented an interrupt service routine to toggle the onboard LED.
4. Compiled and programmed the firmware onto the development board.
5. Verified timer driven LED activity on physical hardware.

## Engineering concepts

* Hardware timer configuration and peripheral timing
* Interrupt service routines
* Interrupt driven execution versus continuous software polling
* Integration of peripheral configuration and application firmware

## Verification

**Hardware tested:** The onboard LED toggled under timer interrupt control. This demonstrated working hardware timing and interrupt handling on the development board.

No precise timing accuracy measurements or oscilloscope captures have been provided, so this milestone does not claim quantified timing performance.

## Source code note

The uploaded project includes Timer 2 related compiled artifacts and MPLAB X configuration. The application `main.c` and generated Harmony C source and header files were not located during the repository review. Add these files to make the implementation inspectable and independently buildable.

## Related project

[Milestone 01: GPIO and LED Control](../pic32mz_bringup_01.X/README.md)
