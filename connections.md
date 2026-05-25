# Circuit Connections

## IR Sensor Connections

### Lane 1 Sensors
| Sensor | ESP32 GPIO Pin |
|--------|----------------|
| IR Sensor 1 | GPIO 13 |
| IR Sensor 2 | GPIO 12 |
| IR Sensor 3 | GPIO 14 |

### Lane 2 Sensors
| Sensor | ESP32 GPIO Pin |
|--------|----------------|
| IR Sensor 4 | GPIO 27 |
| IR Sensor 5 | GPIO 26 |
| IR Sensor 6 | GPIO 25 |

---

## LCD Display Connections

### LCD Display 1
| LCD Pin | ESP32 Connection |
|---------|------------------|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### LCD Display 2
| LCD Pin | ESP32 Connection |
|---------|------------------|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 18 |
| SCL | GPIO 19 |

---

## Traffic LED Connections

### Lane 1 Traffic LEDs
| LED | ESP32 GPIO Pin |
|-----|----------------|
| Red LED | GPIO 33 |
| Yellow LED | GPIO 32 |
| Green LED | GPIO 23 |

### Lane 2 Traffic LEDs
| LED | ESP32 GPIO Pin |
|-----|----------------|
| Red LED | GPIO 4 |
| Yellow LED | GPIO 16 |
| Green LED | GPIO 17 |

---

## Power Connections
- ESP32 powered via USB
- IR sensors powered using 3.3V / 5V
- LCD displays powered using 5V
- Common GND connected across all modules