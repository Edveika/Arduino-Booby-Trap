<p align="center">
  <img height="500px" src="https://github.com/Edveika/Arduino-Booby-Trap/assets/113787144/aafb613f-ed8f-43fb-98ea-ded1976c46a2">
</p>

# ⚠️ Disclaimer

This project serves a learning purpose. I don't want to or encourage to harm anyone or anything. Use with caution and responsibility.

# 🪤 Arduino-Booby-Trap

This project implements a simple booby trap using Arduino. The trap activates when a sensor is triggered by an object passing within a certain distance.

**You can find a demonstration of this project on [YouTube](https://www.youtube.com/shorts/JCjqhoGpUXk)**

# 🛠️ How it works

1. When started, the sensor gets the distance to the closest obect
2. Sensor is constantly running in the main loop, calculating distance
3. If distance change exceeded the limit, the booby trap ignites

`cm_lethal_distance` determines how much the distance can change without the trap getting activated.

NOTE: the ultra sound sensor is not very accurate, the smaller `cm_lethal_distance` value is, the bigger the chance of accidental activation.

# ⚙️ Hardware

* Arduino UNO
* Electronic lighter(or anything else that can make a spark)
* Ultra sound sensor
* LED
* Bread board
* Wires

# 💿 Compiling & Installing

1. Git clone this repo

```
git clone https://github.com/Edveika/Arduino-Booby-Trap.git
```

2. Open main.ino using your arduino IDE
3. Make sure you have Arduino UNO libraries installed
4. Click compile & upload

# 📜 License

This project is licensed under the GPL v2 [LICENSE](LICENSE).
