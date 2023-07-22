## Project introduction
This is a fully open source Refrigerator Temperature Management project by using platformIO Arduino.

## User Requirements
### Refrigerator Temperature Management
1. The refrigerator temperature should be adjustable using the device.
1. The device should automatically shut off the refrigerator if temperature sensor err.
1. The device should store and remember the temperature settings entered by the user.
1. The device should start controlling temperature immediately after being powered on.
1. The device should have a manual power control feature, allowing the user to turn it on or off directly from the device.

## Design Feature set
### Refrigerator Temperature Management
Based on the requirements, here's an example of a feature set meet the user's needs :
1. Temperature Control:
    - Read refrigerator Temperature from sensor.
    - Be able to detect sensor err.
    - Be able to perform cooling actions.
    - Control Logic: Implements the logic for adjusting the refrigerator temperature according to User Settings.
    - When sensor err, it could stop cooling.
2. UI:
    - Adjust the User setting Temperature
    - Power On/Off
        * Include a physical Button on the device to allow users to turn it on or off manually.
        * Power indicator: Provide a visual indicator to display the device's current power status.
    - Display the temperature of the device
    - Notify User when sensor err.
    - Display the software version
3. User Settings:
   - Persistent storage: Store and remember the user's temperature settings even after power loss or device restart.
   - Data Validation: Validates the input data to ensure it falls within acceptable ranges before storing it.
4. Power Management:
    - Turn off whole system then go to sleep.
    - Be able to be wake up by the user.

## Hardware
- 1 refrigerator
- 1 3.3v magnate 220V 10A switch
- 1 bluepill
- 1 rotary encoder
- 1 uart to usb converter
- 1 ds18b20 temperature sensor

## Framework
Implementing Cooperative Round-Robin Multitasking in bare metal embedded programming.

#### Task list
| task | run period |
| -- | -- |
| Temperature update | every 1ms |
| Buttons status update | 10ms |
| UI  | 10ms |