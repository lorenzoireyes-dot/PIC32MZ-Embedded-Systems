# Milestone 01: GPIO and LED Control

## Overview

First firmware milestone using the **Microchip PIC32MZ EF Starter Kit**. Established the MPLAB X development environment, compiled embedded C firmware, programmed the physical microcontroller, and verified basic digital output operation using an onboard LED.

## Objective

Establish a working firmware workflow and confirm that a configured GPIO output can control an LED on the target board.

## Hardware and tools

* Microchip PIC32MZ EF Starter Kit, PIC32MZ2048EFM144
* MPLAB X IDE
* XC32 compiler
* Embedded C
* MPLAB Code Configurator and generated peripheral support

## Work completed

1. Created and configured an MPLAB X application project for the PIC32MZ target.
2. Configured GPIO functionality for LED output.
3. Built firmware with the XC32 compiler.
4. Programmed the physical development board.
5. Confirmed the onboard LED blinked as expected.

## Verification

**Hardware tested:** The LED blink application ran on the physical starter kit. This confirmed the basic edit, build, program, and test workflow.

## Skills demonstrated

GPIO output, firmware compilation, device programming, basic debugging, and hardware verification.

## Source code note

The initial GitHub upload includes project settings and build artifacts. The application `main.c` and required Harmony source and header files were not found during the repository review and still need to be uploaded for a reproducible source project.

## Next milestone

[Milestone 02: Hardware Timer Interrupt and LED Control](../pic32mz_timer_interrupt_01.X/README.md)
