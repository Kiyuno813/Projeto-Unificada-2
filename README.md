# Projeto-Unificada-2
Alarme de baixo custo.

# PROJETO ATUAL - ESP32
Existem somente **3 arquivos** na nova iteração do projeto. O principal deles é o **ESP32_Gmail_Sender.ino** é o principal deles onde a lógica acontece, o **Gsender_32.cpp (NÃO DEVE SER ALTERADO)** define a comunicação SMTP e o **Gsender_32.h** realiza o armazenamento de configurações.

**Email:** esp8266teste@gmail.com

**Senha:** 123456789esp

Sempre usar **Serial.begin(9600)**

**LEITURA DO LDR É ENTRE ELE E O RESISTOR DE RETORNO AO GND**

Pino 01 Digital não funciona

**ADC2 Não pode ser usado com WIFI**

**ADC1 Pode ser utilizado com WIFI**

---


# Resources

Alguns videos, links e scripts que podem ser úties.

[Playlist: "ESP" - Fernando K Tecnologia](https://www.youtube.com/playlist?list=PL_xGnxKCyJXo65eEk9hVlwtLznNnMjB8j)

[Playlist: "ESP Primeiros Passos" - Brincando Com Ideias ](https://www.youtube.com/playlist?list=PL7CjOZ3q8fMe6DxojEFuDx4BP0qbbpKtP)

[Vídeo: "ESP32 o Matador De Arduino - Primeiros Passos" - TDC PROJETOS](https://www.youtube.com/watch?v=i6Z1Ry5moCw)

[ULTRASSONIC ESP32](https://www.instructables.com/id/Pocket-Size-Ultrasonic-Measuring-Tool-With-ESP32/)

[Fernando K - Ultrassonico ESP32](https://www.instructables.com/id/ESP32-With-Ultrasonic-Sensor/)

[Relógio ESP32](https://www.filipeflop.com/blog/relogio-com-esp32-e-oled-com-servidor-ntp/)

[Pinout Reference - ESP32](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)

---
# Esquema elétrico

![Fritizing - Projeto](https://cdn.discordapp.com/attachments/379617751360339968/565286727946600488/unknown.png)

# Layout dos Pinos

![Pinangem DOIT ESP 32](https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-36-GPIOs-updated.jpg?ssl=1)


