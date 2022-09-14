#include "Alfil.h"
#include <string>
#include <iostream>

using namespace std;

Alfil::Alfil(string etiqueta, int contador, string color, int x, int y) : Pieza(etiqueta,contador,color,x,y){
}

bool Alfil::validarMovimiento(int x, int y, Pieza* Tablero[][8]){
        int a=getX();
        int b=getY();
        
        //Verificacion de que el movimiento este en las diagonales
        if(abs(x-a)==abs(y-b)){
            //Caso 0: El movimiento esta en la misma casilla de la pieza
            if (a==x && b==y)
            return false;
            //Caso 1: El movimiento esta en el cuadrante 1
            else if(x > a && y > b){
            for(int i = a+1; i <= x; i++){
                a++;
                b++;
                if(Tablero[b][a]){
                if (a==x && b==y && Tablero[b][a]->getColor()!=getColor()){
                    setX(x);
                    setY(y);
                    return true;
                }
                else {
                    return false;
                }
                }
            }  
            setX(x);
            setY(y); 
            return true;
            }
            //Caso 2: El movimiento esta en el cuadrante 2
            else if(x < a && y > b){
            for(int i = a-1; i >= x; i--){
                a--;
                b++;
                if(Tablero[b][a]){
                if (a==x && b==y && Tablero[b][a]->getColor()!=getColor()){
                    setX(x);
                    setY(y);
                    return true;
                }
                else {
                    return false;
                }
                }
            }   
            setX(x);
            setY(y);
            return true;
            }
            //Caso 3: El movimiento esta en el cuadrante 3  
            else if(x < a && y < b){
            for(int i = a-1; i >= x; i--){
                a--;
                b--;
                if(Tablero[b][a]){
                if (a==x && b==y && Tablero[b][a]->getColor()!=getColor()){
                    setX(x);
                    setY(y);
                    return true;
                }
                else {
                    return false;
                }
                }
            }   
            setX(x);
            setY(y);
            return true;
            }
            //Caso 4: El movimiento esta en el cuadrante 4
            else if(x > a && y < b){
            for(int i = a+1; i <= x; i++){
                a++;
                b--;
                if(Tablero[b][a]){
                if (a==x && b==y && Tablero[b][a]->getColor()!=getColor()){
                    setX(x);
                    setY(y);
                    return true;
                }       
                else{ 
                    return false;
                }
                }
            } 
            setX(x);
            setY(y);  
            return true;
            }
            
        }
        return false; 
        
}

string Alfil::imprime(){
    if (getColor()=="Negras"){
        return RED "A";
    } 
    else{
        return "A";
    }     
}