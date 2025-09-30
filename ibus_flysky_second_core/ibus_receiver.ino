void read_rx(){
  rx_frame_done = false;
  reading_in_house = false;
  if(ibusSerial.available()){
    uint8_t val = ibusSerial.read();
    if(ibus_index == 0 && val != 0x20){
      ibus_index = 0;
      return;
    }
    if(ibus_index == 1 && val != 0x40){
      ibus_index = 0;
      return;
    }

    if(ibus_index == ibus_buffsize){
      ibus_index = 0;
      int high = 3;
      int low = 2;
      reading_in_house = 1;
      for(int i = 0; i < ibus_maxchannels; i++){
        
        channel[i] = (ibus[high] << 8) + ibus[low];
        high += 2;
        low += 2;
      }
      rx_frame_done = true;
      reading_in_house = rx_frame_done;
      return;
    }
    else{
      ibus[ibus_index] = val;
      ibus_index++;
    }
  }
}