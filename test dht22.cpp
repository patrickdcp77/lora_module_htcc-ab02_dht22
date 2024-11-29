#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <U8g2lib.h>

// Définir la broche où le DHT22 est connecté
#define DHTPIN 5  // Changez ceci par la broche que vous utilisez

// Définir le type de capteur DHT
#define DHTTYPE DHT22

// Initialiser le capteur DHT
DHT dht(DHTPIN, DHTTYPE);

// Initialiser l'écran OLED intégré
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  // Démarrer la communication série
  Serial.begin(9600);
  Serial.println("Test du DHT22!");

  // Initialiser le capteur DHT
  dht.begin();
  Serial.println("DHT22 initialisé");

  // Initialiser l'écran OLED
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr); // Choisir une police
  u8g2.drawStr(0, 10, "Initialisation...");
  u8g2.sendBuffer();
  delay(2000); // Pause pour permettre à l'écran de s'initialiser
}

void loop() {
  // Attendre quelques secondes entre les mesures
  delay(2000);
  Serial.println("Lecture des données du DHT22...");

  // Lire l'humidité
  float h = dht.readHumidity();
  // Lire la température en Celsius
  float t = dht.readTemperature();

  // Vérifier si des lectures ont échoué et sortir tôt (pour réessayer).
  if (isnan(h) || isnan(t)) {
    Serial.println("Échec de la lecture du capteur DHT!");
    return;
  }

  // Afficher les résultats sur le moniteur série
  Serial.print("Humidité: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Température: ");
  Serial.print(t);
  Serial.println(" *C");

  // Afficher les résultats sur l'écran OLED
  u8g2.clearBuffer();
  u8g2.setCursor(0, 10);
  u8g2.print("Humidite: ");
  u8g2.print(h);
  u8g2.println(" %");
  u8g2.setCursor(0, 30);
  u8g2.print("Temperature: ");
  u8g2.print(t);
  u8g2.println(" *C");
  u8g2.sendBuffer();
}