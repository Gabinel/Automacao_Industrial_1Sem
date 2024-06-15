
Título Controle de Acesso com Arduino

Descrição
Você foi contratado para desenvolver um sistema de controle 
de acesso simples usando Arduino. O sistema consiste em um 
teclado matricial de 4x4 e um display LCD 16x2. O objetivo é 
permitir que um usuário insira um código de acesso de 4 dígitos. 
Se o código estiver correto, uma mensagem de Acesso Permitido 
será exibida no LCD; caso contrário, será exibida uma mensagem de 
Acesso Negado.

Requisitos
- Caso não possua senhas cadastradas, permitir acesso sem senha
- Após cadastrar o usuário, permitir acesso somente com senha
- Use a tecla # para confirmar
- Use a tecla  para cancelar
- Utilize as letras para navegar entre as funcionalidades

Funcionalidades
1. Usuário Logado
  - Cadastrar novas senhas
  - Excluir senhas
  - Mostrar senhas cadastradas
  - Logoff
2. Usuário deslogado
  - Login

Funcionalidade Adicional (Opcional)
Implemente um mecanismo de bloqueio temporário após um número definido de tentativas fracassadas.
Permita que o código de acesso seja alterado pelo usuário através de uma interface simples.




#include LiquidCrystal.h

 conexão física nos pinos
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);
const int rows[] = {6, 7, 8, 9};
const int cols[] = {10, 11, 12, 13};

 VARIÁVEIS
bool emptyPassword = true, online = false, admin = false;
String passwords[4] = {, , , };
int totalPasswords = 0, attempts = 0, currentPassword = 0;

 mapear o teclado
const char keys[4][4] = {{'1', '2', '3', 'A'},
                         {'4', '5', '6', 'B'},
                         {'7', '8', '9', 'C'},
                         {'', '0', '#', 'D'}};


void setup()
{
   inicialização do display lcd
  lcd.begin(16,2);
  print(0,0,Bem vindo!);
  delay(2000);
   iniciazação o teclado matricial
  for (int i=0; i4; i++) {
    pinMode(rows[i], INPUT_PULLUP);
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], HIGH);
  }
}


void loop() {

  if(emptyPassword) {  Caso, ao entrar, o usuário não tenha ainda uma senha cadastrada

    print(0,0,A. Cadastrar);

    if(keyboardScan() == 'A')
      registration();

  } else if(online) {  Caso esteja logado
    
    print(0,0,A. Add);
    print(7,0,B. Del);
    print(0,1,C. Show);
    print(8,1,D. Off);

    switch(keyboardScan()) {

      case 'A'
        add();
        break;

      case 'B'
        del();
        break;
      
      case 'C'
        show();
        break;
      
      case 'D'
        logoff();
        break;

      default
        break;

    } 

  } else {  Caso deslogado, fazer login novamente
    print(0,0,A. Login);

    if(keyboardScan() == 'A')
      login();
  }

}


char keyboardScan() {
   retorno da função - padrão retorna nulo
  char ret = 0;

  for (int i=0; i4; i++) {
     colocar o pino de saída (coluna) em nível lógico baixo
    digitalWrite(cols[i], LOW);
     verificar em todas as entradas (linhas)
     se tem algum sinal em nível lógico baixo (botão pressionado)
    for (int j=0; j4; j++) {
       verificar se tem sinal nos pinos de entrada (linhas) em nível lógico baixo
      if (digitalRead(rows[j]) == LOW) {
        ret = keys[j][i];
         escreve a coluna e linha pressionada
         lcd.print(Col  + String(i) +  - Lin  + String(j));
      }
    }
     colocar o pino de saída (coluna) em nível lógico alto
    digitalWrite(cols[i], HIGH);
  }
   retorno da função
  return ret;
}

 FUNÇÕES
 Printa uma mensagem no LCD
void print(int col, int lin, String text) {

  lcd.setCursor(col,lin);
  lcd.print(text);

}

 Registra o usuário
