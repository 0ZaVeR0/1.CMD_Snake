#include <iostream>
#include <Windows.h>
#include <experimental/random>
#include <conio.h>
#include <stdlib.h> 

using namespace std;
int main(){
    bool game = true,doesappleexist = false,appleeaten = false;
    int size = 10,score = 0,appleindex = -1,headindex = 2;
    int field[size][size] = {};
    int apple [2];
    int headpos[2];
    
    //spawn apple
    apple[0] = experimental::randint(0,size-1);
    apple[1] = experimental::randint(0,size-1); 
    field[apple[0]][apple[1]] = appleindex;
    doesappleexist = true;

    //spawn snake
    headpos[0] = experimental::randint(1,size-2);
    headpos[1] = experimental::randint(1,size-2);
    field[headpos[0]][headpos[1]] = headindex-1;
    
    while(game){
        //move
        switch (_getch()){
        case 'w':
            if (headpos[0] == 0 || field[headpos[0]-1][headpos[1]] > 1) {game = false;break;}
            headpos[0] --;
            break;
        case 'a':
            if (headpos[1] == 0 || field[headpos[0]][headpos[1]-1] > 1) {game = false;break;}
            headpos[1] --;
            break;
        case 's':
            if (headpos[0] == size-1 || field[headpos[0]+1][headpos[1]] > 1) {game = false;break;}
            headpos[0] ++;
            break;
        case 'd':
            if (headpos[1] == size-1 || field[headpos[0]][headpos[1]+1] > 1) {game = false;break;}
            headpos[1] ++;
            break;    
        }
        if (field[headpos[0]][headpos[1]] == appleindex) {
            field[headpos[0]][headpos[1]] = headindex;
            appleeaten = true;
            doesappleexist = false;
            headindex++;
        }
        else {field[headpos[0]][headpos[1]] = headindex;}
        
        //update snake pos
        if (appleeaten){
            appleeaten = false;
        }
        else{
            for(int a = 0; a < size; a++){
                for(int b = 0; b < size; b++){
                    if (field[a][b] > 0){
                        field[a][b] --;
                    }
                }
            }
        }

        //spawn apple
        if (doesappleexist == false){
            while (field[apple[0]][apple[1]] != 0){
                apple[0] = experimental::randint(0,size-1);
                apple[1] = experimental::randint(0,size-1); 
            }
            field[apple[0]][apple[1]] = appleindex; 
            doesappleexist = true;
        }
        
        //draw
        cout << "Snake: " << "x:" << headpos[0] << " y:" << headpos[1] << '\n';
        cout << "Apple: " << "x:" << apple[0] << " y:" << apple[1] << '\n';
        cout << "Score: " << headindex-2 << '\n';
        for(int a = 0; a < size; a++){
            for(int b = 0; b < size; b++){
                if (field[a][b] == headindex-1)
                {
                    cout <<"Ü ";
                }
                else if (field[a][b] > 0)
                {
                    cout <<"■ ";
                }
                else if (field[a][b] < 0)
                {
                    cout <<"ඞ ";
                }
                
                else
                {
                    cout << "· ";
                }
            }
            cout << '\n';
        }     
    }
    return 0;
}