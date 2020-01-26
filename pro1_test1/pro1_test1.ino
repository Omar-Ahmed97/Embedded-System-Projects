#include <EEPROM.h>
#define MAX_NUM_ITEMS 8
#define TRANSMITION_DONE 'K'

#define START_EEPROM 0
#define Digital_panel_Frequency_Command_index START_EEPROM
#define Command_frequency_source_select_index START_EEPROM+3
#define Operation_Command_source_index START_EEPROM+6
#define Acceleration_time_index START_EEPROM+9
#define Deceleration_time_index START_EEPROM+12


#define SegA 2
#define SegB 3
#define SegC 4
#define SegD 5
#define SegE 6
#define SegF 7
#define SegG 8


#define A 10
#define b 11
#define C 12
#define d 13
#define E 14
#define F 15
#define G 16
#define H 17
#define h 18
#define i 19
#define L 20
#define n 21
#define o 22
#define p 23
#define q 24
#define r 25
#define s 26
#define t 27
#define U 28
#define v 29
#define y 30
#define Z 31
#define M 32

#define Dig1 9 // [!][!][x]
#define Dig2 17 // [!][x][!]
#define Dig3 18// [x][!][!]

#define Sw1 14
#define Sw2 15
#define Sw3 16

#define DD_SS 10
#define DD_MOSI 11
#define DD_MISO 12
#define DD_SCK 13

#define RTS 'S'
#define RTR 'R'
#define FULL_CMD_CNT 7

byte tick4_ms;

volatile byte current_digit = 1;  //determine which segments on
volatile byte s1,s2,s3;    // position of character in tables

volatile byte sw1Debounce =0;     //State of switch to prevent debounce
volatile bool sw1UP_Pressed = 0;

volatile byte sw2Debounce =0;     //State of switch to prevent debounce
volatile bool sw2DOWN_Pressed = 0;

volatile byte sw3Debounce =0;     //State of switch to prevent debounce
volatile bool sw3OK_Pressed = 0;

volatile bool SELECTED = LOW;    // this index have been selected

volatile unsigned int NO_List=0;        //index of main list
volatile unsigned int Digital_panel_Frequency_Command  = 0 ;
volatile unsigned int Command_frequency_source_select =0;
volatile unsigned int Operation_Command_source =0;
volatile unsigned int Acceleration_time = 0;
volatile unsigned int Deceleration_time = 0;

volatile unsigned int Output_Cur = 0;
volatile unsigned int Motor_RPM = 0;

volatile unsigned int DClink_Voltage = 0;

volatile char cmd[FULL_CMD_CNT];




void setup() {

  //init_eeprom();

  
  pinMode(Sw1, INPUT);
  pinMode(Sw1, INPUT_PULLUP);
  
  pinMode(Sw2, INPUT);
  pinMode(Sw2, INPUT_PULLUP);

  pinMode(Sw3, INPUT);
  pinMode(Sw3, INPUT_PULLUP);

  pinMode(Dig1, OUTPUT);
  pinMode(Dig2, OUTPUT);
  pinMode(Dig3, OUTPUT);
  Timer0_init();
  Segments_init();
  SPI_SlaveInit();
  init_settings();
 // send_initSettings();
  //Serial.begin(9600);


}

ISR(TIMER0_COMPA_vect){  //timer0 interrupt 1kHz 
  
  tick4_ms++;    //take an event evey 4 milli seconds
  if(digitalRead(Sw1)== LOW){
     
    if(100 == sw1Debounce){
      sw1Debounce = 0;
      sw1UP_Pressed = 1;
    }
    else {
      sw1Debounce++;
      }
    
    }
   else{
     sw1Debounce = 0;
    }
    
if(digitalRead(Sw2)== LOW){
     
    if(100 == sw2Debounce){
      sw2Debounce = 0;
      sw2DOWN_Pressed = 1;
    }
    else {
      sw2Debounce++;
      }
    
    }
   else{
     sw2Debounce = 0;
    }
if(digitalRead(Sw3)== LOW){
     
    if(100 == sw3Debounce){
      sw3Debounce = 0;
      sw3OK_Pressed = 1;
    }
    else {
      sw3Debounce++;
      }
    
    }
   else{
     sw3Debounce = 0;
    }
    
  if( 4 == tick4_ms){

  disp_off();  // turn off the display
  switch (current_digit)
  {
    case 1:
      disp(s1);   // prepare to display digit 1 (most left)
      digitalWrite(Dig1, HIGH);  // turn on digit 1
      break;
 
    case 2:
      disp(s2);   // prepare to display digit 2
      digitalWrite(Dig2, HIGH);     // turn on digit 2
      break;
 
    case 3:
      disp(s3);   // prepare to display digit 3
      digitalWrite(Dig3, HIGH);    // turn on digit 3
      break;
 
  }
 
  current_digit = (current_digit % 3) + 1;
  tick4_ms = 0; //reset Delay 
 
  }
   
    
    
    
}

