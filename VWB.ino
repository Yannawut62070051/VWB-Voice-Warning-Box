// ส่วนในการกำหนด board arduino
#include <SD.h>                           // เพิ่ม library รับ SD card
#include <TMRpcm.h>                       // เพิ่ม library 
#define SD_ChipSelectPin 4                // กำหนดช่องอ่าน SD card
TMRpcm tmrpcm;                            // กำหนดไฟล์เสียงให้กับลำโพง ouput
// ส่วนของการกำหนดค่าก่อนเริ่มทำงาน
void setup(){
  Serial.begin(9600);
  tmrpcm.speakerPin = 9;                  // กำหนดช่อง output เพื่อต่อกับลำโพง
  if (!SD.begin(SD_ChipSelectPin)) {      // ตรวจสอบว่า sd card พร้อมหรือไม่
    
    return;                               // ถ้าไม่พร้อมจะไม่ทำงานต่อ
  }
}
// ส่วนของการทำงานหลักของ board Arduino
void loop(){
  int mic = analogRead(A0); //กำหนดช่องในการ input ความดังของเสียง 
  if (mic > 75) { // ถ้าดังเกินกว่า 75 dB ให้แสดงข้อความ
    Serial.println("Please Be quiet"); // แสดงผลผ่าน display ของ software arduino เพื่อตรวจสอบว่าใช้งานได้หรือไม่
    delay(50); // กำหนดดีเลย์ในการแสดงผลเป็นหน่วย 50 millisec
    tmrpcm.setVolume(6); // กำหนดความดังของการแสดงผลผ่านลำโพง
    tmrpcm.play("1.wav"); // เล่นไฟล์เสียงที่ได้ใส่ไว้ใน SD card ต้องเป็นสกุล .wav เท่านั้น
    delay(1000); // กำหนดดีเลย์ในการแสดงผลเป็นหน่วย 1 second
  }
}
