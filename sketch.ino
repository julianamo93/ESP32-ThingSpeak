/********************************************************************
 * Projeto: ORBIS - ESP32 com MQTT + ThingSpeak
 * Base: Envio de Dados MQTT com ESP32 - FIAP / André Tritiack
 * Adaptado por: Byte Bloom Tech e OpenAI (junho/2025)
 ********************************************************************/

#include <WiFi.h>
#include <HTTPClient.h>

// Dados da rede Wi-Fi
const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";

// Dados do ThingSpeak
String apiKey = "QVQJY7J1ZWYJVQBB"; 
const char* server = "http://api.thingspeak.com/update";

// Função de conexão Wi-Fi
void conectaWiFi() {
  Serial.print("Conectando ao Wi-Fi");
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n Wi-Fi conectado!");
}

void setup() {
  Serial.begin(115200);
  conectaWiFi();
}

void loop() {
  // Leitura dos sensores
  int rawEnchente = analogRead(32);
  int rawChuva = analogRead(34);
  int rawVento = analogRead(35);

  // Conversão dos valores para percentual (%)
  float percEnchente = (rawEnchente / 4095.0) * 100;
  float percChuva = (rawChuva / 4095.0) * 100;
  float percVento = (rawVento / 4095.0) * 100;

  // Exibir no Serial Monitor
  Serial.println("Leituras dos sensores (%):");
  Serial.println("Enchente: " + String(percEnchente, 2) + "%");
  Serial.println("Chuva: " + String(percChuva, 2) + "%");
  Serial.println("Vento: " + String(percVento, 2) + "%");

  // Envio para o ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Monta URL de envio
    String url = String(server) + "?api_key=" + apiKey + 
                 "&field1=" + String(percEnchente, 2) + 
                 "&field2=" + String(percChuva, 2) + 
                 "&field3=" + String(percVento, 2);

    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.println("Dados enviados para ThingSpeak com sucesso.");
    } else {
      Serial.print("Erro ao enviar. Código HTTP: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Wi-Fi desconectado. Tentando reconectar...");
    conectaWiFi();
  }

  delay(15000); // delay de 15 segundos do ThingSpeak
}