void loop() {

 

 
  UP(&NO_List,1);    //switch up increment counter
  DOWN(&NO_List,1);   //switch down decrement counter
  OK(&SELECTED,HIGH); // selsction has done
  //cli();
 // while(SPI_WriteCmd(cmd , RTS , 'F' , 123 ,7)!= transmition_DONE );
  //sei();
  if(NO_List > NO_List+1)
    NO_List =MAX_NUM_ITEMS;
  if(NO_List > MAX_NUM_ITEMS)
    NO_List =0;

switch (NO_List)
  {
    case 0 : 
        {   s1=0;
            s2=0;
            s3=0;
            if(SELECTED){
              do{
                
               if(Digital_panel_Frequency_Command < 400)
                UP(&Digital_panel_Frequency_Command,1);
               else UP(&Digital_panel_Frequency_Command,0);
               
               if(Digital_panel_Frequency_Command > 0)
                DOWN(&Digital_panel_Frequency_Command,1);
               else  DOWN(&Digital_panel_Frequency_Command,0);
                OK(&SELECTED,LOW);

               s1=Digital_panel_Frequency_Command%10;
               s2=(Digital_panel_Frequency_Command/10)%10;
               s3=(Digital_panel_Frequency_Command/100)%10;
   
              }while(SELECTED);
                   
            
            do{
             SPI_WriteCmd( RTS , 'F' , Digital_panel_Frequency_Command );
              delay(10);
             }while(SPI_Receive()!=TRANSMITION_DONE);
            saveValue_eeprom(Digital_panel_Frequency_Command , Digital_panel_Frequency_Command_index );
            }
        }
    
        break;
    case 1:
     {      s1=q;
            s2=r;
            s3=F;
            if(SELECTED){
              do{
                
               if(Command_frequency_source_select < 4)
                UP(&Command_frequency_source_select,1);
               else UP(&Command_frequency_source_select,0);
               
               if(Command_frequency_source_select > 0)
                DOWN(&Command_frequency_source_select,1);
               else  DOWN(&Command_frequency_source_select,0);
                OK(&SELECTED,LOW);

               s1=Command_frequency_source_select%10;
               s2=(Command_frequency_source_select/10)%10;
               s3=(Command_frequency_source_select/100)%10;
   
              }while(SELECTED);
              saveValue_eeprom(Command_frequency_source_select , Command_frequency_source_select_index);
            }
        }
        break;
    case 2:
     {      s1=v;
            s2=r;
            s3=d;
            if(SELECTED){
              do{
                
               if(Operation_Command_source < 4)
                UP(&Operation_Command_source,1);
               else UP(&Operation_Command_source,0);
               
               if(Operation_Command_source > 0)
                DOWN(&Operation_Command_source,1);
               else  DOWN(&Operation_Command_source,0);
                OK(&SELECTED,LOW);

               s1=Operation_Command_source%10;
               s2=(Operation_Command_source/10)%10;
               s3=(Operation_Command_source/100)%10;
   
              }while(SELECTED);
              saveValue_eeprom(Operation_Command_source,Operation_Command_source_index);
            }
        }
        break; 
 case 3:
     {      s1=C;
            s2=C;
            s3=A;
            if(SELECTED){
              do{
                
               if(Acceleration_time < 600)
                UP(&Acceleration_time,10);
               else UP(&Acceleration_time,0);
               
               if(Acceleration_time > 0)
                DOWN(&Acceleration_time,10);
               else  DOWN(&Acceleration_time,0);
                OK(&SELECTED,LOW);

               s1=Acceleration_time%10;
               s2=(Acceleration_time/10)%10;
               s3=(Acceleration_time/100)%10;
   
              }while(SELECTED);
            
              do{
             SPI_WriteCmd( RTS , 'A' , Acceleration_time );
              delay(10);
             }while(SPI_Receive()!=TRANSMITION_DONE);
             saveValue_eeprom(Acceleration_time,Acceleration_time_index);
        }
     }
        break;
     
 case 4:
     {      s1=C;
            s2=E;
            s3=d;
            if(SELECTED){
              do{
                
               if(Deceleration_time < 600)
                UP(&Deceleration_time,10);
               else UP(&Deceleration_time,0);
               
               if(Deceleration_time > 0)
                DOWN(&Deceleration_time,10);
               else  DOWN(&Deceleration_time,0);
                OK(&SELECTED,LOW);

               s1=Deceleration_time%10;
               s2=(Deceleration_time/10)%10;
               s3=(Deceleration_time/100)%10;
   
              }while(SELECTED);

            do{
             SPI_WriteCmd( RTS , 'D' , Deceleration_time );
              delay(10);
             }while(SPI_Receive()!=TRANSMITION_DONE);
             saveValue_eeprom(Deceleration_time,Deceleration_time_index);
            }
        }
        break;
 case 5:
     {      s1=r;
            s2=U;
            s3=C;
            if(SELECTED){
              do{
                
               // READ(&OUTPUT_CURR)
               OK(&SELECTED,LOW);

               s1=Output_Cur%10;
               s2=(Output_Cur/10)%10;
               s3=(Output_Cur/100)%10;
   
              }while(SELECTED);

            
            }
        }
        break;    
 case 6:
     {      s1=M;
            s2=p;
            s3=r;
            if(SELECTED){
              do{
               
               OK(&SELECTED,LOW);

               //READ(RPM)
               s1=Motor_RPM%10;
               s2=(Motor_RPM/10)%10;
               s3=(Motor_RPM/100)%10;
   
              }while(SELECTED);
              
            }
        }
        break;    
  case 7:
     {      s1=L;
            s2=C;
            s3=d;
            if(SELECTED){
              do{
                

                OK(&SELECTED,LOW);

                //SHOW(DC_LINK_VOLTAGE)

               s1=DClink_Voltage%10;
               s2=(DClink_Voltage/10)%10;
               s3=(DClink_Voltage/100)%10;
   
              }while(SELECTED);
              
            }
        }
        break;    
 case 8:
     {      s1=n;
            s2=o;
            s3=n;
            if(SELECTED){
              do{
                
              
                OK(&SELECTED,LOW);
                

           //Displays the types of faults, frequency and operating status at the time of the fault

   
              }while(SELECTED);
              
            }
        }
        break;        
            
    
    }

}

