#include <SFML/Graphics.hpp>
// To use time library of C
#include <time.h>
#include<iostream>
using namespace std;

double max(double a, double b) { return a > b ? a : b; }
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(300, 100), "SFML Horses testing!");
    sf::CircleShape shape(100.f);
    sf::Texture h1;
    sf::Texture h2;
    sf::Texture h3;
    h1.loadFromFile("img/horse1.png");
    h2.loadFromFile("img/horse2.png");
    h3.loadFromFile("img/horse3.png");
    sf::Sprite horse1;
    sf::Sprite horse2;
    sf::Sprite horse3;

    sf::Sprite ending;
    sf::Texture Tend;
    Tend.loadFromFile("img/race_ending.png");
    ending.setTexture(Tend);
    ending.setPosition(60, 30);

  /*  sf::Text t;
    t.setFont()
    t.setCharacterSize(10);
    t.setFillColor(sf::Color::Red);
    t.setString("Carrera finalizada");*/
    
    
    vector<sf::Sprite> horses;
    horses.push_back(horse1);
    horses.push_back(horse2);
    horses.push_back(horse3);
    horses[0].setTexture(h1);
    horses[1].setTexture(h2);
    horses[2].setTexture(h3);
    sf::Vector2f ogv2(0.0,25.0);
    sf::Vector2f ogv3(0.0,50.0);
    horses[1].move(ogv2);
    horses[2].move(ogv3);
   
    vector<sf::Vector2f> v;
    bool Rep = true;
    double v1x=0.0;
    double v2x=0.0;
    double v3x=0.0;
    while (Rep) {
        v1x = rand() % 20 + 5;
        v2x = rand() % 20 + 5;
        v3x = rand() % 20 + 5;
          

        if (v1x != v2x and v1x != v3x and v2x != v3x)
        {
            Rep = false;
        }
    }
    sf::Vector2f v1(v1x, 0.0);
    sf::Vector2f v2(v2x, 0.0);
    sf::Vector2f v3(v3x, 0.0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    shape.setFillColor(sf::Color::Red);
   // double max = v1.x > v2.x ? v1.x : v2.x;
    //max = max > v3.x ? max : v3.x;
    double m = max(v1.x, v2.x);
    m = max(m, v3.x);
    string winner;
    int i = 0;
    for (sf::Vector2f value : v)
    {
        
        if (value.x == m)
        {
            break;
        }
        i++;
    }
    bool ended = false;
    while (window.isOpen())
    {
        delay(1);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!ended)
        {
            horses[0].move(v1);
            horses[1].move(v2);
            horses[2].move(v3);
        }
        if (horses[i].getPosition().x >= 300)
        {
            ended = true;
            int idx = 0;
            cout << "Carrera finalizada"<< endl;
            cout << "ha ganado el caballo numero:" << (i+1) << endl;  
            window.clear();
            window.draw(ending);
            window.display();
            delay(3);
            window.close();
            
        }
        else
        {
            double x = horses[i].getPosition().x;
            cout << "Faster horse number->"<<(i+1)<<",is on position->" << x << endl;
            /* x = horse2.getPosition().x;
             cout << "Horse2 x" << x << endl;
             x = horse3.getPosition().x;
             cout << "Horse3 x" << x << endl;*/

             //sf::Vector2f f1 = horse1.getPosition();
           /*  if (f1.x != 300)
             {
                 sf::Vector2f f2 = horse2.getPosition();
                 if (f2.y != 300)
                 {

                     sf::Vector2f f3 = horse3.getPosition();
                     if (f3.y == 300)
                     {
                         cout << "Horse2 Winner";
                     }
                 }
                 else
                 {
                     cout << "Horse2 Winner";
                 }
             }
             else {
                 cout << "Horse 1 WINNER!!";
             }*/
            window.clear();

            window.draw(shape);
            window.draw(horses[0]);
            window.draw(horses[1]);
            window.draw(horses[2]);
        
            window.display();
        }
    }

    return 0;
}