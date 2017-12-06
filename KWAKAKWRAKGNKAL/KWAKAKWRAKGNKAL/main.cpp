#include"gamedata.h"
#include"IDcard.h"
#include <chrono>
#include <thread>
#include <SFML/Network.hpp>
std::string ip;
const int port = 550000;
sf::TcpSocket socket;
sf::Mutex mutex;
bool gat = false;
sf::Font normal;
sf::Font bold;


bool client(void)
{
	std::cout << "input port";
	std::cin >> ip;
	if (socket.connect(ip, port) == sf::Socket::Done)
	{
		std::cout << "Connected" << std::endl;
		return true;
	}
	return false;
}
void manage(void)
{
	std::string msg;
	sf::Packet in;
	while (1)
	{
		if (client())
		{
			mutex.lock();
			socket.receive(in);
			in >> msg;
			mutex.unlock();
			if (msg == "go")
			{
				gat = true;
			}
		}
		else
		{
			std::cout << "Connection has failed" << std::endl;
		}
	}
}

int main(void) {
	srand(time(NULL));// THIS LINE MUST EXECUTE FIRST AND ONLY ONCE

	if (!normal.loadFromFile("DejaVuSansMono.ttf"))
	{
		// Error...
	}
	if (bold.loadFromFile("DejaVuSansMono-Bold.ttf"))
	{
		//Error
	}
	sf::Text story("A man enters your booth raving about the merrits of long action large calliber rifels for war as compared to the currrently \n accepted docterine using smaller callibers and supression fire. Believing him to be\n a high ordinator of the holy church of Kube you feel you should accept him into the city", normal, 10);
	sf::Text pass("You allow the man into the city, he thanks you and hands you a spam can filled with ammunation for your duty rifle. As he walks\n through the barriers to the city you hear him  ranting about sptizer ammunition\n being the devils pills. You feel the glowing merrits of hardball ammunition in your heart.", normal, 10);
	sf::Text fail("The man declares I am a cardinal of the Kube, Feel the might of 7.62 x 63 After one of the mans bodyguards shoots you, you feel\n deep pain. Not just from the gaping flesh wound but also deep shame from failing\n your training and intution. The man and his entourage then walks through your baricade unmolested. -2 life", normal, 10);

	
	sf::Thread net(&manage);
	net.launch();
	gamedata data;
	sf::RenderWindow window1(sf::VideoMode(700, 490), "Passport");
	sf::RenderWindow window2(sf::VideoMode(480, 600), "ID");
	sf::RenderWindow window3(sf::VideoMode(700, 500), "Visa");
	sf::RenderWindow window4(sf::VideoMode(400, 300), "Orders");
	while (window1.isOpen() && window2.isOpen() && window3.isOpen() && window4.isOpen())
	{
		

		sf::Event event;
		sf::Keyboard keyboard;
		//Okay, we're doing the game logic in  main
		// We'll seee how long I keep that up
		//gameplay loop runs until playerfinishes the month or loses all lives;
		//Once events are figgered out, be sure that the player can exit at their discretion 
		int flip;
		while (data.getlives() > 0 && data.getday() < 12)
		{
			
			data.genchara();
			//placeholder for actually displaying to the screen
		    //data.debugshowdata();

			data.displaychara(window1, window2, window3, window4);
			//get user input for judging the documents
			//replace with events once that's figured
			//for now a basic input loop
			flip = 0;
			if (gat == true)//////////////////////
			{
				std::cout << "Package Recieved";
				window1.draw(story);
				while (window1.pollEvent(event) != sf::Event::KeyPressed && flip ==0)
				{
					switch (event.type)
						case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::X)
						{
							window1.draw(pass);
							flip = 1;
							data.decrementlives();
							data.decrementlives();
						}
						else
						{
							window1.draw(fail);
							flip = 1;
						}
				}
				gat = false;
			}
			while (window1.pollEvent(event) != sf::Event::KeyPressed && flip == 0 && gat == false)
			{
				switch (event.type)
				{
					// window closed
				case sf::Event::Closed:
					window1.close();
					window2.close();
					window3.close();
					window4.close();
					break;

					// key pressed
				case sf::Event::KeyPressed:

					if (event.key.code == sf::Keyboard::Z)
					{
						
						data.advance(false);
						flip = 1;
						data.display_choice_deny(window1);
						std::this_thread::sleep_for(std::chrono::milliseconds(1000*3));
					}
					else if (event.key.code == sf::Keyboard::X)
					{
						data.advance(true);
						flip = 1;
						data.display_choice_accept(window1);
						std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 3));
					}
					break;


					// we don't process other types of events
				default:
					break;
				}
				
			}
			
		}
		if (window1.pollEvent(event) == sf::Event::Closed || window2.pollEvent(event) == sf::Event::Closed || window3.pollEvent(event) == sf::Event::Closed || window4.pollEvent(event) == sf::Event::Closed )
		{
			window1.close();
			window2.close();
			window3.close();
			window4.close();
		}
	}
	std::cout << "\nGame over";
	//TODO: Write a Game over display function
	// Function will internally handle whether to display a "Victory" or "Game Over" screen

	return 0;
};
