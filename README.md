# Projeto-Unificada-2
Alarme de baixo custo.

## Repositório
A versão atual do alarme funciona utilizando **3 arquivos**. Ainda estou estudando se o código atual é compatível com o novo modelo do NodeMCU baseado no ESP32.

O arquivo .ino **é o arquivo principal**, a execução das instruções principais acontecem nele enquanto os outros dois são utilizados para a definição de valores e armazenamento de configurações.

## ESP8266_Gmail_Sender.ino

Este arquivo é o set de instruções principais do alarme. 

### Gsender.cpp **(NÃO DEVE SER ALTERADO)**

Definição a estrutura para a conexão ao servidor SMTP do email.

### Gsender.h

Contém as informações do email utilizado pelo alarme como endereço, destino, login e servidor de SMTP.










