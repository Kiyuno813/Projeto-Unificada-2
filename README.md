# Projeto-Unificada-2
Alarme de baixo custo.

## Repositório
A versão atual do alarme funciona utilizando **3 arquivos**. Ainda estou estudando se o código atual é compatível com o novo modelo do NodeMCU baseado no ESP32. 

**SE REALMENTE NÃO FOR COMPATÍVEL PRATICAMENTE O CÓGIDO TODO VAI TER QUE SER REESCRITO**

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








