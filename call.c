#include <stdio.h>
#include <math.h>
#include <windows.h>


float suma(float n1,float n2);
float resta(float n1,float n2);
float divi(float n1,float n2);
float mul(float n1,float n2);
float pot(float n1,float n2);
float rc(float n1);

int main()
{
	//Declarando variables
	int opcion;
	float n1, n2, resultado;
	
	do{
	system("pause");
	system("cls"); //Limpiar pantalla
	printf("Elige una opcion:\n");
	printf("\t 1.- Suma\n");
	printf("\t 2.- Resta\n");
	printf("\t 3.- Division\n");
	printf("\t 4.- Multiplicacion\n");
	printf("\t 5.- Potencia\n");
	printf("\t 6.- Raiz cuadrada\n");
	printf("\t 7.- Salir\n");
	scanf("%d",&opcion);	
	system("cls"); //Limpiar pantalla
	
	if(opcion==6){
		printf("\nDame el primer valor: ");
		scanf("%f", &n1);
	}
	else if(opcion>=7){
		
	}
	else{
		printf("\nDame el primer valor: ");
		scanf("%f", &n1);
		printf("\nDame el segundo valor: ");
		scanf("%f", &n2);
	}

	//Estructura de control de selección multiple

	switch(opcion)
	{
	case 1:
		printf("\n%f\n", suma(n1,n2));
		break;
	case 2:
		printf("\n%f\n", resta(n1,n2));
		break;
	case 3: 
	    if(n2==0)
		{
			printf("La operacion entre 0 no esta definida");
		}
		else{
		printf("\n%f\n", divi(n1,n2));
		}
	    
		break;
	case 4: 
		printf("\n%f\n", mul(n1,n2));
		break;
	case 5: 		
		printf("\n%f\n", pot(n1,n2));
		break;
	case 6: 
	    if(n1<0){
				printf("No esta definida");
		}
		else{
		printf("\n%f\n", rc(n1));
		}
		break;
	default:
		printf("Salir");
		exit(0);
	}	//Sale break
  } while(opcion<7);
}
float suma(float n1,float n2){
int resultado =0;
resultado = n1 + n2;
return resultado;
}

float resta(float n1,float n2){
int resultado =0;
resultado = n1 - n2;
return resultado;
}

float divi(float n1,float n2){
int resultado =0;
resultado = n1 / n2;
return resultado;
}

float mul(float n1,float n2){
int resultado =0;
resultado = n1 * n2;
return resultado;
}

float pot(float n1,float n2){
int resultado =0;
resultado = pow(n1,n2);
return resultado;
}

float rc(float n1){
int resultado =0;
resultado = sqrt (n1);
return resultado;
	}
