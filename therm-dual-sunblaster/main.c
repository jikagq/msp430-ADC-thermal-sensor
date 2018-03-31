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
