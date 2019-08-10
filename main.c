/*
 * distilator.c
 *
 * Created: 3/28/2018 7:50:30 AM
 * Author : Mircea.Sarateanu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 100000

unsigned int temperatura1;
unsigned int tempreala;
unsigned int presiune1;
unsigned int nivel1;

unsigned int temperatura2;
unsigned int presiune2;


static unsigned int multiplexing = 0;
static unsigned int baleaj = 0;

#define tmax 110
#define tmin 90
#define pmax 12
#define pmin 8
#define hmax 180
#define hmin 1


#define tcmax  40
#define tcmin  23

static unsigned int staredeavarie = 0;


void afisare_LCD(unsigned int numar1, unsigned int numar2, unsigned int digit)
{
	unsigned int separat[3];
	unsigned int unitati, zeci, sute;
	unsigned int valoare, count, aux;
	valoare = numar1;
	count = 0;
	aux = 0;
	separat[0] = separat[1] = separat[2] = 0;
	while(valoare!=0)
	{
		aux = valoare % 10;
		valoare = valoare / 10;
		separat[count] = aux;
		count ++;
		
	}//END WHILE
	
	sute = separat[2];
	zeci = separat[1];
	unitati = separat[0];//Separa numarul in componente numar1
	
	
	
	
	
	
	
	
	
	
	if(digit == 0){
		PORTB |= (1<<PB0);
		PORTB &= ~((1<<PB2)|(1<<PB1)|(1<<PB3)|(1<<PB4)|(1<<PB5));
		switch(unitati){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
	}//END IF
	if(digit == 1){
		PORTB |=(1<<PB1);
		PORTB &= ~((1<<PB2)|(1<<PB0)|(1<<PB3)|(1<<PB4)|(1<<PB5));
		switch(zeci){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
		
		
	}
	
	if(digit == 2){
		PORTB |=(1<<PB2);
		PORTB &= ~((1<<PB1)|(1<<PB0)|(1<<PB3)|(1<<PB4)|(1<<PB5));
		switch(sute){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
		
		
	}
	
	unsigned int separat1[3];
	unsigned int unitati1, zeci1, sute1;
	unsigned int valoare1, count1, aux1;
	valoare1 = numar2;
	count1 = 0;
	aux1 = 0;
	separat1[0] = separat1[1] = separat1[2] = 0;
	while(valoare1!=0)
	{
		aux1 = valoare1 % 10;
		valoare1 = valoare1 / 10;
		separat1[count1] = aux1;
		count1 ++;
		
	}//END WHILE
	
	sute1 = separat1[2];
	zeci1 = separat1[1];
	unitati1 = separat1[0];//Separa numarul in componente numar1
	
	if(digit == 3){
		PORTB |= (1<<PB3);
		PORTB &= ~((1<<PB2)|(1<<PB1)|(1<<PB0)|(1<<PB4)|(1<<PB5));
		switch(unitati1){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
	}//END IF
	if(digit == 4){
		PORTB |=(1<<PB4);
		PORTB &= ~((1<<PB2)|(1<<PB0)|(1<<PB1)|(1<<PB3)|(1<<PB5));
		switch(zeci1){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
		
		
	}
	
	if(digit == 5){
		PORTB |=(1<<PB5);
		PORTB &= ~((1<<PB1)|(1<<PB0)|(1<<PB2)|(1<<PB3)|(1<<PB4));
		switch(sute1){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
		
		
	}
	
	
	
}//END FUNCTION






void initializare_ADC()
{
	ADMUX = 0;
	ADMUX |= (1<<REFS0);//Vezi pagina 211 din datasheet Atmega16
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//Enable ADC si stabilire factor divizare frecventa core cu 128
	
	
	
}


unsigned int citeste_ADC(int intrare)
{
	unsigned int rezultat;
	ADMUX = 0;
	ADMUX |= (1<<REFS1)|(1<<REFS0);
	
	if(intrare == 0)
		{
			ADMUX |=(1<<REFS0);
			ADCSRA |= (1<<ADSC);
			while((ADCSRA & (1<<ADIF))==0)
			{
				//Asteapta sfarsitul conversiei
				
			}
			
			rezultat = ADCL + (ADCH*256);
		}
	
	
	if(intrare == 1)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX0);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
	}
	
	if(intrare == 2)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX1);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
	}
	
	if(intrare == 3)
	{
		ADMUX |=(1<<REFS0)|(1<<MUX0)|(1<<MUX1);
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF))==0)
		{
			//Asteapta sfarsitul conversiei
			
		}
		
		rezultat = ADCL + (ADCH*256);
	}
	
	return rezultat;
}//Sfarsit citire ADC, intoarce valoare

void afisaj_BARGRAPH(unsigned int bareta){
	if(bareta == 0) {PORTA &=~((1<<PA4)|(1<<PA5)|(1<<PA6));}
	if((bareta>0)&&(bareta<30)){PORTA |=(1<<PA4);PORTA &=~((1<<PA5)|(1<<PA6));}
	if((bareta>=30)&&(bareta<60)){PORTA |=(1<<PA4)|(1<<PA5); PORTA &=~(1<<PA6);}
	if((bareta>=60)&&(bareta<100)){PORTA |=(1<<PA4)|(1<<PA5)|(1<<PA6);}
	
	
	
}

void start_TIMER16(int presc)
{
	TIMSK = (1<<TOIE1);
	TCCR1A = 0;
	TCCR1B = 0;
	if(presc == 1)
	TCCR1B |= (1<<CS10);
	if(presc == 8)
	TCCR1B |= (1<<CS11);
	if(presc == 256)
	TCCR1B |= (1<<CS12);
	if(presc == 1024)
	TCCR1B |= (1<<CS12)|(1<<CS10);
	
	
}

void start_TIMER8(int presc)
{
	TIMSK = (1<<TOIE0);
	TCCR0 = 0;
	
	if(presc == 1)
	TCCR0 |=(1<<CS00);
	if(presc == 8)
	TCCR0 |=(1<<CS01);
	if(presc == 64)
	TCCR0 |= (1<<CS01)|(1<<CS00);
	if(presc == 256)
	TCCR0 |= (1<<CS02);
	if(presc == 1024)
	TCCR0 |=(1<<CS02)|(1<<CS00);
	
	
	
	
}

ISR(TIMER0_OVF_vect){
	// 8 bit timer
	if((PINC&(1<<PC7))==0){
		afisare_LCD((temperatura1/6.82),presiune1/10, baleaj);
		
	}
	else{
	afisare_LCD((tempreala-574)/4,presiune1/10, baleaj);
	}
	baleaj = baleaj + 1;
	
	if(baleaj > 5){baleaj = 0;}
		
		
		if(multiplexing == 0){
			//Citeste temperatura pe reactor
			temperatura1 = citeste_ADC(0);
		}
		
		if(multiplexing == 1){
			//Citeste presiune pe reactor
			presiune1 = citeste_ADC(1);
			
		}
		
		if (multiplexing == 2){
			//Citeste Temperatura pe racitor
			temperatura2 = citeste_ADC(2);
			
		}
		
		if (multiplexing==3){
			//Citeste nivel fluid pe reactor
			tempreala = citeste_ADC(3);
		}
		
		if(multiplexing <=3 ){
			multiplexing = multiplexing + 1;
		}
		else {
			multiplexing = 0;
			
		}
		
		
		afisaj_BARGRAPH(temperatura2/12);
	
}

 ISR(TIMER1_OVF_vect){
	
	
	
		
	
	
}




int main(void)
{
	
	sei();
	unsigned int timp;
	unsigned int intarziere = 0;
	unsigned int setup = 0;
	unsigned int tempmaxreactor = 1000;
	//Initializare porturi digitale //
	//PORTC 1 = OUTPUT ; 0 = INPUT
	DDRC = 0xFF;
	DDRA = 0;
	DDRA |=(1<<PA4)|(1<<PA5)|(1<<PA6);//Pini de iesire pentru BARGRAPH
	DDRB = 0xFF; //Iesire baleiaj display
	DDRD = 0xFF; //Iesire led-uri
	DDRB &= ~(1<<PB7);//Intrare buton EMERGENCY STOP
	DDRC &= ~(1<<PC7);//Intrare comutator temperatura reala / temperatura citita
	initializare_ADC();
	
	//Port PC0,PC1,PC2,PC3,PC4,PC5 - iesiri pentru ledurile bicolor, PC0 - Verde, PC1 - Rosu , => electrovana alimentare fluid
	//PC2 - Verde, PC3 - Rosu => Electrovana alimentare gaze
	//PC4 - Verde, PC5 - Rosu => Electrovana alimentare fluid racire condensator
	
	//DDRC |= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);
	
	//Activare sistem intreruperi
	
	
	
	
	start_TIMER8(8);//Activeaza timer-ul pentru afisare temperatura
	timp = 10;
	
	PORTD = 0;
    /* Replace with your application code */
    while (1) 
    {
		
		if(staredeavarie == 0){
		//Compara temperatura reactor semnalizare LED PD0
		
		if(temperatura1/6.82 >= (tempreala-574)/4){
		
		PORTD |= (1<<PD7);
		PORTD &= ~(1<<PD6);
	}
	else{
		
		PORTD &= ~(1<<PD7);
		PORTD |= (1<<PD6);
	}
	
	if((temperatura1/6.82)>=140){
		
		PORTD |= (1<<PD2);
		PORTD &= ~(1<<PD3);
		
	}
	
	else {
		
		PORTD &= ~(1<<PD2);
		PORTD |= (1<<PD3);
		
		
	}
					
		//Compara presiune reactor	semnalizare LED PD1		
		
		if(presiune1 >= 600){
		PORTD |= (1<<PD0);
		PORTD &= ~(1<<PD1);
	}
	else {
		PORTD &= ~(1<<PD0);
		PORTD |= (1<<PD1);
		
	}
					
					
					
		//Compara temperatura racitor	semnalizare LED PD2		
		if(temperatura2>=600){
			PORTD |= (1<<PD4);
			PORTD &= ~(1<<PD5);
			
						}			
	
	else {
		
		PORTD &= ~(1<<PD4);
		PORTD |= (1<<PD5);
		
					}
					
					if((PINB&(1<<PB7)) == 128){
				staredeavarie = 0;
				
					}
					else{
						
					staredeavarie =1;
					PORTD |= (1<<PD2);
					PORTD &= ~(1<<PD3);//Setare led rosu
					
					PORTD |= (1<<PD0);
					PORTD &= ~(1<<PD1);
					
					PORTD &= ~(1<<PD4);
					PORTD |= (1<<PD5);
						
					}
		}//END IF STARE DE AVARIE
	
	}//END WHILE

}//END MAIN
	

