#include "Alfil.h"
#include "Caballo.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"
#include "Peon.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#define NC "\e[0m"
/*COSAS QUE FALTAN
-Implementar coronar
-*/
using namespace std;

string cambiar(string &turno) {
  if (turno == "Blancas") {
    turno = "Negras";
  } else {
    turno = "Blancas";
  }
  return turno;
}

int cambiarLetra(char &letra) { return letra - 97; }

int cambiarNumero(char &numero) { return 7 - (numero - 49); }

void coronar(int &xAct, int &yAct, int &x, int &y, Pieza *tablero[][8]) {
  int opPeon;

  if (tablero[y][x]->getColor() == "Blancas" && y==0) {
    cout << "Elija una pieza:" << endl;
    cout << "\t1. Reina" << endl;
    cout << "\t2. Torre" << endl;
    cout << "\t3. Alfil" << endl;
    cout << "\t4. Caballo" << endl;
    cin >> opPeon;
    do {
      switch (opPeon) {
      case 1:
        delete tablero[y][x];
        tablero[y][x] = new Reina("Reina", 0, "Blancas", x, y);
        break;

      case 2:
        delete tablero[y][x];
        tablero[y][x] = new Torre("Torre", 0, "Blancas", x, y);
        break;

      case 3:
        delete tablero[y][x];
        tablero[y][x] = new Alfil("Alfil", 0, "Blancas", x, y);
        break;

      case 4:
        delete tablero[y][x];
        tablero[y][x] = new Caballo("Caballo", 0, "Blancas", x, y);
        break;

      default:
        break;
      }
    } while (opPeon != 1 && opPeon != 2 && opPeon != 3 && opPeon != 4);
  } 
  else if (tablero[y][x]->getColor() == "Negras" && y==7) {
    cout << "Elija una pieza:" << endl;
    cout << "\t1. Reina" << endl;
    cout << "\t2. Torre" << endl;
    cout << "\t3. Alfil" << endl;
    cout << "\t4. Caballo" << endl;
    cin >> opPeon;
    do {
      switch (opPeon) {
      case 1:
        delete tablero[y][x];
        tablero[y][x] = new Reina("Reina", 0, "Negras", x, y);
        break;

      case 2:
        delete tablero[y][x];
        tablero[y][x] = new Torre("Torre", 0, "Negras", x, y);
        break;

      case 3:
        delete tablero[y][x];
        tablero[y][x] = new Alfil("Alfil", 0, "Negras", x, y);
        break;

      case 4:
        delete tablero[y][x];
        tablero[y][x] = new Caballo("Caballo", 0, "Negras", x, y);
        break;

      default:
        break;
      }
    } while (opPeon != 1 && opPeon != 2 && opPeon != 3 && opPeon != 4);
  }
}

void comidaPaso(int &xAct, int &yAct, int &x, int &y, Pieza *tablero[][8]) {
  tablero[y][x] = tablero[yAct][xAct];
  tablero[yAct][xAct] = NULL;
  if (tablero[y][x]->getColor() == "Blancas") {
    delete tablero[y + 1][x];
    tablero[y + 1][x] = NULL;
  } else {
    delete tablero[y - 1][x];
    tablero[y - 1][x] = NULL;
  }
}

bool comidaPrueba(int &xAct, int &yAct, int &x, int &y, string pRey, Pieza *tableroCopia[][8]){
  tableroCopia[y][x] = tableroCopia[yAct][xAct];
  tableroCopia[yAct][xAct] = NULL;
  if (tableroCopia[y][x]->getColor() == "Blancas") {
    delete tableroCopia[y + 1][x];
    tableroCopia[y + 1][x] = NULL;
  } else {
    delete tableroCopia[y - 1][x];
    tableroCopia[y - 1][x] = NULL;
  }

  for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (tableroCopia[i][j] == NULL) {
          cout << NC "[ ]";

        } else {
          cout << NC "[" << tableroCopia[i][j]->imprime() << NC "]";
        }

        if (j == 7) {
          cout << " " << 8 - i << endl;
        }
      }
    } 
  
  if (Rey* ptrRey = dynamic_cast<Rey *>(tableroCopia[cambiarNumero(pRey[1])][cambiarLetra(pRey[0])])) { 
    return ptrRey->esta_En_Jaque(cambiarLetra(pRey[0]), cambiarNumero(pRey[1]), tableroCopia);
  }
}

void enroqueCorto(int &xAct, int &yAct, Pieza *tablero[][8]) {
  // Mover al rey
  tablero[yAct][6] = tablero[yAct][xAct];
  tablero[yAct][xAct] = NULL;
  // Mover a la torre
  tablero[yAct][5] = tablero[yAct][7];
  tablero[yAct][7] = NULL;
}

