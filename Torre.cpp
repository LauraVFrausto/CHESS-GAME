#include "Torre.h"
Torre::Torre(string etiqueta, int contador, string color, int x, int y) : Pieza(etiqueta,contador,color,x,y){
}

bool Torre::validarMovimiento(int x, int y, Pieza* Tablero[][8]){
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

string Torre::imprime(){
    if (getColor()=="Negras"){
        return RED "T";
    } 
    else{
        return "T";
    }     
}