#include <WiFiS3.h>  // ไลบรารี WiFi สำหรับ Arduino UNO R4 WiFi
#include <WiFiSSLClient.h>  // สำหรับการเชื่อมต่อ HTTPS

// WiFi credentials
const char* ssid = "panpanpopular";
const char* password = "panpanpopular";

// LINE Notify Token
const char* lineToken = "bM9ewRHfVX1Rncg32CwyFCZ8WrSgC2AYa3XbshP8E1Q";

// กำหนดพินของเซ็นเซอร์และค่าที่ใช้ในโค้ด
#define MQ_PIN 5

// กำหนดค่าของแก๊สต่างๆ ที่จะตรวจจับ
#define GAS_LPG   0
#define GAS_CO    1
#define GAS_SMOKE 2

// LINE Notify Message
String message;

void setup() {
  Serial.begin(9600);

  // เชื่อมต่อ WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // อ่านค่าจาก MQ2
  float gasLPG = MQGetGasPercentage(MQRead(MQ_PIN), GAS_LPG);
  float gasCO = MQGetGasPercentage(MQRead(MQ_PIN), GAS_CO);
  float gasSmoke = MQGetGasPercentage(MQRead(MQ_PIN), GAS_SMOKE);

  // แสดงค่าจากเซ็นเซอร์และสถานะการเชื่อมต่อ WiFi ทุกๆ 2 วินาที
  Serial.print("LPG: "); Serial.print(gasLPG); Serial.println(" ppm");
  Serial.print("CO: "); Serial.print(gasCO); Serial.println(" ppm");
  Serial.print("Smoke: "); Serial.print(gasSmoke); Serial.println(" ppm");

  // ตรวจสอบสถานะ WiFi
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi Status: Connected");
  } else {
    Serial.println("WiFi Status: Disconnected");
  }

  // ตรวจสอบเงื่อนไข: แก๊สหรือควันมากกว่า 5 
  if (gasLPG > 5 || gasCO > 5 || gasSmoke > 5) {
    // สร้างข้อความแจ้งเตือน
    message = "แจ้งเตือน! ตรวจพบแก๊สหรือควัน\n";
    message += "LPG: " + String(gasLPG) + " ppm, ";
    message += "CO: " + String(gasCO) + " ppm, ";
    message += "Smoke: " + String(gasSmoke) + " ppm, ";
    
    // ส่งข้อความแจ้งเตือนไปยัง LINE Notify
    Line_Notify(message);
    
    // รอ 1 นาที (ป้องกันการส่งข้อความถี่เกินไป)
    delay(60000);
  }

  delay(2000);  // ตรวจสอบทุกๆ 2 วินาที
}

// ฟังก์ชันสำหรับการอ่านค่า MQ2 (ตัวอย่างการจำลอง)
float MQRead(int pin) {
  return analogRead(pin);  // อ่านค่าจาก MQ2 (กรุณาปรับตามการใช้งานจริง)
}

// ฟังก์ชันสำหรับการคำนวณเปอร์เซ็นต์แก๊สจาก MQ2 (ตัวอย่าง)
float MQGetGasPercentage(float value, int gasType) {
  // ตัวอย่างการแปลงค่า (ปรับตามเซ็นเซอร์ที่คุณใช้)
  return value / 1024 * 100;  // แปลงค่าอนาล็อกเป็นเปอร์เซ็นต์
}

// ฟังก์ชันสำหรับส่งข้อความไปยัง LINE Notify
void Line_Notify(String message) {
  WiFiSSLClient client;

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("Connection failed");
    return;
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(lineToken) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: Arduino\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;

  client.print(req);
  delay(20);

  // ตรวจสอบการตอบกลับจาก LINE Notify
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
  client.stop();
}
