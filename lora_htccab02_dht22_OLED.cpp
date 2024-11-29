/*
fonctionne correctement???????
------------************************
dernier essai

pour les balances, cablage des connecteurs étanches
cordon crème et plat
noire   A,B+
rouge   E-
jaune   E+
vert    A,B-

correspondance avec les cables noirs étanches
vert    A,B+
noir    E-
rouge   E+
bleu    A,B-

cablage des balances vues en dessous (donc platine porte jauges retournée)
vue eu U inversé
    -------------------------
    |  E-              A,B+ |
    |                       |    
    |                       |
    |   A,B-            E+  |

fils noirs des jauges relient les jauges E- avec AB-  et AB+ avec E+
fils blancs des jauges telient E- avec AB+    et AB- avec E+

*/
#include "LoRaWan_APP.h"
#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <U8g2lib.h>

// Définir la broche où le DHT22 est connecté
#define DHTPIN 5  // Changez ceci par la broche que vous utilisez

// Définir le type de capteur DHT
#define DHTTYPE DHT22

// Initialiser le capteur DHT
DHT dht(DHTPIN, DHTTYPE);

// Initialiser l'écran OLED intégré
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

/*
 * set LoraWan_RGB to Active,the RGB active in loraWan
 * RGB red means sending;
 * RGB purple means joined done;
 * RGB blue means RxWindow1;
 * RGB yellow means RxWindow2;
 * RGB green means received done;
 */

/* OTAA para c'est ce OTAA paramêtre qui est utilisé */

uint8_t appEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/*décommenter les modules à programmer */

/*décommenter les modules à programmer */

//lora-01
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xE8 };
//uint8_t appKey[] = { 0x64, 0x15, 0x08, 0x32, 0x47, 0x90, 0x93, 0x43, 0x1D, 0x26, 0xB5, 0xFD, 0x34, 0xF8, 0xF0, 0xB8 };

//lora-02 
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xE9 };
//uint8_t appKey[] = { 0x44, 0x9B, 0x5A, 0x40, 0x01, 0x94, 0x8A, 0x20, 0xE0, 0xD5, 0x89, 0x1B, 0xB6, 0x64, 0x7C, 0xCC };

//lora-03 GP
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xEA };
//uint8_t appKey[] = { 0xDF, 0x6F, 0x66, 0x43, 0x25, 0x79, 0x56, 0x07, 0x11, 0x06, 0x0D, 0x5A, 0x39, 0x4B, 0x9C, 0x36 };

//lora-04
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xEB};
//uint8_t appKey[] = { 0x03, 0x6C, 0x0D, 0x88, 0x44, 0xDC, 0x68, 0xE4, 0xE5, 0xAE, 0xEE, 0x00, 0xCF, 0xA5, 0xFD, 0x67 };

// lora-05
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xE2 };
//uint8_t appKey[] = { 0x1E, 0xE9, 0x60, 0x7D, 0x71, 0x7A, 0x40, 0x17, 0x67, 0x10, 0x62, 0xFD, 0x02, 0xF3, 0xBB, 0x54 };

//bat //lora-06
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xC4, 0xD3};
//uint8_t appKey[] = { 0x9C, 0xBB, 0x00, 0x03, 0xF8, 0xC6, 0xB9, 0xB2, 0x7B, 0x47, 0xAC, 0xEE, 0x38, 0xD2, 0x52, 0xE1  };

//lora-07
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xED };
//uint8_t appKey[] = { 0xF1, 0x3D, 0x66, 0x8A, 0x97, 0x04, 0xE7, 0x9D, 0x9F, 0xA6, 0x7A, 0x8B, 0x35, 0x9E, 0xF1, 0x24 };

//lora-08 GPS
uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xE4 };
uint8_t appKey[] = { 0x8D, 0x7D, 0xFE, 0x05, 0x32, 0x45, 0xAD, 0xAC, 0x3A, 0x40, 0x74, 0x04, 0x78, 0x85, 0xDE, 0xF0 };

