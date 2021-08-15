#include "src/BleKeyboard.h"
#include "src/Button2.h"

BleKeyboard kbd;
Button2 btn(0);
bool state = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE Keyboard!");
  kbd.begin();
  btn.onClicked([](Button2 &btn){
    state = !state;
    if(state){
      Serial.println( "[PopCat] start!" );
    }else{
      Serial.println( "[PopCat] stop" );
    }
  });
  Serial.println("[PopCat] pressed the Button (GPIO 0) to start/stop.");
}

void loop() {
  if(kbd.isConnected() && state) {
    kbd.write(KEY_RETURN);
    //delay(1);
  }
  btn.loop();
}