void enroqueLargo(int &xAct, int &yAct, Pieza *tablero[][8]) {
  // Mover al rey
  tablero[yAct][2] = tablero[yAct][xAct];
  tablero[yAct][xAct] = NULL;
  // Mover a la torre
  tablero[yAct][3] = tablero[yAct][0];
  tablero[yAct][0] = NULL;
}

void cambioPosicion(int &xAct, int &yAct, int &x, int &y, Pieza *tablero[][8]) {
  delete tablero[y][x];
  tablero[y][x] = NULL;
  tablero[y][x] = tablero[yAct][xAct];
  tablero[yAct][xAct] = NULL;
}

bool cambioPrueba(int &xAct, int &yAct, int &x, int &y, string pRey, Pieza *tableroCopia[][8]) {
  delete tableroCopia[y][x];
  tableroCopia[y][x] = NULL;
  tableroCopia[y][x] = tableroCopia[yAct][xAct];
  tableroCopia[yAct][xAct] = NULL;
  // Rey en jaque = true & Rey no en jaque = false;
  if (Rey* ptrRey = dynamic_cast<Rey *>(tableroCopia[cambiarNumero(pRey[1])][cambiarLetra(pRey[0])])) { 
    return ptrRey->esta_En_Jaque(cambiarLetra(pRey[0]), cambiarNumero(pRey[1]), tableroCopia);
  }
  //return 0; 
}