void Timer0_init(){
   //Timer0 1ms initialize
  
  cli();//stop interrupts
  
  //set timer0 interrupt at 1kHz
  TCCR0A = 0;// set entire TCCR0A register to 0
  TCCR0B = 0;// same for TCCR0B
  TCNT0  = 0;//initialize counter value to 0
  
  // set compare match register for 1khz increments
  OCR0A = 249;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);

  sei(); //allow interrupts
  
  }
  
  
    

  void Segments_init(){
    //Seven segment
    for (int x = 2; x <= 8; x++) {
    pinMode(x, OUTPUT);
      }
   
    }

void disp(byte number)
{
  switch (number)
  {
    case 0:  // print 0
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break;
 
    case 1:  // print 1
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
 
    case 2:  // print 2
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break;
 
    case 3:  // print 3
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break;
 
    case 4:  // print 4
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
 
    case 5:  // print 5
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
 
    case 6:  // print 6
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
    
    case 7:  // print 7
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
 
    case 8:  // print 8
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
 
    case 9:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
    case A:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
    case b:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 
    case C:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break; 
    case d:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break;
    case E:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 
    case F:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 
    case G:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break; 
    case H:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
    case h:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 
    case i:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
    case L:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break; 
    case n:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break; 
    case o:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break;

      case p:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 

      case q:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 
      case r:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break; 
      case s:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
      case t:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 
      case U:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break; 
      case v:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break; 
      case y:  // print 9
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break; 
      case Z:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break; 
      case M:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break;      
                                                         
  }
}
    void disp_off()
{
   digitalWrite(Dig1, LOW);
   digitalWrite(Dig2, LOW);
   digitalWrite(Dig3, LOW);
}