void registration() {

  lcd.clear();

  delay(500);

  print(0,0,Digite a senha);

  Entra na função wait(), aguardando o usuário digitar a senha
    Se não cancelar, cadastra a senha
  String password = wait(false);

  if(password != 0 && sizeof(password) = (sizeof(char)  4)) {
    passwords[totalPasswords] = password;
    lcd.clear();
    print(0,0,Cadastrado!);
    delay(3000);

    emptyPassword = false;
    online = true;
    totalPasswords++;
    lcd.clear();
  }

  if(password == passwords[0])
    admin = true;

}

 Função que irá retornar se o usuário cancelou ou confirmou a senha
   O parâmetro del é caso a função seja chamada quando queira deletar uma senha, pois desativa o if de confirmar com #
String wait(bool del) {

  String password = ;
  int passwordLength = 0;

   Entra em looping caso o usuário digite # - confirma, caso  - cancela
  while(1) {
     chama a função que verifica e retorna se alguma tecla for pressionada
    char key = keyboardScan();
     se retornar 0 = nulo, não tem tecla pressionada

    if(key == '#' && (passwordLength == 4  del)) {
      return password;
    }
    else if(key == '') {
      lcd.clear();
      return 0;
    } else {
       Printa a senha na tela
      if(key  0 && passwordLength  4) {	  
        print(passwordLength,1,String(key));
        password = password + String(key);
        delay(500);  evitar considerar acionamentos sequenciais
        passwordLength++;
      }
    }
  }

}

 A função de adicionar uma nova senha é, literalmente, igual a de registrar a primeira
void add() {
  registration();
}

 Exclui uma senha
void del() {

  String option = ;

  delay(500);

  lcd.clear();
  print(0,0,Qual senha);

   Loop - testa se o que o usuário digitar vai ser 1, 2, 3 ou 4, referentes às senhas
  while(1) {

    option = wait(true);

     Caso entre, e a senha selecionada existir, deleta e move todas as outras senhas uma casa pra trás
    if(option == 1  option == 2  option == 3  option == 4) {
      lcd.clear();

       Só deleta a senha se a senha que for deletada existir ou se não for a única senha existente 
      if(passwords[option.toInt() - 1] !=  && passwords[1] != ){
        passwords[option.toInt() - 1] = ;
        totalPasswords--;

        for(int i = 1; i  4; i++)
          passwords[i - 1] = passwords[i];

        passwords[3] = ;
        
        print(0,0,Removido!);
      } else {
        print(0,0,Não removido!);
      }
      
      delay(3000);
      return;
    }

  }

}

 Exibe as senhas
   Exibe todas se for o admin (primeira senha), senão exibe só a primeira
void show() {

  unsigned long currentTime;

  lcd.clear();

  while(1) {

     Se for o admin, consegue ver as outras senhas
    if(admin) {
      print(0,0,passwords[0]);
      print(0,1,passwords[1]);

      currentTime = millis();

      while(currentTime  millis() - 2000){
        if(keyboardScan() == '')
          return;
      }

      if(passwords[2] != ) {
        print(0,0,passwords[2]);
        print(0,1,passwords[3]);
      }

      while(currentTime  millis() - 2000){
        if(keyboardScan() == '')
          return;
      }
    } else {
      print(0,0,passwords[currentPassword]);
      if(keyboardScan() == '')
        return;
    }

  }

}

 Sai da conta - fica offline (online = false)
void logoff() {
  lcd.clear();
  online = false;
  admin = false;
  return;
}

 Login do usuário depois de dar logoff uma vez
void login() {

  lcd.clear();
   Tenta digitar a senha, se conseguir, fica online (online = true) e da return
  print(0,0,Digite a senha);
  delay(500);
  String password = wait(false);

  for(int i = 0; i  4; i++) {
    if(password == passwords[i]){
      online = true;
      lcd.clear();
      print(0,0,Logado!);
      delay(2000);
      lcd.clear();

      if(password == passwords[0])
        admin = true;

      currentPassword = i;

      return;
    }
  }

  lcd.clear();
  print(0,0,Tente novamente!);
  delay(2000);
  lcd.clear();

  attempts++;

   Se errar 3 vezes, dá um bloqueio de 10s
     É obrigado registrar a senha de novo
  if(attempts = 3){
    lcd.clear();
    print(0,0,Acesso negado!);
    delay(10000);

    registration();
    attempts = 0;
    currentPassword = 1;
    return;
  }

   Por recursividade, chama a função novamente - LOOPING
  login();

}