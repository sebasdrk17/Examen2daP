#include<library/18F4620.h>
#use delay(crystal=16000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
int count=0;
#int_timer0
void timer0()
{
    count++;
    set_timer0(15536);
}
void main(){
    char cadena[100];
    int indice=0;
    printf("Ingresa la palabra:");
    while(TRUE){
        if(kbhit()){
            cadena[indice]=getch();
            if(cadena[indice]>=97 && cadena<=122 || cadena[indice]==13){
                printf("%d",cadena[indice]);
            }
        }
    }
}