# PIC32MZ Embedded Systems and Firmware Development

An ongoing independent embedded systems development series built around the **Microchip PIC32MZ EF Starter Kit**. This repository records progressive experiments in embedded C, microcontroller peripherals, interrupt handling, and hardware validation.

## Project objectives

Develop practical firmware engineering skills by configuring and programming real microcontroller hardware, understanding peripheral behavior, debugging firmware, and preserving each completed milestone as a separate MPLAB X project.

## Hardware and development tools

| Component | Details |
| --- | --- |
| Development board | Microchip PIC32MZ EF Starter Kit |
| Target MCU | PIC32MZ2048EFM144 |
| IDE | MPLAB X IDE |
| Compiler | MPLAB XC32 |
| Language | Embedded C |
| Configuration | MPLAB Code Configurator and Harmony generated peripheral code |

## Completed milestones

| Milestone | Description | Status |
| --- | --- | --- |
| [01: GPIO and LED Control](pic32mz_bringup_01.X/README.md) | Configured a development environment and GPIO output, programmed the device, and verified onboard LED operation. | Completed on hardware |
| [02: Timer Interrupt and LED Control](pic32mz_timer_interrupt_01.X/README.md) | Configured a hardware timer and interrupt service routine to toggle an onboard LED without continuous software polling. | Completed on hardware |

Each milestone has its own MPLAB X project folder and documentation.

## Development progression

**Milestone 01** establishes project setup, firmware compilation, programming, GPIO output, and direct hardware verification.

**Milestone 02** extends that foundation with peripheral driven timing and interrupt service routines.

Future areas of exploration may include additional timers, communication interfaces, hardware interfacing, and integrated embedded applications. These are goals, not completed milestones.

## Repository contents

* `pic32mz_bringup_01.X/`: GPIO and LED milestone project.
* `pic32mz_timer_interrupt_01.X/`: Timer interrupt milestone project.

### Source availability

The current uploads include MPLAB X configuration and generated build artifacts, but the application C source files and some generated Harmony sources were not located during repository review. These files must be added before the repository can be considered a complete, independently rebuildable firmware archive. In particular, include the actual `main.c` for each milestone and its required Harmony `config/` source and header files.

Compiled `.hex` and `.elf` files are not substitutes for source code.

## Engineering focus

GPIO configuration, embedded C development, MCU programming, peripheral configuration, hardware interrupts, debugging, and test verification.

## Project status

Ongoing independent development. Milestones are documented separately as work is completed and verified.
