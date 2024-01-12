/**
 * @file    userConfig_sample.h
 * @brief   Values must be configured by the user
 * @version 4.0.0 Master
 *
 */

#pragma once

// firmware version (must match with definitions in the main source file)
#define USR_FW_VERSION    4
#define USR_FW_SUBVERSION 0
#define USR_FW_HOTFIX     0
#define USR_FW_BRANCH     "MASTER"

// List of supported machines
enum MACHINE {
    RancilioSilvia,   // MACHINEID 0
    RancilioSilviaE,  // MACHINEID 1
    Gaggia,           // MACHINEID 2
    QuickMill         // MACHINEID 3
};

/**
 * Preconfiguration
 */

// Machine
#define MACHINEID RancilioSilvia   // Machine type (see enum MACHINE)

// Display
#define OLED_DISPLAY 2             // 0 = deactivated, 1 = SH1106 (e.g. 1.3 "128x64), 2 = SSD1306 (e.g. 0.96" 128x64), 3 = SH1106_126x64_SPI
#define OLED_I2C 0x3C              // I2C address for OLED, 0x3C by default
#define DISPLAYTEMPLATE 3          // 1 = Standard display template, 2 = Minimal template, 3 = only temperature, 4 = scale template, 20 = vertical display (see git Handbook for further information)
#define DISPLAYROTATE U8G2_R0      // rotate display clockwise: U8G2_R0 = no rotation; U8G2_R1 = 90°; U8G2_R2 = 180°; U8G2_R3 = 270°
#define SCREEN_WIDTH 128           // OLED display width, in pixels
#define SCREEN_HEIGHT 64           // OLED display height, in pixels
#define SHOTTIMER 1                // 0 = deactivated, 1 = activated 2 = with scale
#define HEATINGLOGO 0              // 0 = deactivated, 1 = Rancilio, 2 = Gaggia
#define OFFLINEGLOGO 1             // 0 = deactivated, 1 = activated
#define SHOTTIMERDISPLAYDELAY 3000 // time in ms that shot timer will be shown after brew finished
#define VERBOSE 0                  // 1 = Show verbose output (serial connection), 0 = show less

#define LANGUAGE 0                 // LANGUAGE = 0 (DE), LANGUAGE = 1 (EN), LANGUAGE = 2 (ES)

// Connectivity
#define CONNECTMODE 1              // 0 = offline 1 = WIFI-MODE
#define HOSTNAME "silvia"
#define PASS "CleverCoffee"        // default password for WiFiManager
#define MAXWIFIRECONNECTS 5        // maximum number of reconnection attempts, use -1 to deactivate
#define WIFICONNECTIONDELAY 10000  // delay between reconnects in ms

// PID & Hardware
#define ONLYPID 1                  // 0 = PID and preinfusion, 1 = Only PID
#define ONLYPIDSCALE 0             // 0 = off , 1 = OnlyPID with Scale
#define BREWMODE 1                 // 1 = Brew by time (with preinfusion); 2 = Brew by weight (from scale)
#define BREWDETECTION 0            // 0 = off, 1 = Software (Onlypid 1), 2 = Hardware (Onlypid 0), 3 = optocoupler for Only PID
#define BREWSWITCHTYPE 0           // 0 = no switch connected, 1 = normal switch, 2 = trigger switch
#define POWERSWITCHTYPE 0          // 0 = no switch connected, 1 = normal switch, 2 = trigger switch
#define STEAMSWITCHTYPE 0          // 0 = no switch connected, 1 = normal switch, 2 = trigger switch
#define OPTOCOUPLERTYPE HIGH       // BREWDETECTION 3 configuration; HIGH or LOW trigger optocoupler
#define TRIGGERTYPE HIGH           // LOW = low trigger, HIGH = high trigger relay for pump & valve
#define PRESSURESENSOR 0           // 0 = no pressure sensor connected, 1 = pressure sensor connected, 2 = ABP2 pressure sensor connected
#define TEMP_LED 1                 // Blink status LED when temp is in range
#define WATER_SENS 0               // 0 = no water sensor, 1 = water sensor XKC-Y25-NPN connected, 2 = XKC-Y25-PNP connected

// Brew Scale
#define SCALE_SAMPLES 2                     // Load cell sample rate
#define SCALE_CALIBRATION_FACTOR 3195.83    // Raw data is divided by this value to convert to readable data

// Backflush values
#define FILLTIME 5000              // time in ms the pump is running
#define FLUSHTIME 10000            // time in ms the 3-way valve is open -> backflush
#define MAXFLUSHCYCLES 5           // number of cycles the backflush should run, 0 = disabled

/* Pressure sensor
 *
 * measure and verify "offset" value, should be 10% of ADC bit reading @supply volate (3.3V)
 * same goes for "fullScale", should be 90%
 */
#define OFFSET      102            // 10% of ADC input @3.3V supply = 102
#define FULLSCALE   922            // 90% of ADC input @3.3V supply = 922
#define MAXPRESSURE 200

// PlatformIO OTA
#define OTA true                   // true = OTA activated, false = OTA deactivated
#define OTAPASS "otapass"          // Password for OTA updates

// MQTT
#define MQTT 0                             // 1 = MQTT enabled, 0 = MQTT disabled
#define MQTT_USERNAME "mymqttuser"
#define MQTT_PASSWORD "mymqttpass"
#define MQTT_TOPIC_PREFIX "custom/Küche."               // topic will be "<MQTT_TOPIC_PREFIX><HOSTNAME>/<READING>"
#define MQTT_SERVER_IP "XXX.XXX.XXX.XXX"                // IP-Address of the MQTT Server
#define MQTT_SERVER_PORT 1883                           // Port of the specified MQTT Server
#define MQTT_HASSIO_SUPPORT 0                           // Enables the Homeassistant Auto Discovery Feature
#define MQTT_HASSIO_DISCOVERY_PREFIX "homeassistant"    // Homeassistant Auto Discovery Prefix

// PID Parameters (not yet in Web interface)
#define EMA_FACTOR 0.6             // Smoothing of input that is used for Tv (derivative component of PID). Smaller means less smoothing but also less delay, 0 means no filtering

#define TEMPSENSOR 2               // Temp sensor type: 1 = DS18B20, 2 = TSIC306

