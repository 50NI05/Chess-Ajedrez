#include<stdio.h>
#include<conio.h> 
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// VARIABLE GLOBAL
int **ajedrez;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Validacion para numero
int b = 1;

int validFormat(const char*, void*);
int validFormat(const char* tipo, void* validar)
{
    b = 1;

    if(!scanf(tipo, validar))
    {
    	printf("\nERROR, Por favor ingrese un numero valido\n\n");
        clearBuf();
        return 1;
	}
    
    if(getchar() != '\n')
	{
		printf("\nERROR, Por favor ingrese un numero valido\n\n");
        clearBuf();
        return 1;
	}
		
		
    system("cls");
    return 0;
}

void clearBuf(void);

void clearBuf()
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TABLERO DE AJEDREZ
void tablero(int **, int);
void tablero(int **ajedrez, int a)
{
	int i, j;
	
	// PIEZAS DEL JUGADOR 1
	// PIEZAS DE LA FILA 0 (INDICE 0)
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(i % 2 == 0)
			{
				ajedrez[i][j] = 1;
			}
			
			// TORRES BLANCO
			ajedrez[0][0] = 12;
			ajedrez[0][7] = 12;
			
			// CABALLOS BLANCO
			ajedrez[0][1] = 13;
			ajedrez[0][6] = 13;
			
			// ALFILES BLANCO
			ajedrez[0][2] = 14;
			ajedrez[0][5] = 14;
			
			// REINA BLANCO
			ajedrez[0][3] = 15;
			
			// REI BLANCO
			ajedrez[0][4] = 16;
		}
	}
	
	// PEONES (BLANCA)
	// PIEZAS DE LA FILA 1 (INDICE 1)
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(i % 2 != 0)
			{
				ajedrez[1][j] = 11;
			}
			
			else
			{
				ajedrez[1][j] = 11;
			}
		}
	}
	
	// ESPACIOS VACIOS
	for(i = 2; i < (3 + (8 - 4)); i++)
	{
		for(j = 0; j < 8; j++)
		{
			ajedrez[i][j] = 0;
		}
	}

	// PIEZAS DEL JUGADOR 2
	
	// PEONES (NEGRA)
	// PIEZAS DE LA FILA 7 (INDICE 6)
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(i % 2 != 0)
			{
				ajedrez[3 + (8 - 5)][j] = 22;
			}
			
			else
			{
				ajedrez[3 + (8 - 5)][j] = 22;
			}
		}
	}
	
	// PIEZAS DE LA FILA 8 (INDICE 7)
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(i % 2 != 0)
			{
				ajedrez[3 + (8 - 4)][j] = 2;
			}
			
			// TORRES NEGRO
			ajedrez[7][0] = 21;
			ajedrez[7][7] = 21;
			
			// CABALLOS NEGRO
			ajedrez[7][1] = 23;
			ajedrez[7][6] = 23;
			
			// ALFILES NEGRO
			ajedrez[7][2] = 24;
			ajedrez[7][5] = 24;
			
			// REINA NEGRO
			ajedrez[7][3] = 25;
			
			// REI NEGRO
			ajedrez[7][4] = 26;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MOVIMIENTOS DE LAS PIEZAS Y TURNOS DE LOS JUGADORES
