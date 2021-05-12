# Acionamento remoto de LEDs com Blynk 🚦

## It's showtime! 🗿
Para este tutorial, utilizaremos o Blynk e o Arduino IDE para montarmos um circuito que nos permite acender LED's remotamente.  

Estaremos utilizando o Arduino IDE, plataforma de desenvolvimento Arduino, pela sua praticidade, mas recomendamos também o uso do PlatformIO para uma melhor estrutura de código.

## O que é o Blynk?  
O Blynk é uma plataforma mobile que nos permite criar aplicações que possam interagir com uma grande variedade de hardwares remotamente – ESP32, ESP8266, todos os modelos de Arduino e Raspberry, etc.  
  
O aplicativo é gratuito e está disponível para Android e iOS.  
  
Para entendermos como funciona o Blynk, podemos dividi-lo em três partes:  
  
- Blynk App: permite que o usuário configure uma tela que possa interagir com o hardware selecionado utilizando de Widgets, que vão de botões até displays, notificações, músicas e muito mais.  
- Blynk Server: realiza a comunicação entre o app e o hardware, através do Cloud Blynk, armazenando e transmitindo dados, onde o servidor é independente do app.  
- Blynk Libraries: a biblioteca Blynk, disponível em diversas plataformas, é responsável pela conexão do hardware com o servidor, gerindo requisições de entrada e saída de dados e comandos.  
  
## Montando a aplicação
Após cadastrarmos uma conta e estarmos logado, encontramos a tela que nos permite criar novos projetos, gerenciar nossas aplicações e acessar a comunidade do Blynk. 

Bora criar um novo projeto, então! :shipit:  

Escolhemos um nome de nossa escolha e selecionamos o dispositivo NodeMCU, com o tipo de conexão Wi-Fi e sendo o tema de nossa escolha.  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117669261-12d66180-b17d-11eb-9c9f-225265481620.jpg" width="250">
   <img src="https://user-images.githubusercontent.com/60518597/117670378-351caf00-b17e-11eb-85ff-d3abfe503145.jpg" width="250">
</p>

Após criarmos o projeto, nos será enviado um token de autenticação da nossa aplicação que utilizaremos para fazer a conexão do hardware com o servidor – guarde-o bem.  

No canto superior direito encontramos um símbolo de + que abrirá a caixa de seleção de Widgets, onde selecionaremos um Styled Button.  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117670818-9e042700-b17e-11eb-8414-ea9b321d0963.jpg" width="250">
</p>

O botão aparecerá na tela, podendo ser movido e redirecionado.  

Ao clicar no botão sem a aplicação rodando nós podemos selecionar um nome para o botão e estilizá-lo a vontade.  

É importante configurarmos o OUTPUT do botão que representa a saída lógica do nosso ESP8266.  

Temos opções de pinos digitais, analógicos e virtuais referentes ao nosso microcontrolador, onde para o primeiro botão selecionaremos a saída D1. 

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117836746-3b2e9080-b24f-11eb-85b2-8775a8a03a82.jpg" width="250">
  <img src="https://user-images.githubusercontent.com/60518597/117836793-4681bc00-b24f-11eb-8234-95bb520bb3e1.jpg" width="250">
</p>

Ainda no canto direito, temos um símbolo de start que “rodará” a aplicação, nos permitindo testar o visual de nosso botão.  

Também temos um símbolo de microcontrolador que nos permite conferir se nosso servidor está ligado ou não.  

Você pode optar por manter apenas um LED, mas em nosso exemplo criamos mais 2 botões.  

Basta seguirmos os mesmos passos para criar os botões, porém definindo o botão do LED amarelo como saída D2 e o botão do LED verde como saída D3.  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117836846-51d4e780-b24f-11eb-9a7a-63f3ddcc8832.jpg" width="250">
  <img src="https://user-images.githubusercontent.com/60518597/117672232-07d10080-b180-11eb-85ed-5e4ca439794b.jpg" width="250">
</p>

Podemos também compartilhar o acesso da nossa aplicação, recurso disponível nas configurações do projeto, mas essa função nos consome 1000 energias permanentes.  

Energias são uma espécie de "dinheiro" que são usadas para adicionar Widgets ou compartilhar projetos, então tem que administrar bem!

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117977713-7ee4d100-b307-11eb-8a60-f35c21f35c4e.png" width="250">
  <img src="https://user-images.githubusercontent.com/60518597/117977669-755b6900-b307-11eb-8ea3-3217a1c501b5.jpg" width="250">
