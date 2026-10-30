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
| [02: Timer Interrupt and LED Control](pic32mz_timer_interrupt_01.X/README.md) | Configured a hardware timer and interrupt service routine to toggle an onboard LED without continuous software polling. | Completed on hardware |\n| [03: Soccer Scoreboard](scoreboard/README.md) | Integrated scoreboard firmware with provisional 114 LED mapping and simulator testing. | Simulator verified; hardware pending |

The introductory milestones have their own MPLAB X project folders. The scoreboard is the intended application showcase; its source files will be added after review. Milestone 01 is retained as a documented historical exercise; its original application source was lost and intentionally will not be reconstructed.

## Development progression

**Milestone 01** establishes project setup, firmware compilation, programming, GPIO output, and direct hardware verification.

**Milestone 02** extends that foundation with peripheral driven timing and interrupt service routines.

The integrated application is the [PIC32 Soccer Scoreboard](scoreboard/README.md). Its firmware has compiled and passed simulator tests; physical LED hardware integration remains pending.

## Repository contents

* `pic32mz_bringup_01.X/`: GPIO and LED milestone project.
* `pic32mz_timer_interrupt_01.X/`: Timer interrupt milestone project.\n* `scoreboard/`: Scoreboard application documentation; firmware upload pending.

### Source availability and archive policy

**Milestone 01:** The original GPIO LED blink `main.c` was lost. Because this was a small introductory exercise, it has been intentionally omitted rather than reconstructed. The milestone remains documented as hardware verified, but its retained MPLAB X folder is not a complete reproducible source archive. No replacement source upload is planned.

**Milestone 02:** The timer interrupt project includes an application `main.c` in its project folder. Other generated project dependencies may be required for a complete independent rebuild; the repository should not be interpreted as a verified turnkey archive unless those dependencies are present.

Compiled `.hex` and `.elf` files do not replace original source code. This documentation describes the files as they exist without requesting further uploads for the omitted first milestone.

## Engineering focus

GPIO configuration, embedded C development, MCU programming, peripheral configuration, hardware interrupts, debugging, and test verification.

## Project status

Ongoing independent development. Milestones are documented separately as work is completed and verified.