int main() {
  system("color 07");
  Pieza *tablero[8][8], *tableroCopia[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tablero[i][j] = NULL;
    }
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tableroCopia[i][j] = NULL;
    }
  }
  //-------------------------BLANCAS------------------------
  tablero[7][4] = new Rey("Rey", 0, "Blancas", 4, 7);
  tablero[7][3] =new Reina("Reina", 0, "Blancas", 3, 7);
  tablero[7][1] =new Caballo("Caballo", 0, "Blancas", 1, 7);
  tablero[7][6] =new Caballo("Caballo", 0, "Blancas", 6, 7);
  tablero[7][2] =new Alfil("Alfil", 0, "Blancas", 2, 7);
  tablero[7][5] =new Alfil("Alfil", 0, "Blancas", 5, 7);
  tablero[7][0] = new Torre("Torre", 0, "Blancas", 0, 7);
  tablero[7][7] = new Torre("Torre", 0, "Blancas", 7, 7);
  tablero[6][0] = new Peon("Peon", 0, "Blancas", 0, 6, false);
  tablero[6][1] = new Peon("Peon", 0, "Blancas", 1, 6, false);
  tablero[6][2] = new Peon("Peon", 0, "Blancas", 2, 6, false);
  tablero[6][3] = new Peon("Peon", 0, "Blancas", 3, 6, false);
  tablero[6][4] = new Peon("Peon", 0, "Blancas", 4, 6, false);
  tablero[6][5] = new Peon("Peon", 0, "Blancas", 5, 6, false);
  tablero[6][6] = new Peon("Peon", 0, "Blancas", 6, 6, false);
  tablero[6][7] = new Peon("Peon", 0, "Blancas", 6, 1, false);

  //-------------------------NEGRAS------------------------
  tablero[0][4] = new Rey("Rey", 0, "Negras", 4, 0);
  tablero[0][3]=new Reina("Reina", 0, "Negras", 3, 0);
  tablero[0][1]=new Caballo("Caballo", 0, "Negras", 1, 0);
  tablero[0][6]=new Caballo("Caballo", 0, "Negras", 6, 0);
  tablero[0][2]=new Alfil("Alfil", 0, "Negras", 2, 0);
  tablero[0][5]=new Alfil("Alfil", 0, "Negras", 5, 0);
  tablero[0][0] = new Torre("Torre", 0, "Negras", 0, 0);
  tablero[0][7] = new Torre("Torre", 0, "Negras", 7, 0);
  tablero[1][0] = new Peon("Peon", 0, "Negras", 0, 1, false);
  tablero[1][1] = new Peon("Peon", 0, "Negras", 1, 1, false);
  tablero[1][2] = new Peon("Peon", 0, "Negras", 2, 1, false);
  tablero[1][3] = new Peon("Peon", 0, "Negras", 3, 1, false);
  tablero[1][4] = new Peon("Peon", 0, "Negras", 4, 1, false);
  tablero[1][5] = new Peon("Peon", 0, "Negras", 5, 1, false);
  tablero[1][6] = new Peon("Peon", 0, "Negras", 6, 1, false);
  tablero[1][7] = new Peon("Peon", 0, "Negras", 7, 1, false);

  cout << "----------------------------" << endl;
  cout << "|        BIENVENIDO        |" << endl;
  cout << "----------------------------" << endl;
  cout << "Comencemos..." << endl;

  bool camPrueba,
       vcp;
  double opcion;
  int opRey, 
      xAct, 
      yAct, 
      x, 
      y;
  string acepta, 
         turno = "Blancas", 
         pieza, 
         posicion, 
         ReyBlanco ="e1",
         ReyNegro = "e8", 
         desetPeon="";
  Pieza *valPieza;

  do {
    // imprime tablero
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (tablero[i][j] == NULL) {
          cout << NC "[ ]";

        } else {
          cout << NC "[" << tablero[i][j]->imprime() << NC "]";
        }

        if (j == 7) {
          cout << " " << 8 - i << endl;
        }
      }
    }
    //actualizar tablero copia
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        tableroCopia[i][j] = NULL;
      }
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if(!tablero[i][j]){
          delete tableroCopia[i][j];
          tableroCopia[i][j]=NULL;
        } else{
            delete tableroCopia[i][j];
            tableroCopia[i][j] = NULL;
            if (tablero[i][j]->getEtiqueta() == "Torre") {
                tableroCopia[i][j] = new Torre(tablero[i][j]->getEtiqueta(),tablero[i][j]->getContador(), tablero[i][j]->getColor(), tablero[i][j]->getX(), tablero[i][j]->getY());
            } 
            else if (tablero[i][j]->getEtiqueta() == "Alfil") {
                tableroCopia[i][j] = new Alfil(tablero[i][j]->getEtiqueta(), tablero[i][j]->getContador(), tablero[i][j]->getColor(), tablero[i][j]->getX(), tablero[i][j]->getY());
            } 
            else if (tablero[i][j]->getEtiqueta() == "Reina") {
                tableroCopia[i][j] = new Reina(tablero[i][j]->getEtiqueta(), tablero[i][j]->getContador(), tablero[i][j]->getColor(), tablero[i][j]->getX(), tablero[i][j]->getY());
            } 
            else if (tablero[i][j]->getEtiqueta() == "Rey") {
                tableroCopia[i][j] = new Rey(tablero[i][j]->getEtiqueta(), tablero[i][j]->getContador(), tablero[i][j]->getColor(), tablero[i][j]->getX(), tablero[i][j]->getY());
            } 
            else if (tablero[i][j]->getEtiqueta() == "Caballo") {
                tableroCopia[i][j] = new Caballo(tablero[i][j]->getEtiqueta(), tablero[i][j]->getContador(), tablero[i][j]->getColor(), tablero[i][j]->getX(), tablero[i][j]->getY());
            } 
            else if (Peon *ptrPeon =dynamic_cast<Peon *>(tablero[i][j])) {
                tableroCopia[i][j] = new Peon(ptrPeon->getEtiqueta(),ptrPeon->getContador(), ptrPeon->getColor(), ptrPeon->getX(), ptrPeon->getY(), ptrPeon->getAvanceDoble());
            }
        }  
      }
    }
    cout << NC " a  b  c  d  e  f  g  h" << endl;
    cout << "Turno " << turno << endl;
    cout << "\t1. Rendirse" << endl;
    cout << "\t2. Ofrecer tablas" << endl;
    cout << "\t3. Mover pieza" << endl;
    cin >> opcion;
    if(opcion ==(int)opcion){
    switch ((int)opcion) {
    case 1:
      cout << "Felicidades " << cambiar(turno) << ", has ganado" << endl;
      break;

    case 2:
      cout << "El otro jugador acepta el empate? (si/no)" << endl;
      cin >> acepta;
      while (true) {
        try {
          if (acepta != "no" && acepta != "si") {
            throw "Opcion no valida";
          } else if (acepta == "si") {
            opcion = 1;
            cout << "Es un empate" << endl;
          } else {
            cambiar(turno);
          }

          break;
        } catch (const char *msg) {
          cerr << msg << endl;
          cout << "Ingresa otra opcion: ";
          cin >> acepta;
        }
      }
      break;

    case 3:
      cout << "Pieza a mover (ingrese la posicion, ejemplo \"d3\"): ";
      cin >> pieza;
      while (true) {
        xAct = cambiarLetra(pieza[0]);
        yAct = cambiarNumero(pieza[1]);
        try {
          if (xAct < 0 || xAct > 7 || pieza.length() != 2) {
            throw "Posicion no valida";
          } else if (yAct < 0 || yAct > 7 || pieza.length() != 2) {
            throw "Posicion no valida";
          } else if (tablero[yAct][xAct] == NULL) {
            throw "No se encuentra alguna pieza en esta posicion";
          } else if (tablero[yAct][xAct]->getColor() != turno) {
            throw "No corresponde a su color";
          }
          valPieza = tablero[yAct][xAct];
          if (Rey *ptrRey =dynamic_cast<Rey *>(tablero[yAct][xAct])) {
            while (true) {
              cout << "\t1. Enroque largo" << endl;
              cout << "\t2. Enroque corto" << endl;
              cout << "\t3. Mover" << endl;
              cin >> opRey;
                if (opRey == 1 || opRey == 2) {
                  if (opRey == 1 && ptrRey->validarEnroque("Largo", tablero)) {
                    // funcion que hace el cambio a enroque largo
                    enroqueLargo(xAct, yAct, tablero);
                    break;
                  } else if (opRey ==
                             2 && ptrRey->validarEnroque("Corto", tablero)) {
                    // funcion que hace el cambio a enroque corto
                    enroqueCorto(xAct, yAct, tablero);
                    break;
                  } else {
                    cout << "Elija otra opcion" << endl;
                    continue;
                  }
                } else if (opRey == 3) {
                  break;
                } else {
                  cout << "Opcion incorrecta" << endl;
                }
              }
          }
          break;
        } catch (const char *msg) {
          cerr << msg << endl;
          cout << "Ingresa otra posicion: ";
          cin >> pieza;
        }
      }
      // Esto nos ayuda en caso de que se haga un enroque para que el usuario no
      // ingrese otra posicion
      if (opRey == 1 || opRey == 2) {
        opRey = 0;
        cambiar(turno);
        continue;
      }

      cout << "A donde la quieres mover: ";
      cin >> posicion;
        x = cambiarLetra(posicion[0]);
        y = cambiarNumero(posicion[1]);
        try {
          if (x < 0 || x > 7 || posicion.length() != 2) {
            throw "Posicion no valida";
          } else if (y < 0 || y > 7 || posicion.length() != 2) {
            throw "Posicion no valida";
          } else if(Peon *ptrPeon = dynamic_cast<Peon *>(tablero[yAct][xAct])){
              vcp=ptrPeon->validarComidaPaso(x,y,tablero);
              if (!vcp && !ptrPeon->validarMovimiento(x, y, tablero)) {
              throw "Movimiento no valido";
            } 
          }else if(!valPieza->validarMovimiento(x, y, tablero) && valPieza->getEtiqueta()!="Peon"){
            throw "Movimiento no valido";
          }
          if (Peon *ptrPeon =dynamic_cast<Peon *>(tablero[yAct][xAct])){

            if (vcp && turno=="Blancas"){
              camPrueba=comidaPrueba(xAct, yAct, x, y, ReyBlanco, tableroCopia);
              cout<<camPrueba<<endl;
              if(camPrueba){
                //break;
              }
              else{
                comidaPaso(xAct, yAct, x, y, tablero);
                //break;
              }
            }
            else if (vcp && turno=="Negras"){
              camPrueba=comidaPrueba(xAct, yAct, x, y, ReyNegro, tableroCopia);
              cout<<camPrueba<<endl;
              if(camPrueba){
                //break;
              }
              else{
                comidaPaso(xAct, yAct, x, y, tablero);
                //break;
              } 
            }
          }else{
            if(turno=="Blancas"){
                camPrueba=cambioPrueba(xAct, yAct, x, y, ReyBlanco, tableroCopia);
                if(camPrueba){
                 // break;
                }
            }else{
                camPrueba=cambioPrueba(xAct, yAct, x, y, ReyNegro, tableroCopia);
                if(camPrueba){
                 // break;
                }
            }
          }

          if (valPieza->getEtiqueta()=="Rey" && valPieza->getColor()=="Blancas"){
            cout<<"camboReyB"<<endl;
            ReyBlanco=posicion;
          }
          else if (valPieza->getEtiqueta()=="Rey" && valPieza->getColor()=="Negras"){ 
            ReyNegro=posicion;
          }
          
          cambioPosicion(xAct, yAct, x, y, tablero);
          
          if(desetPeon!=""){
            if (Peon* ptrPeon =dynamic_cast<Peon *>( tablero[cambiarNumero(desetPeon[1])][cambiarLetra(desetPeon[0])])){
              ptrPeon->setAvanceNormal();
            }
            }
            desetPeon="";
          if (Peon* ptrPeon =dynamic_cast<Peon *>( tablero[y][x])){
            if (ptrPeon->getAvanceDoble()){
              desetPeon=posicion;
              }
            }
          if(valPieza->getEtiqueta()=="Peon" && y==0 || y==7){
            coronar(xAct, yAct, x, y, tablero);
          }

        //  break;
        } catch (const char *msg) {
          cerr << msg << endl;
          //cout << "Ingresa otra posicion: ";
          //cin >> posicion;
          continue;
        }
      
      if(camPrueba){
        cout<<"Tu rey esta en jaque... Intente de nuevo"<<endl;
        tablero[yAct][xAct]->setX(xAct);
        tablero[yAct][xAct]->setY(yAct);
        continue;
      }
      break;

    default:
      cout << "Intente de nuevo..." << endl;
      break;
    }
    }else{
      cout<<"Intente de nuevo..."<<endl;
    }
    cambiar(turno);
  } while (opcion != 1);
}

//Finished