</p>

E pronto, temos nossa aplicação configurada!  

## Configurando o Arduino IDE
Link para download: https://www.arduino.cc/en/software  

Para podermos utilizar o nosso ESP8266 em nosso Arduino IDE, devemos selecionar "Arquivo > Preferências" e colar o link a seguir em "URLs Adicionais para Gerenciadores de Placas": 

> http://arduino.esp8266.com/stable/package_esp8266com_index.json

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117676159-aa3eb300-b183-11eb-9f92-8706bcfa289a.png">
  <img src="https://user-images.githubusercontent.com/60518597/117676368-dd814200-b183-11eb-8cd2-fa301af01f65.png" width="586">
</p>

Então, para selecionarmos a placa ESP8266, selecionamos "Ferramentas > Placa > ESP8266 Boards" e encontramos diversos modelos do ESP8266 onde selecionaremos "Generic ESP8266 Module".  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117679107-5d101080-b186-11eb-9920-0f93e398e863.png">
</p>

Após isso, devemos selecionar "Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...", pesquisar a biblioteca do Blynk e a instalar.  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117677096-8760ce80-b184-11eb-9914-3aeb95b353d7.png" width="650">
  <img src="https://user-images.githubusercontent.com/60518597/117837205-a2e4db80-b24f-11eb-9923-d17f37ed0e2e.png" width="650">
</p>

Agora podemos codar!  

Utilizaremos o código a seguir:  

```
//Mensagens de status de conexão que aparecerão no terminal Serial
#define BLYNK_PRINT Serial

//Definição de constantes dos pinos
#define LED_PIN_D1 5
#define LED_PIN_D2 4
#define LED_PIN_D3 0

//Configurações Blynk x Esp8266
#include <BlynkSimpleEsp8266.h>

//Token de autorização do seu projeto (enviado por email)
char auth[] = "my-auth";
//Informações da sua rede Wi-Fi
char ssid[] = "my-wifi-name";
char pass[] = "my-wifi-password";

void setup()
{
  //Definição dos pinos
  pinMode(LED_PIN_D1, OUTPUT);
  pinMode(LED_PIN_D2, OUTPUT);
  pinMode(LED_PIN_D3, OUTPUT);

  //Inicialização do terminal Serial
  Serial.begin(9600);

  //Responsável por configurações e conexão da rede
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  //Gerencia a conexão com o servidor
  Blynk.run();
}

```

Esse código está disponível para download aqui no repositório, basta que você abra o .ino e dê o upload do código em seu ESP8266 ao clicar no botão "Carregar" ou ao pressionar as teclas CTRL + U.  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117816790-45479380-b23d-11eb-93cd-9c5e0ce820e8.png" width="300">
</p>

Podemos clicar o ícone do monitor Serial que se encontra no canto superior direito da IDE, onde podemos acompanhar o status da conexão.  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117818031-9310cb80-b23e-11eb-9d49-515d96e4bce0.png" width="400">
  <img src="https://user-images.githubusercontent.com/60518597/117837593-f35c3900-b24f-11eb-9a6c-5f27938a4988.png">
</p>

Se aparece no Serial um "Ready", tudo aparenta estar bem!  

## Circuito
Itens necessários:  

- 1x jogo de jumpers macho X fêmea;  
- 1x jogo de jumpers macho X macho;  
- 1x protoboard de 400 pontos ou maior;  
- 3x resistores 330Ohm;  
- 3x LEDs disfusos, cor de preferência (usamos vermelho, amarelo e verde);  
- 1x microcontrolador ESP8266.  

Agora montamos o circuito, que deve ficar dessa forma:  

<p align="center">
  <img src="https://user-images.githubusercontent.com/60518597/117968318-70dd8300-b2fc-11eb-94d2-a91612c0dd82.png">
</p>

E, se estiver tudo certo, esse será o resultado:  

https://user-images.githubusercontent.com/60518597/117822641-1d5b2e80-b243-11eb-8199-09e62d9efd6c.mp4

## Fin
Se funcionou, mandou bem!  

Senão, pode voltar no tutorial ou entrar em contato que podemos te ajudar! :)  

Esperamos que tenha gostado, sayonara!
