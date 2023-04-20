#include "param.h"

//Создание массива
int** createField(){
    int** array=new int*[FIELD_SIZE];
    for (int i=0;i<FIELD_SIZE;i++){
        array[i]=new int[FIELD_SIZE];
    }
    return array;
}
// первоначальное заполнение поля
void Board(int**& array){
    
    for (int i=0; i<FIELD_SIZE; i++) {
        for (int j=0; j<FIELD_SIZE; j++){
            array[i][j]=EMPTY;
            }
    }
}

//Вывод поля в консоль
void showField(int** array){
    
    for (int i=0;i<2;i++){
        cout<<endl;
    }
    cout<<"    ";
    for (int i=0;i<FIELD_SIZE;i++){
        if (i>8) cout<<i+1<<" ";
        else  cout<<i+1<<"  ";
       
    }
    cout<<endl<<endl;
    for (int i=0; i<FIELD_SIZE; i++) {
        for (int j=0; j<FIELD_SIZE; j++){
            if (j==0){
                if (i>8){
                    cout<< i+1<<"  ";
                }
                else {
                    cout<< i+1<<"   ";
                }
            }
            if (j>8){
                cout<<array[i][j]<<"  ";
            }
            else {
                cout<<array[i][j]<<"  ";
            }
            }
        cout<<endl<<endl;
    }
    for (int i=0;i<2;i++){
        cout<<endl;
    }
}

bool validMove(int**& array,int x, int y){
    if (array[y][x]==EMPTY) return true;
    
    else return false;
}

void makeMove(int**& array,int x, int y, int color){
    array[y][x]=color;
}




int main() {
    
    int** field=createField();
    Board(field);
    showField(field);
    int x=0, y=0;
    
    
        
    
    
    
    
    return 0;
}