//lora-09 GPS
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xEE };
//uint8_t appKey[] = { 0x1C, 0x92, 0x06, 0x95, 0xD4, 0x03, 0xF4, 0x34, 0xC6, 0x60, 0xB8, 0xC4, 0xFD, 0x90, 0xA2, 0x8D };

//lora-10
//uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x05, 0xB1, 0xE7 };
//uint8_t appKey[] = { 0xAD, 0x07, 0x52, 0x8F, 0x33, 0x61, 0xBC, 0x9B, 0xDD, 0x28, 0x54, 0x93, 0x35, 0x4A, 0x35, 0x29 };


/* ABP para*/
uint8_t nwkSKey[] = { 0x15, 0xb1, 0xd0, 0xef, 0xa4, 0x63, 0xdf, 0xbe, 0x3d, 0x11, 0x18, 0x1e, 0x1e, 0xc7, 0xda,0x85 };
uint8_t appSKey[] = { 0xd7, 0x2c, 0x78, 0x75, 0x8c, 0xdc, 0xca, 0xbf, 0x55, 0xee, 0x4a, 0x77, 0x8d, 0x16, 0xef,0x67 };

uint32_t devAddr =  ( uint32_t )0x007e6ae1;

/*LoraWan channelsmask, default channels 0-7*/ 
uint16_t userChannelsMask[6]={ 0x00FF,0x0000,0x0000,0x0000,0x0000,0x0000 };

/*LoraWan region, select in arduino IDE tools*/
LoRaMacRegion_t loraWanRegion = ACTIVE_REGION;

/*LoraWan Class, Class A and Class C are supported*/
DeviceClass_t  loraWanClass = LORAWAN_CLASS;

/*the application data transmission duty cycle.  value in [ms].*/
uint32_t appTxDutyCycle = 60000;//900000;//////////////à modifier pour changer cycle d'envoi à TTN  900 000 = 15mn

/*OTAA or ABP*/
bool overTheAirActivation = LORAWAN_NETMODE;

/*ADR enable*/
bool loraWanAdr = LORAWAN_ADR;

/* set LORAWAN_Net_Reserve ON, the node could save the network info to flash, when node reset not need to join again */
bool keepNet = LORAWAN_NET_RESERVE;

/* Indicates if the node is sending confirmed or unconfirmed messages */
bool isTxConfirmed = LORAWAN_UPLINKMODE;

/* Application port */
uint8_t appPort = 2;
/*!
* Number of trials to transmit the frame, if the LoRaMAC layer did not
* receive an acknowledgment. The MAC performs a datarate adaptation,
* according to the LoRaWAN Specification V1.0.2, chapter 18.4, according
* to the following table:
*
* Transmission nb | Data Rate
* ----------------|-----------
* 1 (first)       | DR
* 2               | DR
* 3               | max(DR-1,0)
* 4               | max(DR-1,0)
* 5               | max(DR-2,0)
* 6               | max(DR-2,0)
* 7               | max(DR-3,0)
* 8               | max(DR-3,0)
*
* Note, that if NbTrials is set to 1 or 2, the MAC will not decrease
* the datarate, in case the LoRaMAC layer did not receive an acknowledgment
*/
uint8_t confirmedNbTrials = 4;

int maxtry = 50;

/*!
   \brief   Prepares the payload of the frame
*/

