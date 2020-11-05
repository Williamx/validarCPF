#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "string.h"
#include "stdlib.h"
#include "locale.h"

using namespace System;
bool ehdigito(char c){
	return (c >='0' && c <= '9');
}
int convertenumerico(char c){
	return c - '0';	
}
void converteentrada(char entrada[], int cpf[]){
	int i = strlen(entrada)-1,j = 10;
	while (i >=0){
		if(ehdigito(entrada[i])){
			cpf[j] = convertenumerico(entrada[i]);
			j--; 
		}
		i--;		
	}
	while (j>=0){
		cpf[j]=0;
		j--;
	}
}
bool verificadigito(int cpf[], int mult[],int n){
	int i ,soma=0;
	for(i=0;i<n;i++)
		soma = soma +cpf[i]*mult[i];
	int resto = ((soma*10)%11)%10;
	return resto == cpf[n];
}
void removeEspacos(char *str) 
{ 
  
    int count = 0; 
  
    for (int i = 0; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i]; 
                                   
    str[count] = '\0'; 
} 
void valida_cpf(int cpf[11],int m1[9],int m2[10],char entrada[11],char entrada2[14],int i){
    converteentrada(entrada,cpf);
	if(verificadigito(cpf,m1,9)&& verificadigito(cpf,m2,10))
	{
		for (i=0; i<1; i++)
               {
	  
               sprintf(entrada2,"%c %c %c %s %c %c %c %s %c %c %c %s %c %c",
               entrada[0],
               entrada[1],
               entrada[2],".",
               entrada[3],
               entrada[4],
               entrada[5],".",
               entrada[6],
               entrada[7],
			   entrada[8],"-",
			   entrada[9],
			   entrada[10]
	                   );
               }
	   removeEspacos(entrada2);
	   printf("%s %s",entrada2,"\n CPF válido\n");
	   system("pause");	
	}
	else
	{
		 printf("CPF inválido\n");	
		 system("pause");
	}

};
int main(array<System::String ^> ^args)

{
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i,j;
	char entrada[13];
	char entrada2[14];

	setlocale(LC_ALL,"portuguese");
	printf("Entre com os 11 dígitos do CPF:\n");
	gets (entrada);
    valida_cpf(cpf,m1,m2,entrada,entrada2,0);

    return 0;
}
