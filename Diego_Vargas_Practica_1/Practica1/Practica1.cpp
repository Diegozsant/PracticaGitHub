// Practica1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>

int main()
{
	char cLetras[30];
	bool bGameOver = true;
	unsigned int iAPos(0);
	unsigned int iEPos(29);
	unsigned int iOPosIni(iAPos + 1);
	unsigned int iPuntos(0);

	for (int i = 0; i < 29; i++)
	{
		cLetras[i] = ' ';
	}
	cLetras[iAPos] = 'A';
	cLetras[iEPos] = 'E';

	while (bGameOver)
	{

		system("cls");

		if (GetKeyState('S') & 0x8000)
		{
			if (iOPosIni == iAPos + 1)
			{
				cLetras[iOPosIni] = 'o';
			}

		}

		if (cLetras[iOPosIni] == 'o' && iOPosIni + 1 < 30)
		{
			cLetras[iOPosIni+1] = cLetras[iOPosIni];
			cLetras[iOPosIni] = ' ';
			iOPosIni++;
		}

		if (cLetras[iEPos] == 'E' && iEPos > iAPos)
		{
			cLetras[iEPos - 1] = cLetras[iEPos];
			cLetras[iEPos] = ' ';
			iEPos--;
		}

		if (iOPosIni > iEPos)
		{
			iPuntos++;
			cLetras[iOPosIni - 1] = ' ';
			cLetras[iOPosIni] = ' ';

			if(cLetras[iEPos - 1]!='A')
			{
				cLetras[iEPos - 1] = ' ';
			}
			
			iEPos = 29;
			iOPosIni =	 iAPos + 1;
			cLetras[iEPos] = 'E';
		}



		printf("Dispara con S\n");
		printf("\n");

		for (int i = 0; i < 30; i++)
		{
			printf("%c", cLetras[i]);
		}

		printf("\n");
		printf("\n");
		printf("Puntos: %d \n", iPuntos);
		Sleep(10);

		if (iAPos+1 == iEPos)
		{
			bGameOver = false;
		}



	}
	system("cls");
	printf("Game Over, los puntos obtenidos son: %d", iPuntos);
	printf("\n");
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
