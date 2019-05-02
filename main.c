#include<library/serial.h>
#include<library/errores.h>
#include<library/matematica.h>
#include<library/stdio.h>
void limpiarVector(char cadena[]);
int verificarEntrada(char cadena[]);
void main(){
	char cadena[34],temporal="";
	int calcular=2,indice=0,i=0,j=0,error=0,operando=1,punto=0,operacion=0,temp=0,operandoPegado=0;
    printf("Ingresa los datos: ");
	while(TRUE){
        if(kbhit()){
            cadena[i]=getch();
            if(cadena[i]>=42 && cadena[i]<=57 || cadena[i]==13){
                if(cadena[i]!=','){
                    printf("%c",cadena[i]);
                }else{
                    i--;
                }
            	if(cadena[i]==13 && cadena[0]!=13){
    				calcular=1;
    			}else if(cadena[0]==13){ //si la posiscion 0 es un enter, marcar error
                    menuError(3);
                    error=1;
                }
                if(cadena[i]=='.'){
                    punto++;
                }
                //if para validacion del punto antes de la operacion
                if(i>0){
                    if(cadena[i]=='+' || cadena[i]=='-' || cadena[i]=='*' || cadena[i]=='/'){
                        operacion=1;
                        temporal=cadena[i];
                    }
                    j=i-1;
                    if(cadena[i]=='+' || cadena[i]=='-' || cadena[i]=='*' || cadena[i]=='/'){
                        operando++;
                        if(cadena[j]=='+' || cadena[j]=='-' || cadena[j]=='*' || cadena[j]=='/'){
                            operando--;
                            temp=1;
                            operandoPegado++;
                        }
                    }
                }
                if(i>1){
                    //validaciones para validar operaciones, no permitir esto: 1+2+3
                    if(cadena[i-1]=='+' && cadena[i]=='*' || cadena[i-1]=='-' && cadena[i]=='*'){
                        menuError(2);
                        error=1;
                    }else if(cadena[i-1]=='+'&&cadena[i]=='/'||cadena[i-1]=='-'&&cadena[i]=='/'){
                        menuError(2);
                        error=1;
                    }else if(cadena[i-1]=='/'&&cadena[i]=='*'||cadena[i-1]=='/'&&cadena[i]=='/'){
                        menuError(2);
                        error=1;
                    }else if(cadena[i-1]=='*' && cadena[i]=='/' || cadena[i-1]=='*' && cadena[i]=='*'){
                        menuError(2);                        
                        error=1;
                    }
                }
                //si temporal contiene algo
                if(temporal){
                    if(cadena[i]=='.'){
                        punto--;
                        punto++;
                    }
                }
                //si haya mas de dos operandos pegados, ejemplo: 1+--
                if(operandoPegado==2){
                    menuError(2);
                    error=1;
                    operandoPegado=0;
                }
                //si hay mas de 2 operandos: 1+2+3
                if(operando>2){
                    menuError(2);
                    error=1;
                    temp=0;
                }
    			i++;
        	}
        }
        //si hay mas de dos puntos antes del simbolo de operacion
        if(punto>1 && operacion==0){
            menuError(2);
            error=1;
        }else if(punto>2 && operacion==1){
            menuError(2);
            error=1;
            operacion=0;
        }
        //si se excede de la cadena
        if(i>34){
            menuError(5);
            error=1;
        }
        //si se encuentra algun error se "limpian" las variables
        if(error==1){
            i=0;
            j=0;
            error=0;
            operando=1;
            punto=0;
            temporal="";
            operacion=0;
            operandoPegado=0;
            temp=0;
            limpiarVector(cadena);
        }
        if(verificarEntrada(cadena)==1){ //si tuvieramos nuestras validaciones en una fucion
            limpiarVector(cadena);
            /*i=0;
            j=0;*/
            error=0;
            operando=1;
            temp=0;
            punto=0;
            temporal="";
            operacion=0;
        }
        // si es posible hacer el calculo
        if(calcular==1){
            obtenerNumero(cadena);//ver en matematica.h
            limpiarVector(cadena);
            //limpiar valores
            calcular=0;
            i=0;
            j=0;
            indice=0;
            error=0;
            operando=1;
            temp=0;
            punto=0;
            operandoPegado=0;
            temporal="";
            operacion=0;
        }
    }
}
//Funcion que limpia todos los valores de la cadena
void limpiarVector(char cadena[]){
    for(int index=0;index<34;index++){
		if(cadena[index]!=NULL){
			cadena[index]=NULL;
		}
	}
}

int verificarEntrada(char cadena[]){
    if(cadena[0]==NULL){
        return 0;
    }else{
        if(cadena[0]=='*' || cadena[0]=='/'){
            menuError(2);
            return 1;
        }else if(cadena[0]=='-' || cadena[0]=='+'){
            if(cadena[1]=='*' || cadena[1]=='/' || cadena[1]=='-' || cadena[1]=='+'){
                menuError(2);
                return 1;
            }
        }
    }
}