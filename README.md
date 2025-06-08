# 🌍 ORBIS — Conectando Solidariedade em Tempos de Emergência

---
### 2TDSZ-2025/2TDSPR-2025

- JULIANA MOREIRA DA SILVA – RM: 554113 - Arquiteta de Soluções em Dados & Cloud

- KEVIN CHRISTIAN NOBRE – RM: 552590 - Desenvolvedor Full Stack - Mobile & .NET

- SABRINA DO COUTO XAVIER – RM: 552728 - Desenvolvedora Back-End Java & QA

--- 

### Introdução ao Projeto

**ORBIS** é uma solução tecnológica voltada para emergências urbanas e desastres naturais, como enchentes, deslizamentos e falhas de infraestrutura. O projeto nasce com o objetivo de conectar comunidades vulneráveis a redes de apoio por meio de um sistema geolocalizado, acessível e em tempo real.
Desenvolvida como um aplicativo leve e seguro, a plataforma ORBIS integra sensores, atuadores, painéis interativos e uma arquitetura IoT conectada a um gateway em Node-RED, permitindo a visualização e o monitoramento contínuo dos riscos.

Funcionalidades principais:
- 📍 Cadastro e validação de dados pessoais;
- 🚨 Disparo de alertas geolocalizados por tipo e gravidade;
- 🗺️ Mapa interativo com ícones de emergência;
- 🫂 Integração com ONGs por localidade e tipo de assistência;
- 🔄 Sistema modular e resiliente, mesmo em áreas com baixa conectividade.

---

## ⚙️ Tecnologias Utilizadas

- ESP32 (Simulado no Wokwi)
- Sensores (simulados): enchentes, chuvas fortes, ventos fortes
- MQTT (protocolo de comunicação)
- ThingSpeak (gateway para comunicação e dashboard)
- Plataforma Wokwi (simulador de hardware)
- JSON (formato padrão de troca de mensagens)

---

## 📡 Estrutura IoT

A solução IoT ORBIS é composta por:

- 3 sensores simulados no Wokwi:
  - Sensor de Enchente
  - Sensor de Chuvas Fortes
  - Sensor de ventos Fortes
- Envio contínuo de dados via MQTT
- Gateway ThingSpeak que:
  - Processa e encaminha os dados
  - Exibe um **dashboard em tempo real** com status dos sensores
  - Gera alertas visuais para situações críticas
- Fluxos ThingSpeak organizados e comentados para replicação

---

## 🧭 Dashboard

O painel desenvolvido no Node-RED exibe em tempo real:

- Status dos sensores (OK / ALERTA)
- Gráficos e indicadores por tipo de sensor
- Histórico recente de alertas
- Canal de controle (para atuadores, se aplicável)

### Dashboard ThingSpeak
![image](https://github.com/user-attachments/assets/35a6a7d7-57a0-4a69-93d3-3bd22d561690)


---

## 🔁 Como Executar a Solução

### Pré-requisitos:
- Conta gratuita no [Wokwi](https://wokwi.com/)
- Node-RED instalado localmente ou acesso via [FRED](https://fred.sensetecnic.com/)
- Broker MQTT (ex: broker.hivemq.com ou test.mosquitto.org)

### Passos:

1. Clone o repositório:
   ```bash
   git clone https://github.com/SEU_USUARIO/orbis-iot.git

2. Obtenha a Arduino IDE
   
3. Escolha a placa ESP32 Dev Board (simulador)
    ```

### Link Youtube
- [Global Solution Protech the Future - Disruptives Architectures IoT, IoB & Gen AI - 2TDSZ-2025](https://youtu.be/O27VZrL3HFQ)
