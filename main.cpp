 #include "mbed.h"
 #include "arm_book_lib.h"
DigitalIn enterButton(BUTTON1);
DigitalIn gasDetector(D2);
DigitalIn overTempDetector(D3);
DigitalIn aButton(D4);
DigitalIn bButton(D5);
DigitalIn cButton(D6);
DigitalIn dButton(D7);
int tempr;
    char recC = '\0';
        bool alarmG = gasDetector;
        bool alarmT = overTempDetector;
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);
 void uartTask();

int main() {
    gasDetector.mode(PullDown);
    int count = 0;
    overTempDetector.mode(PullDown);
    while (true) {
    srand(time(0));
    tempr = rand() % 101;
        ThisThread::sleep_for(1000ms);
        uartTask();
    } 
}
void uartTask() {
        gasDetector.mode(PullDown);
    overTempDetector.mode(PullDown); 
        alarmG = gasDetector;
        alarmT = overTempDetector;
        if (tempr >= 40){
            alarmT = HIGH;
        }
         char text[20];
         sprintf(text,"%d",tempr);

            if ( alarmG == HIGH ) {
                uartUsb.write( "The gas alarm is activated wee woo wee woo\r\n", 44);
             } else {
                 uartUsb.write( "The gas alarm is not activated\r\n", 32);
            } 
              if ( alarmT == HIGH ) {
                uartUsb.write( "The temp alarm is activated wee woo wee woo temp:", 51);
                uartUsb.write(text, 2);
                uartUsb.write("\n", 2);
            } else {
                uartUsb.write( "The temp alarm is not activated:", 33);       
                  uartUsb.write(text, 2); 
                  uartUsb.write("\n", 2); 
    } 
 }