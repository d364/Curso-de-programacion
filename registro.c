#include <stdio.h>
#include <stdlib.h>

int main()
{
   struct estudiante 
   {
   	  int numero;
      char nombre[60];
      
   }fca[5];        
   
   FILE *fichero;
   int i, n=0, semestre;
 
   fichero = fopen("estudiantes.txt", "a");
   if (fichero == NULL)
      printf("No se pudo abrir el archivo :(\n");
   else
   {
      for (i=0; i<5; i++) 
      {
      	
      	puts("\t\tBienvenido al registro de alumnos de la FCA");
      	puts("Rellena los campos siguientes para el registro");
         puts("Nombre:");
 	 fgets(fca[i].nombre, 60 , stdin);
         fprintf(fichero, "\n%s", fca[i].nombre);
         puts("Numero de cuenta:");
         scanf("%d", &fca[i].numero);
         getchar();
         fprintf(fichero, "%d", fca[i].numero);
       
      }
   }
   fclose(fichero);
      fichero = fopen("estudiantes.txt", "r");
      if (fichero == NULL)
         printf("No se pudo abrir el archivo.\n"); 
      else
      {  
         do   
         {
            puts("\nEscriba el numero de registro que desea a leer[1-5]:\n" 
                 "(Para salir presione 0).");
            scanf("%d", &n);
            for (i=0; i<n; i++) 
            {     
               if (i == (n-1))
               {
                  printf("Registro:%d\n\tNombre:%s\n\tNumero de cuenta:%d\n", 
                     n,fca[i].nombre,fca[i].numero);   
                  getchar();   
               }
            }
         }
while(n!=0);                                                  
         fclose(fichero);
     }
     return 0;
}
