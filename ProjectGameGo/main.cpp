#include "param.h"

//Создание массива
int** createField() {
    int** array = new int* [FIELD_SIZE];
    for (int i = 0; i < FIELD_SIZE; i++) {
        array[i] = new int[FIELD_SIZE];
    }
    return array;
}
// первоначальное заполнение поля
void Board(int**& array) {

    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            array[i][j] = EMPTY;
        }
    }
}

//Вывод поля в консоль
void showField(int** array) {

    for (int i = 0; i < 2; i++) {
        cout << endl;
    }
    cout << "    ";
    for (int i = 0; i < FIELD_SIZE; i++) {
        if (i > 8) cout << i + 1 << " ";
        else  cout << i + 1 << "  ";

    }
    cout << endl << endl;
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (j == 0) {
                if (i > 8) {
                    cout << i + 1 << "  ";
                }
                else {
                    cout << i + 1 << "   ";
                }
            }
            if (j > 8) {
                cout << array[i][j] << "  ";
            }
            else {
                cout << array[i][j] << "  ";
            }
        }
        cout << endl << endl;
    }
    for (int i = 0; i < 2; i++) {
        cout << endl;
    }
}
//Проверка верности хода
bool validMove(int**& array, int x, int y, int color) {
    if (array[y][x] != EMPTY) return false;
    else{
        array[y][x]=color;
        if (checkCapture(array,x,y,color)){
            array[y][x]=EMPTY;
            return false;
        }
        if (checkCapture(array, x, y, getOppositeColor(color))) {
            array[y][x] = EMPTY;
            return false;
        }
     }
    return true;
}

//Делаем ход
void makeMove(int**& array, int x, int y, int color, int& moveCount) {
    if(validMove(array, x, y, color)){
        array[y][x] = color;
        checkCapture(array,x,y,color);
        moveCount++;
    }
    showField(array);
}
//Проверка конца игры
bool gameOver(int** array, int moveCount) {
    if (moveCount==FIELD_SIZE){
        return true;
    }
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (array[i][j] == EMPTY) {
                if (validMove(array, j, i, BLACK) || validMove(array, j, i, WHITE)){
                    return false;
                }
            }
        }
    }
    return true;
}

// Определение цвета камней
int getStoneColor(int**& array, int x, int y) {

    return array [y][x];
}

// Jпределение противоположного цвета
int getOppositeColor(int color) {
    if (color == BLACK) {
        return WHITE;
    }
    else {
        return BLACK;
    }
}

// Удаление камней при захвате
void removeStones(int**& array, int x, int y, int color) {
    array[y][x] = EMPTY;
    if (x > 0 && array[y][x - 1] == color) {
        removeStones(array, x - 1, y, color);
    }
    if (x < FIELD_SIZE - 1 && array[y][x + 1] == color) {
        removeStones(array, x + 1, y, color);
    }
    if (y > 0 && array[y - 1][x] == color) {
        removeStones(array, x, y - 1, color);
    }
    if (y < FIELD_SIZE - 1 && array[y + 1][x] == color) {
        removeStones(array, x, y + 1, color);
    }
}

// Проверка на захват
bool checkCapture(int**& array, int x, int y, int color) {
    bool isCaptured = false;
    if (x > 0 && array[y][x - 1] == getOppositeColor(color)) {
        isCaptured = isCaptured || checkCaptureHelper(array, x - 1, y, color);
    }
    if (x < FIELD_SIZE - 1 && array[y][x + 1] == getOppositeColor(color)) {
        isCaptured = isCaptured || checkCaptureHelper(array, x + 1, y, color);
    }
    if (y > 0 && array[y - 1][x] == getOppositeColor(color)) {
        isCaptured = isCaptured || checkCaptureHelper(array, x, y - 1, color);
    }
    if (y < FIELD_SIZE - 1 && array[y + 1][x] == getOppositeColor(color)) {
        isCaptured = isCaptured || checkCaptureHelper(array, x, y + 1, color);
    }
    if (isCaptured) {
        removeStones(array, x, y, color);
    }
    return isCaptured;
}

// Проверка соседних клеток
bool checkCaptureHelper(int**& array, int x, int y, int color) {
    if (array[y][x] == EMPTY) {
        return true;
    }
    if (array[y][x] == color) {
        return false;
    }
    bool isCaptured = true;
    array[y][x] = EMPTY;
    if (x > 0 && array[y][x - 1] != color) {
        isCaptured = isCaptured && checkCaptureHelper(array, x - 1, y, color);
    }
    if (x < FIELD_SIZE - 1 && array[y][x + 1] != color) {
        isCaptured = isCaptured && checkCaptureHelper(array, x + 1, y, color);
    }
    if (y > 0 && array[y - 1][x] != color) {
        isCaptured = isCaptured && checkCaptureHelper(array, x, y - 1, color);
    }
    if (y < FIELD_SIZE - 1 && array[y + 1][x] != color) {
        isCaptured = isCaptured && checkCaptureHelper(array, x, y + 1, color);
    }
    return isCaptured;
}






int main() {
    
    int** field = createField();
    Board(field);
    showField(field);
    int x = 0, y = 0, moveCount=0;
    bool flag = true;
    while (!gameOver(field, moveCount)) {
        while (flag) {
            cout << "White turn ";
            cin >> x >> y;
            if (validMove(field, x-1, y-1, WHITE)) {
                makeMove(field, x-1, y-1, WHITE,moveCount);
                flag = false;
            }
            else cout << "Wrong turn";
        }
        while (!flag) {
            cout << "Black turn ";
            cin >> x >> y;
            if (validMove(field, x -1, y-1,BLACK)) {
                makeMove(field, x-1, y-1, BLACK,moveCount);
                flag = false;
            }
            else cout << "Wrong turn";
        }
        
    }
}