void turnoJugador(int **, int);
void turnoJugador(int **ajedrez, int a)
{
	int turnos = 0, jugador, fichaFila, fichaCol;
	int moverFila, moverCol, aux;
	int i, j, opcion, movimiento;
	int numero[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	char pieza[2][10] = {"Blanca", "Negra"};  
	char ficha[6][10] = {"Peon", "Alfil", "Caballo", "Torre", "Reina", "Rey"};
	char piezaSeleccionado1[6][5] = {"PBL", "ABL", "CBL", "TBL", "MBL", "RBL"};
	char piezaSeleccionado2[6][5] = {"PNR", "ANR", "CNR", "TNR", "MNR", "RNR"};
	// INICIAMOS LA PARTIDA EN FALSE
	bool partida = false;
	
do
{
	movimiento = 0;
	
	// TURNOS DE LOS JUGADORES
	if(turnos % 2 == 0)
	{
		jugador = 1;
		
		printf("\n\nTurno del jugador: %i (%s)\n", jugador, pieza[0]);
	}
	
	else
	{
		jugador = 2;
		
		printf("\n\nTurno del jugador: %i (%s)\n", jugador, pieza[1]);
	}
	
	
	do
	{
		if(turnos % 2 == 0)
		{
			printf("\n1. Peon");
	        printf("\n2. Alfil");
	        printf("\n3. Caballo");
	        printf("\n4. Torre");
	        printf("\n5. Reina");
	        printf("\n6. Rey");
	        printf("\nOpcion: ");
	        if(validFormat("%i", &opcion)) continue;
	    
	        if(opcion > 0)
		    {
			    if(opcion >= 1 && opcion <= 6)
			    {
				    b = opcion < 1;
			    }
			    
			    else
			    {
			    	printf("\nERROR, Por favor ingrese un numero valido\n\n");
				}
			}
		
		    else
		    {
			    printf("\nERROR, Por favor ingrese un numero valido\n\n");
		    }
		}
		
		else
		{
			printf("\n1. Peon");
	        printf("\n2. Alfil");
	        printf("\n3. Caballo");
	        printf("\n4. Torre");
	        printf("\n5. Reina");
	        printf("\n6. Rey");
	        printf("\nOpcion: ");
	        if(validFormat("%i", &opcion)) continue;
	    
	        if(opcion > 0)
		    {
			    if(opcion >= 1 && opcion <= 6)
			    {
				    b = opcion < 1;
			    }
			    
			    else
			    {
			    	printf("\nERROR, Por favor ingrese un numero valido\n\n");
				}
			}
		
		    else
		    {
			    printf("\nERROR, Por favor ingrese un numero valido\n\n");
		    }
		}
		
		    
	}while(b); 
	
	
	switch(opcion)
	{
/////////////////////////////////////////////////////////////////////////    PEONES    /////////////////////////////////////////////////////////////////////////////////////////////		
		
		case 1: 
		{
////////////////////////////////////////////////////////////////////    POSICION INICIAL    ////////////////////////////////////////////////////////////////////////////////////////
			do
			{
			    // PEDIMOS AL USUARIO QUE INGRESE LA FILA Y LA COLUMNA DE LA PIEZA QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[0], jugador, piezaSeleccionado1[0]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[1], jugador, piezaSeleccionado2[0]);
	                }
	                
	            	
	            	// MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
		                	// PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaFila)) continue;
	    
	                if(fichaFila > 0)
	 	            {
			            if(fichaFila >= 1 && fichaFila <= 7)
			            {
				            b = fichaFila < 1;
			            }
			
			            if(fichaFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaFila == 0)
		            {
			            b = fichaFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[0], jugador, piezaSeleccionado1[0]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[1], jugador, piezaSeleccionado2[0]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaCol)) continue;
	    
	                if(fichaCol > 0)
		            {
			            if(fichaCol >= 1 && fichaCol <= 7)
			            {
				            b = fichaCol < 1;
			            }
			
			            else if(fichaCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaCol == 0)
		            {
			            b = fichaCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	            
////////////////////////////////////////////////////////////////////    POSICION FINAL (DESTINO)    /////////////////////////////////////////////////////////////////////////////////      
	            
	            // PEDIMOS AL USUARIO QUE INGRESE LA POSICION QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[0], jugador, piezaSeleccionado1[0]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[1], jugador, piezaSeleccionado2[0]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la posicion que desea mover: ");
	                if(validFormat("%i", &moverFila)) continue;
	    
	                if(moverFila > 0)
		            {
			            if(moverFila >= 1 && moverFila <= 7)
			            {
				            b = moverFila < 1;
			            }
			
			            else if(moverFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(moverFila == 0)
		            {
			            b = moverFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[0], jugador, piezaSeleccionado1[0]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[0], pieza[1], jugador, piezaSeleccionado2[0]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la posicion que desea mover: ");
	                if(validFormat("%i", &moverCol)) continue;
	    
	                if(moverCol > 0)
		            {
			            if(moverCol >= 1 && moverCol <= 7)
			            {
				            b = moverCol < 1;
			            }
			
			            else if(moverCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		 
		            else if(moverCol == 0)
		            {
			            b = moverCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		            
		    
	            }while(b); 
	            
	        
	        
///////////////////////////////////////////////////////////////////////    MOVIMIENTOS (PEONES)	   /////////////////////////////////////////////////////////////////////////////
	        
//////////////////////////////////////////////////////////////////////////    PEONES BLANCO    /////////////////////////////////////////////////////////////////////////////////
			    if(jugador == 1)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES PEON BLANCO
				    if(ajedrez[fichaFila][fichaCol] == 11)  // 11 = PEON BLANCO
				    {
				    	// MOVIMIENTO: 1 PASO
			            i = fichaFila + 1; 
				        for(j = fichaCol; fichaCol == j; j++)
				        {
					        // VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
							// COMER LA PIEZA DE SU MISMO BANDO
					        if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
							   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					        {
					            movimiento = 0;
			    		        break;
							}
							
							if(i == moverFila && j == moverCol)
			    	        {
			    		        movimiento = 1;
			    		        break;
					        }
						}
						
						if(movimiento == 0)
						{
							// MOVIMIENTOS: 2 PASOS
							i = fichaFila + 2; 
				        	for(j = fichaCol; fichaCol == j; j++)
				        	{
					            if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            {
					                movimiento = 0;
			    		            break;
								}
								
								// PARA QUE EL PEON NO SE SALTARA ENCIMA DE OTRA PIEZA
								if(ajedrez[moverFila - 1][moverCol] == 13 || ajedrez[moverFila - 1][moverCol] == 12 || ajedrez[moverFila - 1][moverCol] == 14 || 
								   ajedrez[moverFila - 1][moverCol] == 15 || ajedrez[moverFila - 1][moverCol] == 16 || ajedrez[moverFila - 1][moverCol] == 21 ||
								   ajedrez[moverFila - 1][moverCol] == 22 || ajedrez[moverFila - 1][moverCol] == 23 || ajedrez[moverFila - 1][moverCol] == 24 ||
								   ajedrez[moverFila - 1][moverCol] == 25 || ajedrez[moverFila - 1][moverCol] == 26)
					        	{
					        		movimiento = 0;
			    		        	break;
								}
								
								if(i == moverFila && j == moverCol)
			    	        	{
			    		        	movimiento = 1;
			    		        	break;
					        	}
					        	
					        	
							}
							
							if(movimiento == 0)
							{
								printf("Movimiento no valido\n");
							}
							
							else
				            {
				            	// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
								// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				            	if(ajedrez[moverFila][moverCol] == 26)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
									
					            aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
				            }
						}
				        
				        else
				        {
				        	if(ajedrez[moverFila][moverCol] == 26)
		                    {
		                        partida = true;
		                        ganador(ajedrez, 8, moverFila, moverCol);
		                        break;
							}
							
					        aux = ajedrez[fichaFila][fichaCol];  
		                    ajedrez[fichaFila][fichaCol] = 0;    
		                    ajedrez[moverFila][moverCol] = aux;
				        }
				        
				        
				        // MOSTRAMOS EL TABLERO DESPUES DEL CAMBIO
				        if(movimiento == 1)
	                    {
		                    // MOSTRAMOS EL TABLERO 
	                        for(i = 0; i < 8; i++)
	                        {
		                        printf("\n\n");
		
		                        for(j = 0; j < 8; j++)
		                        {
			                        // PEONES BLANCO
		                	        if(ajedrez[i][j] == 11)
		                	        {
		                		        printf("\t[ PBL ]");
							        }
		                	
		                	        // PEONES NEGRO
		                	        else if(ajedrez[i][j] == 22)
		                	        {
		                		        printf("\t[ PNR ]");
							        }
							
							
							
							        // TORRES BLANCO
							        else if(ajedrez[i][j] == 12)
		                	        {
		                		        printf("\t[ TBL ]");
							        }
							
							        // TORRES NEGRO
							        else if(ajedrez[i][j] == 21)
		                	        {
		                		        printf("\t[ TNR ]");
							        }
							
							
							        // CABALLOS BLANCO
							        else if(ajedrez[i][j] == 13)
		                	        {
		                		        printf("\t[ CBL ]");
							        }
							
							        // CABALLOS NEGRO
							        else if(ajedrez[i][j] == 23)
		                	        {
		                		        printf("\t[ CNR ]");
							        }
							
		                	
		                	        // ALFILES BLANCO
			                        else if(ajedrez[i][j] == 14)
		                	        {
		                		        printf("\t[ ABL ]");
							        }
							
							        // ALFILES NEGRO
							        else if(ajedrez[i][j] == 24)
		                	        {
		                		        printf("\t[ ANR ]");
							        }
							
							
							        // REINA BLANCO
							        else if(ajedrez[i][j] == 15)
		                	        {
		                		        printf("\t[ MBL ]");
							        }
							
							        // REINA NEGRO
							        else if(ajedrez[i][j] == 25)
		                	        {
		                		        printf("\t[ MNR ]");
							        }
							
							
							
							        // REI BLANCO
							        else if(ajedrez[i][j] == 16)
		                	        {
		                		        printf("\t[ RBL ]");
							        }
							
							        // REI NEGRO
							        else if(ajedrez[i][j] == 26)
		                	        {
		                		        printf("\t[ RNR ]");
							        }
							
							
							
							        // ESPACIOS
							        else
							        {
								        printf("\t[  ]");
							        }
		                        }
	                        }
	                    }
			        }
			    
			        else
			        {
			    	    printf("\nNo puedes seleccionar a este pieza, selecciona una pieza valida\n");
				    }
		        }

//////////////////////////////////////////////////////////////////////////    PEONES NEGRO    /////////////////////////////////////////////////////////////////////////////////
		    
		        else if(jugador == 2)
		        {
		        	// VERIFICAMOS SI LA PIEZA ES PEON NEGRO
		    	    if(ajedrez[fichaFila][fichaCol] == 22)  // 22 = PEON NEGRO
				    {
				        // MOVIMIENTO: 1 PASO
			            i = fichaFila - 1; 
				        for(j = fichaCol; fichaCol == j; j++)
				        {
					        // VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
							// COMER LA PIEZA DE SU MISMO BANDO
					        if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
							   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					        {
					            movimiento = 0;
			    		        break;
							}
							
							if(i == moverFila && j == moverCol)
			    	        {
			    		        movimiento = 1;
			    		        break;
					        }
						}
						
						if(movimiento == 0)
						{
							// MOVIMIENTOS: 2 PASOS
							i = fichaFila - 2; 
				        	for(j = fichaCol; fichaCol == j; j++)
				        	{
					            if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            {
					                movimiento = 0;
			    		            break;
								}
								
								// PARA QUE EL PEON NO SE SALTARA ENCIMA DE OTRA PIEZA
								if(ajedrez[moverFila + 1][moverCol] == 13 || ajedrez[moverFila + 1][moverCol] == 12 || ajedrez[moverFila + 1][moverCol] == 14 || 
								   ajedrez[moverFila + 1][moverCol] == 15 || ajedrez[moverFila + 1][moverCol] == 16 || ajedrez[moverFila + 1][moverCol] == 21 ||
								   ajedrez[moverFila + 1][moverCol] == 11 || ajedrez[moverFila + 1][moverCol] == 23 || ajedrez[moverFila + 1][moverCol] == 24 ||
								   ajedrez[moverFila + 1][moverCol] == 25 || ajedrez[moverFila + 1][moverCol] == 26)
					        	{
					        		movimiento = 0;
			    		        	break;
								}
								
				        		if(i == moverFila && j == moverCol)
			    	        	{
			    		        	movimiento = 1;
			    		        	break;
					        	}
							}
							
							if(movimiento == 0)
							{
								printf("Movimiento no valido\n");
							}
							
							else
				            {
				            	// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
								// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				            	if(ajedrez[moverFila][moverCol] == 16)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
					            aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
				            }
						}
				        
				        else
				        {
				        	if(ajedrez[moverFila][moverCol] == 16)
		                    {
		                        partida = true;
		                        ganador(ajedrez, 8, moverFila, moverCol);
		                        break;
							}
								
					        aux = ajedrez[fichaFila][fichaCol];  
		                    ajedrez[fichaFila][fichaCol] = 0;    
		                    ajedrez[moverFila][moverCol] = aux;
				        }
				        
				        // MOSTRAMOS EL TABLERO DESPUES DEL CAMBIO
				        if(movimiento == 1)
	                    {
		                    // MOSTRAMOS EL TABLERO 
	                        for(i = 0; i < 8; i++)
	                        {
		                        printf("\n\n");
		
		                        for(j = 0; j < 8; j++)
		                        {
			                        // PEONES BLANCO
		                	        if(ajedrez[i][j] == 11)
		                	        {
		                		        printf("\t[ PBL ]");
							        }
		                	
		                	        // PEONES NEGRO
		                	        else if(ajedrez[i][j] == 22)
		                	        {
		                		        printf("\t[ PNR ]");
							        }
							
							
							
							        // TORRES BLANCO
							        else if(ajedrez[i][j] == 12)
		                	        {
		                		        printf("\t[ TBL ]");
							        }
							
							        // TORRES NEGRO
							        else if(ajedrez[i][j] == 21)
		                	        {
		                		        printf("\t[ TNR ]");
							        }
							
							
							        // CABALLOS BLANCO
							        else if(ajedrez[i][j] == 13)
		                	        {
		                		        printf("\t[ CBL ]");
							        }
							
							        // CABALLOS NEGRO
							        else if(ajedrez[i][j] == 23)
		                	        {
		                		        printf("\t[ CNR ]");
							        }
							
		                	
		                	        // ALFILES BLANCO
			                        else if(ajedrez[i][j] == 14)
		                	        {
		                		        printf("\t[ ABL ]");
							        }
							
							        // ALFILES NEGRO
							        else if(ajedrez[i][j] == 24)
		                	        {
		                		        printf("\t[ ANR ]");
							        }
							
							
							        // REINA BLANCO
							        else if(ajedrez[i][j] == 15)
		                	        {
		                		        printf("\t[ MBL ]");
							        }
							
							        // REINA NEGRO
							        else if(ajedrez[i][j] == 25)
		                	        {
		                		        printf("\t[ MNR ]");
							        }
							
							
							
							        // REI BLANCO
							        else if(ajedrez[i][j] == 16)
		                	        {
		                		        printf("\t[ RBL ]");
							        }
							
							        // REI NEGRO
							        else if(ajedrez[i][j] == 26)
		                	        {
		                		        printf("\t[ RNR ]");
							        }
							
							
							
							        // ESPACIOS
							        else
							        {
								        printf("\t[  ]");
							        }
		                        }
	                        }
	                    }
			        }
			    
			        else
			        {
			    	    printf("\nNo puedes seleccionar a este pieza, selecciona una pieza valida\n");
				    }
			    }
			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		    
		        else
		        {
		    	    printf("\nNo puedes seleccionar pieza del otro jugador\n");
			    }
		    
		    }while(ajedrez[fichaFila][fichaCol] == 22 || ajedrez[fichaFila][fichaCol] == 11 || ajedrez[fichaFila][fichaCol] == 24 || ajedrez[fichaFila][fichaCol] == 14 || 
			       ajedrez[fichaFila][fichaCol] == 13 || ajedrez[fichaFila][fichaCol] == 23 || ajedrez[fichaFila][fichaCol] == 12 || ajedrez[fichaFila][fichaCol] == 21 ||
				   ajedrez[fichaFila][fichaCol] == 15 || ajedrez[fichaFila][fichaCol] == 25 || ajedrez[fichaFila][fichaCol] == 16 || ajedrez[fichaFila][fichaCol] == 26);
			
			break;
		}
		
		
		
///////////////////////////////////////////////////////////////////////////    ALFILES    //////////////////////////////////////////////////////////////////////////////////////////
		
		case 2: 
		{
///////////////////////////////////////////////////////////////////////    POSICION INICIAL    /////////////////////////////////////////////////////////////////////////////////////
			do
			{
				
				// PEDIMOS AL USUARIO QUE INGRESE LA FILA Y LA COLUMNA DE LA PIEZA QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[0], jugador, piezaSeleccionado1[1]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[1], jugador, piezaSeleccionado2[1]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaFila)) continue;
	    
	                if(fichaFila > 0)
	 	            {
			            if(fichaFila >= 1 && fichaFila <= 7)
			            {
				            b = fichaFila < 1;
			            }
			
			            if(fichaFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaFila == 0)
		            {
			            b = fichaFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[0], jugador, piezaSeleccionado1[1]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[1], jugador, piezaSeleccionado2[1]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaCol)) continue;
	    
	                if(fichaCol > 0)
		            {
			            if(fichaCol >= 1 && fichaCol <= 7)
			            {
				            b = fichaCol < 1;
			            }
			
			            else if(fichaCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaCol == 0)
		            {
			            b = fichaCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	            
////////////////////////////////////////////////////////////////////    POSICION FINAL (DESTINO)    //////////////////////////////////////////////////////////////////////////////////	            
	            
	            // PEDIMOS AL USUARIO QUE INGRESE LA POSICION QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[0], jugador, piezaSeleccionado1[1]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[1], jugador, piezaSeleccionado2[1]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la posicion que desea mover: ");
	                if(validFormat("%i", &moverFila)) continue;
	    
	                if(moverFila > 0)
		            {
			            if(moverFila >= 1 && moverFila <= 7)
			            {
				            b = moverFila < 1;
			            }
			
			            else if(moverFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(moverFila == 0)
		            {
			            b = moverFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[0], jugador, piezaSeleccionado1[1]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[1], pieza[1], jugador, piezaSeleccionado2[1]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la posicion que desea mover: ");
	                if(validFormat("%i", &moverCol)) continue;
	    
	                if(moverCol > 0)
		            {
			            if(moverCol >= 1 && moverCol <= 7)
			            {
				            b = moverCol < 1;
			            }
			
			            else if(moverCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		 
		            else if(moverCol == 0)
		            {
			            b = moverCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		            
		    
	            }while(b); 
	            
///////////////////////////////////////////////////////////////////////    MOVIMIENTOS (ALFILES)    /////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////    ALFILES BLANCO    /////////////////////////////////////////////////////////////////////////////////	            
	            
				if(jugador == 1)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES ALFIL BLANCO
				    if(ajedrez[fichaFila][fichaCol] == 14)  // 14 = ALFIL BLANCO
				    {
				    	// VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[1][1] == 0 || ajedrez[1][3] == 0 || ajedrez[1][4] == 0 || ajedrez[1][6] == 0)
				    	{
					        // MOVIMIENTOS DIAGONAL DERECHA HACIA BAJO
	                        j = fichaCol + 1;
	                        for(i = fichaFila + 1; i < 8; i++)
	                        {
		                        // VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            {
					                movimiento = 0;
			    		            break;
								}
								
		                        if(i == moverFila && j == moverCol)
		                        {
			                        movimiento = 1;
			                        break;
		                        }
		                        
		                        j++;
	                        }
	            
	                        if(movimiento == 0)
	                        {
		                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA BAJO
		                        j = fichaCol - 1;
		                        for(i = fichaFila + 1; i < 8; i++)
		                        {
					                if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
									   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                {
					                    movimiento = 0;
			    		                break;
									}
									
			                        if(i == moverFila && j == moverCol)
			                        {
				                        movimiento = 1;
				                        break;
			                        }
			
			                        j--;
		                        }
		
		                        if(movimiento == 0)
		                        {
			                        // MOVIMIENTOS DIAGONAL DERECHA HACIA ARRIBA 
			                        j = fichaCol + 1;
			                        for(i = fichaFila - 1; i >= 0; i--)
			                        {
					            		if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   		   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            		{
					                		movimiento = 0;
			    		            		break;
										}
										
				                        if(i == moverFila && j == moverCol)
				                        {
					                        movimiento = 1;
				                            break;
				                        }
				
				                        j++;
			                        }
			
			
			                        if(movimiento == 0)
			                        {
				                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA ARRIBA
				                        j = fichaCol - 1;
				                        for(i = fichaFila - 1; i >= 0; i--)
				                        {
					            			if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   			   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            			{
					                			movimiento = 0;
			    		            			break;
											}
											
					                        if(i == moverFila && j == moverCol)
					                        {
						                        movimiento = 1;
				                                break;
					                        }
					
					                        j--;
				                        }
				
				                        if(movimiento == 0)
				                        {
					                        printf("Movimiento no valido\n");
				                        }
				
				                        else
				                        {
				                        	// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
											// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				                        	if(ajedrez[moverFila][moverCol] == 26)
		                        			{
		                            			partida = true;
		                            			ganador(ajedrez, 8, moverFila, moverCol);
		                            			break;
											}
								
					                        aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
				                        }
			                        }
			
			                        else
			                        {
			                        	if(ajedrez[moverFila][moverCol] == 26)
		                        		{
		                            		partida = true;
		                            		ganador(ajedrez, 8, moverFila, moverCol);
		                            		break;
										}
								
				                        aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
			                        }
			
		                        }
		
		                        else
		                        {
		                        	if(ajedrez[moverFila][moverCol] == 26)
		                        	{
		                            	partida = true;
		                            	ganador(ajedrez, 8, moverFila, moverCol);
		                            	break;
									}
								
			                        aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
		                        }
	                        }
	
	                        else
	                        {
	                        	if(ajedrez[moverFila][moverCol] == 26)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
		                        aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
	                        }
	
	                        if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
	                    
	                    }
	                    
	                    else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						}
				    }
	            
	                else
	                {
	            	    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
	            }
	        
//////////////////////////////////////////////////////////////////////////    ALFILES NEGRO    /////////////////////////////////////////////////////////////////////////////////

                else if(jugador == 2)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES ALFIL NEGRO
				    if(ajedrez[fichaFila][fichaCol] == 24)  // 24 = ALFIL NEGRO
				    {
				    	// VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[6][1] == 0 || ajedrez[6][3] == 0 || ajedrez[6][4] == 0 || ajedrez[6][6] == 0)
				    	{
					        // MOVIMIENTOS DIAGONAL DERECHA HACIA BAJO
	                        j = fichaCol + 1;
	                        for(i = fichaFila + 1; i < 8; i++)
	                        {
	                        	// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            {
					                movimiento = 0;
			    		            break;
								}
											
		                        if(i == moverFila && j == moverCol)
		                        {
			                        movimiento = 1;
			                        break;
		                        }
		
		                        j++;
	                        }
	            
	                        if(movimiento == 0)
	                        {
		                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA BAJO
		                        j = fichaCol - 1;
		                        for(i = fichaFila + 1; i < 8; i++)
		                        {
					            	if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   	   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            	{
					                	movimiento = 0;
			    		            	break;
									}
											
			                        if(i == moverFila && j == moverCol)
			                        {
				                        movimiento = 1;
				                        break;
			                        }
			
			                        j--;
		                        }
		
		                        if(movimiento == 0)
		                        {
			                        // MOVIMIENTOS DIAGONAL DERECHA HACIA ARRIBA 
			                        j = fichaCol + 1;
			                        for(i = fichaFila - 1; i >= 0; i--)
			                        {
					            		if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   		   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            		{
					                		movimiento = 0;
			    		            		break;
										}
											
				                        if(i == moverFila && j == moverCol)
				                        {
					                        movimiento = 1;
				                            break;
				                        }
				
				                        j++;
			                        }
			
			
			                        if(movimiento == 0)
			                        {
				                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA ARRIBA
				                        j = fichaCol - 1;
				                        for(i = fichaFila - 1; i >= 0; i--)
				                        {
					            			if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   			   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            			{
					                			movimiento = 0;
			    		            			break;
											}
											
					                        if(i == moverFila && j == moverCol)
					                        {
						                        movimiento = 1;
				                                break;
					                        }
					
					                        j--;
				                        }
				
				                        if(movimiento == 0)
				                        {
					                        printf("Movimiento no valido\n");
				                        }
				
				                        else
				                        {
				                        	// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
											// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				                        	if(ajedrez[moverFila][moverCol] == 16)
		                        			{
		                            			partida = true;
		                            			ganador(ajedrez, 8, moverFila, moverCol);
		                            			break;
											}
								
					                        aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
				                        }
			                        }
			
			                        else
			                        {
			                        	if(ajedrez[moverFila][moverCol] == 16)
		                        		{
		                            		partida = true;
		                            		ganador(ajedrez, 8, moverFila, moverCol);
		                            		break;
										}
								
				                        aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
			                        }
			
		                        }
		
		                        else
		                        {
		                        	if(ajedrez[moverFila][moverCol] == 16)
		                        	{
		                            	partida = true;
		                            	ganador(ajedrez, 8, moverFila, moverCol);
		                            	break;
									}
								
			                        aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
		                        }
	                        }
	
	                        else
	                        {
	                        	if(ajedrez[moverFila][moverCol] == 16)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
		                        aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
	                        }
	
	                        if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
	                    }
	                    
	                    else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						}
				    }
				
				    else
				    {
					    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
	            
	            }
			
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
	        
	            else
	            {
	        	    printf("\n\nNo puede seleccionar este pieza, selecciona una pieza valida\n");
			    }
			
		    }while(ajedrez[fichaFila][fichaCol] == 24 || ajedrez[fichaFila][fichaCol] == 14 || ajedrez[fichaFila][fichaCol] == 11 || ajedrez[fichaFila][fichaCol] == 22 ||
			       ajedrez[fichaFila][fichaCol] == 13 || ajedrez[fichaFila][fichaCol] == 23 || ajedrez[fichaFila][fichaCol] == 12 || ajedrez[fichaFila][fichaCol] == 21 ||
				   ajedrez[fichaFila][fichaCol] == 15 || ajedrez[fichaFila][fichaCol] == 25 || ajedrez[fichaFila][fichaCol] == 16 || ajedrez[fichaFila][fichaCol] == 26);
		
		    break;
	    }
	    
	    
/////////////////////////////////////////////////////////////////////////    CABALLOS    /////////////////////////////////////////////////////////////////////////////////////////////		
		
		case 3: 
		{
//////////////////////////////////////////////////////////////////////    POSICION INICIAL    ////////////////////////////////////////////////////////////////////////////////////////
			do
			{
			    // PEDIMOS AL USUARIO QUE INGRESE LA FILA Y LA COLUMNA DE LA PIEZA QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[0], jugador, piezaSeleccionado1[2]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[1], jugador, piezaSeleccionado2[2]);
	                }
	                
	            	
	            	// MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
		                	// PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaFila)) continue;
	    
	                if(fichaFila > 0)
	 	            {
			            if(fichaFila >= 1 && fichaFila <= 7)
			            {
				            b = fichaFila < 1;
			            }
			
			            if(fichaFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaFila == 0)
		            {
			            b = fichaFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[0], jugador, piezaSeleccionado1[2]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[1], jugador, piezaSeleccionado2[2]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaCol)) continue;
	    
	                if(fichaCol > 0)
		            {
			            if(fichaCol >= 1 && fichaCol <= 7)
			            {
				            b = fichaCol < 1;
			            }
			
			            else if(fichaCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaCol == 0)
		            {
			            b = fichaCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	            
////////////////////////////////////////////////////////////////////    POSICION FINAL (DESTINO)    /////////////////////////////////////////////////////////////////////////////////      
	            
	            // PEDIMOS AL USUARIO QUE INGRESE LA POSICION QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[0], jugador, piezaSeleccionado1[2]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[1], jugador, piezaSeleccionado2[2]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la posicion que desea mover: ");
	                if(validFormat("%i", &moverFila)) continue;
	    
	                if(moverFila > 0)
		            {
			            if(moverFila >= 1 && moverFila <= 7)
			            {
				            b = moverFila < 1;
			            }
			
			            else if(moverFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(moverFila == 0)
		            {
			            b = moverFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[0], jugador, piezaSeleccionado1[2]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\tPieza seleccionado: %s\n\n", ficha[2], pieza[1], jugador, piezaSeleccionado2[2]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la posicion que desea mover: ");
	                if(validFormat("%i", &moverCol)) continue;
	    
	                if(moverCol > 0)
		            {
			            if(moverCol >= 1 && moverCol <= 7)
			            {
				            b = moverCol < 1;
			            }
			
			            else if(moverCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		 
		            else if(moverCol == 0)
		            {
			            b = moverCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		            
		    
	            }while(b); 
	            
	        
	        
///////////////////////////////////////////////////////////////////////    MOVIMIENTOS (CABALLOS)	   /////////////////////////////////////////////////////////////////////////////
	        
//////////////////////////////////////////////////////////////////////////    CABALLOS BLANCO    /////////////////////////////////////////////////////////////////////////////////
			    if(jugador == 1)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES CABALLO BLANCO
				    if(ajedrez[fichaFila][fichaCol] == 13)  // 13 = CABALLO BLANCO
				    {
				    	// MOVIMIENTOS HACIA ABAJO DERECHA
			            j = fichaCol;
			            for(i = fichaFila + 1; i < 48; i++)
			            {
					        // VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
							// COMER LA PIEZA DE SU MISMO BANDO
					        if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
							   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					        {
					            movimiento = 0;
			    		        break;
							}
							
			    	        if(i == moverFila && j == moverCol)
			    	        {
			    		        movimiento = 1;
			    		        break;
					        }
					        
					        j++;
				        }
				        
				        
				        if(movimiento == 0)
				        {
				        	// MOVIMIENTOS HACIA ARRIBA IZQUIERDA
				        	j = fichaCol;
			                for(i = fichaFila - 1; i >= 0; i--)
			                {
					            if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            {
					                movimiento = 0;
			    		            break;
								}
								
			    	            if(i == moverFila && j == moverCol)
			    	            {
			    		            movimiento = 1;
			    		            break;
					            }
					        
					            j--;
				            }
				            
				            if(movimiento == 0)
				            {
				            	// MOVIMINETOS HACIA ARRIBA DERECHA
				            	j = fichaCol;
				            	for(i = fichaFila - 1; i >= 0; i--)
				            	{
					                if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
									   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                {
					                    movimiento = 0;
			    		                break;
									}
									
				            		if(i == moverFila && j == moverCol)
			    	                {
			    		                movimiento = 1;
			    		                break;
					                }
					                
					                j++;
								}
								
								if(movimiento == 0)
								{
									// MOVIMIENTOS HACIA ABAJO IZQUIERDA
									j = fichaCol;
									for(i = fichaFila + 1; i < 48; i++)
									{
					                    if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
										   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
										
										if(i == moverFila && j == moverCol)
			    	                    {
			    		                    movimiento = 1;
			    		                    break;
					                    }
					                
					                    j--;
									}
									
									if(movimiento == 0)
									{
										// MOVIMIENTOS HACIA DERECHA ABAJO
										i = fichaFila;
										for(j = fichaCol + 1; j < 8; j++)
										{
					                        if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        {
					                            movimiento = 0;
			    		                        break;
											}
											
											if(i == moverFila && j == moverCol)
			    	                        {
			    		                        movimiento = 1;
			    		                        break;
					                        }
					                        
					                        i++;
										}
										
										if(movimiento == 0)
										{
											// MOVIMIENTOS HACIA DERECHA ARRIBA
											i = fichaFila;
											for(j = fichaCol + 1; j < 8; j++)
											{
					                            if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
												   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                            {
					                                movimiento = 0;
			    		                            break;
												}
												
												if(i == moverFila && j == moverCol)
			    	                            {
			    		                            movimiento = 1;
			    		                            break;
					                            }
					                            
					                            i--;
											}
											
											if(movimiento == 0)
											{
												// MOVIMIENTOS HACIA IZQUIERDA ARRIBA
												i = fichaFila;
												for(j = fichaCol - 1; j >= 0; j--)
												{
					                                if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
													   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                                {
					                                    movimiento = 0;
			    		                                break;
													}
													
													if(i == moverFila && j == moverCol)
			    	                                {
			    		                                movimiento = 1;
			    		                                break;
					                                }
					                                
					                                i--;
												}
												
												if(movimiento == 0)
												{
													// MOVIMIENTOS HACIA IZQUIERDA ABAJO
													i = fichaFila;
													for(j = fichaCol - 1; j >= 0; j--)
													{
					                                    if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
														   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                                    {
					                                    	movimiento = 0;
			    		                                    break;
														}
														
														if(i == moverFila && j == moverCol)
			    	                                    {
			    		                                    movimiento = 1;
			    		                                    break;
					                                    }
					                                
					                                    i++;
													}
													
													if(movimiento == 0)
													{
														printf("\nMovimiento no valido\n");
													}
													
													else
													{
														// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
														// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
														if(ajedrez[moverFila][moverCol] == 26)
		                        						{
		                            						partida = true;
		                            						ganador(ajedrez, 8, moverFila, moverCol);
		                            						break;
														}
														
														
														aux = ajedrez[fichaFila][fichaCol];  
		                                                ajedrez[fichaFila][fichaCol] = 0;    
		                                                ajedrez[moverFila][moverCol] = aux;
														
													}
												}
												
												else
												{
													if(ajedrez[moverFila][moverCol] == 26)
		                        					{
		                            					partida = true;
		                            					ganador(ajedrez, 8, moverFila, moverCol);
		                            					break;
													}
								
													aux = ajedrez[fichaFila][fichaCol];  
		                                            ajedrez[fichaFila][fichaCol] = 0;    
		                                            ajedrez[moverFila][moverCol] = aux;
												}
											}
											
											else
											{
												if(ajedrez[moverFila][moverCol] == 26)
		                        				{
		                            				partida = true;
		                            				ganador(ajedrez, 8, moverFila, moverCol);
		                            				break;
												}
								
												aux = ajedrez[fichaFila][fichaCol];  
		                                        ajedrez[fichaFila][fichaCol] = 0;    
		                                        ajedrez[moverFila][moverCol] = aux;
											}
										}
										
										else
										{
											if(ajedrez[moverFila][moverCol] == 26)
		                        			{
		                            			partida = true;
		                            			ganador(ajedrez, 8, moverFila, moverCol);
		                            			break;
											}
								
											aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
										}
									}
									
									else
									{
										if(ajedrez[moverFila][moverCol] == 26)
		                        		{
		                            		partida = true;
		                            		ganador(ajedrez, 8, moverFila, moverCol);
		                            		break;
										}
								
										aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
									}
								}
								
								else
								{
									if(ajedrez[moverFila][moverCol] == 26)
		                        	{
		                            	partida = true;
		                            	ganador(ajedrez, 8, moverFila, moverCol);
		                            	break;
									}
								
									aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
								}
							}
				            
				            else
				            {
				            	if(ajedrez[moverFila][moverCol] == 26)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
					            aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
				            }
				            
				            
						}
				
				        else
				        {
				        	if(ajedrez[moverFila][moverCol] == 26)
		                    {
		                        partida = true;
		                        ganador(ajedrez, 8, moverFila, moverCol);
		                        break;
							}
								
					        aux = ajedrez[fichaFila][fichaCol];  
		                    ajedrez[fichaFila][fichaCol] = 0;    
		                    ajedrez[moverFila][moverCol] = aux;
				        }
				        
				        // MOSTRAMOS EL TABLERO DESPUES DEL CAMBIO
				        if(movimiento == 1)
	                    {
		                    // MOSTRAMOS EL TABLERO 
	                        for(i = 0; i < 8; i++)
	                        {
		                        printf("\n\n");
		
		                        for(j = 0; j < 8; j++)
		                        {
			                        // PEONES BLANCO
		                	        if(ajedrez[i][j] == 11)
		                	        {
		                		        printf("\t[ PBL ]");
							        }
		                	
		                	        // PEONES NEGRO
		                	        else if(ajedrez[i][j] == 22)
		                	        {
		                		        printf("\t[ PNR ]");
							        }
							
							
							
							        // TORRES BLANCO
							        else if(ajedrez[i][j] == 12)
		                	        {
		                		        printf("\t[ TBL ]");
							        }
							
							        // TORRES NEGRO
							        else if(ajedrez[i][j] == 21)
		                	        {
		                		        printf("\t[ TNR ]");
							        }
							
							
							        // CABALLOS BLANCO
							        else if(ajedrez[i][j] == 13)
		                	        {
		                		        printf("\t[ CBL ]");
							        }
							
							        // CABALLOS NEGRO
							        else if(ajedrez[i][j] == 23)
		                	        {
		                		        printf("\t[ CNR ]");
							        }
							
		                	
		                	        // ALFILES BLANCO
			                        else if(ajedrez[i][j] == 14)
		                	        {
		                		        printf("\t[ ABL ]");
							        }
							
							        // ALFILES NEGRO
							        else if(ajedrez[i][j] == 24)
		                	        {
		                		        printf("\t[ ANR ]");
							        }
							
							
							        // REINA BLANCO
							        else if(ajedrez[i][j] == 15)
		                	        {
		                		        printf("\t[ MBL ]");
							        }
							
							        // REINA NEGRO
							        else if(ajedrez[i][j] == 25)
		                	        {
		                		        printf("\t[ MNR ]");
							        }
							
							
							
							        // REI BLANCO
							        else if(ajedrez[i][j] == 16)
		                	        {
		                		        printf("\t[ RBL ]");
							        }
							
							        // REI NEGRO
							        else if(ajedrez[i][j] == 26)
		                	        {
		                		        printf("\t[ RNR ]");
							        }
							
							
							
							        // ESPACIOS
							        else
							        {
								        printf("\t[  ]");
							        }
		                        }
	                        }
	                    }
			        }
			    
			        else
			        {
			    	    printf("\nNo puedes seleccionar a este pieza, selecciona una pieza valida\n");
				    }
		        }

//////////////////////////////////////////////////////////////////////////    CABALLOS NEGRO    /////////////////////////////////////////////////////////////////////////////////
		    
		        else if(jugador == 2)
		        {
		        	// VERIFICAMOS SI LA PIEZA ES CABALLO NEGRO
		    	    if(ajedrez[fichaFila][fichaCol] == 23)  // 23 = CABALLO NEGRO
				    {
				        // MOVIMIENTOS HACIA BAJO DRECHA
			            j = fichaCol;
			            for(i = fichaFila + 1; i < 48; i++)
			            {
			            	// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
							// COMER LA PIEZA DE SU MISMO BANDO
					        if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
							   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					        {
					            movimiento = 0;
			    		        break;
							}
														
			    	        if(i == moverFila && j == moverCol)
			    	        {
			    		        movimiento = 1;
			    		        break;
					        }
					        
					        j++;
				        }
				        
				        
				        if(movimiento == 0)
				        {
				        	// MOVIMIENTOS HACIA ARRIBA IZQUIERDA
				        	j = fichaCol;
			                for(i = fichaFila - 1; i >= 0; i--)
			                {
					            if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            {
					                movimiento = 0;
			    		            break;
								}
														
			    	            if(i == moverFila && j == moverCol)
			    	            {
			    		            movimiento = 1;
			    		            break;
					            }
					        
					            j--;
				            }
				            
				            if(movimiento == 0)
				            {
				            	// MOVIMINETOS HACIA ARRIBA DERECHA
				            	j = fichaCol;
				            	for(i = fichaFila - 1; i >= 0; i--)
				            	{
					                if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
									   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                {
					                    movimiento = 0;
			    		                break;
									}
									
				            		if(i == moverFila && j == moverCol)
			    	                {
			    		                movimiento = 1;
			    		                break;
					                }
					                
					                j++;
								}
								
								if(movimiento == 0)
								{
									// MOVIMIENTOS HACIA BAJO IZQUIERDA
									j = fichaCol;
									for(i = fichaFila + 1; i < 48; i++)
									{
					                    if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
										   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
														
										if(i == moverFila && j == moverCol)
			    	                    {
			    		                    movimiento = 1;
			    		                    break;
					                    }
					                
					                    j--;
									}
									
									if(movimiento == 0)
									{
										// MOVIMIENTOS HACIA DERECHA BAJO
										i = fichaFila;
										for(j = fichaCol + 1; j < 8; j++)
										{
					                        if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        {
					                            movimiento = 0;
			    		                        break;
											}
														
											if(i == moverFila && j == moverCol)
			    	                        {
			    		                        movimiento = 1;
			    		                        break;
					                        }
					                        
					                        i++;
										}
										
										if(movimiento == 0)
										{
											// MOVIMIENTOS HACIA DERECHA ARRIBA
											i = fichaFila;
											for(j = fichaCol + 1; j < 8; j++)
											{
					                            if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
												   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                            {
					                                movimiento = 0;
			    		                            break;
												}
														
												if(i == moverFila && j == moverCol)
			    	                            {
			    		                            movimiento = 1;
			    		                            break;
					                            }
					                            
					                            i--;
											}
											
											if(movimiento == 0)
											{
												// MOVIMIENTOS HACIA IZQUIERDA ARRIBA
												i = fichaFila;
												for(j = fichaCol - 1; j >= 0; j--)
												{
					                                if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
													   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                                {
					                                    movimiento = 0;
			    		                                break;
													}
														
													if(i == moverFila && j == moverCol)
			    	                                {
			    		                                movimiento = 1;
			    		                                break;
					                                }
					                                
					                                i--;
												}
												
												if(movimiento == 0)
												{
													// MOVIMIENTOS HACIA IZQUIERDA BAJO
													i = fichaFila;
													for(j = fichaCol - 1; j >= 0; j--)
													{
					                                    if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
														   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                                    {
					                                    	movimiento = 0;
			    		                                    break;
														}
														
														if(i == moverFila && j == moverCol)
			    	                                    {
			    		                                    movimiento = 1;
			    		                                    break;
					                                    }
					                                
					                                    i++;
													}
													
													if(movimiento == 0)
													{
														printf("\nMovimiento no valido\n");
													}
													
													else
													{
														// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
														// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
														if(ajedrez[moverFila][moverCol] == 16)
		                        						{
		                            						partida = true;
		                            						ganador(ajedrez, 8, moverFila, moverCol);
		                           							break;
														}
								
														aux = ajedrez[fichaFila][fichaCol];  
		                                                ajedrez[fichaFila][fichaCol] = 0;    
		                                                ajedrez[moverFila][moverCol] = aux;
													}
												}
												
												else
												{
													if(ajedrez[moverFila][moverCol] == 16)
		                        					{
		                            					partida = true;
		                            					ganador(ajedrez, 8, moverFila, moverCol);
		                            					break;
													}
								
													aux = ajedrez[fichaFila][fichaCol];  
		                                            ajedrez[fichaFila][fichaCol] = 0;    
		                                            ajedrez[moverFila][moverCol] = aux;
												}
											}
											
											else
											{
												if(ajedrez[moverFila][moverCol] == 16)
		                        				{
		                            				partida = true;
		                            				ganador(ajedrez, 8, moverFila, moverCol);
		                            				break;
												}
								
												aux = ajedrez[fichaFila][fichaCol];  
		                                        ajedrez[fichaFila][fichaCol] = 0;    
		                                        ajedrez[moverFila][moverCol] = aux;
											}
										}
										
										else
										{
											if(ajedrez[moverFila][moverCol] == 16)
		                        			{
		                            			partida = true;
		                            			ganador(ajedrez, 8, moverFila, moverCol);
		                            			break;
											}
								
											aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
										}
									}
									
									else
									{
										if(ajedrez[moverFila][moverCol] == 16)
		                        		{
		                            		partida = true;
		                            		ganador(ajedrez, 8, moverFila, moverCol);
		                            		break;
										}
								
										aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
									}
								}
								
								else
								{
									if(ajedrez[moverFila][moverCol] == 16)
		                        	{
		                            	partida = true;
		                            	ganador(ajedrez, 8, moverFila, moverCol);
		                            	break;
									}
								
									aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
								}
							}
				            
				            else
				            {
				            	if(ajedrez[moverFila][moverCol] == 16)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
					            aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
				            }
				            
				            
						}
				
				        else
				        {
				        	if(ajedrez[moverFila][moverCol] == 16)
		                    {
		                        partida = true;
		                        ganador(ajedrez, 8, moverFila, moverCol);
		                        break;
							}
							
					        aux = ajedrez[fichaFila][fichaCol];  
		                    ajedrez[fichaFila][fichaCol] = 0;    
		                    ajedrez[moverFila][moverCol] = aux;
				        }
				        
				        // MOSTRAMOS EL TABLERO DESPUES DEL CAMBIO
				        if(movimiento == 1)
	                    {
		                    // MOSTRAMOS EL TABLERO 
	                        for(i = 0; i < 8; i++)
	                        {
		                        printf("\n\n");
		
		                        for(j = 0; j < 8; j++)
		                        {
			                        // PEONES BLANCO
		                	        if(ajedrez[i][j] == 11)
		                	        {
		                		        printf("\t[ PBL ]");
							        }
		                	
		                	        // PEONES NEGRO
		                	        else if(ajedrez[i][j] == 22)
		                	        {
		                		        printf("\t[ PNR ]");
							        }
							
							
							
							        // TORRES BLANCO
							        else if(ajedrez[i][j] == 12)
		                	        {
		                		        printf("\t[ TBL ]");
							        }
							
							        // TORRES NEGRO
							        else if(ajedrez[i][j] == 21)
		                	        {
		                		        printf("\t[ TNR ]");
							        }
							
							
							        // CABALLOS BLANCO
							        else if(ajedrez[i][j] == 13)
		                	        {
		                		        printf("\t[ CBL ]");
							        }
							
							        // CABALLOS NEGRO
							        else if(ajedrez[i][j] == 23)
		                	        {
		                		        printf("\t[ CNR ]");
							        }
							
		                	
		                	        // ALFILES BLANCO
			                        else if(ajedrez[i][j] == 14)
		                	        {
		                		        printf("\t[ ABL ]");
							        }
							
							        // ALFILES NEGRO
							        else if(ajedrez[i][j] == 24)
		                	        {
		                		        printf("\t[ ANR ]");
							        }
							
							
							        // REINA BLANCO
							        else if(ajedrez[i][j] == 15)
		                	        {
		                		        printf("\t[ MBL ]");
							        }
							
							        // REINA NEGRO
							        else if(ajedrez[i][j] == 25)
		                	        {
		                		        printf("\t[ MNR ]");
							        }
							
							
							
							        // REI BLANCO
							        else if(ajedrez[i][j] == 16)
		                	        {
		                		        printf("\t[ RBL ]");
							        }
							
							        // REI NEGRO
							        else if(ajedrez[i][j] == 26)
		                	        {
		                		        printf("\t[ RNR ]");
							        }
							
							
							
							        // ESPACIOS
							        else
							        {
								        printf("\t[  ]");
							        }
		                        }
	                        }
	                    }
			        }
			    
			        else
			        {
			    	    printf("\nNo puedes seleccionar a este pieza, selecciona una pieza valida\n");
				    }
			    }
			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		    
		        else
		        {
		    	    printf("\nNo puedes seleccionar pieza del otro jugador\n");
			    }
		    
		    }while(ajedrez[fichaFila][fichaCol] == 22 || ajedrez[fichaFila][fichaCol] == 11 || ajedrez[fichaFila][fichaCol] == 24 || ajedrez[fichaFila][fichaCol] == 14 || 
			       ajedrez[fichaFila][fichaCol] == 13 || ajedrez[fichaFila][fichaCol] == 23 || ajedrez[fichaFila][fichaCol] == 12 || ajedrez[fichaFila][fichaCol] == 21 ||
				   ajedrez[fichaFila][fichaCol] == 15 || ajedrez[fichaFila][fichaCol] == 25 || ajedrez[fichaFila][fichaCol] == 16 || ajedrez[fichaFila][fichaCol] == 26);
			
			break;
		}
		
		
		
///////////////////////////////////////////////////////////////////////////    TORRES    ///////////////////////////////////////////////////////////////////////////////////////////		
		
		case 4: 
		{
//////////////////////////////////////////////////////////////////////    POSICION INICIAL    ///////////////////////////////////////////////////////////////////////////////////////
            do
			{
			    // PEDIMOS AL USUARIO QUE INGRESE LA FILA Y LA COLUMNA DE LA PIEZA QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[0], jugador, piezaSeleccionado1[3]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[1], jugador, piezaSeleccionado2[3]);
	                }
	                
	            	
	            	// MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
		                	// PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaFila)) continue;
	    
	                if(fichaFila > 0)
	 	            {
			            if(fichaFila >= 1 && fichaFila <= 7)
			            {
				            b = fichaFila < 1;
			            }
			
			            if(fichaFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaFila == 0)
		            {
			            b = fichaFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[0], jugador, piezaSeleccionado1[3]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[1], jugador, piezaSeleccionado2[3]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaCol)) continue;
	    
	                if(fichaCol > 0)
		            {
			            if(fichaCol >= 1 && fichaCol <= 7)
			            {
				            b = fichaCol < 1;
			            }
			
			            else if(fichaCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaCol == 0)
		            {
			            b = fichaCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	            
////////////////////////////////////////////////////////////////////    POSICION FINAL (DESTINO)    /////////////////////////////////////////////////////////////////////////////////      
	            
	            // PEDIMOS AL USUARIO QUE INGRESE LA POSICION QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[0], jugador, piezaSeleccionado1[3]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[1], jugador, piezaSeleccionado2[3]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la posicion que desea mover: ");
	                if(validFormat("%i", &moverFila)) continue;
	    
	                if(moverFila > 0)
		            {
			            if(moverFila >= 1 && moverFila <= 7)
			            {
				            b = moverFila < 1;
			            }
			
			            else if(moverFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(moverFila == 0)
		            {
			            b = moverFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[0], jugador, piezaSeleccionado1[3]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[3], pieza[1], jugador, piezaSeleccionado2[3]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la posicion que desea mover: ");
	                if(validFormat("%i", &moverCol)) continue;
	    
	                if(moverCol > 0)
		            {
			            if(moverCol >= 1 && moverCol <= 7)
			            {
				            b = moverCol < 1;
			            }
			
			            else if(moverCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		 
		            else if(moverCol == 0)
		            {
			            b = moverCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		            
		    
	            }while(b); 
            
///////////////////////////////////////////////////////////////////////    MOVIMIENTOS (TORRES)	   /////////////////////////////////////////////////////////////////////////////
	        
//////////////////////////////////////////////////////////////////////////    TORRES BLANCO    /////////////////////////////////////////////////////////////////////////////////
			    if(jugador == 1)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES TORRES BLANCO
				    if(ajedrez[fichaFila][fichaCol] == 12)  // 12 = TORRES BLANCO
				    {
				    	// VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[1][0] == 0 || ajedrez[1][7] == 0)
				    	{
				    		// MOVIMIENTOS HACIA ALANTE
			            	j = fichaCol;
			            	for(i = fichaFila + 1; i < 48; i++)
			            	{
			            		// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            {
					                movimiento = 0;
			    		            break;
								}
														
			    	        	if(i == moverFila && j == moverCol)
			    	        	{
			    		        	movimiento = 1;
			    		        	break;
					        	}
				        	}
				        
				        	if(movimiento == 0)
				        	{
				        		// MOVIMIENTOS HACIA DERECHA
				        		i = fichaFila;
			                	for(j = fichaCol + 1; j < 8; j++)
			                	{
					                if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
									   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                {
					                    movimiento = 0;
			    		                break;
									}
														
			    	            	if(i == moverFila && j == moverCol)
			    	            	{
			    		            	movimiento = 1;
			    		            	break;
					            	}
				            	}
				            
				            
				            	if(movimiento == 0)
				            	{
				            		// MOVIMIENTOS HACIA ATRAS
					            	j = fichaCol;
			                    	for(i = fichaFila - 1; i >= 0; i--)
			                    	{
					                    if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
										   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
														
			    	                	if(i == moverFila && j == moverCol)
			    	                	{
			    		                	movimiento = 1;
			    		                	break;
					                	}
				                	}
				                
				                	if(movimiento == 0)
				                	{
				                		// MOVIMIENTOS HACIA IZQUIERDA
				                		i = fichaFila;
			                        	for(j = fichaCol - 1; j >= 0; j--)
			                        	{
					                        if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        {
					                            movimiento = 0;
			    		                        break;
											}
														
			    	                    	if(i == moverFila && j == moverCol)
			    	                    	{
			    		                    	movimiento = 1;
			    		                    	break;
					                    	}
				                    	}
				                    
				                    	if(movimiento == 0)
				                    	{
				                    		printf("Movimiento no valido\n");
										}
									
										else
										{
											// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
											// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
											if(ajedrez[moverFila][moverCol] == 26)
		                            		{
		                                		partida = true;
		                                		ganador(ajedrez, 8, moverFila, moverCol);
		                                		break;
											}
									
											aux = ajedrez[fichaFila][fichaCol];  
		                                	ajedrez[fichaFila][fichaCol] = 0;    
		                                	ajedrez[moverFila][moverCol] = aux;
										}
									}
								
									else
									{
										if(ajedrez[moverFila][moverCol] == 26)
		                            	{
		                                	partida = true;
		                                	ganador(ajedrez, 8, moverFila, moverCol);
		                                	break;
										}
									
										aux = ajedrez[fichaFila][fichaCol];  
		                            	ajedrez[fichaFila][fichaCol] = 0;    
		                            	ajedrez[moverFila][moverCol] = aux;
									}
				            	}
				            
				            	else
				            	{
				            		if(ajedrez[moverFila][moverCol] == 26)
		                            {
		                                partida = true;
		                                ganador(ajedrez, 8, moverFila, moverCol);
		                                break;
									}
									
				            		aux = ajedrez[fichaFila][fichaCol];  
		                        	ajedrez[fichaFila][fichaCol] = 0;    
		                        	ajedrez[moverFila][moverCol] = aux;
								}
				            
							}
				
				        	else
				        	{
				        		if(ajedrez[moverFila][moverCol] == 26)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
									
					        	aux = ajedrez[fichaFila][fichaCol];  
		                    	ajedrez[fichaFila][fichaCol] = 0;    
		                    	ajedrez[moverFila][moverCol] = aux;
				        	}
				        	
				        	if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }    
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
						}        
						
						
						else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						} 
			        }
			    
			        else
			        {
			    	    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
		        }

//////////////////////////////////////////////////////////////////////////    TORRES NEGRO    /////////////////////////////////////////////////////////////////////////////////
		    
		        else if(jugador == 2)
		        {
		        	// VERIFICAMOS SI LA PIEZA ES TORRE NEGRO
		    	    if(ajedrez[fichaFila][fichaCol] == 21)  // 21 = TORRE NEGRO
				    {
				        // VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[6][0] == 0 || ajedrez[6][7] == 0)
				    	{
				    		// MOVIMIENTOS HACIA ALANTE
			            	j = fichaCol;
			            	for(i = fichaFila + 1; i < 48; i++)
			            	{
			            		// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            {
					                movimiento = 0;
			    		            break;
								}
											
			    	        	if(i == moverFila && j == moverCol)
			    	        	{
			    		        	movimiento = 1;
			    		        	break;
					        	}
				        	}
				        
				        	if(movimiento == 0)
				        	{
				        		// MOVIMIENTOS HACIA DERECHA
				        		i = fichaFila;
			                	for(j = fichaCol + 1; j < 8; j++)
			                	{
					                if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
									   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                {
					                    movimiento = 0;
			    		                break;
									}
											
			    	            	if(i == moverFila && j == moverCol)
			    	            	{
			    		            	movimiento = 1;
			    		            	break;
					            	}
				            	}
				            
				            
				            	if(movimiento == 0)
				            	{
				            		// MOVIMIENTOS HACIA ATRAS
					            	j = fichaCol;
			                    	for(i = fichaFila - 1; i >= 0; i--)
			                    	{
					                    if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
										   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
											
			    	                	if(i == moverFila && j == moverCol)
			    	                	{
			    		                	movimiento = 1;
			    		                	break;
					                	}
				                	}
				                
				                	if(movimiento == 0)
				                	{
				                		// MOVIMIENTOS HACIA IZQUIERDA
				                		i = fichaFila;
			                        	for(j = fichaCol - 1; j >= 0; j--)
			                        	{
					                        if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        {
					                            movimiento = 0;
			    		                        break;
											}
											
			    	                    	if(i == moverFila && j == moverCol)
			    	                    	{
			    		                    	movimiento = 1;
			    		                    	break;
					                    	}
				                    	}
				                    
				                    	if(movimiento == 0)
				                    	{
				                    		printf("Movimiento no valido\n");
										}
									
										else
										{
											
				                        	// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
											// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
											if(ajedrez[moverFila][moverCol] == 16)
		                            		{
		                                		partida = true;
		                                		ganador(ajedrez, 8, moverFila, moverCol);
		                                		break;
											}
									
											aux = ajedrez[fichaFila][fichaCol];  
		                                	ajedrez[fichaFila][fichaCol] = 0;    
		                                	ajedrez[moverFila][moverCol] = aux;
										}
									}
								
									else
									{
										if(ajedrez[moverFila][moverCol] == 16)
		                            	{
		                                	partida = true;
		                                	ganador(ajedrez, 8, moverFila, moverCol);
		                                	break;
										}
									
										aux = ajedrez[fichaFila][fichaCol];  
		                            	ajedrez[fichaFila][fichaCol] = 0;    
		                            	ajedrez[moverFila][moverCol] = aux;
									}
				            	}
				            
				            	else
				            	{
				            		if(ajedrez[moverFila][moverCol] == 16)
		                            {
		                                partida = true;
		                                ganador(ajedrez, 8, moverFila, moverCol);
		                                break;
									}
									
				            		aux = ajedrez[fichaFila][fichaCol];  
		                        	ajedrez[fichaFila][fichaCol] = 0;    
		                        	ajedrez[moverFila][moverCol] = aux;
								}
				            
							}
				
				        	else
				        	{
				        		if(ajedrez[moverFila][moverCol] == 16)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
					        	aux = ajedrez[fichaFila][fichaCol];  
		                    	ajedrez[fichaFila][fichaCol] = 0;    
		                    	ajedrez[moverFila][moverCol] = aux;
				        	}
				        	
				        	if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }    
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
						}        
						
						
						else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						} 
			        }
			    
			        else
			        {
			    	    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
			    }
			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		    
		        else
		        {
		    	    printf("\nNo puedes seleccionar pieza del otro jugador\n");
			    }
		    
		    }while(ajedrez[fichaFila][fichaCol] == 22 || ajedrez[fichaFila][fichaCol] == 11 || ajedrez[fichaFila][fichaCol] == 24 || ajedrez[fichaFila][fichaCol] == 14 || 
			       ajedrez[fichaFila][fichaCol] == 13 || ajedrez[fichaFila][fichaCol] == 23 || ajedrez[fichaFila][fichaCol] == 12 || ajedrez[fichaFila][fichaCol] == 21 ||
				   ajedrez[fichaFila][fichaCol] == 15 || ajedrez[fichaFila][fichaCol] == 25 || ajedrez[fichaFila][fichaCol] == 16 || ajedrez[fichaFila][fichaCol] == 26);            
            
            
            break;
        }
        
        
////////////////////////////////////////////////////////////////////////////    REINA    //////////////////////////////////////////////////////////////////////////////////////////
		
		
		case 5: 
		{
///////////////////////////////////////////////////////////////////////    POSICION INICIAL    /////////////////////////////////////////////////////////////////////////////////////
			do
			{
				
				// PEDIMOS AL USUARIO QUE INGRESE LA FILA Y LA COLUMNA DE LA PIEZA QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[0], jugador, piezaSeleccionado1[4]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[1], jugador, piezaSeleccionado2[4]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaFila)) continue;
	    
	                if(fichaFila > 0)
	 	            {
			            if(fichaFila >= 1 && fichaFila <= 7)
			            {
				            b = fichaFila < 1;
			            }
			
			            if(fichaFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaFila == 0)
		            {
			            b = fichaFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[0], jugador, piezaSeleccionado1[4]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[1], jugador, piezaSeleccionado2[4]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaCol)) continue;
	    
	                if(fichaCol > 0)
		            {
			            if(fichaCol >= 1 && fichaCol <= 7)
			            {
				            b = fichaCol < 1;
			            }
			
			            else if(fichaCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaCol == 0)
		            {
			            b = fichaCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	            
////////////////////////////////////////////////////////////////////    POSICION FINAL (DESTINO)    //////////////////////////////////////////////////////////////////////////////////	            
	            
	            // PEDIMOS AL USUARIO QUE INGRESE LA POSICION QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[0], jugador, piezaSeleccionado1[4]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[1], jugador, piezaSeleccionado2[4]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la posicion que desea mover: ");
	                if(validFormat("%i", &moverFila)) continue;
	    
	                if(moverFila > 0)
		            {
			            if(moverFila >= 1 && moverFila <= 7)
			            {
				            b = moverFila < 1;
			            }
			
			            else if(moverFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(moverFila == 0)
		            {
			            b = moverFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[0], jugador, piezaSeleccionado1[4]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[4], pieza[1], jugador, piezaSeleccionado2[4]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la posicion que desea mover: ");
	                if(validFormat("%i", &moverCol)) continue;
	    
	                if(moverCol > 0)
		            {
			            if(moverCol >= 1 && moverCol <= 7)
			            {
				            b = moverCol < 1;
			            }
			
			            else if(moverCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		 
		            else if(moverCol == 0)
		            {
			            b = moverCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		            
		    
	            }while(b); 
	            
///////////////////////////////////////////////////////////////////////    MOVIMIENTOS (REINA)    /////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////    REINA BLANCO    /////////////////////////////////////////////////////////////////////////////////	            
	            
				if(jugador == 1)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES REINA BLANCO
				    if(ajedrez[fichaFila][fichaCol] == 15)  // 15 = REINA BLANCO
				    {
				    	// VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[1][2] == 0 || ajedrez[1][3] == 0 || ajedrez[1][4] == 0)
				    	{
					        // MOVIMIENTOS DIAGONAL DERECHA HACIA BAJO
	                        j = fichaCol + 1;
	                        for(i = fichaFila + 1; i < 8; i++)
	                        {
	                        	// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            {
					                movimiento = 0;
			    		            break;
								}
											
		                        if(i == moverFila && j == moverCol)
		                        {
			                        movimiento = 1;
			                        break;
		                        }
		
		                        j++;
	                        }
	            
	                        if(movimiento == 0)
	                        {
		                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA BAJO
		                        j = fichaCol - 1;
		                        for(i = fichaFila + 1; i < 8; i++)
		                        {
					                if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
									   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                {
					                    movimiento = 0;
			    		                break;
									}
											
			                        if(i == moverFila && j == moverCol)
			                        {
				                        movimiento = 1;
				                        break;
			                        }
			
			                        j--;
		                        }
		
		                        if(movimiento == 0)
		                        {
			                        // MOVIMIENTOS DIAGONAL DERECHA HACIA ARRIBA 
			                        j = fichaCol + 1;
			                        for(i = fichaFila - 1; i >= 0; i--)
			                        {
					                    if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
										   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
										
				                        if(i == moverFila && j == moverCol)
				                        {
					                        movimiento = 1;
				                            break;
				                        }
				
				                        j++;
			                        }
			
			
			                        if(movimiento == 0)
			                        {
				                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA ARRIBA
				                        j = fichaCol - 1;
				                        for(i = fichaFila - 1; i >= 0; i--)
				                        {
					                        if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        {
					                            movimiento = 0;
			    		                        break;
											}
											
					                        if(i == moverFila && j == moverCol)
					                        {
						                        movimiento = 1;
				                                break;
					                        }
					
					                        j--;
				                        }
				                        
				                        if(movimiento == 0)
				                        {
				                        	// MOVIMIENTOS HACIA ALANTE
				                        	j = fichaCol;
				                        	for(i = fichaFila + 1; i < 8; i++)
				                        	{
					                        	if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   	   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        	{
					                            	movimiento = 0;
			    		                        	break;
												}
											
				                        		if(i == moverFila && j == moverCol)
					                            {
						                            movimiento = 1;
				                                    break;
					                            }
											}
											
											if(movimiento == 0)
											{
												// MOVIMIENTOS HACIA DERECHA
												i = fichaFila;
												for(j = fichaCol + 1; i < 8; i++)
												{
					                        		if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   		   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        		{
					                            		movimiento = 0;
			    		                        		break;
													}
											
													if(i == moverFila && j == moverCol)
					                                {
						                                movimiento = 1;
				                                        break;
					                                }
												}
												
												if(movimiento == 0)
												{
													// MOVIMIENTOS HACIA ATRAS
					            	                j = fichaCol;
			                    					for(i = fichaFila - 1; i >= 0; i--)
			                    					{
					                        			if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   			   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        			{
					                            			movimiento = 0;
			    		                        			break;
														}
											
			    	                					if(i == moverFila && j == moverCol)
			    	                					{
			    		                					movimiento = 1;
			    		                					break;
					                					}
				                					}
				                					
				                					if(movimiento == 0)
				                					{
				                						// MOVIMIENTOS HACIA IZQUIERDA
				                						i = fichaFila;
			                        					for(j = fichaCol - 1; j >= 0; j--)
			                        					{
					                        				if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   			       ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        				{
					                            				movimiento = 0;
			    		                        				break;
															}
											
			    	                    					if(i == moverFila && j == moverCol)
			    	                    					{
			    		                    					movimiento = 1;
			    		                    					break;
					                    					}
				                    					}
				                    					
				                    					if(movimiento == 0)
				                        				{
					                        				printf("Movimiento no valido\n");
				                        				}
				                        				
				                        				
				                        				else
				                        				{
				                        					// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
														// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				                        					if(ajedrez[moverFila][moverCol] == 26)
		                                    				{
		                                    					partida = true;
		                                    					ganador(ajedrez, 8, moverFila, moverCol);
		                                    					break;
															}
															
				                        					aux = ajedrez[fichaFila][fichaCol];  
		                                    				ajedrez[fichaFila][fichaCol] = 0;    
		                                    				ajedrez[moverFila][moverCol] = aux;
														}
													}
													
													else
				                        			{
				                        				if(ajedrez[moverFila][moverCol] == 26)
		                                    			{
		                                    				partida = true;
		                                    				ganador(ajedrez, 8, moverFila, moverCol);
		                                    				break;
														}
				                        				
				                        				aux = ajedrez[fichaFila][fichaCol];  
		                                    			ajedrez[fichaFila][fichaCol] = 0;    
		                                    			ajedrez[moverFila][moverCol] = aux;
													}
											    }
											    
											    else
				                        		{
		                                    		if(ajedrez[moverFila][moverCol] == 26)
		                                    		{
		                                    			partida = true;
		                                    			ganador(ajedrez, 8, moverFila, moverCol);
		                                    			break;
													}
				                        			
				                        			aux = ajedrez[fichaFila][fichaCol];  
		                                    		ajedrez[fichaFila][fichaCol] = 0;    
		                                    		ajedrez[moverFila][moverCol] = aux;
												}
											}
											
											else
				                        	{
		                                    	if(ajedrez[moverFila][moverCol] == 26)
		                                    	{
		                                    		partida = true;
		                                    		ganador(ajedrez, 8, moverFila, moverCol);
		                                    		break;
												}
				                        		
				                        		aux = ajedrez[fichaFila][fichaCol];  
		                                    	ajedrez[fichaFila][fichaCol] = 0;    
		                                    	ajedrez[moverFila][moverCol] = aux;
											}
										}
				
				                        else
				                        {
		                                    if(ajedrez[moverFila][moverCol] == 26)
		                                    {
		                                    	partida = true;
		                                    	ganador(ajedrez, 8, moverFila, moverCol);
		                                    	break;
											}
				                        	
					                        aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
				                        }
			                        }
			
			                        else
			                        {
		                                if(ajedrez[moverFila][moverCol] == 26)
		                                {
		                                    partida = true;
		                                    ganador(ajedrez, 8, moverFila, moverCol);
		                                    break;
										}
										
				                        aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
			                        }
			
		                        }
		
		                        else
		                        {
		                        	if(ajedrez[moverFila][moverCol] == 26)
		                            {
		                                partida = true;
		                                ganador(ajedrez, 8, moverFila, moverCol);
		                                break;
									}
		                        	
			                        aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
		                        }
	                        }
	
	                        else
	                        {
		                        if(ajedrez[moverFila][moverCol] == 26)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
		                        aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
	                        }
	
	                        if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
	                    
	                    }
	                    
	                    else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						}
				    }
	            
	                else
	                {
	            	    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
	            }
	        
//////////////////////////////////////////////////////////////////////////    REINA NEGRO    /////////////////////////////////////////////////////////////////////////////////

                else if(jugador == 2)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES REINA NEGRO
				    if(ajedrez[fichaFila][fichaCol] == 25)  // 25 = REINA NEGRO
				    {
				    	// VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[6][2] == 0 || ajedrez[6][3] == 0 || ajedrez[6][4] == 0)
				    	{
					        // MOVIMIENTOS DIAGONAL DERECHA HACIA BAJO
	                        j = fichaCol + 1;
	                        for(i = fichaFila + 1; i < 8; i++)
	                        {
	                        	// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            {
					                movimiento = 0;
			    		            break;
								}
															
		                        if(i == moverFila && j == moverCol)
		                        {
			                        movimiento = 1;
			                        break;
		                        }
		
		                        j++;
	                        }
	            
	                        if(movimiento == 0)
	                        {
		                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA BAJO
		                        j = fichaCol - 1;
		                        for(i = fichaFila + 1; i < 8; i++)
		                        {
					                if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
									   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                {
					                    movimiento = 0;
			    		                break;
									}
															
			                        if(i == moverFila && j == moverCol)
			                        {
				                        movimiento = 1;
				                        break;
			                        }
			
			                        j--;
		                        }
		
		                        if(movimiento == 0)
		                        {
			                        // MOVIMIENTOS DIAGONAL DERECHA HACIA ARRIBA 
			                        j = fichaCol + 1;
			                        for(i = fichaFila - 1; i >= 0; i--)
			                        {
					                    if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
										   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
															
				                        if(i == moverFila && j == moverCol)
				                        {
					                        movimiento = 1;
				                            break;
				                        }
				
				                        j++;
			                        }
			
			
			                        if(movimiento == 0)
			                        {
				                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA ARRIBA
				                        j = fichaCol - 1;
				                        for(i = fichaFila - 1; i >= 0; i--)
				                        {
					                        if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        {
					                            movimiento = 0;
			    		                        break;
											}
															
					                        if(i == moverFila && j == moverCol)
					                        {
						                        movimiento = 1;
				                                break;
					                        }
					
					                        j--;
				                        }
				                        
				                        if(movimiento == 0)
				                        {
				                        	// MOVIMIENTOS HACIA ALANTE
				                        	j = fichaCol;
				                        	for(i = fichaFila + 1; i < 48; i++)
				                        	{
					                        	if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   	   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        	{
					                            	movimiento = 0;
			    		                        	break;
												}
															
				                        		if(i == moverFila && j == moverCol)
					                            {
						                            movimiento = 1;
				                                    break;
					                            }
											}
											
											if(movimiento == 0)
											{
												// MOVIMIENTOS HACIA DERECHA
												i = fichaFila;
												for(j = fichaCol + 1; j < 8; j++)
												{
					                        		if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   		   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        		{
					                            		movimiento = 0;
			    		                        		break;
													}
															
													if(i == moverFila && j == moverCol)
					                                {
						                                movimiento = 1;
				                                        break;
					                                }
												}
												
												if(movimiento == 0)
												{
													// MOVIMIENTOS HACIA ATRAS
					            	                j = fichaCol;
			                    					for(i = fichaFila - 1; i >= 0; i--)
			                    					{
					                        			if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   			   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        			{
					                            			movimiento = 0;
			    		                        			break;
														}
															
			    	                					if(i == moverFila && j == moverCol)
			    	                					{
			    		                					movimiento = 1;
			    		                					break;
					                					}
				                					}
				                					
				                					if(movimiento == 0)
				                					{
				                						// MOVIMIENTOS HACIA IZQUIERDA
				                						i = fichaFila;
			                        					for(j = fichaCol - 1; j >= 0; j--)
			                        					{
					                        				if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   				   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        				{
					                            				movimiento = 0;
			    		                        				break;
															}
															
			    	                    					if(i == moverFila && j == moverCol)
			    	                    					{
			    		                    					movimiento = 1;
			    		                    					break;
					                    					}
				                    					}
				                    					
				                    					if(movimiento == 0)
				                        				{
					                        				printf("Movimiento no valido\n");
				                        				}
				                        				
				                        				else
				                        				{
				                        					// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
														// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				                        					if(ajedrez[moverFila][moverCol] == 16)
		                                    				{
		                                    					partida = true;
		                                    					ganador(ajedrez, 8, moverFila, moverCol);
		                                    					break;
															}
															
				                        					aux = ajedrez[fichaFila][fichaCol];  
		                                    				ajedrez[fichaFila][fichaCol] = 0;    
		                                    				ajedrez[moverFila][moverCol] = aux;
														}
													}
													
													else
				                        			{
				                        				if(ajedrez[moverFila][moverCol] == 16)
		                                    			{
		                                    				partida = true;
		                                    				ganador(ajedrez, 8, moverFila, moverCol);
		                                    				break;
														}
															
				                        				aux = ajedrez[fichaFila][fichaCol];  
		                                    			ajedrez[fichaFila][fichaCol] = 0;    
		                                    			ajedrez[moverFila][moverCol] = aux;
													}
											    }
											    
											    else
				                        		{
				                        			if(ajedrez[moverFila][moverCol] == 16)
		                                    		{
		                                    			partida = true;
		                                    			ganador(ajedrez, 8, moverFila, moverCol);
		                                    			break;
													}
															
				                        			aux = ajedrez[fichaFila][fichaCol];  
		                                    		ajedrez[fichaFila][fichaCol] = 0;    
		                                    		ajedrez[moverFila][moverCol] = aux;
												}
											}
											
											else
				                        	{
				                        		if(ajedrez[moverFila][moverCol] == 16)
		                                    	{
		                                    		partida = true;
		                                    		ganador(ajedrez, 8, moverFila, moverCol);
		                                    		break;
												}
												
				                        		aux = ajedrez[fichaFila][fichaCol];  
		                                    	ajedrez[fichaFila][fichaCol] = 0;    
		                                    	ajedrez[moverFila][moverCol] = aux;
											}
										}
				
				                        else
				                        {
				                        	if(ajedrez[moverFila][moverCol] == 16)
		                                    {
		                                    	partida = true;
		                                    	ganador(ajedrez, 8, moverFila, moverCol);
		                                    	break;
											}
											
					                        aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
				                        }
			                        }
			
			                        else
			                        {
			                        	if(ajedrez[moverFila][moverCol] == 16)
		                                {
		                                    partida = true;
		                                    ganador(ajedrez, 8, moverFila, moverCol);
		                                    break;
										}
										
				                        aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
			                        }
			
		                        }
		
		                        else
		                        {
		                        	if(ajedrez[moverFila][moverCol] == 16)
		                            {
		                                partida = true;
		                                ganador(ajedrez, 8, moverFila, moverCol);
		                                break;
									}
									
			                        aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
		                        }
	                        }
	
	                        else
	                        {
	                        	if(ajedrez[moverFila][moverCol] == 16)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
		                        aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
	                        }
	
	                        if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
	                    }
	                    
	                    else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						}
				    }
				
				    else
				    {
					    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
	            
	            }
			
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
	        
	            else
	            {
	        	    printf("\n\nNo puede seleccionar este pieza, selecciona una pieza valida\n");
			    }
			
		    }while(ajedrez[fichaFila][fichaCol] == 24 || ajedrez[fichaFila][fichaCol] == 14 || ajedrez[fichaFila][fichaCol] == 11 || ajedrez[fichaFila][fichaCol] == 22 ||
			       ajedrez[fichaFila][fichaCol] == 13 || ajedrez[fichaFila][fichaCol] == 23 || ajedrez[fichaFila][fichaCol] == 12 || ajedrez[fichaFila][fichaCol] == 21 ||
				   ajedrez[fichaFila][fichaCol] == 15 || ajedrez[fichaFila][fichaCol] == 25 || ajedrez[fichaFila][fichaCol] == 16 || ajedrez[fichaFila][fichaCol] == 26);
		
		    break;
	    }
	    
	    
	    
//////////////////////////////////////////////////////////////////////////////    REY    ///////////////////////////////////////////////////////////////////////////////////////////
		
		case 6: 
		{
///////////////////////////////////////////////////////////////////////    POSICION INICIAL    /////////////////////////////////////////////////////////////////////////////////////
			do
			{
				
				// PEDIMOS AL USUARIO QUE INGRESE LA FILA Y LA COLUMNA DE LA PIEZA QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[0], jugador, piezaSeleccionado1[5]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[1], jugador, piezaSeleccionado2[5]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaFila)) continue;
	    
	                if(fichaFila > 0)
	 	            {
			            if(fichaFila >= 1 && fichaFila <= 7)
			            {
				            b = fichaFila < 1;
			            }
			
			            if(fichaFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaFila == 0)
		            {
			            b = fichaFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[0], jugador, piezaSeleccionado1[5]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[1], jugador, piezaSeleccionado2[5]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la pieza que desea mover: ");
	                if(validFormat("%i", &fichaCol)) continue;
	    
	                if(fichaCol > 0)
		            {
			            if(fichaCol >= 1 && fichaCol <= 7)
			            {
				            b = fichaCol < 1;
			            }
			
			            else if(fichaCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(fichaCol == 0)
		            {
			            b = fichaCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	            
////////////////////////////////////////////////////////////////////    POSICION FINAL (DESTINO)    //////////////////////////////////////////////////////////////////////////////////	            
	            
	            // PEDIMOS AL USUARIO QUE INGRESE LA POSICION QUE DESEA MOVER
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[0], jugador, piezaSeleccionado1[5]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[1], jugador, piezaSeleccionado2[5]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la fila de la posicion que desea mover: ");
	                if(validFormat("%i", &moverFila)) continue;
	    
	                if(moverFila > 0)
		            {
			            if(moverFila >= 1 && moverFila <= 7)
			            {
				            b = moverFila < 1;
			            }
			
			            else if(moverFila >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		
		            else if(moverFila == 0)
		            {
			            b = moverFila > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		    
	            }while(b); 
	
	            do
	            {
	            	//TURNO Y COLOR DE PIEZAS
	            	if(turnos % 2 == 0)
	                {
	                	jugador = 1;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[0], jugador, piezaSeleccionado1[5]);
	                }
	
	                else
	                {
	                	jugador = 2;
	                	
		                printf("\nPieza: %s %s (%i)\t\t\t\t\tPieza seleccionado: %s\n\n", ficha[5], pieza[1], jugador, piezaSeleccionado2[5]);
	                }
	            	
		            // MOSTRAMOS EL TABLERO 
	            	for(i = 0; i < 8; i++)
	            	{
	            		printf("\t  %i  ", numero[i]);
					}
	            	
	                for(i = 0; i < 8; i++)
	                {
		                printf("\n\n");
		
		                for(j = 0; j < 8; j++)
		                {
			                // PEONES BLANCO
		                	if(ajedrez[i][j] == 11)
		                	{
		                		printf("\t[ PBL ]");
							}
		                	
		                	// PEONES NEGRO
		                	else if(ajedrez[i][j] == 22)
		                	{
		                		printf("\t[ PNR ]");
							}
							
							
							
							// TORRES BLANCO
							else if(ajedrez[i][j] == 12)
		                	{
		                		printf("\t[ TBL ]");
							}
							
							// TORRES NEGRO
							else if(ajedrez[i][j] == 21)
		                	{
		                		printf("\t[ TNR ]");
							}
							
							
							// CABALLOS BLANCO
							else if(ajedrez[i][j] == 13)
		                	{
		                		printf("\t[ CBL ]");
							}
							
							// CABALLOS NEGRO
							else if(ajedrez[i][j] == 23)
		                	{
		                		printf("\t[ CNR ]");
							}
							
		                	
		                	// ALFILES BLANCO
			                else if(ajedrez[i][j] == 14)
		                	{
		                		printf("\t[ ABL ]");
							}
							
							// ALFILES NEGRO
							else if(ajedrez[i][j] == 24)
		                	{
		                		printf("\t[ ANR ]");
							}
							
							
							// REINA BLANCO
							else if(ajedrez[i][j] == 15)
		                	{
		                		printf("\t[ MBL ]");
							}
							
							// REINA NEGRO
							else if(ajedrez[i][j] == 25)
		                	{
		                		printf("\t[ MNR ]");
							}
							
							
							
							// REI BLANCO
							else if(ajedrez[i][j] == 16)
		                	{
		                		printf("\t[ RBL ]");
							}
							
							// REI NEGRO
							else if(ajedrez[i][j] == 26)
		                	{
		                		printf("\t[ RNR ]");
							}
							
							
							
							// ESPACIOS
							else
							{
								printf("\t[  ]");
							}
		                }
		                
		                printf("\t  %i  ", numero[i]);
	                }
		
	                printf("\n\nIngrese la columna de la posicion que desea mover: ");
	                if(validFormat("%i", &moverCol)) continue;
	    
	                if(moverCol > 0)
		            {
			            if(moverCol >= 1 && moverCol <= 7)
			            {
				            b = moverCol < 1;
			            }
			
			            else if(moverCol >= 8)
			            {
				            printf("\nERROR, Por favor ingrese un numero valido\n\n");
			            }
		            }
		 
		            else if(moverCol == 0)
		            {
			            b = moverCol > 1;
		            }
		            
		            else
		            {
		            	printf("\nERROR, Por favor ingrese un numero valido\n\n");
					}
		            
		    
	            }while(b); 
	            
/////////////////////////////////////////////////////////////////////////    MOVIMIENTOS (REY)    ///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////    REY BLANCO    //////////////////////////////////////////////////////////////////////////////////	            
	            
				if(jugador == 1)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES REY BLANCO
				    if(ajedrez[fichaFila][fichaCol] == 16)  // 16 = REY BLANCO
				    {
				    	// VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[1][3] == 0 || ajedrez[1][4] == 0 || ajedrez[1][5] == 0)
				    	{
					        // MOVIMIENTOS DIAGONAL DERECHA HACIA BAJO
	                        j = fichaCol + 1;
	                        for(i = fichaFila + 1; i < 8; i++)
	                        {
	                        	// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					            {
					                movimiento = 0;
			    		            break;
								}
															
		                        if(i == moverFila && j == moverCol)
		                        {
			                        movimiento = 1;
			                        break;
		                        }
	                        }
		                        
	            
	                        if(movimiento == 0)
	                        {
		                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA BAJO
		                        j = fichaCol - 1;
		                        for(i = fichaFila + 1; i < 8; i++)
		                        {
					                if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
								       ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                {
					                    movimiento = 0;
			    		                break;
									}
															
			                        if(i == moverFila && j == moverCol)
			                        {
				                        movimiento = 1;
				                        break;
			                        }
		                        }
		
		                        if(movimiento == 0)
		                        {
			                        // MOVIMIENTOS DIAGONAL DERECHA HACIA ARRIBA 
			                        j = fichaCol + 1;
			                        for(i = fichaFila - 1; i >= 0; i--)
			                        {
					                    if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
										   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
										
				                        if(i == moverFila && j == moverCol)
				                        {
					                        movimiento = 1;
				                            break;
				                        }
			                        }
			
			
			                        if(movimiento == 0)
			                        {
				                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA ARRIBA
				                        j = fichaCol - 1;
				                        for(i = fichaFila - 1; i >= 0; i--)
				                        {
					                        if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        {
					                            movimiento = 0;
			    		                        break;
											}
															
					                        if(i == moverFila && j == moverCol)
					                        {
						                        movimiento = 1;
				                                break;
					                        }
				                        }

				                        
				                        if(movimiento == 0)
				                        {
				                        	// MOVIMIENTOS HACIA ALANTE
										    i = fichaFila + 1;
										    for(j = fichaCol; fichaCol == j; j++)
										    {
					                        	if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   	   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        	{
					                            	movimiento = 0;
			    		                        	break;
												}
															
										    	if(i == moverFila && j == moverCol)
					                            {
						                            movimiento = 1;
				                                    break;
					                            }
											}
											
											if(movimiento == 0)
											{
												// MOVIMIENTOS HACIA DERECHA
												j = fichaCol + 1;
												for(i = fichaFila; fichaFila == i; i++)
												{
					                        		if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   		   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        		{
					                            		movimiento = 0;
			    		                        		break;
													}
															
													if(i == moverFila && j == moverCol)
					                                {
						                                movimiento = 1;
				                                        break;
					                                }
												}
					                            
												
												if(movimiento == 0)
												{
													// MOVIMIENTOS HACIA ATRAS
				                					i = fichaFila - 1;
										            for(j = fichaCol; fichaCol == j; j++)
										            {
					                        			if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   			   ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        			{
					                            			movimiento = 0;
			    		                        			break;
														}
															
										    	        if(i == moverFila && j == moverCol)
					                            		{
						                            		movimiento = 1;
				                                    		break;
					                            		}
													}
					                				
				                					
				                					if(movimiento == 0)
				                					{
				                						// MOVIMIENTOS HACIA IZQUIERDA
				                    					j = fichaCol - 1;
				                    					for(i = fichaFila; fichaFila == i; i++)
				                    					{
					                        				if(ajedrez[moverFila][moverCol] == 11 || ajedrez[moverFila][moverCol] == 12 || ajedrez[moverFila][moverCol] == 13 ||
											   			       ajedrez[moverFila][moverCol] == 14 || ajedrez[moverFila][moverCol] == 15 || ajedrez[moverFila][moverCol] == 16)
					                        				{
					                            				movimiento = 0;
			    		                        				break;
															}
															
				                    						if(i == moverFila && j == moverCol)
			    	                    					{
			    		                    					movimiento = 1;
			    		                    					break;
					                    					}
														}
					                    				
				                    					
				                    					if(movimiento == 0)
				                        				{
					                        				printf("Movimiento no valido\n");
				                        				}
				                        				
				                        				
				                        				else
				                        				{
				                        					// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
														// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				                        					if(ajedrez[moverFila][moverCol] == 26)
		                                    				{
		                                    					partida = true;
		                                    					ganador(ajedrez, 8, moverFila, moverCol);
		                                    					break;
															}
															
				                        					aux = ajedrez[fichaFila][fichaCol];  
		                                    				ajedrez[fichaFila][fichaCol] = 0;    
		                                    				ajedrez[moverFila][moverCol] = aux;
														}
													}
													
													else
				                        			{
				                        				if(ajedrez[moverFila][moverCol] == 26)
		                                    			{
		                                    				partida = true;
		                                    				ganador(ajedrez, 8, moverFila, moverCol);
		                                    				break;
														}
														
				                        				aux = ajedrez[fichaFila][fichaCol];  
		                                    			ajedrez[fichaFila][fichaCol] = 0;    
		                                    			ajedrez[moverFila][moverCol] = aux;
													}
											    }
											    
											    else
				                        		{
				                        			if(ajedrez[moverFila][moverCol] == 26)
		                                    		{
		                                    			partida = true;
		                                    			ganador(ajedrez, 8, moverFila, moverCol);
		                                    			break;
													}
													
				                        			aux = ajedrez[fichaFila][fichaCol];  
		                                    		ajedrez[fichaFila][fichaCol] = 0;    
		                                    		ajedrez[moverFila][moverCol] = aux;
												}
											}
											
											else
				                        	{
				                        		if(ajedrez[moverFila][moverCol] == 26)
		                                    	{
		                                    		partida = true;
		                                    		ganador(ajedrez, 8, moverFila, moverCol);
		                                    		break;
												}
												
				                        		aux = ajedrez[fichaFila][fichaCol];  
		                                    	ajedrez[fichaFila][fichaCol] = 0;    
		                                    	ajedrez[moverFila][moverCol] = aux;
											}
										}
				
				                        else
				                        {
				                        	if(ajedrez[moverFila][moverCol] == 26)
		                                    {
		                                    	partida = true;
		                                    	ganador(ajedrez, 8, moverFila, moverCol);
		                                    	break;
											}
											
					                        aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
				                        }
			                        }
			
			                        else
			                        {
			                        	if(ajedrez[moverFila][moverCol] == 26)
		                                {
		                                    partida = true;
		                                    ganador(ajedrez, 8, moverFila, moverCol);
		                                    break;
										}
										
				                        aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
			                        }
			
		                        }
		
		                        else
		                        {
		                        	if(ajedrez[moverFila][moverCol] == 26)
		                            {
		                                partida = true;
		                                ganador(ajedrez, 8, moverFila, moverCol);
		                                break;
									}
									
			                        aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
		                        }
	                        }
	
	                        else
	                        {
	                        	if(ajedrez[moverFila][moverCol] == 26)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
		                        aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
	                        }
	
	                        if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
	                    
	                    }
	                    
	                    else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						}
				    }
	            
	                else
	                {
	            	    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
	            }
	        
//////////////////////////////////////////////////////////////////////////    REY NEGRO    /////////////////////////////////////////////////////////////////////////////////

                else if(jugador == 2)
			    {
			    	// VERIFICAMOS SI LA PIEZA ES REY NEGRO
				    if(ajedrez[fichaFila][fichaCol] == 26)  // 26 = REINA NEGRO
				    {
				    	// VERIFICAMOS SI HAY MOVIMIENTOS POSIBLES EN LA POSICION INICIAL
				    	if(ajedrez[6][3] == 0 || ajedrez[6][4] == 0 || ajedrez[6][5] == 0)
				    	{
					        // MOVIMIENTOS DIAGONAL DERECHA HACIA BAJO
	                        j = fichaCol + 1;
	                        for(i = fichaFila + 1; i < 8; i++)
	                        {
	                        	// VERIFICAMOS LA COORDENADA FINAL(DESTINO) SI ES LA PIEZA DEL MISMO BANDO, EN CASO DE SI, NO SE PUEDE MOVER NI 
								// COMER LA PIEZA DE SU MISMO BANDO
					            if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
								   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					            {
					                movimiento = 0;
			    		            break;
							    }
															
		                        if(i == moverFila && j == moverCol)
		                        {
			                        movimiento = 1;
			                        break;
		                        }
	                        }
		                        
	            
	                        if(movimiento == 0)
	                        {
		                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA BAJO
		                        j = fichaCol - 1;
		                        for(i = fichaFila + 1; i < 8; i++)
		                        {
					                if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
									   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                {
					                    movimiento = 0;
			    		                break;
									}
															
			                        if(i == moverFila && j == moverCol)
			                        {
				                        movimiento = 1;
				                        break;
			                        }
		                        }
		
		                        if(movimiento == 0)
		                        {
			                        // MOVIMIENTOS DIAGONAL DERECHA HACIA ARRIBA 
			                        j = fichaCol + 1;
			                        for(i = fichaFila - 1; i >= 0; i--)
			                        {
					                    if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
										   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                    {
					                        movimiento = 0;
			    		                    break;
										}
															
				                        if(i == moverFila && j == moverCol)
				                        {
					                        movimiento = 1;
				                            break;
				                        }
			                        }
			
			
			                        if(movimiento == 0)
			                        {
				                        // MOVIMIENTOS DIAGONAL IZQUIERDA HACIA ARRIBA
				                        j = fichaCol - 1;
				                        for(i = fichaFila - 1; i >= 0; i--)
				                        {
					                        if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        {
					                            movimiento = 0;
			    		                        break;
										    }
															
					                        if(i == moverFila && j == moverCol)
					                        {
						                        movimiento = 1;
				                                break;
					                        }
				                        }

				                        
				                        if(movimiento == 0)
				                        {
				                        	// MOVIMIENTOS HACIA ALANTE
										    i = fichaFila + 1;
										    for(j = fichaCol; fichaCol == j; j++)
										    {
					                        	if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   	   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        	{
					                            	movimiento = 0;
			    		                        	break;
												}
															
										    	if(i == moverFila && j == moverCol)
					                            {
						                            movimiento = 1;
				                                    break;
					                            }
											}
											
											if(movimiento == 0)
											{
												// MOVIMIENTOS HACIA DERECHA
												j = fichaCol + 1;
												for(i = fichaFila; fichaFila == i; i++)
												{
					                        		if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   		   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        		{
					                            		movimiento = 0;
			    		                        		break;
													}
															
													if(i == moverFila && j == moverCol)
					                                {
						                                movimiento = 1;
				                                        break;
					                                }
												}
					                            
												
												if(movimiento == 0)
												{
													// MOVIMIENTOS HACIA ATRAS
				                					i = fichaFila - 1;
										            for(j = fichaCol; fichaCol == j; j++)
										            {
					                        			if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   			   ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        			{
					                            			movimiento = 0;
			    		                        			 break;
														}
															
										    	        if(i == moverFila && j == moverCol)
					                            		{
						                            		movimiento = 1;
				                                    		break;
					                            		}
													}
					                				
				                					
				                					if(movimiento == 0)
				                					{
				                						// MOVIMIENTOS HACIA IZQUIERDA
				                    					j = fichaCol - 1;
				                    					for(i = fichaFila; fichaFila == i; i++)
				                    					{
					                        				if(ajedrez[moverFila][moverCol] == 21 || ajedrez[moverFila][moverCol] == 22 || ajedrez[moverFila][moverCol] == 23 ||
											   			       ajedrez[moverFila][moverCol] == 24 || ajedrez[moverFila][moverCol] == 25 || ajedrez[moverFila][moverCol] == 26)
					                        				{
					                            				movimiento = 0;
			    		                        				break;
															}
															
				                    						if(i == moverFila && j == moverCol)
			    	                    					{
			    		                    					movimiento = 1;
			    		                    					break;
					                    					}
														}
					                    				
				                    					
				                    					if(movimiento == 0)
				                        				{
					                        				printf("Movimiento no valido\n");
				                        				}
				                        				
				                        				
				                        				else
				                        				{
				                        					// VERIFICAMOS SI ES JAQUE MATE, EN CASO DE QUE ES JAQUE MATE, PARTIDA PASA A TRUE Y DEJA DE LLAMAR LA FUNCION turnoJugador
														// DESPUES LLAMA LA FUNCION ganador Y MUESTRA EL GANADOR, EL BREAK PARA SALTAR Y/O TERMINAR LA EJECUCION DE LA FUNCION turnojugador
				                        					if(ajedrez[moverFila][moverCol] == 16)
		                                    				{
		                                    					partida = true;
		                                    					ganador(ajedrez, 8, moverFila, moverCol);
		                                    					break;
															}
															
				                        					aux = ajedrez[fichaFila][fichaCol];  
		                                    				ajedrez[fichaFila][fichaCol] = 0;    
		                                    				ajedrez[moverFila][moverCol] = aux;
														}
													}
													
													else
				                        			{
				                        				if(ajedrez[moverFila][moverCol] == 16)
		                                    			{
		                                    				partida = true;
		                                    				ganador(ajedrez, 8, moverFila, moverCol);
		                                    				break;
														}
														
				                        				aux = ajedrez[fichaFila][fichaCol];  
		                                    			ajedrez[fichaFila][fichaCol] = 0;    
		                                    			ajedrez[moverFila][moverCol] = aux;
													}
											    }
											    
											    else
				                        		{
				                        			if(ajedrez[moverFila][moverCol] == 16)
		                                    		{
		                                    			partida = true;
		                                    			ganador(ajedrez, 8, moverFila, moverCol);
		                                    			break;
													}
													
				                        			aux = ajedrez[fichaFila][fichaCol];  
		                                    		ajedrez[fichaFila][fichaCol] = 0;    
		                                    		ajedrez[moverFila][moverCol] = aux;
												}
											}
											
											else
				                        	{
				                        		if(ajedrez[moverFila][moverCol] == 16)
		                                    	{
		                                    		partida = true;
		                                    		ganador(ajedrez, 8, moverFila, moverCol);
		                                    		break;
												}
												
				                        		aux = ajedrez[fichaFila][fichaCol];  
		                                    	ajedrez[fichaFila][fichaCol] = 0;    
		                                    	ajedrez[moverFila][moverCol] = aux;
											}
										}
				
				                        else
				                        {
				                        	if(ajedrez[moverFila][moverCol] == 16)
		                                    {
		                                    	partida = true;
		                                    	ganador(ajedrez, 8, moverFila, moverCol);
		                                    	break;
											}
											
					                        aux = ajedrez[fichaFila][fichaCol];  
		                                    ajedrez[fichaFila][fichaCol] = 0;    
		                                    ajedrez[moverFila][moverCol] = aux;
				                        }
			                        }
			
			                        else
			                        {
			                        	if(ajedrez[moverFila][moverCol] == 16)
		                                {
		                                    partida = true;
		                                    ganador(ajedrez, 8, moverFila, moverCol);
		                                    break;
										}
										
				                        aux = ajedrez[fichaFila][fichaCol];  
		                                ajedrez[fichaFila][fichaCol] = 0;    
		                                ajedrez[moverFila][moverCol] = aux;
			                        }
			
		                        }
		
		                        else
		                        {
		                        	if(ajedrez[moverFila][moverCol] == 16)
		                            {
		                                partida = true;
		                                ganador(ajedrez, 8, moverFila, moverCol);
		                                break;
									}
									
			                        aux = ajedrez[fichaFila][fichaCol];  
		                            ajedrez[fichaFila][fichaCol] = 0;    
		                            ajedrez[moverFila][moverCol] = aux;
		                        }
	                        }
	
	                        else
	                        {
	                        	if(ajedrez[moverFila][moverCol] == 16)
		                        {
		                            partida = true;
		                            ganador(ajedrez, 8, moverFila, moverCol);
		                            break;
								}
								
		                        aux = ajedrez[fichaFila][fichaCol];  
		                        ajedrez[fichaFila][fichaCol] = 0;    
		                        ajedrez[moverFila][moverCol] = aux;
	                        }
	
	                        if(movimiento == 1)
	                        {
		                        // MOSTRAMOS EL TABLERO 
	                            for(i = 0; i < 8; i++)
	                            {
		                            printf("\n\n");
		
		                            for(j = 0; j < 8; j++)
		                            {
			                            // PEONES BLANCO
		                	            if(ajedrez[i][j] == 11)
		                	            {
		                		            printf("\t[ PBL ]");
							            }
		                	
		                	            // PEONES NEGRO
		                	            else if(ajedrez[i][j] == 22)
		                	            {
		                		            printf("\t[ PNR ]");
							            }
							
							
							
							            // TORRES BLANCO
							            else if(ajedrez[i][j] == 12)
		                	            {
		                		            printf("\t[ TBL ]");
							            }
							
							            // TORRES NEGRO
							            else if(ajedrez[i][j] == 21)
		                	            {
		                		            printf("\t[ TNR ]");
							            }
							
							
							            // CABALLOS BLANCO
							            else if(ajedrez[i][j] == 13)
		                	            {
		                		            printf("\t[ CBL ]");
							            }
							
							            // CABALLOS NEGRO
							            else if(ajedrez[i][j] == 23)
		                	            {
		                		            printf("\t[ CNR ]");
							            }
							
		                	
		                	            // ALFILES BLANCO
			                            else if(ajedrez[i][j] == 14)
		                	            {
		                		            printf("\t[ ABL ]");
							            }
							
							            // ALFILES NEGRO
							            else if(ajedrez[i][j] == 24)
		                	            {
		                		            printf("\t[ ANR ]");
							            }
							
							
							            // REINA BLANCO
							            else if(ajedrez[i][j] == 15)
		                	            {
		                		            printf("\t[ MBL ]");
							            }
							
							            // REINA NEGRO
							            else if(ajedrez[i][j] == 25)
		                	            {
		                		            printf("\t[ MNR ]");
							            }
							
							
							
							            // REI BLANCO
							            else if(ajedrez[i][j] == 16)
		                	            {
		                		            printf("\t[ RBL ]");
							            }
							
							            // REI NEGRO
							            else if(ajedrez[i][j] == 26)
		                	            {
		                		            printf("\t[ RNR ]");
							            }
							
							
							
							            // ESPACIOS
							            else
							            {
								            printf("\t[  ]");
							            }
		                            }
	                            }
	                        }
	                    }
	                    
	                    else
	                    {
	                    	printf("\nMovimiento no valido, sin movimientos posibles\n");
						}
				    }
				
				    else
				    {
					    printf("\nNo puedes seleccionar este pieza, selecciona una pieza valida\n");
				    }
	            
	            }
			
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
	        
	            else
	            {
	        	    printf("\n\nNo puede seleccionar este pieza, selecciona una pieza valida\n");
			    }
			
		    }while(ajedrez[fichaFila][fichaCol] == 24 || ajedrez[fichaFila][fichaCol] == 14 || ajedrez[fichaFila][fichaCol] == 11 || ajedrez[fichaFila][fichaCol] == 22 ||
			       ajedrez[fichaFila][fichaCol] == 13 || ajedrez[fichaFila][fichaCol] == 23 || ajedrez[fichaFila][fichaCol] == 12 || ajedrez[fichaFila][fichaCol] == 21 ||
				   ajedrez[fichaFila][fichaCol] == 15 || ajedrez[fichaFila][fichaCol] == 25 || ajedrez[fichaFila][fichaCol] == 16 || ajedrez[fichaFila][fichaCol] == 26);
		
		    break;
	    }
	}
	
	turnos++;
	
}while(partida != true);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ganador(int **, int, int, int);
void ganador(int **ajedrez, int a, int moverFila, int moverCol)
{
	int i, j, jugador;
	
	// VERIFICAMOS QUIEN ES EL GANADOR
	if(ajedrez[moverFila][moverCol] == 16)
	{
		jugador = 2;
	}
	
	if(ajedrez[moverFila][moverCol] == 26)
	{
		jugador = 1;
	}
	
	printf("\n\nEl ganador es el jugador: %i", jugador);
	printf("\n\nFelicidades, Ganaste\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int i;
	
	// ASIGNAMOS O RESERVAMOS ESPACIO DE MEMORIA DE LA MATRIZ
	ajedrez = (int **) calloc(8, sizeof(int *));
	for(i = 0; i < 8; i++)
	{
		ajedrez[i] = (int *) calloc(8, sizeof(int));
	}
	
	
	tablero(ajedrez, 8);
	turnoJugador(ajedrez, 8);
	
	
	// LIBERAMOS ESPACIO DE MEMORIA DE LA MATRIZ
	for(i = 0; i < 8; i++)
	{
		free(ajedrez[i]);
	}
	
	free(ajedrez);
	
	getch();
	return 0; 
} 
