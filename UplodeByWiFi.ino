//WiFi ของคอมพิวเตอร์ที่จะทำการอัพโหลดโค้ดลงลอร์ดจำเป็นต้องเป็น WiFi เดียวกันกับบอร์ด
#include <WiFi.h> //ไลบรารี่ที่ใช้ในการเชื่อมต่อ WiFi
#include <ArduinoOTA.h>//ไลบรารี่ที่ใช้ในการอัพโหลดโค้ดแบบไร้สาย

const char* ssid = "ชื่อWiFiที่ต้องการเชื่อต่อ";
const char* password = "รหัสWiFiที่ต้องการเชื่อต่อ";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);//ทำการเชื่อต่อ WiFi
  //ทำการตรวจสอบ WiFi ว่าสามารถเชื่อมต่อ WiFi ได้หรือไม่
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  //ทำการเริ่มใช้การอัพโหลดแบบไร้สาย
  ArduinoOTA.setHostname("ตั้งชื่อ ip ที่ใช้ในการอับโหลโค้ดแบบไร้สาย");
  ArduinoOTA.begin();//เริ่มทำการใช้งานการอับโหลโค้ดแบบไร้สาย
}

void loop() {
  ArduinoOTA.handle();//ทำการเข้าโหมดเตรียมพร้อมอับโหลโค้ดแบบไร้สาย
}