void UP(volatile unsigned int* count , int val){
  if(sw1UP_Pressed)
  {
    (*count)+=val;
    sw1UP_Pressed = 0;
    }
  }

void DOWN(volatile unsigned int* count , int val){
  if(sw2DOWN_Pressed)
  {
    (*count)-=val;
    sw2DOWN_Pressed = 0;
    }
  }

void OK(volatile bool* SEL , bool st){
  if(sw3OK_Pressed)
  {
    (*SEL)= st;
    sw3OK_Pressed = 0;
    }
  }

void SPI_SlaveInit(void)
{
    pinMode( DD_MOSI , INPUT);
    pinMode( DD_SCK , INPUT);
    pinMode( DD_SS , INPUT);
    /* Set MISO output, all others input */
    pinMode( DD_MISO , OUTPUT);
    /* Enable SPI and interrupt*/
    SPCR = (1<<SPE);
  
}

  void SPI_Write(char data)    /* SPI write data function */
{
  char flush_buffer;
  SPDR = data;      /* Write data to SPI data register */
  while(!(SPSR & (1<<SPIF))); /* Wait till transmission complete */
  flush_buffer = SPDR;    /* Flush received data */
/* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
}
char SPI_Receive()      /* SPI Receive data function */
{
  while(!(SPSR & (1<<SPIF))); /* Wait till reception complete */
  return(SPDR);     /* Return received data */
}
void SPI_WriteStr(char* cmd , int size)    /* SPI write data function */
{
  char index;
  for(index=0; index<size;index++)
      SPI_Write( cmd[index]);
}

void  SPI_WriteCmd( char serv , char type , int val)
{

  cmd[0] ='X';
  cmd[1] =serv;
  cmd[2] =type;
  cmd[3]=((val/100)%10)+'0'; 
  cmd[4]=((val/10)%10)+'0'; 
  cmd[5]=((val)%10)+'0';
  cmd[6]=';';    
  SPI_WriteStr(cmd,FULL_CMD_CNT);

  }

  
void saveValue_eeprom(int val , char index ){
  EEPROM.write(index ,((val/100)%10) );// low index High byte
  EEPROM.write(index+1 ,((val/10)%10) );
  EEPROM.write(index+2 ,((val)%10) );
  }
int readValue_eeprom( char index ){

  int val;
  val = EEPROM.read(index ) * 100 ;// low index High byte
  val += EEPROM.read(index+1) * 10;
  val += EEPROM.read(index+2 );
   return val;
  }
 void init_settings(){

  Digital_panel_Frequency_Command = readValue_eeprom(Digital_panel_Frequency_Command_index);
  Command_frequency_source_select = readValue_eeprom(Command_frequency_source_select_index );
  Operation_Command_source  = readValue_eeprom(Operation_Command_source_index );
  Acceleration_time = readValue_eeprom(Acceleration_time_index);
  Deceleration_time = readValue_eeprom(Deceleration_time_index);
 }
void init_eeprom(){
  for(int iter =0; iter < 1023; iter++){
    EEPROM.write(iter,0);
  }
}

void send_initSettings(){


  do{
        SPI_WriteCmd( RTS , 'F' ,Digital_panel_Frequency_Command);
              delay(10);
       }while(SPI_Receive()!=TRANSMITION_DONE);
  do{
        SPI_WriteCmd(  RTS , 'S' , Command_frequency_source_select);
              delay(10);
       }while(SPI_Receive()!=TRANSMITION_DONE);
  do{
          SPI_WriteCmd( RTS  , 'A' , Acceleration_time);
              delay(10);
       }while(SPI_Receive()!=TRANSMITION_DONE);

  do{
            SPI_WriteCmd( RTS  , 'D' , Deceleration_time);
              delay(10);
       }while(SPI_Receive()!=TRANSMITION_DONE);

  
}
