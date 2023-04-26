// LIBRERIAS
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{


// ++++++++++++++++++++++++++++++++++++++++++++++++  CONFIGURACIONES INICIALES +++++++++++++++++++++++++++++++++++++++++++++++++++++
  // CONFIGURACION DE PUERTOS
  DDRA = 0b00000111; //Configuracion del puerto A
  DDRB = 0b11111111; //Configuracion del puerto B
  DDRD = 0b00001111; //Configuracion del puerto D

  //CONFIGURACION DE VARIABLES
  int baja=0;
  int media=0;
  int alta=0;


//-----------------------------------------------------        LOOP         -------------------------------------------------------------
while (1) {



// +++++++++++++++++++++++++++++++++++++++++     BOTONES       ++++++++++++++++++++++++++++++++++++++++++++++++++++++


    int botonbaja = (PIND & (1 << PD4)) >> PD4;
    int botonmedia = (PIND & (1 << PD5)) >> PD5;
    int botonalta = (PIND & (1 << PD6)) >> PD6;
  
  if (botonbaja == 1) {
  PORTA = 0b00000001; 
  baja = 1;
  }  

  if (botonmedia == 1) {
  PORTA = 0b00000010; 
  media = 1;
  } 

  if (botonalta == 1) {
  PORTA = 0b00000100; 
  alta = 1;
  } 






// +++++++++++++++++++++++++++++++++++++      ESTADOS DE LAVADO       ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//BAJA
if(baja == 1){
  // AGUA
  PORTD = 0b00000001; // luz del agua
  // inicio de conteo
  PORTB = 0x01;
  _delay_ms(100000);
  PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // LAVAR
  PORTD = 0b00000010; // luz del lavar
  // inicio de conteo
  PORTB = 0x03;
  _delay_ms(100000);
  PORTB = 0x02;
  _delay_ms(100000);
  PORTB = 0x01;
  _delay_ms(100000); 
    PORTB = 0x00; 
  _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // ENJUAGAR
  PORTD = 0b00000100; // luz del enjuagar
  // inicio de conteo
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // CENTRIFUGAR
  PORTD = 0b00001000;  // luz del enjuagar
  // inicio de conteo
  PORTB = 0x33;
  _delay_ms(100000);
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;
baja = 0;
PORTA = 0x00;
}//fin if baja



//MEDIA
if(media == 1){
    // AGUA
  PORTD = 0b00000001;
  // inicio de conteo
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo 
  PORTD = 0b00000000;

    // LAVAR
  PORTD = 0b00000010;
  // inicio de conteo
  PORTB = 0x77;
  _delay_ms(100000);
  PORTB = 0x66;
  _delay_ms(100000); 
    PORTB = 0x55; 
   _delay_ms(100000);
  PORTB = 0x44;
  _delay_ms(100000);
  PORTB = 0x33;
  _delay_ms(100000); 
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // ENJUAGAR
  PORTD = 0b00000100;
  // inicio de conteo
  PORTB = 0x44;
  _delay_ms(100000);
  PORTB = 0x33;
  _delay_ms(100000); 
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // CENTRIFUGAR
  PORTD = 0b00001000;
  // inicio de conteo
  PORTB = 0x66;
  _delay_ms(100000); 
    PORTB = 0x55; 
   _delay_ms(100000);
  PORTB = 0x44;
  _delay_ms(100000);
  PORTB = 0x33;
  _delay_ms(100000); 
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;
media = 0;
PORTA = 0x00;
}//fin if media



//ALTA
if(alta == 1){
    // AGUA
  PORTD = 0b00000001;
  // Inicio del conteo
  PORTB = 0x33;
  _delay_ms(100000); 
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // LAVAR
  PORTD = 0b00000010;
  // inicio de conteo
  PORTB = 0x11;
  _delay_ms(100000);
  PORTB = 0x99;
  _delay_ms(100000); 
    PORTB = 0x88; 
   _delay_ms(100000);
  PORTB = 0x77;
  _delay_ms(100000);
  PORTB = 0x66;
  _delay_ms(100000); 
    PORTB = 0x55; 
   _delay_ms(100000);
  PORTB = 0x44;
  _delay_ms(100000);
  PORTB = 0x33;
  _delay_ms(100000); 
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // ENJUAGAR
  PORTD = 0b00000100;
  // inicio de conteo 
    PORTB = 0x55; 
   _delay_ms(100000);
  PORTB = 0x44;
  _delay_ms(100000);
  PORTB = 0x33;
  _delay_ms(100000); 
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;

    // CENTRIFUGAR
  PORTD = 0b00001000;
  // inicio de conteo
  PORTB = 0x99;
  _delay_ms(100000); 
    PORTB = 0x88; 
   _delay_ms(100000);
  PORTB = 0x77;
  _delay_ms(100000);
  PORTB = 0x66;
  _delay_ms(100000); 
    PORTB = 0x55; 
   _delay_ms(100000);
  PORTB = 0x44;
  _delay_ms(100000);
  PORTB = 0x33;
  _delay_ms(100000); 
  PORTB = 0x22;
  _delay_ms(100000);
  PORTB = 0x11;
  _delay_ms(100000); 
    PORTB = 0x00; 
   _delay_ms(100000);
  //fin del conteo
  PORTD = 0b00000000;
alta = 0;
PORTA = 0x00;
}//fin if alta










}// FIN DEL LOOP










// ++++++++++++++++++++++++++++++++++++++++++++++++  FUNCION INTERRUPCIONES +++++++++++++++++++++++++++++++++++++++++++++++++++++
  //TCCR0B=0x05; // Pone un  N = 1064 (creo)
}
