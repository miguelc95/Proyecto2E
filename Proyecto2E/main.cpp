//Autores: Jose Carmelo Ramirez Beltran A01175987 y Miguel Cuellar A01280736
//Fecha: 20/04/2016
//Programa: 2D - Sparko's Birthday
//Clase: Algoritmos


#include <iostream>
#include <cmath>
using namespace std;
//Matriz para calcular los errores;
int iMat[100][100][100],  iArrDiam[5000];;

//Funcion para sacar la matriz inicial. Es usada para calcular las siguientes matrices
void matrizInicial(int iPlatos, int iPerros)
{
    int iDif, j, iCont, iSum=1, iAux;
    
    iDif = (iPlatos - iPerros*3) + 1;
    //Calculamos la diagonal principal
    for(int i=1; i<= iDif; i++)
    {
        iMat[i][i+2][1] = pow((iArrDiam[i-1]-iArrDiam[i]),2);
    }
    
    //Calculamos el resto de la matriz
    iAux = 3;
    for(int i=1; i<=iDif-1; i++)
    {
        for(int j=1; j<= iDif-i; j++)
        {
            iMat[j][j+iAux][1] = min((iMat[j][(j+iAux)-1][1]), (iMat[j+1][j+iAux][1]));
        }
        iAux++;
    }
    
}

void llenarMatriz(int iPlatos, int iPerros)
{
    int iDif, iCont, iSum=1, iAux, iError;
    
    //Diferencia entre el numero de platos y perros
    iDif = (iPlatos - iPerros*3) + 1;
    //Auxiliar para ayudar a calcular
    iAux=(iPerros*3)-1;
    
    for(int j=1; j<= iDif; j++)
    {
        iMat[j][j+iAux][iPerros] = iMat[j][j+2][1] + iMat[j+2][j+iAux][iPerros-1];
    }
    //Calculamos el resto de la matriz
    iAux = iPerros*3;
    for(int i=1; i<=iDif-1; i++)
    {
        for(int j=1; j<= iDif-i; j++)
        {
            iError=  min(iMat[j+1][j+iAux][iPerros], (iMat[j][j+2][1] + iMat[j+2][j+iAux][iPerros-1]));
            iMat[j][j+iAux][iPerros] = min(iMat[j][(j+iAux)-1][iPerros],iError);
        }
        iAux++;
    }
}


int main()
{
    int iPerros, iPlatos, iCont=2;
    
    cin>>iPerros>>iPlatos;
    
    //Ingresamos los valos de los diametros de los platos
    for(int i=0; i<iPlatos; i++)
        cin>>iArrDiam[i];
    
    matrizInicial(iPlatos, 1);
    //Numero de matrizes a calcular
    if(iPerros > 1)
    {
        while(iCont<=iPerros)
        {
            llenarMatriz(iPlatos, iCont);
            iCont++;
        }
    }
    
    cout<<iMat[1][iPlatos][iPerros]<<endl;
    return 0;
}