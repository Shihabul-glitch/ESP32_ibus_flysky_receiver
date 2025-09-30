#include <HardwareSerial.h>

#define ibusRXPin 5

HardwareSerial ibusSerial(1);


#define ibus_buffsize 14//14//32 chilo
#define ibus_maxchannels 6
static uint8_t ibus_index = 0;
static uint8_t ibus[ibus_buffsize] ;
static bool rx_frame_done = false;
static bool reading_in_house = false;
static uint16_t channel[ibus_maxchannels];
TaskHandle_t Task1;
void codeForTask1( void * parameter )
{

for (;;) {
  while(reading_in_house != true){
    read_rx();
  }
  reading_in_house = false;

  vTaskDelay(7/portTICK_PERIOD_MS);                    /////////You need to test this time. 7400 semms fine primarily. need more testing.6700-7400
  }
}

void setup() {
      Serial.begin(115200);
    ibusSerial.begin(115200, SERIAL_8N1, ibusRXPin, -1);

    xTaskCreatePinnedToCore(
    codeForTask1,
    "led1Task",
    10000,
    NULL,
    tskIDLE_PRIORITY,
    &Task1,
    0);
  delay(500);  // needed to start-up task1

}

void loop() {
  if(rx_frame_done){
    for(int i = 0; i < ibus_maxchannels; i++){
      Serial.print(channel[i]);
      Serial.print("  ");
    }
    Serial.println();
  }

  delay(100);

}
