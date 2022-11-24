#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800,600),"My Game");
    window.setKeyRepeatEnabled(false);

    // Declare Variables
    float x1 = 1000.0;
    float x2 = 2000.0;
    float x3 = 3000.0;
    float x4 = 4000.0;
    float my = 220.0;
    bool play = true;
    bool Up = false;
    bool return1 = false;
    bool hit = false;
    bool Enter = false;
    long long counttime = 1;
    int i = 0;

    //--------------------

    // Road Of The Game
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(800,600));
    rect.setPosition(0,0);
    sf::Texture image;
    image.loadFromFile("Data/ss.png");
    rect.setTexture(&image);

    // Image Of Barrier (Oil)
    sf::Texture image1;
    image1.loadFromFile("Data/Oil.jpg");

    // Barrier 1
    sf::RectangleShape rect1;
    rect1.setSize(sf::Vector2f(70,70));
    rect1.setPosition(x1,195);
    rect1.setTexture(&image1);

    // Barrier 2
    sf::RectangleShape rect2;
    rect2.setSize(sf::Vector2f(70,70));
    rect2.setPosition(x2,195);
    rect2.setTexture(&image1);

    // Barrier 3
    sf::RectangleShape rect3;
    rect3.setSize(sf::Vector2f(70,70));
    rect3.setPosition(x3,195);
    rect3.setTexture(&image1);

    // Barrier 4
    sf::RectangleShape rect4;
    rect4.setSize(sf::Vector2f(70,70));
    rect4.setPosition(x4,195);
    rect4.setTexture(&image1);

    // The High Part Of Green Background
    sf::RectangleShape rect5;
    rect5.setSize(sf::Vector2f(800,180));
    rect5.setPosition(0,0);
    sf::Texture image3;
    image3.loadFromFile("Data/mah.jpg");
    rect5.setTexture(&image3);

    // The Low Part Of Green Background
    sf::RectangleShape rect6;
    rect6.setSize(sf::Vector2f(800,400));
    rect6.setPosition(0,320);
    rect6.setTexture(&image3);

    // Mahmoud
    sf::RectangleShape rect7;
    rect7.setSize(sf::Vector2f(300,80));
    rect7.setPosition(220,0);
    sf::Texture image0;
    image0.loadFromFile("Data/ma.jpg");
    rect7.setTexture(&image0);

    // Start The Game
    sf::RectangleShape rect8;
    rect8.setSize(sf::Vector2f(800,600));
    rect8.setPosition(0,0);
    sf::Texture image5;
    image5.loadFromFile("Data/start.png");
    rect8.setTexture(&image5);

    // Game Over
    sf::RectangleShape rect9;
    rect9.setSize(sf::Vector2f(800,600));
    rect9.setPosition(0,0);
    sf::Texture image6;
    image6.loadFromFile("Data/Over.jpg");
    rect9.setTexture(&image6);

    //---------------------

    // The Player
    sf::CircleShape car;
    car.setRadius(25);
    car.setPosition(100,my);
    car.setFillColor(sf::Color(60,10,80));

    // Sound Effect Of The Game

    // Sound Of Jump
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Data/Jump.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    // Sound Of Game Over
    sf::SoundBuffer buffer1;
    buffer1.loadFromFile("Data/Game Over.wav");
    sf::Sound sound1;
    sound1.setBuffer(buffer1);

    // Sound Of Good Score
    sf::SoundBuffer buffer2;
    buffer2.loadFromFile("Data/GoodScore.wav");
    sf::Sound sound2;
    sound2.setBuffer(buffer2);

    //---------------------

    //Font
    sf::Font font;
    font.loadFromFile("Data/calibri.ttf");

    // Time
    sf::Text time;
    time.setFont(font);
    time.setString("Time : ");
    time.setPosition(500,500);
    time.setFillColor(sf::Color::Green);
    time.setCharacterSize(50);

    // Value Of Time
    sf::Text Vtime;
    Vtime.setFont(font);
    Vtime.setPosition(650,500);
    Vtime.setFillColor(sf::Color::Green);
    Vtime.setCharacterSize(50);


 // Start the game loop
    while(play)
    {
        // Process events
        sf::Event move;
        while(window.pollEvent(move))
        {
            if(move.type == sf::Event::KeyPressed && move.key.code ==sf::Keyboard::Enter)
            {
                Enter =true;
            }
            if(move.type == sf::Event::KeyPressed && move.key.code ==sf::Keyboard::Up)
            {
                Up=true;
            }
            if(move.type==sf::Event::Closed)
            {
                play=false;
            }
        }

        //------------------
        // Logic
        if(Enter ==true)
        {
            if(car.getGlobalBounds().intersects(rect1.getGlobalBounds())==true||car.getGlobalBounds().intersects(rect2.getGlobalBounds())==true||car.getGlobalBounds().intersects(rect3.getGlobalBounds())==true||car.getGlobalBounds().intersects(rect4.getGlobalBounds())==true)//||car.getGlobalBounds().intersects(rect1.getGlobalBounds())==true||culer.getGlobalBounds().intersects(rect2.getGlobalBounds())==true||culer1.getGlobalBounds().intersects(rect.getGlobalBounds())==true)
            {
                sound1.play();
                hit = true;
                Enter = false;
            }
            if(Up == true&&return1 == false&&my>=80)
            {
                sound.play();
                my-=0.5;
                car.setPosition(100,my);
            }
            if (my<=80)
            {
                return1 = true;
                Up=false;
            }
            if(return1 == true)
            {
                my+=0.2;
                car.setPosition(100,my);
            }
            if(my>=220)
            {
                return1 =false;
            }

            // Place Of Barriers
            rect1.setPosition(x1,195);
            rect2.setPosition(x2,195);
            rect3.setPosition(x3,195);
            rect4.setPosition(x4,195);

            if(x1<=0)
            {
                x1 = 1500;
            }
            if(x2<=0)
            {
                x2 = 2500;
            }
            if(x3<=0)
            {
                x3 = 3500;
            }
            if(x4<=0)
            {
                x4 = 4500;
            }

            x1-=0.4;
            x2-=0.4;
            x3-=0.4;
            x4-=0.4;

            i+=1;
            std::string s = std::to_string(counttime);
            Vtime.setString(s);
            if(i==100)
            {
                counttime = counttime + 1;
                i =0 ;
            }
            if(counttime%100==0)
            {
                sound2.play();
            }

            //---------------------
            // rendring

            window.clear();
            window.draw(rect);
            window.draw(rect5);
            window.draw(rect7);
            window.draw(rect6);
            window.draw(car);
            window.draw(rect1);
            window.draw(rect2);
            window.draw(rect3);
            window.draw(rect4);
            window.draw(time);
            window.draw(Vtime);

        }

        if(hit == true)
        {
            window.draw(rect9);
            window.draw(time);
            window.draw(Vtime);
        }

        window.display();
        window.draw(rect8);
    }
}
