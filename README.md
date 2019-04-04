# Projeto-Unificada-2
Alarme de baixo custo.

# Repositório

## PROJETO ATUAL - ESP32
Existem somente **2 arquivos** na nova iteração do projeto. O principal deles é o **Gsender_32.cpp** é o principal deles onde a lógica acontece, e o **Gsender_32.h** realiza o armazenamento de configurações.

---

## PROJETO ANTIGO - ESP8266
A versão atual do alarme funciona utilizando **3 arquivos**. Ainda estou estudando se o código atual é compatível com o novo módulo DOIT Devkit 1 baseado no ESP32. 

**~~SE REALMENTE NÃO FOR COMPATÍVEL PRATICAMENTE O CÓGIDO TODO VAI TER QUE SER REESCRITO~~**
** UPTDATE: TODO O CÓDIGO REALMENTE TERA QUE SER REFEITO **

O arquivo .ino **é o arquivo principal**, a execução das instruções principais acontecem nele enquanto os outros dois são utilizados para a definição de valores e armazenamento de configurações.

### ESP8266_Gmail_Sender.ino

Este arquivo é o set de instruções principais do alarme. 

### Gsender.cpp **(NÃO DEVE SER ALTERADO)**

Definição a estrutura para a conexão ao servidor SMTP do email.

### Gsender.h

Contém as informações do email utilizado pelo alarme como endereço, destino, login e servidor de SMTP.

# Resources

Alguns videos, links e scripts que podem ser úties.

[Playlist: "ESP" - Fernando K Tecnologia](https://www.youtube.com/playlist?list=PL_xGnxKCyJXo65eEk9hVlwtLznNnMjB8j)

[Playlist: "ESP Primeiros Passos" - Brincando Com Ideias ](https://www.youtube.com/playlist?list=PL7CjOZ3q8fMe6DxojEFuDx4BP0qbbpKtP)

[Vídeo: "ESP32 o Matador De Arduino - Primeiros Passos" - TDC PROJETOS](https://www.youtube.com/watch?v=i6Z1Ry5moCw)

[ULTRASSONIC ESP32](https://www.instructables.com/id/Pocket-Size-Ultrasonic-Measuring-Tool-With-ESP32/)

[Fernando K - Ultrassonico ESP32](https://www.instructables.com/id/ESP32-With-Ultrasonic-Sensor/)

[Relógio ESP32] (https://www.filipeflop.com/blog/relogio-com-esp32-e-oled-com-servidor-ntp/)


# Layout dos Pinos

![Pinangem DOIT ESP 32](https://docs.zerynth.com/latest/_images/doitesp32pin.jpg)


