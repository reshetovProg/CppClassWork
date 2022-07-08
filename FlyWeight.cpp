#include <iostream>
#include <ctime>
using namespace std;
#define random(a,b) a+rand()%(b+1-a)

class BulletType;
class BulletFabric;

class BulletType {
private:
    string pathTexture;//38
    string color;//38
    float height;//4
    float width;//4
    float weight;//4
    int poligonCount;//4
    int damage;//4
    int density;//4
public:
    BulletType(string pathTexture, string color, float height, float width, float weight, int poligonCount,
        int damage, int density) {
        this->pathTexture = pathTexture;
        this->color = color;
        this->height = height;
        this->width = width;
        this->weight = weight;
        this->poligonCount = poligonCount;
        this->damage = damage;
        this->density = density;
    }
};

class Bullet {
private:
    float xPosition;//4
    float yPosition;//4
    BulletType* type = nullptr;
public:
    Bullet() {}
    Bullet(float x, float y, BulletType*& type) {
        this->xPosition = x;
        this->yPosition = y;
        this->type = type;
    }
    ~Bullet() {
        delete type;
    }
};

class BulletFabric {
private:
    BulletType* type = nullptr;
public:
    BulletFabric(string pathTexture, string color, float height, float width, float weight, int poligonCount,
        int damage, int density) {
        type = new BulletType(pathTexture, color, height, width, weight, poligonCount, damage, density);
    }
    Bullet& create(float x, float y) {
        Bullet* bul = new Bullet(x, y, type);
        return *bul;
    }

};


float byteToMb(int byte) {
    return float(byte) / 1024 / 1024;
}

int main()
{
    srand(time(NULL));
    BulletFabric fFireball("fireball.png", "red", 20, 20, 0, 100, 20, 2);
    BulletFabric fMidBullet("midBullet.png", "gold", 5, 2, 0.2, 20, 5, 100);
    Bullet* fireballs = new Bullet[500000];
    Bullet* midBullets = new Bullet[500000];
    for (int i = 0; i < 500000; i++) {
        fireballs[i] = fFireball.create(random(1, 100), random(1, 100));
    }

    for (int i = 0; i < 500000; i++) {
        midBullets[i] = fMidBullet.create(random(1, 100), random(1, 100));
    }

    system("pause");


}
