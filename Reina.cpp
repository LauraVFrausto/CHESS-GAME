#include "Reina.h"

Reina::Reina(string etiqueta, int contador, string color, int x, int y):Pieza(etiqueta, contador, color, x, y){}

bool Reina::validarMovimiento(int x, int y, Pieza* Tablero[][8]){
    //Movimiento similar a la Torre
    if ((getX()==x && getY()!=y) || (getX()!=x && getY()==y)){
        vector<int> posicionX;
        vector<int> posicionY;
        int a=getX();
        int b=getY();
        
        //Mover Torre en X
        while(a>0){
            if(Tablero[b][a-1]==NULL){
            posicionX.push_back(a-1);
            posicionY.push_back(b);
            a--;
            }
            else{
            break;
            }
            
        }
        //Verificar si hay pieza estorbando 
        if(a!=0){
            if(Tablero[b][a-1]->getColor() != getColor() ){
            posicionX.push_back(a-1);
            posicionY.push_back(b);
            
            }
        }
        
        
        a=getX();

        while(a<7){
            if(Tablero[b][a+1]==NULL){
            posicionX.push_back(a+1);
            posicionY.push_back(b);
            a++;
            }
            else{
            break;
            }
            
        }
        //Verificar si hay pieza estorbando
            if(a!=7){
            if(Tablero[b][a+1]->getColor() != getColor() ){
            posicionX.push_back(a+1);
            posicionY.push_back(b);
            
            }
        }

        

        //Mover Torre en Y
        a=getX();
        while(b>0){
            if(Tablero[b-1][a]==NULL){
            posicionX.push_back(a);
            posicionY.push_back(b-1);
            b--;
            }
            else{
            break;
            }
            
        }
        //Verificar si hay pieza estorbando 
        if(b!=0){
            if(Tablero[b-1][a]->getColor() != getColor() ){
            posicionX.push_back(a);
            posicionY.push_back(b-1);
            
            }
        }
        
        b=getY();

        while(b<7){
            if(Tablero[b+1][a]==NULL){
            posicionX.push_back(a);
            posicionY.push_back(b+1);
            b++;
            }
            else{
            break;
            }
            
        }
        //Verificar si hay pieza estorbando
        if(b!=7){
            if(Tablero[b+1][a]->getColor() != getColor() ){
            posicionX.push_back(a);
            posicionY.push_back(b+1);
            
            }
        }

        
        for (int j=0; j<posicionX.size(); j++){
                if(posicionX[j]==x && posicionY[j]==y){
                    setX(x);
                    setY(y);
                    return true;
                }
            }
        
        return false;
    }

    //Movimiento similar al Alfil
    else{
        //Obtencion de coordenadas de la pieza
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
}

string Reina::imprime(){
    if (getColor()=="Negras"){
        return RED "D";
    } 
    else{
        return "D";
    }     
}