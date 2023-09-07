#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

class Vec2 {
public: 
    float x,y;
    Vec2 (float _x,float _y) {
        x = _x;
        y = _y;
    }
};
Vec2 operator + (Vec2 p1,Vec2 p2){
    return Vec2(p1.x+p2.x,p1.y+p2.y);
}
Vec2 operator - (Vec2 p1,Vec2 p2){
    return Vec2(p1.x-p2.x,p1.y-p2.y);
}
Vec2 operator * (Vec2 p1,Vec2 p2){
    return Vec2(p1.x*p2.x,p1.y*p2.y);
}
Vec2 operator * (float n,Vec2 p1){
    return Vec2 (p1.x*n,p1.y*n);
}
Vec2 operator * (Vec2 p1,float n){
    return Vec2 (p1.x*n,p1.y*n);
}
float RandomFloat(){
    float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return random;
}
void pointMake (Vec2 p1,Vec2 p2, Vec2 p3,int z){
    int t = rand();
    srand (time(NULL)+z+t);
    Vec2 a = p2-p1;
    Vec2 b = p3-p1;
    float u1 = RandomFloat();
    float u2 = RandomFloat();
    if (u1+u2 > 1){
        u1 = 1-u1;
        u2 = 1-u2;
    }
    Vec2 w = (u1*a) + (u2*b);
    Vec2 point = w+p1;
    cout << "Ponto "<< z << ": ";
    cout << "("<<point.x<<" "<<point.y<<")"<<endl;
}

int main (){
    cout << "Digite o tamanho do lado do triangulo equilatero: " << endl;
    float side;
    cin  >> side;
    //Para facilitar o processo, temos que p1 sempre sera na coordenada (0,0) <- sendo (0,0) o centro do nosso plano cartesiano teorico
    Vec2 p1 (0,0);
    Vec2 p2 (side,0);
    
    float heigth = sqrt(pow(side,2) - ((side/2),2));
    Vec2 p3 (side/2,heigth);
    cout << "Quantos pontos desejam ser gerados ? " << endl;
    int nP;
    cin >> nP;
    for (int k = 0;k<=nP;k++){
        pointMake(p1,p2,p3,k);
    }
}