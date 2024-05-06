#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID
char pass[] = SECRET_PASS;    // your network password

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "10.5.15.62";
int        port     = 1883;
const char topic[]  = "Remote";

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(topic);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(topic);

  Serial.print("Topic: ");
  Serial.println(topic);

  Serial.println();

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // call poll() regularly to allow the library to receive MQTT messages and
  // send MQTT keep alive which avoids being disconnected by the broker
  mqttClient.poll();
}

void onMqttMessage(int messageSize) {
  // we received a message, print out the topic and contents
  // Serial.print("Received a message with topic '");
  // Serial.print(mqttClient.messageTopic());
  // Serial.print("', length ");
  // Serial.print(messageSize);
  // Serial.println(" bytes:");

  // Read the message into a buffer
  char message[messageSize + 1];
  for (int i = 0; i < messageSize; i++) {
    message[i] = (char)mqttClient.read();
  }
  message[messageSize] = '\0'; // Null terminate the string

  // Parse the message as two int numbers
  int x, y;
  if (sscanf(message, "%d,%d", &x, &y) != 2) {
    Serial.println("Failed to parse message");
    return;
  }

  y = -y;

  int speed = sqrt(x * x + y * y);

  if (abs(y) > abs(x)) {
    if (y > 0) {
      forward(speed);
      Serial.println("forward " + String(speed));
    } else {
      back(speed);
      Serial.println("back" + String(speed));
    }
  } else {
    if (x > 0) {
      right(speed);
      Serial.println("right" + String(speed));
    } else {
      left(speed);
      Serial.println("left" + String(speed));
    }
  }

}

void forward(int speed) {
  analogWrite(6, 0);
  analogWrite(5, speed);
  analogWrite(10, int(speed * 1.42));
  analogWrite(9, 0);
}

void left(int speed) {
  analogWrite(6, speed);
  analogWrite(5, 0);
  analogWrite(10, speed);
  analogWrite(9, 0);
}

void back(int speed) {
  analogWrite(6, speed);
  analogWrite(5, 0);
  analogWrite(10, 0);
  analogWrite(9, int(speed * 1.36));
}

void right(int speed) {
  analogWrite(6, 0);
  analogWrite(5, speed);
  analogWrite(10, 0);
  analogWrite(9, speed);
}