# SmartDoor – Monitoramento de Acesso e Iluminação

## 🎯 Objetivo

Desenvolver um dispositivo embarcado capaz de monitorar a abertura de uma porta e o nível de luminosidade do ambiente, enviar essas informações via MQTT e responder a comandos para ativar um buzzer.

## 🧰 Componentes Utilizados

- **Microcontrolador**: iMCP HTNB32L  
- **Sensor de luminosidade**: BH1750-FVI (I2C)  
- **Sensor de porta**: Reed Switch (GPIO)  
- **Atuador**: Buzzer (GPIO)  
- **Conectividade**: NB-IoT (via modem interno do HTNB32L)  
- **Broker MQTT**:  
  - IP: `131.255.82.115`  
  - Porta: `1883`  
- **PCB personalizada**: obrigatória para montagem do dispositivo final

## ⚙️ Requisitos Funcionais

### 1. Leitura do sensor BH1750-FVI

- Capturar o valor da luminosidade do ambiente periodicamente.  
- Interpretar valor lido para saber se a luz está acesa ou apagada.  
- Quando o estado da lâmpada mudar de **apagado para aceso**, publicar uma vez o valor `"ON"`.  
- Quando o estado da lâmpada mudar de **aceso para apagado**, publicar uma vez o valor `"OFF"`.

### 2. Leitura do reed switch

- Detectar abertura e fechamento da porta.  
- Quando o estado da porta mudar de **fechado para aberto**, publicar uma vez o valor `"OPEN"`.  
- Quando o estado da porta mudar de **aberto para fechado**, publicar uma vez o valor `"CLOSED"`.

### 3. Envio via MQTT

- Publicar os dados conforme os tópicos padronizados descritos abaixo.
- Frequência dos estados: somente em caso de mudança (event-driven).

### 4. Recebimento via MQTT

- Escutar tópico para controle do buzzer.
- Se receber `"ON"`: ativar buzzer.  
- Se receber `"OFF"`: desativar buzzer.

## 🛰️ Tópicos MQTT Padronizados

> 🔔 **IMPORTANTE**: Cada grupo deverá substituir `<ambiente>` pelo nome do local (ex: `lab1`, `salaaula`, `auditorio`), em letras minúsculas e sem espaços.

| Finalidade   | Tópico MQTT                                | Direção   | Tipo de dado     |
|--------------|---------------------------------------------|-----------|------------------|
| Iluminação   | hana/<ambiente>/smartdoor/light             | Publish   | `"ON"` / `"OFF"` |
| Porta        | hana/<ambiente>/smartdoor/door              | Publish   | `"OPEN"` / `"CLOSED"` |
| Buzzer       | hana/<ambiente>/smartdoor/buzzer            | Subscribe | `"ON"` / `"OFF"` |

## 🖨️ Desenvolvimento da PCB

- A placa deve integrar todos os componentes citados.  
- Deve conter conector para alimentação.  
- Deverá ter marcações serigrafadas identificando pinos e funções.  
- Deve ser projetada usando software apropriado (ex: EasyEDA, KiCad).  
- O layout deverá ser entregue nos formatos `.pdf` e `.gerber`.  
- O esquemático deverá ser entregue em `.pdf`.

## 🔍 Observações Técnicas

- O sensor BH1750-FVI comunica via I2C. Verifique o endereço padrão.  
- O reed switch deve ser conectado com resistor de pull-up.  
- O buzzer utilizado no projeto permite controle direto via GPIO.  
- Implementar reconexão automática ao broker MQTT em caso de falha de conexão.

## 📋 Critérios de Avaliação

- Funcionamento correto do envio dos estados de lâmpada e porta via MQTT.  
- Funcionamento do buzzer com comandos MQTT.  
- Uso correto e consistente dos tópicos conforme padronizado.  
- Documentação completa na Wiki do repositório, com evolução do projeto e dificuldades encontradas.  
  - Exemplo de documentação: [Hands-On Linux Wiki](https://github.com/rafaelfacioni/Hands-On-Linux/wiki)  
- Projeto de PCB funcional e documentado na Wiki.  
- Apresentação prática do projeto final.  
- *(Opcional)* Registro pessoal na Wiki com os principais aprendizados adquiridos ao longo do curso.

---

> Este projeto faz parte do Módulo 4 do Curso de Capacitação em Sistemas Embarcados com o iMCP HTNB32L.
