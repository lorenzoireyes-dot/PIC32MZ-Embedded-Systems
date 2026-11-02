# PIC32 Soccer Scoreboard Firmware

An ongoing embedded C project for an LED soccer scoreboard controlled by a **Microchip PIC32MZ EF Starter Kit**. The design combines score and time display logic, timer interrupts, SPI based LED data generation, and a physical WS2812B LED display.

## Progress as of October 30, 2026

**Firmware simulation complete; physical LED interface under active troubleshooting.**

| Area | Current evidence | Status |
| --- | --- | --- |
| Embedded firmware build | MPLAB X / XC32 build completed | Passed |
| Integrated simulator test | Scoreboard logic, timer, display encoding, WS2812B output generation, and integrated firmware tests passed | Passed in simulation |
| Timer interrupt baseline | A separate known working timer interrupt project successfully blinked an onboard LED | Hardware verified in baseline project |
| Test strip power and response | A 14 LED WS2812B strip has powered on and shown limited LED activity | Partial physical response |
| Correct LED color and position | Unexpected white/color output and shifted LED behavior observed | **Unresolved** |
| Full scoreboard integration | The complete display has not been assembled and validated | Pending |

The simulator results do **not** establish correct electrical timing, color ordering, or physical LED addressing.

## Hardware

| Component | Description |
| --- | --- |
| Controller | PIC32MZ EF Starter Kit (PIC32MZ2048EFM144) |
| LED test strip | Inland WS2812B, 5 V, 60 LEDs per meter |
| Physical test segment | 14 LEDs |
| Proposed level shifter | 74AHCT125 |
| Proposed series data resistor | 330 Ω |
| Development environment | MPLAB X, XC32, Harmony generated peripheral configuration |

### Provisional wiring under test

- PIC32 J12 pin 19, **RF5 / SPI1 MOSI**, to a 74AHCT125 input.
- 74AHCT125 output through a **330 Ω** series resistor to the LED strip's DIN.
- PIC32 J12 pin 20 and LED power supply ground connected as a common reference.
- LED strip and level shifter supplied from 5 V, subject to electrical and current capacity validation.

This is the documented test wiring, **not yet a validated final hardware interface**. The scoreboard's power distribution and completed wiring harness remain to be designed and tested.

## LED mapping

The firmware uses a **provisional 114 LED map**:

- Eight seven segment digits.
- Two physical LEDs per segment: 8 digits × 7 segments × 2 LEDs = **112 LEDs**.
- Two additional colon LEDs.
- **Total: 114 LEDs.**

The mapped arrangement has not been physically implemented or checked against the final installation. LED density is **60 LEDs per meter** on the available test strip.

## Hardware bring up observations

During the October 30, 2026 test session:

1. Programming and firmware build operations succeeded, but reliable external LED operation was not obtained.
2. One early test produced light on the first LED while the rest of the 14 LED segment remained dark.
3. A direct GPIO high output check on RF5 was measured as 0 V during that particular test. This is a troubleshooting observation, **not proof of a defective MCU pin**.
4. A previously working timer interrupt project was used to confirm that the PIC32 could execute firmware and blink an onboard LED.
5. Subsequent strip tests showed unexpected LED colors and apparent index shifts, including white on LED 0 and differing red, green, and blue indications on successive LEDs. Disconnecting and reconnecting the data wire also changed the visible output.

**No root cause has been confirmed.** Peripheral enabling, pin configuration, data signal generation, level shifting, LED strip condition, and data timing remain possible investigation areas. The observations do not establish whether the problem is hardware, firmware, configuration, or a combination.

## Planned next validation

1. Test with an alternative WS2812B strip to separate strip behavior from controller output.
2. Confirm the RF5 peripheral configuration and verify the selected SPI output signal on the actual pin.
3. Verify 5 V supply, common ground, level shifter wiring and enable state, and correct DIN orientation.
4. Check the LED protocol waveform and color byte sequence with a scope or logic analyzer where available.
5. Demonstrate repeatable individual LED selection and known red, green, and blue test patterns.
6. Validate the physical 114 LED mapping and power distribution before full display assembly.

### Photographic evidence

Photos of the malfunctioning LED test are planned but **have not yet been uploaded to this repository**. Once available, they should be labeled with the test setup, commanded output, observed LED order and colors, and date.

## Source code and reproducibility

The integrated scoreboard firmware and simulator sources have **not yet been added** to the `scoreboard/` directory; currently this directory contains documentation. The separate [timer interrupt milestone](../pic32mz_timer_interrupt_01.X/README.md) demonstrates known working onboard LED activity, but it does not validate the scoreboard's external LED output.

This record distinguishes **verified simulation results**, **partial hardware observations**, and **pending hardware validation**.