static void prepareTxFrame( uint8_t port )
{
	/*
  //en miliVolts

  //appData[0] = (uint8_t)(batteryVoltage >> 8);//décalage de 8 bit vers la droite, 
  //4803  donne 0001001011000011 sur 16bit donc reste les 8 1ers bits 00010010  soit 12 hex
  //Serial.println(appData[4]);
  
  //appData[1] = (uint8_t)batteryVoltage;
  //4803  donne 0001001011000011 donc si uint_8  on prend donc 8bit de droite 11000011 soit C3 hex
  // quand on concatène 12C3 hex dans un convertisseur hexa vers décimal, cela donne 4803 mV au décodage de la trame LORA
  //Serial.println(appData[5]);

  //calcul pour la température
  //sur lorawan on obtient 00 74 hex
  //on concatène 00 et 74 , on convertit hexa vers décimal et on obtient 116 décimal
  //on reprend la formule de Sylvain  t_byte = (t + 35 )*2  donc partie entière de t=116/2 moins 35 degrés soit 23 degrés
*/
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);// pour activer l'alimentation des capteurs branchés dur Vext
  delay(3000);

  // DHT22 température et humidité locales
  Serial.println("DHTxx test!");
  dht.begin();
  delay(3000);//pour laisser le temps de montée de la sonde
  float h = dht.readHumidity();
  //Read temperature as Celsius
  float t = dht.readTemperature();
  int8_t  t_byte = (t + 35 )*2;      //  à mieux commenter
  uint8_t h_byte = h*2;              // à mieux commenter
  
  Serial.print(t);
  Serial.println( " C DHT  ");
  Serial.print(t_byte,HEX);
  Serial.println(" Byte DHT   ");

  Serial.print(h);
  Serial.println( " hum DHT  ");
  Serial.print(h_byte,HEX);
  Serial.println(" Byte DHT   ");

  //la tension batterie
  uint16_t batteryVoltage = getBatteryVoltage();
  Serial.print(batteryVoltage);
  Serial.println( " mV ");
                  
  appDataSize = 6;// nombre total d'octets de la trame envoyée
  //et à changer selon le nombre de balances et capteurs

  appData[0] = (uint8_t)(batteryVoltage>>8);
  appData[1] = (uint8_t)batteryVoltage;

    
  appData[2] = (uint8_t)(t_byte>>8);
  appData[3] = (uint8_t)t_byte;

    
  appData[4] = (uint8_t)(h_byte>>8);
  appData[5] = (uint8_t)h_byte;

  
  digitalWrite(Vext, HIGH); // pour déconnecter les capteurs branchés sur Vext
  
}
////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  Serial.println("Setup started");

  // Imprimer le nom du fichier
  Serial.print("Nom du fichier: ");
  Serial.println(__FILE__);

  // Initialiser d'autres composants
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW); // Activer l'alimentation des capteurs connectés à Vext
  delay(3000); // Attendre que les capteurs se stabilisent

  dht.begin();
  Serial.println("DHT22 initialisé");

  // Initialiser l'écran OLED
  Serial.println("Initialisation de l'écran OLED...");
  u8g2.begin();
  Serial.println("Écran OLED initialisé");
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr); // Choisir une police
  u8g2.drawStr(0, 10, "Initialisation...");
  u8g2.sendBuffer();
  delay(2000); // Pause pour permettre à l'écran de s'initialiser

  // Afficher un message initial sur l'écran OLED
  u8g2.clearBuffer();
  u8g2.setCursor(0, 10);
  u8g2.print("Systeme initialise");
  u8g2.setCursor(0, 30);
  u8g2.print("Attente des mesures...");
  u8g2.sendBuffer();

  Serial.println("Setup terminé");



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

////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
void loop()
{
	switch( deviceState )
	{
		case DEVICE_STATE_INIT:
		{
#if(LORAWAN_DEVEUI_AUTO)
			LoRaWAN.generateDeveuiByChipID();
#endif
#if(AT_SUPPORT)
			getDevParam();
#endif
			printDevParam();
			LoRaWAN.init(loraWanClass,loraWanRegion);
			deviceState = DEVICE_STATE_JOIN;
			break;
		}
		case DEVICE_STATE_JOIN:
		{
			LoRaWAN.join();
			break;
		}
		case DEVICE_STATE_SEND:
		{
			prepareTxFrame( appPort );
			LoRaWAN.send();
			deviceState = DEVICE_STATE_CYCLE;
			break;
		}
		case DEVICE_STATE_CYCLE:
		{
			// Schedule next packet transmission
			txDutyCycleTime = appTxDutyCycle + randr( 0, APP_TX_DUTYCYCLE_RND );
			LoRaWAN.cycle(txDutyCycleTime);
			deviceState = DEVICE_STATE_SLEEP;
			break;
		}
		case DEVICE_STATE_SLEEP:
		{
			LoRaWAN.sleep();
			break;
		}
		default:
		{
			deviceState = DEVICE_STATE_INIT;
			break;
		}
	}
}
////////////////////////////////////////////////////////////
