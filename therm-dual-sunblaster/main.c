#include <msp430.h> 
#include "ADC.h"

/**
 * main.c
 */

int temp1=20;
int temp2=20;

void delay (unsigned int ms)
{
    volatile unsigned int i, z;
    i=100;
    while (i--) {
        z=ms;
        while(z--);
    }
}


int tempconverion(int tensionadc){//converti la valeur lu de l'adc en temperature reel
    int temp;

    return temp;
}

void initpwms(void){//initialise les pwm des ventilateurs
    P2SEL |=(BIT2|BIT4);
    P2SEL2 &=~(BIT2|BIT4);
    TA1CTL=TASSEL_2 | MC_1;
    TA1CCTL1|= OUTMOD_7;
    TA1CCTL2|= OUTMOD_7;
    TA1CCR0=210;

    TA1CCR1 =100;
    TA1CCR2 =100;


    //tach

    P2DIR  &= ~(BIT0|BIT3);//p2.0 et p2.3 en entrée

    P2IE |= BIT3;//config interruptions p2.3
    P2IES |= BIT3;
    P2IFG &= ~(BIT3);

    P2IE |= BIT0;//config interruptions p2.0
    P2IES |= BIT0;
    P2IFG &= ~(BIT0);

}

int speedfan(int fannumber){
    int speed=0;

    if(fannumber == 1){

    }else{

    }

    return speed;

}

void speedmeasure(void){
    __enable_interrupt();

    __delay_cycles(100);

    __disable_interrupt();
}

void regulation(int temp1, int temp2){//regle les pwm en fonction des temperatures



}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	P1DIR |= (BIT0 | BIT1);// adc
    P2DIR |= (BIT2 | BIT4);// pwm out



	ADC_init();
	initpwms();


	while(1){


	    ADC_Demarrer_conversion(0);
	    temp1=tempconverion(ADC_Lire_resultat());

	    ADC_Demarrer_conversion(1);
	    temp2=tempconverion(ADC_Lire_resultat());




	    regulation(temp1,temp2);


	    delay(1000);
	}
	
	return 0;
}

#pragma vector = PORT2_VECTOR
__interrupt void PORT2_ISR( void){

    if((P2IN & BIT3)==0){
        //
        P2IFG &= ~(BIT3);
    }
    if((P2IN & BIT0)==0){
        //
       P2IFG &= ~(BIT0);
    }

}
