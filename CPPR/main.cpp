#include <SFML/Graphics.hpp>
#include <vector>

// Constants for the different sizes of windows and elements

int const BORDER = 8;
int const SIDEXSIZE = 128;
int const SIDEYSIZE = 512;
int const PLAYXSIZE = 736;
int const PLAYYSIZE = 704;
int const WINDOWXSIZE = 1024;
int const WINDOWYSIZE = 768;
int const PADDLEXSIZE = 24;
int const PADDLEYSIZE = 64;


int replaceByClassSpeed = 13;
// Part of a test with classes, leave commented out
//int counter = 0;

std::vector <sf::Sprite> elementSprites;


int main()
{

    //These should be left alone.  If you want to change sizes, change them via the Constants above.

    int playFieldTLX = (SIDEXSIZE + (BORDER * 2));
    int playFieldTLY = BORDER * 4;
    int sideField1TLX = BORDER;
    int sideField1TLY = ((WINDOWYSIZE/2)-(SIDEYSIZE/2));
    int sideField2TLX = (SIDEXSIZE + (BORDER * 3) + PLAYXSIZE);
    int sideField2TLY = (WINDOWYSIZE/2)-(SIDEYSIZE/2);
    int paddle1X = playFieldTLX;
    int paddle2X = (playFieldTLX + (PLAYXSIZE - PADDLEXSIZE));


    // Create the main window
    sf::RenderWindow app(sf::VideoMode(WINDOWXSIZE, WINDOWYSIZE), "Chemical Ping Pong Reaction");

    // Load a sprite to display
    sf::Texture playFieldTexture;
    sf::Texture sideFieldTexture;
    sf::Texture paddleTexture;
    sf::Texture elementNucleusTexture;
    sf::Texture elementValenceShellTexture;
    sf::Texture elementElectronTexture;

    if (!playFieldTexture.loadFromFile("playField.png"))
    return EXIT_FAILURE;

    if (!sideFieldTexture.loadFromFile("sideField.png"))
    return EXIT_FAILURE;

    if (!paddleTexture.loadFromFile("paddle.png"))
    return EXIT_FAILURE;

    if (!elementNucleusTexture.loadFromFile("NucleusBlank.png"))
    return EXIT_FAILURE;

    if (!elementValenceShellTexture.loadFromFile("Blank8Shell.png"))
    return EXIT_FAILURE;

    sf::Sprite playFieldSprite(playFieldTexture);
    sf::Sprite sideFieldSprite_P1(sideFieldTexture);
    sf::Sprite sideFieldSprite_P2(sideFieldTexture);
    sf::Sprite padSprite_P1(paddleTexture);
    sf::Sprite padSprite_P2(paddleTexture);
    sf::Sprite eNSprite(elementNucleusTexture);
    sf::Sprite eVSprite(elementValenceShellTexture);
    //sf::Sprite eElectron(elementElectronTexture);

    playFieldSprite.setPosition(playFieldTLX, playFieldTLY);
    sideFieldSprite_P1.setPosition(sideField1TLX,sideField1TLY);
    sideFieldSprite_P2.setPosition(sideField2TLX, sideField2TLY);
    padSprite_P1.setPosition(paddle1X, ((PLAYXSIZE / 2) - (PADDLEYSIZE / 2)));
    padSprite_P2.setPosition(paddle2X, ((PLAYXSIZE / 2) - (PADDLEYSIZE / 2)));




	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();

            //From here until end, is just four cases for moving the paddle via key presses.  It is not the best way to do that
            //and it could be condensed into a function.
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                {
                    if (padSprite_P1.getPosition().y > BORDER)
                    {
                        padSprite_P1.move(0, - replaceByClassSpeed);
                    }
                    else
                    {
                        padSprite_P1.setPosition(paddle1X, BORDER);
                    }
                }

             }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::S)
                {
                    if (padSprite_P1.getPosition().y < (PLAYYSIZE + BORDER) - PADDLEYSIZE)
                    {
                        padSprite_P1.move(0, replaceByClassSpeed);
                    }
                    else
                    {
                        padSprite_P1.setPosition(paddle1X, (PLAYYSIZE + BORDER) - PADDLEYSIZE);
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    if (padSprite_P2.getPosition().y > BORDER)
                    {
                        padSprite_P2.move(0, - replaceByClassSpeed);
                    }
                    else
                    {
                        padSprite_P2.setPosition(paddle2X, BORDER);
                    }
                }

             }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down)
                {
                    if (padSprite_P2.getPosition().y < (PLAYYSIZE + BORDER) - PADDLEYSIZE)
                    {
                        padSprite_P2.move(0, replaceByClassSpeed);
                    }
                    else
                    {
                        padSprite_P2.setPosition(paddle2X, (PLAYYSIZE + BORDER) - PADDLEYSIZE);
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    sf::Sprite tempSpriteObj(paddleTexture);
                    counter++;
                    tempSpriteObj.setPosition(5*counter, 10*counter);
                    elementSprites.push_back(tempSpriteObj);
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    elementSprites.pop_back();
                }
            }
            //END
        }

        //TODO in the While Gamplay Loop
        /*

        The elements and the players are in their own class.  Their attributes should be in the least, setPosition, and getPosition.
        New classes or extensions may be needed for the fireGun function.


        check and move paddles
            move paddle is done, can be shortened into a function
        check and move gun

        fireGun

        move the elements

        check if the elements bond

        check if the elements bounce

        check if the elements hit paddle

        check if the elements hit destruction zone/time out/need to be murdered
            play delete animation

        increase score

        Check if game over
            if yes: go to different screen/turn off game/ something
        */


        //This for is a part of a test to create objects of classes.  It can be left commented out.
            /*
            for (int i = 0; i < elementSprites.size(); i++)
            {
                elementSprites[i].move(1, 1);
            }
            */

        // Clear screen
        app.clear();

        // Draw the sprite
        //Same as the for loop above
        /*
        for (int i = 0; i < elementSprites.size(); i++)
        {
            app.draw(elementSprites[i]);
        }
        */
        app.draw(sideFieldSprite_P1);
        app.draw(sideFieldSprite_P2);
        app.draw(padSprite_P1);
        app.draw(padSprite_P2);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
