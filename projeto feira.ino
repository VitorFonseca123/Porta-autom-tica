#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 4, 3, 2, 1, 0);
const byte qtdLinhas = 4; //QUANTIDADE DE LINHAS DO TECLADO
const byte qtdColunas = 4; //QUANTIDADE DE COLUNAS DO TECLADO
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte PinosqtdLinhas[qtdLinhas] = {6, 7, 8, 9}; //PINOS UTILIZADOS PELAS LINHAS
byte PinosqtdColunas[qtdColunas] = {10, 11, 12, 13}; //PINOS UTILIZADOS PELAS COLUNAS
Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas);
  int cursor=0;
  char i =0;
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  for(int i=6; i<=13; i++){
  	pinMode(i, INPUT);
  }
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Digite sua senha:");
}
void loop(){ 
char senha[4] = {'1', '2','3','4'};
char ler = meuteclado.waitForKey(); //ler numero pelo keypad 
  if(ler){ //se alguem digitar
    lcd.setCursor(cursor,1); //o cursor do lcd muda pra a posição 0,1
    if(ler!=senha[0]){//se o numero digitado for diferente do
      //primeiro numero da senha
      	lcd.print('*');
      	cursor++;//contador para modificar posição do cursor
      	ler = meuteclado.waitForKey(); // ler numero no keypad
      	if(ler){ //se for lido
      		lcd.setCursor(cursor, 1); //proxima posição do cursor
          	lcd.print('*');
          	cursor++;
          	ler = meuteclado.waitForKey(); // ler numero no keypad
      		if(ler){ //se for lido
      			lcd.setCursor(cursor, 1); //proxima posição do cursor
          		lcd.print('*');
              	cursor++;//contador para modificar posição do cursor
      			ler = meuteclado.waitForKey(); // ler numero no keypad
      			if(ler){ //se for lido
      				lcd.setCursor(cursor, 1); //proxima posição do cursor
          			lcd.print('*');
          			 //como o primeiro
              		//numero esta errado, senha incorreta
                  	ler = meuteclado.waitForKey();
                  	if(ler){
                      if(ler='#'){
                        delay(1000);
          			lcd.clear();
            		lcd.setCursor(0,0);
          			lcd.print("senha incorreta");
                      //servo fechado
                      }	
                  }
                }
        	}
        }
    }else{
  		lcd.print('*');
      	cursor++;
      	ler = meuteclado.waitForKey();
      	if(ler){
          lcd.setCursor(cursor,1);
          if(ler!=senha[1]){
          	lcd.print('*');
            cursor++;//contador para modificar posição do cursor
      		ler = meuteclado.waitForKey(); // ler numero no keypad
      		if(ler){ //se for lido
      			lcd.setCursor(cursor, 1); //proxima posição do cursor
          		lcd.print('*');
              	cursor++;//contador para modificar posição do cursor
      			ler = meuteclado.waitForKey(); // ler numero no keypad
      			if(ler){ //se for lido
      				lcd.setCursor(cursor, 1); //proxima posição do cursor
          			lcd.print('*');
            		ler = meuteclado.waitForKey();
                  	if(ler){
                      if(ler='#'){
                        delay(1000);
          			lcd.clear();
            		lcd.setCursor(0,0);
          			lcd.print("senha incorreta");
                      //servo fechado
                      }	
                  }
                }
            }
          }else{
          	lcd.print('*');
      		cursor++;
            ler = meuteclado.waitForKey();
      		if(ler){
          		lcd.setCursor(cursor,1);
              	if(ler!=senha[2]){
          			lcd.print('*');
					cursor++;//contador para modificar posição do cursor
      				ler = meuteclado.waitForKey(); // ler numero no keypad
      				if(ler){ //se for lido
      					lcd.setCursor(cursor, 1); //proxima posição do cursor
          				lcd.print('*');
                      	cursor++;//contador para modificar posição do cursor
            				
                          	ler = meuteclado.waitForKey();
                  			if(ler){
                      			if(ler='#'){
                                  delay(1000);
          					lcd.clear();
            				lcd.setCursor(0,0);
          					lcd.print("senha incorreta");
                          	ler = meuteclado.waitForKey();
                      				//servo fechado
                      				
                  			}
                        }
                    }
                }else{
                	lcd.print('*');
      				cursor++;
                  	ler = meuteclado.waitForKey();
      				if(ler){
          				lcd.setCursor(cursor,1);
              			if(ler!=senha[2]){
                          	lcd.setCursor(cursor, 1); //proxima posição do cursor
          					lcd.print('*');
                      		cursor++;
                          	ler = meuteclado.waitForKey();
                          	if(ler){
                      			if(ler='#'){
                                  delay(1000);
            				lcd.clear();
          					lcd.print("senha correta");
                      				//servo aberto
                      				
                  				}
                        	}
                        }
                    }
                }
        	}
          }
      	}
    }
  }
	delay(1000);
  	ler=meuteclado.waitForKey();
  	if(ler){
      lcd.clear();
      if(ler='*'){
        lcd.print("Trancar");
    	}
   }
  delay(2000);
  lcd.clear();
  cursor=0;
  lcd.print("Digite sua senha");
}


