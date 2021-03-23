# SWI-Connector-Demo
This demo uses a single-wire Serial EEPROM, with a density of 1Kbits, called AT21CS01. Microchip’s single-wire devices are 2-pin (SI/O and Ground) memory devices that harvest energy from the SI/O pin to power the integrated circuit.

This demo showcases our single-wire device in a mechanical connector. The firmware will track the number of times the connector is inserted along with identification and counterfeit detection. The identification and counterfeit detection use Extended Tiny Encryption Algorithm (XTEA) Block Cypher and reading the AT21CS01 pre-programmed unique 64-bit serial number.
