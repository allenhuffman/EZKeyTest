/*-----------------------------------------------------------------------------
 
 Bluefruit EZ-Key Test
 By Allen C. Huffman (alsplace@pobox.com)
 www.subethasoftware.com
 
 This is a simple test program that reads serial USB input from the console
 and then writes it out to the Bluefruit EZ-Key via UART. Whatever you type
 on the Serial Monitor will be transmitted via Bluetooth to whatever device
 you have paired.
 
 To test with an iOS device:
 
 Wire everything up, then power up and pair the EZ-Key to the iOS device. Open
 up "Notepad" or a text editor (any place you can type and see text) and then
 run this sketch. From the Serial Monitor, type and send some text, and it will
 be sent out via Bluetooth at 9600 baud to the EZ-Key, which will then send it
 to the iOS device as if it were typed on a Bluetooth keyboard. Spiffy and
 simple.
 
 Hardware:
 
 http://www.adafruit.com/bluefruit
 
 Documentation:
 
 http://learn.adafruit.com/introducing-bluefruit-ez-key-diy-bluetooth-hid-keyboard/overview
 
 CONFIGURATION:
 1. Define the pins on the Arduino that will be used for TX and RX in
    the Software Serial library, and connected to the Bluefruit EZ-KEY.
 
 VERSION HISTORY:
 2014-03-19 0.00 allenh - Initial version.
 
 TODO:
 * Add examples of sending Raw HID Keyboard and Mouse Reports.
 * This will be used as an example of talking to an iOS device (to simulate an
   iCade controller) with two different keypresses for things like "up" and
   "down", and another mode which acts like a traditional USB style keyboard
   for talking to a Mac or PC (where a key is held down until released).
 
 TOFIX:
 * TODO...
 -----------------------------------------------------------------------------*/
#define VERSION "0.00"

#include <SoftwareSerial.h>

/*---------------------------------------------------------------------------*/
// CONFIGURATION
/*---------------------------------------------------------------------------*/
#define RX_PIN         10
#define TX_PIN         11

// Initialize the Software Serial port.
SoftwareSerial EZKey(RX_PIN, TX_PIN); // RX, TX

void setup()
{
  Serial.begin(9600);

  Serial.print(F("Adafruit Bluefruit EZ-Key Test "));
  Serial.print(VERSION);
  Serial.println(F(" by Allen C. Huffman (alsplace@pobox.com)"));

  Serial.print(F("TX PIN : "));
  Serial.println(TX_PIN);
  Serial.print(F("RX PIN : "));
  Serial.println(RX_PIN);

  Serial.println(F("Whatever you type will be sent out to the EZ-Key."));

  // We talk to the EZ-Key at 9600 baud.
  EZKey.begin(9600);
}

void loop()
{
  char ch;

  // If data is available from the USB serial console...
  while(Serial.available()>0)
  {
    // Read a character from the Serial console.
    ch = Serial.read();
    
    // If nothing was read, it returns -1...
    if (ch>=0)
    {
      // Write that character out to the EZKey via UART.
      EZKey.write(ch);
      // Echo back to the serial console.
      Serial.write(ch);
    }
  }
}

/*---------------------------------------------------------------------------*/
// End of EZKeyTest


