#include<library/18F4620.h>
#use delay(crystal=16000000)
//declarar el rs232
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
int count=0;
//declaracion del timer 0
#int_timer0
void timer0()
{
    count=1;
    set_timer0(15536);
}
void limpiar(char cadena[]);
int repetir(char cadena[]);
void mostrarMensaje();
void main(){
    setup_oscillator(OSC_16MHZ);
    setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
    set_timer0(15536);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
    char cadena[100];
    int indice=0,i=0,imprimir=0,numero=0;
    char palabra[10];
    printf("Ingresa la palabra:");
    while(TRUE){
        if(kbhit()){
            cadena[i]=getch();
            if(cadena[i]>=97 && cadena<=122 || cadena[i]==13 || cadena[i]==32){
                printf("%c",cadena[i]);
                if(cadena[i]==13){
                    imprimir=1;
                }
            }
            i++;
        }
        if(imprimir==1){
            indice=0;
            while(cadena[indice]!=32){
                palabra[indice]=cadena[indice];
                indice++;
            }
            numero=repetir(cadena);
            if(numero==0){
                printf("Error");
            }else{
                printf("\n\rVeces a repetir: %d\n\r",numero);
                for(int i=0;i<numero;i++){
                    if(count==1){
                        printf("[%d] -> %s\n\r",i,palabra);
                    }
                }
            }
            imprimir=0;
            indice=0;
            i=0;
            mostrarMensaje();
            limpiar(cadena);
        }
    }
}
void limpiar(char cadena[]){
    for(int index=0;index<100;index++){
		cadena[index]="";
	}
}
int repetir(char cadena[]){
    int indice=0,tmp=0;
    char numero[10];
    while(cadena[indice]!=32){
        indice++;
    }
    indice++;
    while(cadena[indice]!=13){
        numero[tmp]=cadena[indice];
        indice++;
        tmp++;
    }
    switch(numero){
        case "cero":
            return 0;
            break;
        case "uno":
            return 1;
            break;
        case "dos":
            return 2;
            break;
        case "tres":
            return 3;
            break;
        case "cuatro":
            return 4;
            break;
        case "cinco":
            return 5;
            break;
        case "seis":
            return 6;
            break;
        case "siete":
            return 7;
            break;
        case "ocho":
            return 8;
            break;
        case "nueve":
            return 9;
            break;
        default:
            return 0;
            break;
    }
}

void mostrarMensaje(){
    printf("Presiona una tecla para continuar...");
    getch();
    printf("\fIngresa la palabra: ");
}