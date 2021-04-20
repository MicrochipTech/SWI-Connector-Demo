# SWI Connector Demo


## ABOUT
The demo uses a single-wire Serial EEPROM, with a density of 1Kbits, called [**AT21CS01**](https://www.microchip.com/wwwproducts/en/AT21CS01). Microchip's single-wire devices are 2-pin (SI/O and Ground) memory devices that harvest energy from the SI/O pin to power the integrated circuit.
This device’s value is to add configuration and use information in unpowered attachments using a two-contact mechanical connector that brings only one signal (SI/O) wire and one GND wire to the attachment. Some application examples include analog sensor calibration data storage, ink and toner printer cartridge identification, and management of after-market consumables. The device's software addressing scheme allows up to eight devices to share a common single-wire bus.

This demo showcases our single-wire device in a mechanical connector. The firmware will track the number of times the connector is inserted along with identification and counterfeit detection. The identification and counterfeit detection use [**Extended Tiny Encryption Algorithm (XTEA) Block Cypher**](https://en.wikipedia.org/wiki/XTEA) and reading the **AT21CS01** pre-programmed unique 64-bit serial number.

## HARDWARE

- [Microchip Curiosity High Pin Count (HPC) Development Board [DM164136]](https://www.microchip.com/dm164136) 

- [Mikroe OLED C CLICK [MIKROE-1585]](https://www.mikroe.com/oled-c-click)

- SWI Connector Demo Board

- SWI Connector Demo Socket and Connectors

### SWI Connector Demo Board and Connectors

The SWI Connector Demo board does not use many components. It includes a pull-up resistor (R1), a bypass capacitor (C1), two test points (SI/O and GND), and a 3D printed socket used for interfacing with the three 3D printed connectors. Each connector includes an **AT21CS01** using the XSFN package. The pads on the XSFN package are designed for mechanical connections. The socket interfaces with the connector using two hairpin bellows contacts.

### Curiosity High Pin Count (HPC) Development Board Configuration

This demo uses the [**PIC16F18875**](https://www.microchip.com/wwwproducts/en/PIC16F18875) MCU, necessary for the firmware provided. Other microcontrollers might not work, so please double check that your Curiosity board uses this MCU.

The primary parts that the user interacts with are:
- USB connector
- VCC jumper (verify the jumper is set to 3.3V)
- RESET button switch (top-left corner)
- S1 button switch (bottom-center)
- S2 button switch (bottom-center)
- OLED C click, installed in MicroBUS™ connector 1 (top-right corner)
- SWI Connector Demo board, installed in MicroBUS™ connector 2 (bottom-right corner)
- Three connectors (RED, GREEN, BLUE) including an **AT21CS01-MSHM10-T** in each

### Demo Behavior
The purpose of the demo is to showcase the ability to use a single-wire device in a mechanical connector by keeping track of the number of times the connector is inserted along with identification and counterfeit detection. By default, the Red connector is considered "genuine", while the Green and Blue are "invalid" or counterfeits, but this can be modified by the end user using a specific sequence of buttons shown later in this document.

When the demo is powered (via USB cable) and there isn’t a connector installed in the socket, the screen defaults to a Microchip logo and "SWI Demo" text. While the demo is on this screen, the firmware uses a polling routine (using the Reset and Discovery Response) to determine when a connector is inserted.

When a connector is inserted into the socket, the firmware reads two data sets from the **AT21CS01**. The first is the pre-programmed unique 64-bit serial number. The second is 8 bytes in the 1 K-bit **AT21CS01** memory array; this data set should be the encrypted version of the serial number in a "genuine" connector. After both data sets are read, the second data set is decrypted and then compared to the serial number read. If both data sets match, the connector is considered "genuine". If both data sets do not match, the connector is considered "invalid" or a counterfeit.

 Once the connector is determined to be genuine or invalid, two more data bytes are read from the **AT21CS01**; this is the insertion count for that connector. After the data is read, the insert count is incremented by one and then re-written to the connector. The current count for the inserted connector can be found at the bottom of the OLED screen regardless of whether the connector is genuine or invalid.

### COUNTERFEITING A CONNECTOR
Another feature of the demo is simulating a competitor trying to counterfeit the connector. This is done by reading the entire array, or copying one connector, and then writing that same array to another connector. Because XTEA Block Cypher is used and the serial number doesn’t match the encrypted data, this creates a counterfeit or "invalid" connector.

1. **Read Entire Array (S1 Button):** While a connector is inserted, the user can press the S1 button and the demo will read or copy the entire array (1-Kbit). 

1. **Copy and Write Array (S2 Button):** After a 1-Kbit array has been read, the user can then remove that connector and insert another. When the new connector has been inserted, the user can then write the data pattern from the first connector to the new connector by pressing the S2 button. This clones the data from the first connector to the new counterfeit connector.

### CREATING GENUINE AND ERASING CONNECTORS
In addition to keeping track of the insert count and whether the connector is genuine, the demo can also modify which of the connector(s) are "genuine" along with erasing or re-initializing a connector.

#### Creating a Genuine Connector (RESET + S1 Buttons)
To create a "genuine" connector, the firmware reads the **AT21CS01** serial number, encrypts the serial number and writes the encrypted data to the connector. During this process, the insert count is also reset to 1. Below are the steps to create a "genuine" connector.

1. Make sure the board is powered and a connector is inserted into the socket
2. Press and hold the RESET button
3. While the RESET button is held, press and hold the S1 button
4. With both the S1 and RESET buttons held, release the RESET button
5. Release the S1 button to complete the operation

#### Erasing a Connector (RESET + S2 Buttons)
To erase or re-initialize a connector, the firmware resets the insert count to 1 along with erasing the rest of the array to `0xFF` (hex). Below are the steps to erase or re-initialize a connector.

1. Make sure the board is powered and a connector is inserted into the socket
2. Press and hold the RESET button
3. While the RESET button is held, press and hold the S2 button
4. With both the S2 and RESET buttons held, release the RESET button
5. Release the S2 button to complete the operation

## **Support**
To submit a support ticket request, please contact [Microchip Support](https://microchipsupport.force.com/s/)