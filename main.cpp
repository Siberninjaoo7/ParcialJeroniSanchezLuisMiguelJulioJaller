#include "mbed.h"
#include "iostream"
#include <algorithm>
#include <cmath>
using namespace std;
#define BLINKING_RATE     100ms


DigitalOut arregloCol [3] ={D6,D7,D8};
DigitalIn arregloFil [4] = {D2,D3,D4,D5};
UnbufferedSerial Serial (USBTX, USBRX,9600);
int teclado [4][3] ={1,2,3,4,5,6,7,8,9,0,0,0};
PwmOut ledR(LED1);
PwmOut ledG(LED2);
PwmOut ledB(LED3);
// main() runs in its own thread in the OS

int main()
{
    int xFuncion = -1, yFuncion = -1;
    //cout<<"hola"<<endl;
    while (true) {

 for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    xFuncion = i;
                    yFuncion = j;
                    break;
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
     }
      if(xFuncion == 0 && yFuncion == 0){
        cout<<"Primer funcion"<<endl;
        double x1,y1,x2,y2;
        
        cout<<"Ingrese la coordenadas del primer punto"<<endl;
        for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    x1 = teclado[i][j];
                    break;
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
         
     }
     for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    y1 = teclado[i][j];
                    break;
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
     }
       cout<<"Ingrese la coordenadas del segundo punto"<<endl;
        for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    x2 = teclado[i][j];
                    break;
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
         
     }
     for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    y2 = teclado[i][j];
                    break;
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
     }
     
    if(x1 ==x2 && y1 ==y2){
        cout<<"los puntos son iguales la pendiente es indefinida"<<endl;
    }else if(x2-x1 == 0){
        cout<<"la pendiente e indefinida por division entre cero"<<endl;
    }else{
        double pendiente = (y2-y1)/(x2-x1);
        double interceptoY = y1-pendiente*x1;
        cout<<"La pendiente es "<<pendiente<<endl;
        cout<<"El intercepto con el eje Y es"<<interceptoY<<endl;
    }

xFuncion = -1;
yFuncion = -1;
    }else if(xFuncion == 1 && yFuncion ==0){
        cout<<"Segunda funcion"<<endl;
        int n;
       double temp;
       double suma =0.0;
       double sumaCuadrados = 0.0;
       cout<<"Ingrese la cantidad de temperaturas"<<endl;
        for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    n = teclado[i][j];
                    break;
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
     }
     for(int u = 0; u<n;u++){
         cout<<"Ingrese la temperatura"<<endl;
          for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    temp = teclado[i][j];
                    break;
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
     }
     suma += temp;
     sumaCuadrados += temp*temp;
     }
    double promedio = suma/n;
    double desviacionStandar = sqrt((sumaCuadrados/n)-promedio*promedio);

    cout<<"El promedio de las temperaturas es "<< promedio<<endl;
    cout<<"La desviacion estandar es "<< desviacionStandar<<endl;
    xFuncion = -1;
    yFuncion = -1;
    }else if (xFuncion == 2 && yFuncion == 0){
        cout<<"tercera funcion"<<endl;
        int validador =1;

        while (validador == 1) {
            string NumeroRGB;
            cout<<("Ingrese el codigo hexaceimal deseado: ");
            int frecuenciaR;
            int frecuenciaG;
            int frecuenciaB;
            int count = 0;
            int countR = 0;
            int countG = 0;
            int countB = 0;
            int R = 0;
            int G = 0;
            int B = 0;
        for(int i =0; i<3; i++){
         arregloCol[i] =0;
         for(int j = 0; j<4;j++){
            
                if(!arregloFil[j]){
                    if(count == 0){
                        R = R+teclado[i][j]*10^countR;
                        countR ++;
                        if(countR == 3){
                            count++;
                        }
                    }else if(count == 1){
                        G = G+teclado[i][j]*10^countG;
                        countG ++;
                        if(countG == 3){
                            count++;
                        }
                    }else if(count == 2){
                        B = B+teclado[i][j]*10^countB;
                        countB ++;
                        if(countB == 3){
                            count++;
                        }
                    }else{
                        break;
                    }
                   // while(!arregloFil[j]);
                }
         }
         arregloCol[i] =1;
     }
            frecuenciaR = R/255;
            frecuenciaG = G/255;
            frecuenciaB = B/255;
            ledR.write(frecuenciaR);
            ledG.write(frecuenciaG);
            ledB.write(frecuenciaB);
            ThisThread::sleep_for(BLINKING_RATE);
            cout<<"Desea otro color(0 para salir),(1 para continuar)";
            cin>>validador;
        }
        xFuncion = -1;
        yFuncion = -1;
        }
    }
   
}

