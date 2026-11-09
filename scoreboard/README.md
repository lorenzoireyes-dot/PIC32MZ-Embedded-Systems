# PIC32 Soccer Scoreboard Firmware

An ongoing embedded C project for a soccer scoreboard driven by the **Microchip PIC32MZ EF Starter Kit (PIC32MZ2048EFM144)**. The application combines score and time display logic, timer interrupts, SPI based WS2812B signal generation, and a planned multi digit LED display.

## Progress as of November 9, 2026

**Firmware simulation passed. The external 5 V LED interface is now responding to PIC32 commands after correcting the ground reference. Individual LED addressing remains under investigation.**

| Area | Evidence | Status |
| --- | --- | --- |
| Firmware build and integrated tests | MPLAB X / XC32 build and integrated scoreboard simulation tests passed | Verified in simulation |
| Timer interrupt baseline | Separate timer milestone blinked an onboard LED | Verified on hardware |
| External LED power | Regulated external 5 V supply powers the WS2812B test strip and level shifter | Working in current test |
| PIC32 to strip signaling | LED commands resumed after joining PIC32 ground to external supply ground | Hardware response restored |
| Individual LED addressing | Observed one LED offset / anomalous first LED behavior | Unresolved; workaround planned |
| Seven segment display | Custom routing and numbering illustration uploaded | Design reference |
| Full 114 LED scoreboard | Complete assembly, current distribution, and digit display test | Pending |

Simulation does not independently verify physical signal timing, color order, addressing, or full display operation.

## Hardware and interfaces

| Component | Details |
| --- | --- |
| Development board | PIC32MZ EF Starter Kit, PIC32MZ2048EFM144 |
| Test LEDs | Inland WS2812B addressable RGB strip, 5 V, 60 LEDs/m |
| Test length | Approximately 14 to 15 LEDs used during bring up |
| Level shifter | SN74AHCT125N, powered by external 5 V |
| LED supply | Separate regulated 5 V power supply |
| Controller signal | RF5, configured for SPI1 data output |
| Development tools | MPLAB X IDE, XC32, Harmony generated configuration |

### Current test wiring

- **PIC32 RF5** drives the corresponding SN74AHCT125N channel input.
- The shifter output drives the WS2812B strip **DIN**.
- The shifter and LEDs receive power from the **external 5 V supply**.
- **PIC32 GND, SN74AHCT125N GND, LED strip GND, and external supply negative are electrically common.** This last connection was the critical hardware correction on November 9.
- For SN74AHCT125N channel 1, pin 14 is VCC, pin 7 is GND, pin 2 is input 1A, pin 3 is output 1Y, and pin 1 (active low 1OE) must be connected low.
- A 330 Ω series data resistor is part of the proposed interface design; its installation in the present test setup has not been separately verified.

**Do not connect the external 5 V rail to a PIC32 GPIO.** The separate supplies can coexist as long as their grounds share a reference. Use only 5 V for the WS2812B strip; a separate strip accidentally exposed to 12 V stopped responding and was discarded.

## November 9 hardware debugging results

The LED strip initially failed to respond after switching to an external 5 V supply. The level shifter and strip were already sharing supply and ground, **but the PIC32 ground was not connected to that network**. Adding the PIC32 ground connection restored responses to LED commands.

This observation identifies a missing signal reference as the cause of that particular nonresponse. It **does not** establish that the remaining LED address offset or first LED anomaly has been resolved.

### One LED offset and planned status indicator

Earlier physical tests showed the first visible LED behaving abnormally, including instances where a command targeting software index 0 instead affected the next visible LED. Rather than treating this as a verified firmware indexing bug, the current practical plan is to **conceal the first physical LED and repurpose it as a status/power indicator** while mapping the visible scoreboard segments around the observed offset.

The exact physical to software index relationship must be confirmed using a repeatable individual pixel test before the workaround becomes a fixed mapping. A software controlled status LED indicates controller activity, not necessarily continuous power availability.

## Seven segment arrangement

The preferred **physical wiring order** for one digit uses this deliberately nonstandard letter assignment:

```text
       B (2)
    A (1)  C (3)
       G (7)
    F (6)  D (4)
       E (5)
```

This order was chosen to simplify strip routing. It is **not** the usual A at top seven segment convention. Digit lookup tables in the firmware must use this custom assignment or explicitly translate from standard segment names.

The design diagram below illustrates the segment routing and continuous WS2812B data path.

![Seven segment wiring reference](Pictures/WS2812B%20Seven-Segment%20Scoreboard%20Wiring%20Guide.png)

The illustration is a design aid, **not a validated electrical schematic or a confirmed final global LED index map**. Verify every number and strip orientation before using it to fabricate the display. Individual data strips must connect **DOUT to the next DIN**, while the 5 V and GND rails remain appropriately distributed.

### Provisional full scoreboard allocation

The existing firmware design allocates:

- 8 digits × 7 segments × 2 LEDs per segment = **112 display LEDs**.
- 2 colon LEDs.
- **114 mapped display LEDs** in total.

The hidden status LED workaround may require **one additional physical LED or an adjustment to the indexing/allocation**; the final physical count has not yet been confirmed. Do not assume the illustrated four digit clock is the complete eight digit soccer scoreboard.

## Photographic documentation

The repository's [Pictures folder](Pictures/) includes photographs of the test setup and supporting images:

- [IMG_5701.jpeg](Pictures/IMG_5701.jpeg)
- [IMG_5715.jpeg](Pictures/IMG_5715.jpeg)
- [Level shifter pinout](Pictures/SN74AHCT125NPinOut.jpg)
- [Seven segment wiring guide](Pictures/WS2812B%20Seven-Segment%20Scoreboard%20Wiring%20Guide.png)

Additional screenshots are retained in the same folder. These are evidence of the ongoing hardware and layout work; not every pictured configuration is necessarily the final validated build.

## Next hardware validation

1. Run a deterministic pixel test and record commanded software index versus physical LED position; confirm the status LED offset policy.
2. Cycle through segments 1 to 7 individually using the preferred physical routing order.
3. Display digits 0 through 9 with an explicitly documented lookup table for the custom A through G labels.
4. Verify current, voltage at strip input and remote ends, signal integrity, and supply sizing before expanding to 114 or more physical LEDs.
5. Confirm the global digit mapping and measure whether additional power injection is required at full scoreboard scale.

## Source availability and limitations

The integrated scoreboard firmware and simulator test sources have **not yet been uploaded** to `scoreboard/`. The separate [timer interrupt milestone](../pic32mz_timer_interrupt_01.X/README.md) demonstrates onboard timer interrupt functionality but does not by itself validate the scoreboard's complete external display.

This README separates simulation results, observed hardware behavior, provisional design decisions, and work still awaiting validation.
