    #include "mbed.h"
    #include "iostream"
    #include <algorithm>
    #include <cmath>
    #include <cmath>
    #include <ostream>
    using namespace std;
    #define BLINKING_RATE     100ms


    DigitalOut arregloCol [3] ={D6,D7,D8};
    DigitalIn arregloFil [4] = {D2,D3,D4,D5};
    UnbufferedSerial Serial (USBTX, USBRX,9600);
    int teclado [4][3] ={{1,2,3},{4,5,6},{7,8,9},{0,0,0}};
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);
    // main() runs in its own thread in the OS

    int main()
    {
        int xFuncion = -1, yFuncion = -1;
        //cout<<"hola"<<endl;
        while (true) {
            bool validadorPrincipal = true;
            cout<<"Selecione la funcion deseada con 1, 2 o 3"<<endl;
            while(validadorPrincipal){
                for(int i =0; i<3; i++){
                    arregloCol[i] =0;
                    for(int j = 0; j<4;j++){
                        if(!arregloFil[j]){
                            xFuncion = i;
                            yFuncion = j;
                            validadorPrincipal=false;
                            while(!arregloFil[j]);
                            break;
                        }
                    }
                    arregloCol[i] =1;
                }
            }
            if(xFuncion == 0 && yFuncion == 0){
                cout<<"Primer funcion"<<endl;
                double x1 =0,y1=0,x2=0,y2=0;
                int counter =0;

                cout<<"Ingrese la coordenada X del primer punto "<<endl;
                bool validador= true;
                while(validador){
                    for(int i =0; i<3; i++){
                    arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                x1 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador  = false;
                                    break;
                                }   
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                counter=0;
                validador = true;
                cout<<"La coordenada X1 ingresada es "<<x1<<endl;
                cout<<"Ingrese la coordenada Y del primer punto "<<endl;
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                y1 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador = false;
                                    break;  
                                }
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                validador=true;
                counter = 0;
                cout<<"La coordenada de Y1 ingresada es "<<y1<<endl;
                cout<<"Ingrese la coordenada X del segundo punto "<<endl;
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                x2 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador  = false;
                                    break;
                                } 
                            }
                        }
                        arregloCol[i] =1;   
                    }
                }
                validador = true;
                counter =0;
                cout<<"La coordenada de X2 ingresada es "<<x2<<endl;
                cout<<"Ingrese la coordenada Y del segundo punto "<<endl;
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                y2 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador = false;
                                    break;  
                                }
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                cout<<"La coordenada de Y2 ingresada es "<<y2<<endl;
                if(x1 ==x2 && y1 ==y2){
                    cout<<"Los puntos son iguales la pendiente es indefinida"<<endl;
                }else if(x2-x1 == 0){
                    cout<<"La pendiente e indefinida por division entre cero"<<endl;
                }else{
                    double pendiente = (y2-y1)/(x2-x1);
                    double interceptoY = y1-pendiente*x1;
                    cout<<"La pendiente es "<<pendiente<<endl;
                    cout<<"El intercepto con el eje Y es "<<interceptoY<<endl;
                }
                xFuncion = -1;
                yFuncion = -1;
            }else if(xFuncion == 1 && yFuncion ==0){
                cout<<"Segunda funcion"<<endl;
                double n =0;
                double temp =0;
                double suma =0.0;
                double sumaCuadrados = 0.0;
                bool validador = true;
                int counter =0;
                cout<<"Ingrese la cantidad de temperaturas"<<endl;
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                n = n + teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador = false;
                                    break;  
                                }
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                cout<<n<<endl;
                validador=true;
                counter=0;
                for(int u = 0; u<n;u++){
                    temp=0;
                    cout<<"Ingrese la temperatura "<<u<<" :"<<endl;
                    while(validador){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    temp += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validador = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    cout<<"La temperatura ingresada es "<<temp<<endl;
                    validador=true;
                    counter=0;
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
                cout<<"Tercera funcion"<<endl;
                int validador = 1;
                while (validador == 1) {
                    int frecuenciaR;
                    int frecuenciaG;
                    int frecuenciaB;
                    int counter = 0;
                    int R = 0;
                    int G = 0;
                    int B = 0;
                    bool validadorRGB = true;
                    cout<<"Ingrese el valor (entre 0 y 255) para el rojo"<<endl;
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    R += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validadorRGB = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    cout<<"Valor ingresado para el rojo: "<<R<<endl;
                    counter = 0;
                    validadorRGB = true;
                    cout<<"Ingrese el valor (entre 0 y 255) para el verde"<<endl;
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    G += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validadorRGB = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    cout<<"Valor ingresado para el verde: "<<G<<endl;
                    counter = 0;
                    validadorRGB = true;
                    cout<<"Ingrese el valor (entre 0 y 255) para el azul"<<endl;
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    B += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validadorRGB = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    cout<<"Valor ingresado para el azul: "<<B<<endl;
                    validadorRGB = true;
                    frecuenciaR = 1-R/255;
                    frecuenciaG = 1-G/255;
                    frecuenciaB = 1-B/255;
                    ledR.write(frecuenciaR);
                    ledG.write(frecuenciaG);
                    ledB.write(frecuenciaB);
                    ThisThread::sleep_for(BLINKING_RATE);
                    cout<<"Desea otro color (0 para salir, 1 para continuar)"<<endl;
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    if(i == 0 && j == 0){
                                        validador = 1;
                                        validadorRGB = false;
                                        break;  
                                    }else if(i == 1 && j == 3){
                                        validador = 0;
                                        validadorRGB = false;
                                        break;
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                }
                xFuncion = -1;
                yFuncion = -1;
            }
        }
    
    }

