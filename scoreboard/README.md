# PIC32 Soccer Scoreboard Firmware

An embedded C application for a soccer scoreboard using a PIC32 microcontroller and addressable LED strips.

## Objective

Implement a configurable scoreboard display, including LED addressing and application logic, then integrate the firmware with a physical LED arrangement. This is the integrated application showcase following the repository's initial GPIO and timer exercises.

## Current status (October 2026)

* Firmware compiled successfully in MPLAB X with XC32.
* Integrated simulator tests passed.
* A provisional mapping of 114 LEDs was selected.
* Physical LED strip arrangement, LED density, power distribution, and final pin assignments remain to be confirmed.
* Hardware operation has **not** yet been verified.

## Architecture and implementation

The project uses modular embedded C firmware with an LED mapping and display control layer. The physical layout and communication wiring must be reconciled with the final LED strip specifications before hardware testing. Exact pin assignments and driver details will be documented from the source files and hardware specifications when available.

## Verification

| Check | Result |
| --- | --- |
| MPLAB X compilation | Passed |
| Integrated simulator tests | Passed |
| Physical LED output | Pending |
| Electrical and power validation | Pending |
| Full scoreboard demonstration | Pending |

The simulator test modules were initially maintained separately from the MPLAB project; the final test sources and invocation instructions will be archived after review.

## Next steps

1. Upload the current MPLAB X project, firmware modules, and simulator test files.
2. Confirm LED strip model, LEDs per meter, operating voltage, and data interface.
3. Arrange 114 LEDs into the scoreboard's physical segments and calculate dimensions.
4. Document PIC32 pin assignments, level shifting if needed, wiring, and power budget.
5. Test physical LED output and record results.

## Portfolio competencies

Embedded C, modular firmware design, microcontroller peripherals, addressable LED interfacing, system integration, test planning, and hardware validation.

This document distinguishes simulator verified firmware from hardware integration that is still in progress.
